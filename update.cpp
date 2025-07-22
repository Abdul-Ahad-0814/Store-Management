#include "update.h"
#include "ui_update.h"
#include<QMessageBox>

update::update(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::update)
{
    ui->setupUi(this);
}


void update::setproductdata(long long int id, std::string name, int quantity, double sp, double p){
    ui->lineEdit->setText(QString::number(id));
    ui->lineEdit_2->setText(QString::fromStdString(name));
    ui->lineEdit_3->setText(QString::number(quantity));
    ui->lineEdit_4->setText(QString::number(sp));
    ui->lineEdit_5->setText(QString::number(p));
}

long long int update::getID() {
    return ui->lineEdit->text().toLongLong();
}

std::string update::getName() {
    return ui->lineEdit_2->text().toStdString();
}

int update::getquantity() {
    return ui->lineEdit_3->text().toInt();
}

float update::getSalePrice() {
    return ui->lineEdit_4->text().toFloat();
}

float update::getPrice() {
    return ui->lineEdit_5->text().toFloat();
}



update::~update()
{
    delete ui;
}

void update::on_updatebutton_clicked()
{
    if (getID() != 0 && getName() != "" && getquantity() > 0 && getSalePrice() > 0 && getPrice() > 0) {

        accept();
    }
    else {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields correctly!");
    }
}

