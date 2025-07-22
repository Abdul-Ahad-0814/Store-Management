#ifndef UPDATE_H
#define UPDATE_H

#include <QDialog>

namespace Ui {
class update;
}

class update : public QDialog
{
    Q_OBJECT

public:
    explicit update(QWidget *parent = nullptr);
    long long int getID();
    std::string getName();
    int  getquantity();
    float getSalePrice();
    float getPrice();
    void setproductdata(long long int id, std::string name, int quantity, double sp, double p);
    ~update();

private slots:
    void on_updatebutton_clicked();

private:
    Ui::update *ui;
};

#endif // UPDATE_H
