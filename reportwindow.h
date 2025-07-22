#ifndef REPORTWINDOW_H
#define REPORTWINDOW_H

#include <QDialog>

namespace Ui {
class reportwindow;
}

class reportwindow : public QDialog
{
    Q_OBJECT

public:
    explicit reportwindow(QWidget *parent = nullptr);
    ~reportwindow();

private slots:
    void on_btn_generatereport_clicked();

private:
    Ui::reportwindow *ui;
};

#endif // REPORTWINDOW_H
