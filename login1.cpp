#include "login1.h"
#include "ui_login1.h"

login1::login1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login1)
{
    ui->setupUi(this);
    movie = new QMovie("E:/oop project final/store-management-system/Assets/Loading_2");
    ui->loadinglabel->setMovie(movie);
    movie->start();
}

login1::~login1()
{
    delete movie;
    delete ui;
}
