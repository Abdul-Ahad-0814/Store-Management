/********************************************************************************
** Form generated from reading UI file 'cashierwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASHIERWINDOW_H
#define UI_CASHIERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_cashierwindow
{
public:
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QLabel *label_6;

    void setupUi(QDialog *cashierwindow)
    {
        if (cashierwindow->objectName().isEmpty())
            cashierwindow->setObjectName("cashierwindow");
        cashierwindow->resize(1267, 661);
        cashierwindow->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #FFFFFF;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #1E90FF;\n"
"    font-family: Arial, sans-serif;\n"
"    color: #333;\n"
"}\n"
""));
        tableWidget = new QTableWidget(cashierwindow);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(40, 60, 751, 251));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #F9FAFB;  /* Light background to contrast with blue */\n"
"    border-radius: 12px;\n"
"    border: 1px solid #E0E5EC;  /* Light gray border for a clean look */\n"
"}\n"
"\n"
"QTableView QHeaderView::section {\n"
"    background-color: #0066CC;  /* Darker blue for headers */\n"
"    color: white;\n"
"    border-top-left-radius: 8px;\n"
"    border-top-right-radius: 8px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QTableView QHeaderView::section:checked {\n"
"    background-color: #3399FF;  /* Lighter blue when selected */\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background-color: #F0F4F7;  /* Very light gray for the scrollbar track */\n"
"    width: 12px;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background-color: #0066CC;  /* Same blue as the header */\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
""
                        "}\n"
"\n"
"QTableWidget::item {\n"
"    background-color: #FFFFFF;  /* White background for items */\n"
"    color: #333333;  /* Dark gray text for readability */\n"
"    padding: 10px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: #E8F2FF;  /* Light blue on hover */\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #0066CC;  /* Dark blue for selected items */\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QTableWidget::item:selected:focus {\n"
"    outline: none;\n"
"}\n"
"\n"
"QTableWidget::item:selected:active {\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QTableWidget::item:selected:first {\n"
"    border-top-left-radius: 10px;\n"
"}\n"
"\n"
"QTableWidget::item:selected:last {\n"
"    border-top-right-radius: 10px;\n"
"}\n"
""));
        tableWidget_2 = new QTableWidget(cashierwindow);
        if (tableWidget_2->columnCount() < 6)
            tableWidget_2->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(40, 380, 751, 251));
        tableWidget_2->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #F9FAFB;  /* Light background to contrast with blue */\n"
"    border-radius: 12px;\n"
"    border: 1px solid #E0E5EC;  /* Light gray border for a clean look */\n"
"}\n"
"\n"
"QTableView QHeaderView::section {\n"
"    background-color: #0066CC;  /* Darker blue for headers */\n"
"    color: white;\n"
"    border-top-left-radius: 8px;\n"
"    border-top-right-radius: 8px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QTableView QHeaderView::section:checked {\n"
"    background-color: #3399FF;  /* Lighter blue when selected */\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background-color: #F0F4F7;  /* Very light gray for the scrollbar track */\n"
"    width: 12px;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background-color: #0066CC;  /* Same blue as the header */\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
""
                        "}\n"
"\n"
"QTableWidget::item {\n"
"    background-color: #FFFFFF;  /* White background for items */\n"
"    color: #333333;  /* Dark gray text for readability */\n"
"    padding: 10px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: #E8F2FF;  /* Light blue on hover */\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #0066CC;  /* Dark blue for selected items */\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QTableWidget::item:selected:focus {\n"
"    outline: none;\n"
"}\n"
"\n"
"QTableWidget::item:selected:active {\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QTableWidget::item:selected:first {\n"
"    border-top-left-radius: 10px;\n"
"}\n"
"\n"
"QTableWidget::item:selected:last {\n"
"    border-top-right-radius: 10px;\n"
"}\n"
""));
        label = new QLabel(cashierwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 20, 211, 41));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color:;\n"
"	color: rgb(42, 36, 36);\n"
"    font-size: 26px;\n"
"    font-weight: bold;\n"
"}\n"
""));
        label_2 = new QLabel(cashierwindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 340, 211, 41));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color:;\n"
"	color: rgb(42, 36, 36);\n"
"    font-size: 26px;\n"
"    font-weight: bold;\n"
"}\n"
""));
        label_3 = new QLabel(cashierwindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(820, 390, 91, 21));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: ;\n"
"	color: rgb(38, 38, 38);\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"}\n"
""));
        lineEdit = new QLineEdit(cashierwindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(1000, 380, 211, 41));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #C5D1E0;\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #1E90FF;\n"
"    background-color: #FFFFFF;\n"
"}\n"
""));
        label_4 = new QLabel(cashierwindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(818, 440, 141, 21));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: ;\n"
"	color: rgb(38, 38, 38);\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"}\n"
""));
        lineEdit_2 = new QLineEdit(cashierwindow);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(1000, 430, 211, 41));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #C5D1E0;\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #1E90FF;\n"
"    background-color: #FFFFFF;\n"
"}\n"
""));
        label_5 = new QLabel(cashierwindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(820, 490, 131, 21));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: ;\n"
"	color: rgb(38, 38, 38);\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"}\n"
""));
        lineEdit_3 = new QLineEdit(cashierwindow);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(1000, 480, 211, 41));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #C5D1E0;\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #1E90FF;\n"
"    background-color: #FFFFFF;\n"
"}\n"
""));
        pushButton_2 = new QPushButton(cashierwindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(830, 250, 381, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:rgb(47, 161, 15) ;\n"
"	color: rgb(4, 218, 65);\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    border: none;\n"
"    padding: 8px 16px;\n"
"    font-size: 18px;\n"
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
        pushButton_3 = new QPushButton(cashierwindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(830, 190, 381, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1E90FF;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    border: none;\n"
"    padding: 8px 16px;\n"
"    font-size: 18px;\n"
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
        pushButton_4 = new QPushButton(cashierwindow);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(820, 540, 391, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:rgb(30, 144, 255) ;\n"
"	color: rgb(4, 218, 65);\n"
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
        pushButton_5 = new QPushButton(cashierwindow);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(820, 590, 391, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(195, 25, 25);\n"
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
        pushButton = new QPushButton(cashierwindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(830, 130, 381, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1E90FF;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    border: none;\n"
"    padding: 8px 16px;\n"
"    font-size: 18px;\n"
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
        label_6 = new QLabel(cashierwindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(840, 60, 371, 41));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color:;\n"
"	color: rgb(42, 36, 36);\n"
"    font-size: 26px;\n"
"    font-weight: bold;\n"
"}\n"
""));
        label->raise();
        label_2->raise();
        label_3->raise();
        lineEdit->raise();
        label_4->raise();
        lineEdit_2->raise();
        label_5->raise();
        lineEdit_3->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton->raise();
        tableWidget->raise();
        tableWidget_2->raise();
        label_6->raise();

        retranslateUi(cashierwindow);

        QMetaObject::connectSlotsByName(cashierwindow);
    } // setupUi

    void retranslateUi(QDialog *cashierwindow)
    {
        cashierwindow->setWindowTitle(QCoreApplication::translate("cashierwindow", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("cashierwindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("cashierwindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("cashierwindow", "Sale price", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("cashierwindow", "Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("cashierwindow", "Discount rate", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("cashierwindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("cashierwindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("cashierwindow", "Sale price", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("cashierwindow", "Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("cashierwindow", "discount", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("cashierwindow", "final price", nullptr));
        label->setText(QCoreApplication::translate("cashierwindow", "Product Table", nullptr));
        label_2->setText(QCoreApplication::translate("cashierwindow", "Cart Table", nullptr));
        label_3->setText(QCoreApplication::translate("cashierwindow", "Sub Total", nullptr));
        label_4->setText(QCoreApplication::translate("cashierwindow", "Total Discount ", nullptr));
        label_5->setText(QCoreApplication::translate("cashierwindow", "Final Amount", nullptr));
        pushButton_2->setText(QCoreApplication::translate("cashierwindow", "Checkout", nullptr));
        pushButton_3->setText(QCoreApplication::translate("cashierwindow", "Clear Cart", nullptr));
        pushButton_4->setText(QCoreApplication::translate("cashierwindow", "Print receipt", nullptr));
        pushButton_5->setText(QCoreApplication::translate("cashierwindow", "Log out", nullptr));
        pushButton->setText(QCoreApplication::translate("cashierwindow", "Add To Cart", nullptr));
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cashierwindow: public Ui_cashierwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASHIERWINDOW_H
