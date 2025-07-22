/********************************************************************************
** Form generated from reading UI file 'cashier.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASHIER_H
#define UI_CASHIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cashier
{
public:
    QWidget *widget;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;

    void setupUi(QDialog *cashier)
    {
        if (cashier->objectName().isEmpty())
            cashier->setObjectName("cashier");
        cashier->resize(1267, 661);
        cashier->setStyleSheet(QString::fromUtf8("background-color:rgb(232, 243, 254);"));
        widget = new QWidget(cashier);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(150, 130, 311, 221));
        widget->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 40, 71, 16));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(110, 40, 113, 20));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 90, 71, 16));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(110, 90, 113, 20));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 150, 56, 18));

        retranslateUi(cashier);

        QMetaObject::connectSlotsByName(cashier);
    } // setupUi

    void retranslateUi(QDialog *cashier)
    {
        cashier->setWindowTitle(QCoreApplication::translate("cashier", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("cashier", "Enter Username: ", nullptr));
        label_2->setText(QCoreApplication::translate("cashier", "Enter Password: ", nullptr));
        pushButton->setText(QCoreApplication::translate("cashier", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cashier: public Ui_cashier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASHIER_H
