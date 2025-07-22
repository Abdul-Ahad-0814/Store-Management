#include "cashier.h"
#include "ui_cashier.h"

cashier::cashier(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::cashier)
{
    ui->setupUi(this);
}


std::string cashier::getusername(){
    return ui->lineEdit->text().toStdString();
}

std::string cashier::getpassword(){
    return ui->lineEdit_2->text().toStdString();
}

void cashier::setstring(std::string password){
}

cashier::~cashier()
{
    delete ui;
}
