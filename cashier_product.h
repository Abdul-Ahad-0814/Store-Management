#ifndef CASHIER_PRODUCT_H
#define CASHIER_PRODUCT_H

#include <QWidget>

namespace Ui {
class Cashier_product;
}

class Cashier_product : public QWidget
{
    Q_OBJECT

public:
    explicit Cashier_product(QWidget *parent = nullptr);
    ~Cashier_product();

private:
    Ui::Cashier_product *ui;
};

#endif // CASHIER_PRODUCT_H
