#include "login_success.h"
#include "ui_login_success.h"

#include<QPixmap>

login_success::login_success(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login_success)
{
    ui->setupUi(this);
    QPixmap successicon("E:/oop project final/store-management-system/Assets/images");
    ui->success->setPixmap(successicon);
    ui->success->setScaledContents(true);
}

login_success::~login_success()
{
    delete ui;
}
