#include "cashier_product.h"
#include "ui_cashier_product.h"

Cashier_product::Cashier_product(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cashier_product)
{
    ui->setupUi(this);
}

Cashier_product::~Cashier_product()
{
    delete ui;
}
