#ifndef ADDPRODUCTS_H
#define ADDPRODUCTS_H

#include <QDialog>
#include<productmain.h>
#include<admin.h>
namespace Ui {
class Addproducts;
}

class Addproducts : public QDialog
{
    Q_OBJECT

public:
    explicit Addproducts(QWidget *parent = nullptr);
    ~Addproducts();
    void editproduct();

    void refreshtable();
private slots:
void openReportWindow();
    void on_add_clicked();

    void on_delete_2_clicked();

    void on_update_clicked();

    void on_discount_clicked();

    void on_discount_2_clicked();

    void on_pushButton_clicked();

    void on_update_cashier_clicked();
    void on_delete_cashier_clicked();

    void on_logout_clicked();

private:
    Ui::Addproducts *ui;
    Addproducts *add;
    std::vector<productmain>* allItem;
    std::vector<user>* allcashier;
};

#endif // ADDPRODUCTS_H
