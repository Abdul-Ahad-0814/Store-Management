#include "rw.h"
#include "ui_rw.h"
#include"utils.h"
#include <QPixmap>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include <filesystem>

using namespace std;
using namespace cv;
using namespace cv::face;

rw::rw(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::rw)
{
    ui->setupUi(this);

    // Show face icon
    QString product=getAssetPath("faceicon.jpg");
    QPixmap faceImg(product);
    if (!faceImg.isNull()) {
        ui->faceicon->setPixmap(faceImg);
        ui->faceicon->setScaledContents(true);
    } else {
        qDebug() << "Error: Face icon image not found!";
    }

    filenumber = 0;
    name = "faceAhad"; // Or make it dynamic from user input
    QString face=getAssetPath("haarcascade_frontalface_default.xml");
    face_cascade.load(face.toStdString());
    if (face_cascade.empty()) {
        qDebug() << "Error loading Haar Cascade!";
    }
}

rw::~rw() {
    delete ui;
}

void rw::detectAndDisplay(Mat frame) {
    vector<Rect> faces;
    Mat frame_gray, faceROI, resized, gray;

    cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);

    face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0, Size(100, 100));
    if (faces.empty()) {
        qDebug() << "No face detected!";
        return;
    }

    for (const auto &face : faces) {
        faceROI = frame(face);
        cv::resize(faceROI, resized, Size(128, 128));
        cvtColor(resized, gray, COLOR_BGR2GRAY);
        QString face1=getAssetPath("faces/");
        string filename = face1.toStdString() + name + to_string(filenumber++) + ".jpg";
        if (imwrite(filename, gray)) {
            qDebug() << "Saved:" << QString::fromStdString(filename);
        } else {
            qDebug() << "Failed to save image!";
        }

        rectangle(frame, face, Scalar(0, 255, 0), 2);
        imshow("Detected Face", faceROI);
        break; // save only one face per frame
    }
}

void rw::addFace() {
    VideoCapture cap(0, cv::CAP_DSHOW);
    if (!cap.isOpened()) {
        qDebug() << "Camera not found!";
        return;
    }

    Mat frame;
    int count = 0;

    while (count < 10) {
        cap >> frame;
        if (frame.empty()) continue;

        imshow("Live Feed", frame);
        int key = waitKey(30);
        detectAndDisplay(frame);
        count++;

        if (key == 27) break; // Esc to exit early
    }

    destroyAllWindows();
    cap.release();
    qDebug() << "Captured 10 images.";
}

void rw::dbread(vector<Mat> &images, vector<int> &labels) {
    QString face3=getAssetPath("faces/");
    string folder = face3.toStdString();
    for (const auto &entry : std::filesystem::directory_iterator(folder)) {
        string path = entry.path().string();
        Mat img = imread(path, IMREAD_GRAYSCALE);
        if (!img.empty()) {
            images.push_back(img);

            // Extract numeric label from filename (e.g. faceAhad0.jpg -> 0)
            string filename = entry.path().filename().string();
            size_t pos = filename.find_first_of("0123456789");
            string number = filename.substr(pos, filename.find_last_of(".") - pos);
            try {
                labels.push_back(stoi(number));
            } catch (...) {
                qDebug() << "Invalid label in:" << QString::fromStdString(filename);
            }
        }
    }
}

void rw::trainEigenFace() {
    vector<Mat> images;
    vector<int> labels;
    dbread(images, labels);

    if (images.empty() || labels.empty()) {
        qDebug() << "No training data found!";
        return;
    }

    Ptr<EigenFaceRecognizer> model = EigenFaceRecognizer::create();
    model->train(images, labels);
    QString product=getAssetPath("eigenface.yml");
    model->save(product.toStdString());

    qDebug() << "Training completed!";
}

void rw::on_pushButton_clicked() {
    addFace();
    trainEigenFace();
}
