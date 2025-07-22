#include "login.h"
#include "ui_login.h"
#include "login1.h"
#include"cashierwindow.h"

#include"user.h"
#include"globals.h"
#include <QMessageBox>
#include <QTimer>
#include <QDir>
#include <QDebug>
#include"addproducts.h"
#include"utils.h"

#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    QString product=getAssetPath("haarcascade_frontalface_default.xml");

    faceDetector.load(product.toStdString());

    loadreferenceimages();
}

LoginWindow::~LoginWindow()
{
    cap.release();
    delete ui;
}

void LoginWindow::loadreferenceimages()
{
    QString facet=getAssetPath("faces");
    QString basePath = facet;
    QDir dir(basePath);
    QStringList filters;
    filters << "*.jpg" << "*.png";
    QFileInfoList fileList = dir.entryInfoList(filters, QDir::Files);

    Ptr<ORB> orb = ORB::create();
    refDescriptors.clear();
    refKeypoints.clear();

    for (const QFileInfo &fileInfo : fileList)
    {
        Mat img = imread(fileInfo.absoluteFilePath().toStdString(), IMREAD_GRAYSCALE);
        if (img.empty()) continue;

        std::vector<KeyPoint> keypoints;
        Mat descriptors;
        orb->detectAndCompute(img, noArray(), keypoints, descriptors);

        if (!descriptors.empty())
        {
            refDescriptors.push_back(descriptors);
            refKeypoints.push_back(keypoints);
        }
    }

    if (!refKeypoints.empty())
        qDebug() << "Reference Keypoints: " << refKeypoints[0].size();
}

bool LoginWindow::recognizeFace(const Mat &inputImage)
{
    if (inputImage.empty())
        return false;

    Mat gray;
    cvtColor(inputImage, gray, COLOR_BGR2GRAY);

    std::vector<Rect> faces;
    faceDetector.detectMultiScale(gray, faces);

    if (faces.empty())
    {
        qDebug() << "No face detected!";
        return false;
    }

    Mat faceROI = gray(faces[0]);

    Ptr<ORB> orb = ORB::create();
    std::vector<KeyPoint> keypoints;
    Mat descriptors;
    orb->detectAndCompute(faceROI, noArray(), keypoints, descriptors);

    if (descriptors.empty())
        return false;

    BFMatcher matcher(NORM_HAMMING, true);

    for (const auto& refDesc : refDescriptors)
    {
        std::vector<DMatch> matches;
        matcher.match(descriptors, refDesc, matches);

        int goodMatches = 0;
        for (const auto &m : matches)
        {
            if (m.distance < 60)
                goodMatches++;
        }

        qDebug() << "Good Matches: " << goodMatches;

        if (goodMatches >= 5)
            return true;
    }

    return false;
}

void LoginWindow::on_pushButton_clicked()
{
    QString role ;
    if (ui->radioButton->isChecked())
        role = "Admin";
    else if (ui->radioButton_2->isChecked())
        role = "User";
    qDebug() << "Login button clicked";

    if (role == "Admin")
    {
        qDebug() << "Admin selected - starting face recognition";

        VideoCapture cap(0);
        if (!cap.isOpened())
        {
            QMessageBox::critical(this, "Error", "Failed to access the camera.");
            return;
        }

        Mat frame;
        QTimer::singleShot(3000, this, [=]() mutable {
            cap.read(frame);
            if (frame.empty())
            {
                QMessageBox::critical(this, "Error", "Frame capture failed!");
                return;
            }

            bool recognized = recognizeFace(frame);

            cap.release();

            if (recognized)
            {
                QMessageBox::information(this, "Success", "Face recognized. Login successful.");
                 Addproducts *loginWin = new Addproducts(this);
                loginWin->show();
            }
            else
            {
                QMessageBox::warning(this, "Failed", "Face not recognized. Try again.");
            }
        });
    }
    else if (ui->radioButton_2->isChecked())
    {

        QString inputUsername = ui->lineEdit->text().trimmed();
        QString inputPassword = ui->lineEdit_2->text().trimmed();

        if (inputUsername.isEmpty() || inputPassword.isEmpty()) {
            QMessageBox::warning(this, "Input Error", "Please enter both username and password.");
            return;
        }

    //     QFile file("E:/oop project final/Store-Management-system/cashiers.csv");
    //     if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    //         QMessageBox::critical(this, "File Error", "Unable to open cashier.csv file.");
    //         return;
    //     }

    //     QTextStream in(&file);
    //     bool found = false;

    //     while (!in.atEnd()) {
    //         QString line = in.readLine();
    //         QStringList fields = line.split(",");

    //         if (fields.size() >= 2) {
    //             QString csvUsername = fields[0].trimmed();
    //             QString csvPassword = fields[1].trimmed();

    //             if (csvUsername == inputUsername && csvPassword == inputPassword) {
    //                 found = true;
    //                 break;
    //             }
    //         }
    //     }

    //     file.close();

    //     if (found) {
    //         QMessageBox::information(this, "Login Successful", "Welcome Cashier!");
    //         login_success* loginWin = new login_success(this);
    //         loginWin->show();
    //     } else {
    //         QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    //     }
    // }
        qDebug() << "List of Cashiers:";
        vector<user>& cashiers = globaladmin.getCashiers();
        for (const user& cashier : cashiers) {
            qDebug() << "Username:" << QString::fromStdString(cashier.getusername());
        }
        bool found = false;
        user* loggedInCashier = nullptr;

        for (user& cashier : cashiers) {
            if (cashier.getusername() == inputUsername && cashier.getpassword() == inputPassword) {
                loggedInCashier = &cashier;
                found = true;
                break;
            }
        }

        if (found && loggedInCashier != nullptr) {
            QMessageBox::information(this, "Login Successful", "Welcome, " + inputUsername + "!");

            // Open the cashier window
            cashierwindow* cashierWin = new cashierwindow(this);
            cashierWin->setCashier(loggedInCashier);  // Pass the cashier object
            cashierWin->show();
        } else {
            QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
        }
    }

    }

void LoginWindow::on_pushButton_2_clicked()
{
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        QMessageBox::critical(this, "Error", "Camera not accessible");
        return;
    }

    int imgCount = 0;
    QString faces=getAssetPath("faces");
    QString saveDir = faces;

    while (imgCount < 10)
    {
        Mat frame;
        cap >> frame;
        if (frame.empty())
        {
            qDebug() << "Error: Frame capture failed!";
            continue;
        }

        QString filename = QString("%1/faceAhad%2.jpg").arg(saveDir).arg(imgCount);
        if (!imwrite(filename.toStdString(), frame))
        {
            qDebug() << "Failed to save: " << filename;
        }
        else
        {
            qDebug() << "Saved: " << filename;
            imgCount++;
        }

        waitKey(300);
    }

    cap.release();
    qDebug() << "Captured 10 images.";
    loadreferenceimages();
    QMessageBox::information(this, "Training", "Training completed!");
}
