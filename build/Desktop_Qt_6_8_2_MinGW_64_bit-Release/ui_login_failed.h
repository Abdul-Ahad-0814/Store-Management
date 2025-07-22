/********************************************************************************
** Form generated from reading UI file 'login_failed.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_FAILED_H
#define UI_LOGIN_FAILED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login_failed
{
public:
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;
    QLabel *failed;

    void setupUi(QDialog *login_failed)
    {
        if (login_failed->objectName().isEmpty())
            login_failed->setObjectName("login_failed");
        login_failed->resize(1267, 661);
        login_failed->setStyleSheet(QString::fromUtf8("background-color:rgb(232, 243, 254)"));
        widget = new QWidget(login_failed);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(165, 153, 942, 363));
        widget->setStyleSheet(QString::fromUtf8("background-color: white;"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(280, 130, 241, 61));
        label->setStyleSheet(QString::fromUtf8("font-size: 40px;"));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 190, 321, 61));
        label_2->setStyleSheet(QString::fromUtf8("font-size: 40px;\n"
""));
        failed = new QLabel(widget);
        failed->setObjectName("failed");
        failed->setGeometry(QRect(370, 100, 37, 12));

        retranslateUi(login_failed);

        QMetaObject::connectSlotsByName(login_failed);
    } // setupUi

    void retranslateUi(QDialog *login_failed)
    {
        login_failed->setWindowTitle(QCoreApplication::translate("login_failed", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("login_failed", "Login Failed", nullptr));
        label_2->setText(QCoreApplication::translate("login_failed", "Please Try Again!", nullptr));
        failed->setText(QCoreApplication::translate("login_failed", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login_failed: public Ui_login_failed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_FAILED_H
