/********************************************************************************
** Form generated from reading UI file 'reportwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTWINDOW_H
#define UI_REPORTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reportwindow
{
public:
    QWidget *widget;
    QLabel *label_reporttype;
    QComboBox *comboBox;
    QLabel *label_datefilter;
    QDateEdit *dateEdit_filter;
    QPushButton *btn_generatereport;
    QTextEdit *text_reportoutput;
    QLabel *label;
    QLineEdit *labelsolditem;
    QLabel *label_2;
    QLineEdit *labelsalestotal;
    QLabel *label_3;
    QLineEdit *labelpurchaseditem;
    QLabel *label_4;
    QLineEdit *labelpurchasedcost;
    QLabel *label_5;
    QLineEdit *labelprofit;
    QLabel *label_6;
    QLineEdit *labelcashiers;
    QLabel *label_7;
    QLineEdit *labelinventory;

    void setupUi(QDialog *reportwindow)
    {
        if (reportwindow->objectName().isEmpty())
            reportwindow->setObjectName("reportwindow");
        reportwindow->resize(1267, 661);
        reportwindow->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #FFFFFF;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #1E90FF;\n"
"    font-family: Arial, sans-serif;\n"
"    color: #333;\n"
"}\n"
""));
        widget = new QWidget(reportwindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(410, 80, 471, 511));
        widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #F4F7FC;\n"
"    color: #333;\n"
"	border: 1px solid black \n"
"}\n"
""));
        label_reporttype = new QLabel(widget);
        label_reporttype->setObjectName("label_reporttype");
        label_reporttype->setGeometry(QRect(20, 30, 111, 31));
        label_reporttype->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"	border:none;\n"
"}\n"
""));
        comboBox = new QComboBox(widget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(200, 30, 251, 31));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #F4F7FC;\n"
"    border: 2px solid #C5D1E0;\n"
"    padding: 5px 10px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    background-color: #F4F7FC;\n"
"    border-left: 1px solid #C5D1E0;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #FFFFFF;\n"
"    border: 1px solid #C5D1E0;\n"
"}\n"
""));
        label_datefilter = new QLabel(widget);
        label_datefilter->setObjectName("label_datefilter");
        label_datefilter->setGeometry(QRect(20, 80, 131, 16));
        label_datefilter->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"	border:none;\n"
"}\n"
""));
        dateEdit_filter = new QDateEdit(widget);
        dateEdit_filter->setObjectName("dateEdit_filter");
        dateEdit_filter->setGeometry(QRect(200, 70, 251, 31));
        dateEdit_filter->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    background-color: #F4F7FC;\n"
"    border: 2px solid #C5D1E0;\n"
"    padding: 5px 10px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    border-left: 1px solid #C5D1E0;\n"
"}\n"
"\n"
"QDateEdit::calendar-popup {\n"
"    background-color: #FFFFFF;\n"
"}\n"
""));
        btn_generatereport = new QPushButton(widget);
        btn_generatereport->setObjectName("btn_generatereport");
        btn_generatereport->setGeometry(QRect(20, 120, 431, 41));
        btn_generatereport->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        text_reportoutput = new QTextEdit(widget);
        text_reportoutput->setObjectName("text_reportoutput");
        text_reportoutput->setGeometry(QRect(20, 180, 431, 311));
        text_reportoutput->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"border-radius: 10px;\n"
"background: white;"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 200, 121, 31));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"	border:none;\n"
"	background: transparent;\n"
"}\n"
""));
        labelsolditem = new QLineEdit(widget);
        labelsolditem->setObjectName("labelsolditem");
        labelsolditem->setGeometry(QRect(220, 200, 211, 31));
        labelsolditem->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 240, 91, 31));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"	border:none;\n"
"	background: transparent;\n"
"}\n"
""));
        labelsalestotal = new QLineEdit(widget);
        labelsalestotal->setObjectName("labelsalestotal");
        labelsalestotal->setGeometry(QRect(220, 239, 211, 31));
        labelsalestotal->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 285, 111, 21));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"	border:none;\n"
"	background: transparent;\n"
"}\n"
""));
        labelpurchaseditem = new QLineEdit(widget);
        labelpurchaseditem->setObjectName("labelpurchaseditem");
        labelpurchaseditem->setGeometry(QRect(220, 280, 211, 31));
        labelpurchaseditem->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 325, 171, 21));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"	border:none;\n"
"	background: transparent;\n"
"}\n"
""));
        labelpurchasedcost = new QLineEdit(widget);
        labelpurchasedcost->setObjectName("labelpurchasedcost");
        labelpurchasedcost->setGeometry(QRect(220, 319, 211, 31));
        labelpurchasedcost->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 365, 81, 21));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"	border:none;\n"
"	background: transparent;\n"
"}\n"
""));
        labelprofit = new QLineEdit(widget);
        labelprofit->setObjectName("labelprofit");
        labelprofit->setGeometry(QRect(220, 360, 211, 31));
        labelprofit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 405, 131, 21));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"	border:none;\n"
"	background: transparent;\n"
"}\n"
""));
        labelcashiers = new QLineEdit(widget);
        labelcashiers->setObjectName("labelcashiers");
        labelcashiers->setGeometry(QRect(220, 400, 211, 31));
        labelcashiers->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 445, 161, 21));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"	border:none;\n"
"	background: transparent;\n"
"}\n"
""));
        labelinventory = new QLineEdit(widget);
        labelinventory->setObjectName("labelinventory");
        labelinventory->setGeometry(QRect(220, 440, 211, 31));
        labelinventory->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        retranslateUi(reportwindow);

        QMetaObject::connectSlotsByName(reportwindow);
    } // setupUi

    void retranslateUi(QDialog *reportwindow)
    {
        reportwindow->setWindowTitle(QCoreApplication::translate("reportwindow", "Dialog", nullptr));
        label_reporttype->setText(QCoreApplication::translate("reportwindow", "Report Type: ", nullptr));
        label_datefilter->setText(QCoreApplication::translate("reportwindow", "Date Filter Label: ", nullptr));
        btn_generatereport->setText(QCoreApplication::translate("reportwindow", "Generate", nullptr));
        label->setText(QCoreApplication::translate("reportwindow", "Total Sold Item: ", nullptr));
        label_2->setText(QCoreApplication::translate("reportwindow", "Total Sales: ", nullptr));
        label_3->setText(QCoreApplication::translate("reportwindow", "Total Purchase Item: ", nullptr));
        label_4->setText(QCoreApplication::translate("reportwindow", "Total Purchase Cost: ", nullptr));
        label_5->setText(QCoreApplication::translate("reportwindow", "Profit: ", nullptr));
        label_6->setText(QCoreApplication::translate("reportwindow", "Total Cashiers: ", nullptr));
        label_7->setText(QCoreApplication::translate("reportwindow", "Inventory Capacity:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reportwindow: public Ui_reportwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTWINDOW_H
