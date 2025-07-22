#include "products1.h"
#include"utils.h"
#include"productmain.h"
#include"globals.h"
#include "ui_products1.h"
#include <QMessageBox>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>

products1::products1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::products1)
{
    ui->setupUi(this);


}

products1::~products1()
{
    if (cap.isOpened()) cap.release();
    delete ui;
}

void products1::on_capturebarcodebutton_clicked()
{
    QString pro = getAssetPath("sr.prototxt");
    QString caffee = getAssetPath("sr.caffemodel");
    cv::barcode::BarcodeDetector barcodeDetector(pro.toStdString(), caffee.toStdString());

    cv::namedWindow("FrameOut", 0);
    cv::namedWindow("FrameIn", 0);

    std::vector<cv::Point> corners;
    std::vector<std::string> decoded_type;
    std::vector<std::string> decoded_info;

    cap.open(0);
    if (!cap.isOpened()) {
        QMessageBox::critical(this, "Error", "Cannot open camera!");
        return;
    }

    cv::Mat frame;

    while (true)
    {
        cap >> frame;
        if (frame.empty()) break;

        cv::imshow("FrameIn", frame);

        barcodeDetector.detectAndDecodeWithType(frame, decoded_info, decoded_type, corners);

        if (!corners.empty())
        {
            for (int i = 0; i < static_cast<int>(corners.size()); i += 4)
            {
                if (!decoded_info[i / 4].empty())
                {
                    std::string barcodeData = decoded_info[i / 4];
                    bool isValid = false;

                    vector<productmain> products = globaladmin.getInventory();

                    // 🔎 Check if the ID already exists in the inventory
                    for (const auto& product : products) {
                        if (std::to_string(product.getid()) == barcodeData) {
                            isValid = true;
                            break;
                        }
                    }

                    if (isValid) {
                        QMessageBox::warning(this, "Input Error", "Product already in Inventory!");
                        cap.release();
                        cv::destroyAllWindows();
                        return;
                    } else {
                        ui->lineEdit->setText(QString::fromStdString(barcodeData));
                        ui->lineEdit->setReadOnly(true);

                        cap.release();
                        cv::destroyAllWindows();
                        return;
                    }
                }
            }
        }


        cv::imshow("FrameOut", frame);
        int key = cv::waitKey(1);
        if (key == 27) { // ESC key pressed
            cap.release();
            cv::destroyAllWindows();
            break;
        }
    }
    cv::destroyAllWindows();
}

long long int products1::getID() { return ui->lineEdit->text().toLongLong(); }
std::string products1::getName() { return ui->lineEdit_2->text().toStdString(); }
int products1::getquantity() { return ui->lineEdit_3->text().toInt(); }
float products1::getSalePrice() { return ui->lineEdit_4->text().toFloat(); }
float products1::getPrice() { return ui->lineEdit_5->text().toFloat(); }

void products1::on_submitbutton_clicked()
{
    if (getID()!=0 && !getName().empty() && getquantity() > 0 && getSalePrice() > 0 && getPrice() > 0) {
        accept();  // Close the dialog
    } else {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields correctly!");
    }
}

