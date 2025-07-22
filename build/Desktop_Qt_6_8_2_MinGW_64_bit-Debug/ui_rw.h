/********************************************************************************
** Form generated from reading UI file 'rw.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RW_H
#define UI_RW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rw
{
public:
    QWidget *Name;
    QLabel *label;
    QFrame *line;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QFrame *line_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *faceicon;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *rw)
    {
        if (rw->objectName().isEmpty())
            rw->setObjectName("rw");
        rw->resize(1267, 661);
        rw->setStyleSheet(QString::fromUtf8("background-color:rgb(232, 243, 254);"));
        Name = new QWidget(rw);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(140, 70, 961, 551));
        Name->setStyleSheet(QString::fromUtf8("background-color: white;"));
        label = new QLabel(Name);
        label->setObjectName("label");
        label->setGeometry(QRect(420, 50, 161, 51));
        label->setStyleSheet(QString::fromUtf8("font-size: 32px;\n"
"font-weight: bold;\n"
"color:rgb(30, 144, 255)"));
        line = new QFrame(Name);
        line->setObjectName("line");
        line->setGeometry(QRect(270, 110, 421, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        lineEdit_2 = new QLineEdit(Name);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(470, 210, 221, 41));
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
        lineEdit_3 = new QLineEdit(Name);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(470, 270, 221, 41));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_4 = new QLineEdit(Name);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(470, 330, 221, 41));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        line_2 = new QFrame(Name);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(270, 390, 421, 20));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        pushButton = new QPushButton(Name);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(460, 430, 91, 21));
        pushButton->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"color: rgb(25, 107, 222);\n"
"font-size: 18px;\n"
"font-weight: bold;"));
        pushButton_2 = new QPushButton(Name);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(270, 470, 421, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1E90FF;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    border: none;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4682B4;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #4169E1;\n"
"}\n"
""));
        faceicon = new QLabel(Name);
        faceicon->setObjectName("faceicon");
        faceicon->setGeometry(QRect(400, 420, 51, 41));
        lineEdit = new QLineEdit(Name);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(470, 150, 221, 41));
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
        label_2 = new QLabel(Name);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(280, 160, 81, 20));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"	border:none\n"
"}\n"
""));
        label_3 = new QLabel(Name);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(280, 220, 81, 20));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"	border:none\n"
"}\n"
""));
        label_4 = new QLabel(Name);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(280, 280, 111, 20));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"	border:none\n"
"}\n"
""));
        label_5 = new QLabel(Name);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(280, 340, 181, 20));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    font-size: 19px;\n"
"    font-weight: bold;\n"
"	border:none\n"
"}\n"
""));

        retranslateUi(rw);

        QMetaObject::connectSlotsByName(rw);
    } // setupUi

    void retranslateUi(QDialog *rw)
    {
        rw->setWindowTitle(QCoreApplication::translate("rw", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("rw", "Register", nullptr));
        lineEdit_2->setText(QString());
        lineEdit_3->setText(QString());
        lineEdit_4->setText(QString());
        pushButton->setText(QCoreApplication::translate("rw", "Add face", nullptr));
        pushButton_2->setText(QCoreApplication::translate("rw", "Register", nullptr));
        faceicon->setText(QCoreApplication::translate("rw", "TextLabel", nullptr));
        lineEdit->setText(QString());
        label_2->setText(QCoreApplication::translate("rw", "Name:", nullptr));
        label_3->setText(QCoreApplication::translate("rw", "Email:", nullptr));
        label_4->setText(QCoreApplication::translate("rw", "Password:", nullptr));
        label_5->setText(QCoreApplication::translate("rw", "Confrim Password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rw: public Ui_rw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RW_H
