/********************************************************************************
** Form generated from reading UI file 'products.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTS_H
#define UI_PRODUCTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Products
{
public:
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *Products)
    {
        if (Products->objectName().isEmpty())
            Products->setObjectName("Products");
        Products->resize(1271, 661);
        Products->setStyleSheet(QString::fromUtf8("background-color: rgb(232, 243, 254);"));
        label = new QLabel(Products);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 160, 131, 31));
        label->setStyleSheet(QString::fromUtf8("font-size: 32px;\n"
"font-weight: bold;"));
        tableWidget = new QTableWidget(Products);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(350, 250, 371, 192));
        pushButton = new QPushButton(Products);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(630, 420, 56, 18));

        retranslateUi(Products);

        QMetaObject::connectSlotsByName(Products);
    } // setupUi

    void retranslateUi(QDialog *Products)
    {
        Products->setWindowTitle(QCoreApplication::translate("Products", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Products", "Products", nullptr));
        pushButton->setText(QCoreApplication::translate("Products", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Products: public Ui_Products {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTS_H
