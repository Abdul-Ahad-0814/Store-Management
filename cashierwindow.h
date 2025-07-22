#ifndef CASHIERWINDOW_H
#define CASHIERWINDOW_H

#include <QDialog>
#include<globals.h>
#include<QString>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>

namespace Ui {
class cashierwindow;
}

class cashierwindow : public QDialog
{
    Q_OBJECT

public:
    explicit cashierwindow(QWidget *parent = nullptr);
    ~cashierwindow();
    void loadproducts();
    void addtocart(const productmain &product);
    void updatetotals();
    void updatecarttable();
    void addtocart(const productmain &product, int quantity);
    void setCashier(user* cashier);
    void updateinventorytable(const std::vector<productmain>& products);
    QString generatereceipt();
    void saveReceiptToFile(const QString &receiptContent);
    void printReceipt(const QString &receiptContent);
    string capturebarcode();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::cashierwindow *ui;
    user* currentCashier;
    cv::VideoCapture cap;

};

#endif // CASHIERWINDOW_H
