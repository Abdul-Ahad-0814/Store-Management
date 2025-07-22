/********************************************************************************
** Form generated from reading UI file 'login1.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN1_H
#define UI_LOGIN1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login1
{
public:
    QWidget *widget;
    QLabel *label;
    QLabel *loadinglabel;

    void setupUi(QDialog *login1)
    {
        if (login1->objectName().isEmpty())
            login1->setObjectName("login1");
        login1->resize(1271, 661);
        login1->setStyleSheet(QString::fromUtf8("background-color: rgb(232, 243, 254)"));
        widget = new QWidget(login1);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(165, 153, 942, 363));
        widget->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 240, 611, 51));
        label->setStyleSheet(QString::fromUtf8("font-size: 40px;"));
        loadinglabel = new QLabel(widget);
        loadinglabel->setObjectName("loadinglabel");
        loadinglabel->setGeometry(QRect(330, 60, 281, 161));

        retranslateUi(login1);

        QMetaObject::connectSlotsByName(login1);
    } // setupUi

    void retranslateUi(QDialog *login1)
    {
        login1->setWindowTitle(QCoreApplication::translate("login1", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("login1", "Wait your face is being recognized", nullptr));
        loadinglabel->setText(QCoreApplication::translate("login1", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login1: public Ui_login1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN1_H
