/********************************************************************************
** Form generated from reading UI file 'addproducts.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPRODUCTS_H
#define UI_ADDPRODUCTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Addproducts
{
public:
    QTableWidget *allItem;
    QLabel *label;
    QPushButton *add;
    QPushButton *update;
    QPushButton *delete_2;
    QPushButton *discount;
    QPushButton *discount_2;
    QLabel *label_2;
    QTableWidget *cashier;
    QPushButton *pushButton;
    QPushButton *update_cashier;
    QPushButton *delete_cashier;
    QPushButton *logout;

    void setupUi(QDialog *Addproducts)
    {
        if (Addproducts->objectName().isEmpty())
            Addproducts->setObjectName("Addproducts");
        Addproducts->resize(1271, 661);
        Addproducts->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #FFFFFF;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #1E90FF;\n"
"    font-family: Arial, sans-serif;\n"
"    color: #333;\n"
"}\n"
""));
        allItem = new QTableWidget(Addproducts);
        if (allItem->columnCount() < 6)
            allItem->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        allItem->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        allItem->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        allItem->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        allItem->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        allItem->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        allItem->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        allItem->setObjectName("allItem");
        allItem->setGeometry(QRect(60, 70, 751, 450));
        allItem->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #F9FAFB;  /* Light background to contrast with blue */\n"
"    border-radius: 12px;\n"
"    border: 1px solid #E0E5EC;  /* Light gray border for a clean look */\n"
"}\n"
"QTableView QHeaderView::section {\n"
"    background-color: #0066CC;  /* Darker blue for headers */\n"
"    color: white;\n"
"	\n"
"    border-top-left-radius: 8px;\n"
"    border-top-right-radius: 8px;\n"
"    margin:0px 0px;\n"
"    padding: 10px;\n"
"	font-weight:bold;\n"
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
"QScroll"
                        "Bar::sub-line:vertical {\n"
"    height: 0px;\n"
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
        label = new QLabel(Addproducts);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 30, 291, 41));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color:;\n"
"	color: rgb(42, 36, 36);\n"
"    font-size: 26px;\n"
"    font-weight: bold;\n"
"}\n"
""));
        add = new QPushButton(Addproducts);
        add->setObjectName("add");
        add->setGeometry(QRect(530, 540, 151, 41));
        add->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        update = new QPushButton(Addproducts);
        update->setObjectName("update");
        update->setGeometry(QRect(370, 540, 151, 41));
        update->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        delete_2 = new QPushButton(Addproducts);
        delete_2->setObjectName("delete_2");
        delete_2->setGeometry(QRect(690, 540, 121, 41));
        delete_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        discount = new QPushButton(Addproducts);
        discount->setObjectName("discount");
        discount->setGeometry(QRect(210, 540, 151, 41));
        discount->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        discount_2 = new QPushButton(Addproducts);
        discount_2->setObjectName("discount_2");
        discount_2->setGeometry(QRect(60, 540, 141, 41));
        discount_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_2 = new QLabel(Addproducts);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(900, 60, 221, 41));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: ;\n"
"	color: rgb(42, 36, 36);\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"}\n"
""));
        cashier = new QTableWidget(Addproducts);
        if (cashier->columnCount() < 2)
            cashier->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        cashier->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        cashier->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        cashier->setObjectName("cashier");
        cashier->setGeometry(QRect(900, 100, 251, 331));
        cashier->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #F9FAFB;  /* Light background to contrast with blue */\n"
"    border-radius: 12px;\n"
"    border: 1px solid #E0E5EC;  /* Light gray border for a clean look */\n"
"}\n"
"QTableView QHeaderView::section {\n"
"    background-color: #0066CC;  /* Darker blue for headers */\n"
"    color: white;\n"
"	\n"
"    border-top-left-radius: 8px;\n"
"    border-top-right-radius: 8px;\n"
"    margin:0px 0px;\n"
"    padding: 10px;\n"
"	font-weight:bold;\n"
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
"QScroll"
                        "Bar::sub-line:vertical {\n"
"    height: 0px;\n"
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
        pushButton = new QPushButton(Addproducts);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(900, 490, 251, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:rgb(47, 161, 15) ;\n"
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
        update_cashier = new QPushButton(Addproducts);
        update_cashier->setObjectName("update_cashier");
        update_cashier->setGeometry(QRect(900, 440, 121, 41));
        update_cashier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        delete_cashier = new QPushButton(Addproducts);
        delete_cashier->setObjectName("delete_cashier");
        delete_cashier->setGeometry(QRect(1030, 440, 121, 41));
        delete_cashier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        logout = new QPushButton(Addproducts);
        logout->setObjectName("logout");
        logout->setGeometry(QRect(900, 540, 251, 41));
        logout->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(Addproducts);

        QMetaObject::connectSlotsByName(Addproducts);
    } // setupUi

    void retranslateUi(QDialog *Addproducts)
    {
        Addproducts->setWindowTitle(QCoreApplication::translate("Addproducts", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = allItem->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Addproducts", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = allItem->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Addproducts", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = allItem->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Addproducts", "Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = allItem->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Addproducts", "Selliing Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = allItem->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Addproducts", "Purchase price", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = allItem->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Addproducts", "Discount rate", nullptr));
        label->setText(QCoreApplication::translate("Addproducts", "Inventory Products", nullptr));
        add->setText(QCoreApplication::translate("Addproducts", "Add product", nullptr));
        update->setText(QCoreApplication::translate("Addproducts", "Update ", nullptr));
        delete_2->setText(QCoreApplication::translate("Addproducts", "Delete", nullptr));
        discount->setText(QCoreApplication::translate("Addproducts", "Apply Discount", nullptr));
        discount_2->setText(QCoreApplication::translate("Addproducts", "Add Cashiers", nullptr));
        label_2->setText(QCoreApplication::translate("Addproducts", "Cashier Panel", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = cashier->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Addproducts", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = cashier->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Addproducts", "Password", nullptr));
        pushButton->setText(QCoreApplication::translate("Addproducts", "Generate Report", nullptr));
        update_cashier->setText(QCoreApplication::translate("Addproducts", "Update", nullptr));
        delete_cashier->setText(QCoreApplication::translate("Addproducts", "Delete", nullptr));
        logout->setText(QCoreApplication::translate("Addproducts", "Log out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Addproducts: public Ui_Addproducts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPRODUCTS_H
