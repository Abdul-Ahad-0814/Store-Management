#ifndef LOGIN1_H
#define LOGIN1_H

#include <QDialog>
#include<QMovie>

namespace Ui {
class login1;
}

class login1 : public QDialog
{
    Q_OBJECT

public:
    explicit login1(QWidget *parent = nullptr);
    ~login1();

private:
    Ui::login1 *ui;
    QMovie *movie;
};

#endif // LOGIN1_H
