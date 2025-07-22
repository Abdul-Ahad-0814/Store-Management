/********************************************************************************
** Form generated from reading UI file 'login_success.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_SUCCESS_H
#define UI_LOGIN_SUCCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login_success
{
public:
    QWidget *widget;
    QLabel *label;
    QLabel *success;

    void setupUi(QDialog *login_success)
    {
        if (login_success->objectName().isEmpty())
            login_success->setObjectName("login_success");
        login_success->resize(1271, 661);
        login_success->setStyleSheet(QString::fromUtf8("background-color: rgb(232, 243, 254)"));
        widget = new QWidget(login_success);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(165, 153, 942, 363));
        widget->setStyleSheet(QString::fromUtf8("background-color: white;"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(260, 180, 151, 61));
        label->setStyleSheet(QString::fromUtf8("font-size: 40px"));
        success = new QLabel(widget);
        success->setObjectName("success");
        success->setGeometry(QRect(230, 70, 221, 111));

        retranslateUi(login_success);

        QMetaObject::connectSlotsByName(login_success);
    } // setupUi

    void retranslateUi(QDialog *login_success)
    {
        login_success->setWindowTitle(QCoreApplication::translate("login_success", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("login_success", "Success", nullptr));
        success->setText(QCoreApplication::translate("login_success", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login_success: public Ui_login_success {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_SUCCESS_H
