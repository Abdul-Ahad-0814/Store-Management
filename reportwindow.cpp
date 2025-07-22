#include "reportwindow.h"
#include"report.h"
#include "ui_reportwindow.h"
#include<string>
#include"globals.h"
reportwindow::reportwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::reportwindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Daily");
    ui->comboBox->addItem("Monthly");
    ui->comboBox->addItem("Yearly");

}

reportwindow::~reportwindow()
{
    delete ui;
}

void reportwindow::on_btn_generatereport_clicked()
{
    std::string type = ui->comboBox->currentText().toStdString(); // Daily / Monthly / Yearly
    std::string date = ui->dateEdit_filter->date().toString("yyyy-MM-dd").toStdString();

    Report report;
    ReportData data = report.generate_report(globaladmin, type, date);

    ui->labelsolditem->setText(QString::number(data.totalItemsSold));
    ui->labelsalestotal->setText(QString::number(data.totalSales));
    ui->labelpurchaseditem->setText(QString::number(data.totalItemsPurchased));
    ui->labelpurchasedcost->setText(QString::number(data.totalPurchaseCost));
    ui->labelprofit->setText(QString::number(data.profit));
    ui->labelcashiers->setText(QString::number(data.totalCashiers));
    ui->labelinventory->setText(QString::number(data.inventorySize));
}


