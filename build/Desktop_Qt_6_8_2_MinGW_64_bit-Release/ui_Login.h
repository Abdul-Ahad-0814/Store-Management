/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(1271, 661);
        LoginWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #FFFFFF;\n"
"    border: 2px solid #1E90FF;\n"
"}\n"
""));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(160, 130, 942, 363));
        widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #F4F7FC;\n"
"    color: #333;\n"
"}\n"
""));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 80, 301, 71));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #1E90FF;\n"
"    font-size: 64px;\n"
"    font-weight: bold;\n"
"}\n"
""));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 160, 141, 31));
        label_2->setStyleSheet(QString::fromUtf8("color: black;\n"
"font-weight: bold;\n"
"font-size: 38px;\n"
"font-weight: regular;"));
        radioButton = new QRadioButton(widget);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(180, 240, 91, 31));
        radioButton->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font-size: 18px;\n"
"    color: #333;\n"
"	outline:none;\n"
"	border:none;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: rgb(30, 144, 255);\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    background-color: #C5D1E0;\n"
"    border-radius: 8px;\n"
"}\n"
""));
        radioButton_2 = new QRadioButton(widget);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(180, 270, 101, 31));
        radioButton_2->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font-size: 18px;\n"
"    color: #333;\n"
"	outline:none;\n"
"	border:none;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: rgb(30, 144, 255);\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    background-color: #C5D1E0;\n"
"    border-radius: 8px;\n"
"}\n"
""));
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(610, 60, 231, 101));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"}\n"
""));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(510, 150, 371, 30));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #F4F7FC;\n"
"    border: 1px solid #C5D1E0;\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #1E90FF;\n"
"    background-color: #FFFFFF;\n"
"}\n"
""));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(510, 190, 371, 30));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #F4F7FC;\n"
"    border: 1px solid #C5D1E0;\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #1E90FF;\n"
"    background-color: #FFFFFF;\n"
"}\n"
""));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(510, 240, 371, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:rgb(30, 144, 255) ;\n"
"	color: rgb(4, 218, 65);\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    border: none;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(20, 96, 167);;\n"
"	cursor: pointer;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #4169E1;\n"
"}\n"
""));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(510, 290, 371, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white ;\n"
"	color: black;\n"
"    border-radius: 10px;\n"
"    border: 2px solid black;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(38, 38, 38);\n"
"	color: white;\n"
"	cursor:pointer;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #4169E1;\n"
"}\n"
""));
        LoginWindow->setCentralWidget(centralwidget);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "Welcome!", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "You Are", nullptr));
        radioButton->setText(QCoreApplication::translate("LoginWindow", "Admin", nullptr));
        radioButton_2->setText(QCoreApplication::translate("LoginWindow", "Cashier", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWindow", "Login / SignUp", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Email ID", "Email Id"));
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Password", "Password"));
        pushButton->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoginWindow", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
