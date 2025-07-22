#ifndef CASHIER_H
#define CASHIER_H

#include <QDialog>

namespace Ui {
class cashier;
}

class cashier : public QDialog
{
    Q_OBJECT

public:
    explicit cashier(QWidget *parent = nullptr);
    std::string getusername();
    std::string getpassword();
    void setstring(std::string password);
    ~cashier();


private:
    Ui::cashier *ui;
};

#endif // CASHIER_H
