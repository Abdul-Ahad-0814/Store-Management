#include "login_failed.h"
#include "ui_login_failed.h"
#include<QPixmap>

login_failed::login_failed(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login_failed)
{
    ui->setupUi(this);
    QPixmap fail("E:/oop project final/store-management-system/Assets/failed");
    ui->failed->setPixmap(fail);
    ui->failed->setScaledContents(true);
}

login_failed::~login_failed()
{
    delete ui;
}
