#include "addproducts.h"
#include "ui_addproducts.h"
#include "products1.h"
#include"person.h"
#include"update.h"
#include <QMessageBox>
#include<QPushButton>
#include<QCheckBox>
#include<QInputDialog>
#include"globals.h"
#include"reportwindow.h"
#include"database.h"
#include"utils.h"

Addproducts::Addproducts(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Addproducts)

{
    ui->setupUi(this);
    allItem=&(globaladmin.display());
    allcashier=&(globaladmin.getCashiers());

    QString product=getAssetPath("products.csv");
    auto loadedproducts= readProductsFromCSV(product.toStdString());
    ui->allItem->setRowCount(0);
    for (auto& p : loadedproducts) {
        long long int id=p.getid();

        string name= p.getname();
        int quantity= p.getquantity();
        double price=p.getprice();
        double sp=p.get_salePrice();
        double dr=p.getdr();
        globaladmin.addproduct(id,quantity,name,sp,price,dr);  // or directly assign to product vector
        // Add to UI table
        int row = ui->allItem->rowCount();
        ui->allItem->insertRow(row);
        ui->allItem->setItem(row, 0, new QTableWidgetItem(QString::number(p.getid())));
        ui->allItem->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(p.getname())));
        ui->allItem->setItem(row, 2, new QTableWidgetItem(QString::number(p.getquantity())));
        ui->allItem->setItem(row, 3, new QTableWidgetItem(QString::number(p.get_salePrice())));
        ui->allItem->setItem(row, 4, new QTableWidgetItem(QString::number(p.getprice())));
        ui->allItem->setItem(row, 5, new QTableWidgetItem(QString::number(p.getdr())));
    }

    // Load cashiers
    QString cashier=getAssetPath("cashiers.csv");
    auto loadedCashiers = readCashiersFromCSV(cashier.toStdString());
    ui->cashier->setRowCount(0);
    for (auto& c : loadedCashiers) {
        globaladmin.addcashier(c.getusername(), c.getpassword());
        int row = ui->cashier->rowCount();
        ui->cashier->insertRow(row);
        ui->cashier->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(c.getusername())));
        ui->cashier->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(c.getpassword())));
    }

    connect(ui->pushButton, &QPushButton::clicked, this, &Addproducts::openReportWindow);


    // Initialize newadmin (pass it via constructor)

    // Populate the table with existing items

    // Table settings
    ui->allItem->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->allItem->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->allItem->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->allItem->horizontalHeader()->setVisible(true);
    ui->allItem->verticalHeader()->setVisible(false);
    ui->allItem->horizontalHeader()->setStretchLastSection(true);
    ui->allItem->setAlternatingRowColors(true);

    ui->cashier->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->cashier->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->cashier->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->cashier->horizontalHeader()->setVisible(true);
    ui->cashier->verticalHeader()->setVisible(false);
    ui->cashier->horizontalHeader()->setStretchLastSection(true);
    ui->cashier->setAlternatingRowColors(true);

}


Addproducts::~Addproducts()
{
    delete ui;
}

void Addproducts::on_add_clicked()
{
    // Create the add product form (products1 UI) and show it
    products1 form1(this);
    productmain product1;

    // Show the form and get product details (you can pass data via getter methods in products1)
    if (form1.exec() == QDialog::Accepted) {
        long long int ID = form1.getID();
        std::string name = form1.getName();
        int quantity = form1.getquantity();
        float salePrice = form1.getSalePrice();
        float price = form1.getPrice();
        double dr=1;
        product1.setid(ID);
        product1.setname(name);
        product1.setquantity(quantity);
        product1.setsaleprice(salePrice);
        product1.setprice(price);
        product1.setdr(dr);

        // Validate product details before adding
        if (ID != -1 && salePrice != 0 && price != 0 && quantity > 0 && !name.empty()) {
            // Add product using newadmin
            globaladmin.addproduct(ID, quantity, name, salePrice, price,dr);


            // Update table view to reflect new product
            int row = ui->allItem->rowCount();
            ui->allItem->insertRow(row);
            ui->allItem->setItem(row, 0, new QTableWidgetItem(QString::number(ID)));
            ui->allItem->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(name)));
            ui->allItem->setItem(row, 2, new QTableWidgetItem(QString::number(quantity)));
            ui->allItem->setItem(row, 3, new QTableWidgetItem(QString::number(salePrice)));
            ui->allItem->setItem(row, 4, new QTableWidgetItem(QString::number(price)));
            ui->allItem->setItem(row, 5, new QTableWidgetItem(QString::number(dr)));
            QString product=getAssetPath("products.csv");

            writeToCSV(product.toStdString(),*allItem);
            // Show success message
            QMessageBox::information(this, "Success", "Item has been added.");
        } else {
            // Show error message if validation fails
            QMessageBox::warning(this, "Error", "Item not added. Please check the input.");
        }
    }
}


// void Addproducts::deleteproduct(int row) {
//     int confirm = QMessageBox::question(this, "Confirm Delete",
//      "Are you sure you want to delete this product?",
//      QMessageBox::Yes | QMessageBox::No);

//     if (confirm == QMessageBox::Yes) {
//         int row = ui->allItem->currentRow();
//         newadmin.deleteproduct(row); // Make sure your admin class handles this
//         refreshtable();
//         QMessageBox::information(this, "Deleted", "Item has been deleted.");
//     }
// }

void Addproducts::editproduct(){
    class update updates(this);
    if (updates.exec() == QDialog::Accepted){
    long long int id=updates.getID();
     string name=updates.getName();
    int quantity=updates.getquantity();
     int saleprice=updates.getSalePrice();
    int price=updates.getPrice();
        globaladmin.updateProduct(id,price,saleprice,quantity,name);
         refreshtable();
         QMessageBox::information(this, "Updated", "Item has been Updated");
         QString product=getAssetPath("products.csv");
         writeToCSV(product.toStdString(),*allItem);
    }
}

void Addproducts::refreshtable(){
    std::vector<productmain> cart = globaladmin.displaycart();

    ui->allItem->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->allItem->setSelectionMode(QAbstractItemView::SingleSelection );
    ui->allItem->setSelectionBehavior(QAbstractItemView::SelectRows );

    ui->allItem->setRowCount(cart.size());
    for (size_t i = 0; i < cart.size(); i++)
    {
        QTableWidgetItem* item = new QTableWidgetItem(QString::number(cart[i].getid()));
        ui->allItem->setItem(i, 0, item);
        item = new QTableWidgetItem(QString::fromStdString(cart[i].getname()));
        ui->allItem->setItem(i, 1, item);
        item = new QTableWidgetItem(QString::number(cart[i].getquantity()));
        ui->allItem->setItem(i, 2, item);
        item = new QTableWidgetItem(QString::number(cart[i].getsellingprice()));
        ui->allItem->setItem(i, 3, item);
        item = new QTableWidgetItem(QString::number(cart[i].getprice()));
        ui->allItem->setItem(i, 4, item);
        item = new QTableWidgetItem(QString::number(cart[i].getdr()));
        ui->allItem->setItem(i, 5, item);
    }

}



void Addproducts::on_delete_2_clicked()
{
    int confirm = QMessageBox::question(this, "Confirm Delete",
                                        "Are you sure you want to delete this product?",
                                        QMessageBox::Yes | QMessageBox::No);

    if (confirm == QMessageBox::Yes) {
        int row = ui->allItem->currentRow();
        globaladmin.deleteproduct(row); // Make sure your admin class handles this

        QString product=getAssetPath("products.csv");
        writeToCSV(product.toStdString(),*allItem);
        refreshtable();
        QMessageBox::information(this, "Deleted", "Item has been deleted.");

    }
}


void Addproducts::on_update_clicked()
{
    int row = ui->allItem->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a product to update.");
        return;
    }

    // Get data from table row
    long long int id = ui->allItem->item(row, 0)->text().toLongLong();
    std::string name = ui->allItem->item(row, 1)->text().toStdString();
    int quantity = ui->allItem->item(row, 2)->text().toInt();
    float saleprice = ui->allItem->item(row, 3)->text().toFloat();
    float price = ui->allItem->item(row, 4)->text().toFloat();

    // Pass to update dialog
   class update updates(this);
    updates.setproductdata(id, name, quantity, saleprice, price); // 👈 You need to implement this in update class

    if (updates.exec() == QDialog::Accepted){
        long long int new_id = updates.getID();
        string new_name = updates.getName();
        int new_quantity = updates.getquantity();
        int new_saleprice = updates.getSalePrice();
        int new_price = updates.getPrice();

        globaladmin.updateProduct(new_id, new_price, new_saleprice, new_quantity, new_name);
        refreshtable();

        QString product=getAssetPath("products.csv");
        writeToCSV(product.toStdString(),*allItem);
        QMessageBox::information(this, "Updated", "Item has been updated.");
    }
}

void Addproducts::on_discount_clicked()
{
    bool ok;
    double discountRate = QInputDialog::getDouble(this, "Apply Discount",
             "Enter discount rate (%):", 0, 0, 100, 2, &ok);
    if(ok){


    int row = ui->allItem->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a product to apply discount.");
        return;
    }
    ui->allItem->setItem(row,5,new QTableWidgetItem(QString::number(discountRate)));
    QString productIdStr = ui->allItem->item(row, 0)->text(); // assuming column 0 is Product ID

    long long int productId = productIdStr.toLongLong(); // convert to int if needed
    globaladmin.updatediscount(productId,discountRate);
    qDebug("Discount Applied");
    refreshtable();
    QString product=getAssetPath("products.csv");
    writeToCSV(product.toStdString(),*allItem);
    }
}


void Addproducts::on_discount_2_clicked()
{
    person p1;
    QString name = QInputDialog::getText(this, "Enter Cashier Name", "Cashier Name:");
    if (name.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Cashier name cannot be empty.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Password",
                                  "Do you want to auto-generate a password?",
                                  QMessageBox::Yes | QMessageBox::No);

    QString password;
    if (reply == QMessageBox::Yes) {
        password = QString::fromStdString(p1.generate_password());
    } else {
        password = QInputDialog::getText(this, "Enter Password", "Password:", QLineEdit::Password);
        if (password.isEmpty()) {
            QMessageBox::warning(this, "Input Error", "Password cannot be empty.");
            return;
        }
    }

    // Add cashier to global admin
    globaladmin.addcashier(name.toStdString(), password.toStdString());

    // Create a new user object
    user temp1(name.toStdString(), password.toStdString());

    // Append the new cashier directly to the CSV file
    QString product = getAssetPath("cashiers.csv");
    writecashiersToCSV(product.toStdString(), temp1);

    // Display success message
    QMessageBox::information(this, "Success", "Cashier added:\nName: " + name + "\nPassword: " + password);

    // Update the Cashier Panel directly
    int row = ui->cashier->rowCount();
    ui->cashier->insertRow(row);
    ui->cashier->setItem(row, 0, new QTableWidgetItem(name));
    ui->cashier->setItem(row, 1, new QTableWidgetItem(password));
}







void Addproducts::openReportWindow()
{
    reportwindow *reportWin = new reportwindow(this);
    // reportWin->setModal(true);  // optional: makes it modal
    reportWin->show();
}

void Addproducts::on_pushButton_clicked() {
    openReportWindow();
}

void Addproducts::on_update_cashier_clicked() {
    int row = ui->cashier->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a cashier to update.");
        return;
    }

    QString username = ui->cashier->item(row, 0)->text();
    QString password = ui->cashier->item(row, 1)->text();

    // Ask for new details
    // QString newName = QInputDialog::getText(this, "Update Cashier", "Enter new Cashier Name:", QLineEdit::Normal, username);
    // if (newName.isEmpty()) {
    //     QMessageBox::warning(this, "Input Error", "Name cannot be empty.");
    //     return;
    // }

    QString newPassword = QInputDialog::getText(this, "Update Cashier", "Enter new Password:", QLineEdit::Password, password);
    if (newPassword.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Password cannot be empty.");
        return;
    }

    // Update cashier data
    globaladmin.updatecashier(username.toStdString(), newPassword.toStdString());

    // Update the UI table
    ui->cashier->item(row, 1)->setText(newPassword);

    std::vector<user> cashiers = globaladmin.getCashiers();
    QString product=getAssetPath("cashiers.csv");

    updateCashierPassword(product.toStdString(), username.toStdString(), newPassword.toStdString());

    QMessageBox::information(this, "Success", "Cashier updated.");
}

void Addproducts::on_delete_cashier_clicked() {
    int row = ui->cashier->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a cashier to delete.");
        return;
    }

    QString username = ui->cashier->item(row, 0)->text();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Delete",
                                  "Are you sure you want to delete this cashier?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        globaladmin.deletecashier(username.toStdString());

        // Update the UI table
        ui->cashier->removeRow(row);

        std::vector<user> cashiers = globaladmin.getCashiers();

        QString product=getAssetPath("cashiers.csv");
        deleteCashierFromCSV(product.toStdString(),username.toStdString());



        QMessageBox::information(this, "Deleted", "Cashier deleted.");
    }
}

void Addproducts::on_logout_clicked()
{
    this->close();
}

