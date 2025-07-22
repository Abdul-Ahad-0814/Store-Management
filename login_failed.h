#ifndef LOGIN_FAILED_H
#define LOGIN_FAILED_H

#include <QDialog>

namespace Ui {
class login_failed;
}

class login_failed : public QDialog
{
    Q_OBJECT

public:
    explicit login_failed(QWidget *parent = nullptr);
    ~login_failed();

private:
    Ui::login_failed *ui;
};

#endif // LOGIN_FAILED_H
