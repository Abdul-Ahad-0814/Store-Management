#include "cashierwindow.h"
#include "ui_cashierwindow.h"
#include "admin.h"
#include "database.h"
#include "globals.h"
#include "user.h"
#include"utils.h"
#include <QList>
#include <QPushButton>
#include <fstream>
#include <QMessageBox>
#include <QInputDialog>
#include<QDateTime>
#include<QFileDialog>
#include<QFile>
#include<QPrinter>
#include<QPrintDialog>
#include<QTextDocument>
cashierwindow::cashierwindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::cashierwindow)
{
    ui->setupUi(this);
    currentCashier = nullptr;
    loadproducts();

    connect(ui->pushButton, &QPushButton::clicked, this, &cashierwindow::on_pushButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &cashierwindow::on_pushButton_2_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &cashierwindow::on_pushButton_4_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &cashierwindow::on_pushButton_3_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &cashierwindow::on_pushButton_5_clicked);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setAlternatingRowColors(true);

    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_2->setAlternatingRowColors(true);
}

cashierwindow::~cashierwindow()
{
    delete ui;
}


void cashierwindow::updatetotals() {
    double subtotal = 0.0, totalDiscount = 0.0, finalPrice = 0.0;

    for (const auto& item : currentCashier->getcart()) {
        double salePrice = item.get_salePrice();
        int quantity = item.getquantity();  // Use int for quantity to avoid decimal values
        double discountRate = item.get_discountRate();

        // Calculate subtotal for the current item
        double itemSubtotal = salePrice * quantity;
        double itemDiscount = itemSubtotal * (discountRate / 100.0);
        double itemFinalPrice = itemSubtotal - itemDiscount;

        subtotal += itemSubtotal;
        totalDiscount += itemDiscount;
        finalPrice += itemFinalPrice;
    }

    // Update the UI fields with formatted values
    ui->lineEdit->setText(QString::number(subtotal, 'f', 2));        // Subtotal
    ui->lineEdit_2->setText(QString::number(totalDiscount, 'f', 2)); // Total Discount
    ui->lineEdit_3->setText(QString::number(finalPrice, 'f', 2));    // Final Price

}


void cashierwindow::setCashier(user* cashier)
{
    currentCashier = cashier;
    if (cashier != nullptr) {
        ui->label_6->setText("Welcome " + QString::fromStdString(cashier->getusername()));
    }
}

void cashierwindow::loadproducts()
{

    QString product=getAssetPath("products.csv");
   ;
    std::vector<productmain> products = readProductsFromCSV(product.toStdString());
    ui->tableWidget->setRowCount(static_cast<int>(products.size()));
    ui->tableWidget->setColumnCount(5);

    for (size_t i = 0; i < products.size(); i++) {
        const productmain &p = products[i];
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(p.getid())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(p.getname())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(p.get_salePrice())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(p.getquantity())));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(p.get_discountRate())));
    }
}

// void cashierwindow::addtocart(const productmain &product, int quantity)
// {
//     // Load the current products from the backend
//     std::vector<productmain> products = readProductsFromCSV("E:/oop project final/Store-Management-system/products.csv");
//     bool productFoundInCart = false;

//     // Check if the product already exists in the cart
//     for (auto &item : currentCashier->getcart()) {
//         if (item.getid() == product.getid()) {
//             int currentQuantityInCart = item.getquantity();

//             // Check if enough stock is available in the backend
//             for (auto &p : products) {
//                 if (p.getid() == product.getid()) {
//                     int adminQuantity = p.getquantity();
//                     if (adminQuantity < quantity) {
//                         QMessageBox::warning(this, "Error", "Insufficient stock.");
//                         return;
//                     }

//                     // Update the backend product quantity
//                     p.setquantity(adminQuantity - quantity);
//                     // Update the cart item quantity correctly
//                     item.setquantity(currentQuantityInCart + quantity);

//                     break;
//                 }
//             }

//             // Set flag to indicate product is already in cart
//             productFoundInCart = true;

//             // Save the updated products list to CSV
//             writeToCSV("E:/oop project final/Store-Management-system/products.csv", products);

//             qDebug() << "Product already in cart. Quantity updated.";
//             updatecarttable();
//             updatetotals();
//             return;
//         }
//     }

//     // If product is not in cart, add it
//     if (!productFoundInCart) {
//         // Check the quantity in the backend vector (admin inventory)
//         for (auto &p : products) {
//             if (p.getid() == product.getid()) {
//                 int adminQuantity = p.getquantity();
//                 if (adminQuantity < quantity) {
//                     QMessageBox::warning(this, "Error", "Insufficient stock.");
//                     return;
//                 }
//                 // Update the backend quantity
//                 p.setquantity(adminQuantity - quantity);

//                 // Add the product to the cart with the entered quantity
//                 productmain newProduct = product;
//                 newProduct.setquantity(quantity);
//                 currentCashier->addtocart(newProduct);

//                 break;
//             }
//         }

//         // Save the updated products list to CSV
//         writeToCSV("E:/oop project final/Store-Management-system/products.csv", products);

//         qDebug() << "Product added to cart: " << QString::fromStdString(product.getname())
//                  << " Quantity: " << quantity;
//         updatecarttable();
//         updatetotals();
//     }
// }
//corrected
// void cashierwindow::addtocart(const productmain &product, int quantity)
// {
//     // Load the current products from the backend (inventory)


//     QString product1=getAssetPath("products.csv");


//     std::vector<productmain> products = readProductsFromCSV(product1.toStdString());
//     bool productFoundInCart = false;

//     // Check if the product already exists in the cart
//     for (auto &item : currentCashier->getcart()) {
//         if (item.getid() == product.getid()) {
//             int currentQuantityInCart = item.getquantity();

//             // Check if enough stock is available in the backend
//             for (auto &p : products) {
//                 if (p.getid() == product.getid()) {
//                     int adminQuantity = p.getquantity();
//                     if (adminQuantity < quantity) {
//                         QMessageBox::warning(this, "Error", "Insufficient stock.");
//                         return;
//                     }

//                     // Update the backend product quantity
//                     p.setquantity(adminQuantity - quantity);

//                     // Update the cart item quantity
//                     item.setquantity(currentQuantityInCart + quantity);
//                     int q=currentQuantityInCart+quantity;
//                     currentCashier->updateCartItem(item);

//                     // Update the inventory table in real-time
//                     updatecarttable();
//                     updateinventorytable(products);
//                     globaladmin.updateSaleRecord(to_string(p.getid()),q,p.get_salePrice(),globaladmin.getcurrentdate());

//                     break;
//                 }
//             }

//             productFoundInCart = true;

//             // Save the updated products list to CSV


//             QString product2=getAssetPath("cashier_products.csv");
//             writeToCSV(product2.toStdString(),products);



//             qDebug() << "Product already in cart. Quantity updated.";

//             // Real-time update of cart and totals
//             updatecarttable();
//             updatetotals();
//             return;
//         }
//     }

//     // If product is not in cart, add it
//     // If product is not in cart, add it
//     if (!productFoundInCart) {
//         for (auto &p : products) {
//             if (p.getid() == product.getid()) {
//                 int adminQuantity = p.getquantity();
//                 if (adminQuantity < quantity) {
//                     QMessageBox::warning(this, "Error", "Insufficient stock.");
//                     return;
//                 }

//                 // Update the backend quantity
//                 p.setquantity(adminQuantity - quantity);
//                 globaladmin.addSaleRecord(to_string(p.getid()), p.getname(), quantity, p.get_salePrice(), globaladmin.getcurrentdate());

//                 // Add the product to the cart with the entered quantity
//                 productmain newProduct = product;
//                 newProduct.setquantity(quantity);
//                 currentCashier->addtocart(newProduct);

//                 // Log the addition to the cart
//                 qDebug() << "Product added to cart: " << QString::fromStdString(product.getname())
//                          << " Quantity: " << quantity;

//                 // Real-time update of cart and totals

//                 updatecarttable();
//                 updatetotals();

//                 // Check the cart size to confirm addition
//                 qDebug() << "Cart size after addition: " << currentCashier->getcart().size();
//                 qDebug() << "Calling updatecarttable() after adding product.";
//                 updatecarttable();
//                 qDebug() << "Finished updating cart table.";

//                 break;
//             }
//         }

//         QString product3 = getAssetPath("cashier_products.csv");
//         writeToCSV(product3.toStdString(), products);
//     }

// }

void cashierwindow::addtocart(const productmain &product, int quantity)
{
    // Load the current products from the backend (inventory)
    QString product1 = getAssetPath("products.csv");
    std::vector<productmain> products = readProductsFromCSV(product1.toStdString());
    bool productFoundInCart = false;

    // Check if the product already exists in the cart
    for (auto &item : currentCashier->getcart()) {
        if (item.getid() == product.getid()) {
            int currentQuantityInCart = item.getquantity();

            // Check if enough stock is available in the backend
            for (auto &p : products) {
                if (p.getid() == product.getid()) {
                    int adminQuantity = p.getquantity();
                    if (adminQuantity < quantity) {
                        QMessageBox::warning(this, "Error", "Insufficient stock.");
                        return;
                    }

                    // Update the backend product quantity
                    p.setquantity(adminQuantity - quantity);

                    // Update the cart item quantity
                    item.setquantity(currentQuantityInCart + quantity);
                    int q = currentQuantityInCart + quantity;
                    currentCashier->updateCartItem(item);

                    // Update the inventory table in real-time
                                        globaladmin.updateSaleRecord(to_string(p.getid()), q, p.get_salePrice(), globaladmin.getcurrentdate());

                    // Write the updated product list back to CSV
                    QString product2 = getAssetPath("products.csv");
                    writeToCSV(product2.toStdString(), products);
                    updatecarttable();
                    updateinventorytable(products);

                    break;
                }
            }

            productFoundInCart = true;
            qDebug() << "Product already in cart. Quantity updated.";

            // Real-time update of cart and totals
            updatecarttable();
            updatetotals();
            return;
        }
    }

    // If product is not in cart, add it
    if (!productFoundInCart) {
        for (auto &p : products) {
            if (p.getid() == product.getid()) {
                int adminQuantity = p.getquantity();
                if (adminQuantity < quantity) {
                    QMessageBox::warning(this, "Error", "Insufficient stock.");
                    return;
                }

                // Update the backend quantity
                p.setquantity(adminQuantity - quantity);
                globaladmin.addSaleRecord(to_string(p.getid()), p.getname(), quantity, p.get_salePrice(), globaladmin.getcurrentdate());

                // Add the product to the cart with the entered quantity
                productmain newProduct = product;
                newProduct.setquantity(quantity);
                currentCashier->addtocart(newProduct);

                qDebug() << "Product added to cart: " << QString::fromStdString(product.getname())
                         << " Quantity: " << quantity;

                // Real-time update of cart and totals
                updatecarttable();
                updatetotals();
               updateinventorytable(products);
                // Write the updated product list back to CSV
                QString product3 = getAssetPath("products.csv");
                writeToCSV(product3.toStdString(), products);
                updatecarttable();
                updatetotals();

                break;
            }
        }
    }
}


void cashierwindow::updatecarttable()
{
    qDebug() << "Number of items in cart: " << currentCashier->getcart().size();

    ui->tableWidget_2->setRowCount(0);
    for (const auto& product : currentCashier->getcart()) {
        int row = ui->tableWidget_2->rowCount();

        ui->tableWidget_2->insertRow(row);
        ui->tableWidget_2->setItem(row, 0, new QTableWidgetItem(QString::number(product.getid())));
        ui->tableWidget_2->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(product.getname())));
        ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(QString::number(product.get_salePrice())));
        ui->tableWidget_2->setItem(row, 3, new QTableWidgetItem(QString::number(product.getquantity())));
        ui->tableWidget_2->setItem(row, 4, new QTableWidgetItem(QString::number(product.getdr())));

        // Correct calculation of final price
        double discount = (product.get_salePrice() * product.getquantity()) * (product.get_discountRate() / 100.0);
        double finalPrice = (product.get_salePrice() * product.getquantity()) - discount;
        ui->tableWidget_2->setItem(row, 5, new QTableWidgetItem(QString::number(finalPrice, 'f', 2)));
    }
}

void cashierwindow::saveReceiptToFile(const QString &receiptContent)
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Receipt", "receipt.txt", "Text Files (*.txt)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << receiptContent;
        file.close();
        QMessageBox::information(this, "Success", "Receipt saved successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Unable to save the receipt.");
    }
}



QString cashierwindow::generatereceipt()
{
    QString receipt;
    receipt += "**************************************\n";
    receipt += "           Store Management System       \n";
    receipt += "**************************************\n";
    receipt += "Date: " + QDateTime::currentDateTime().toString() + "\n";
    receipt += "Cashier: " + QString::fromStdString(currentCashier->getusername()) + "\n";
    receipt += "--------------------------------------\n";
    receipt += "Item\tQty\tPrice\tTotal\n";
    receipt += "--------------------------------------\n";

    double subtotal = 0;
    for (const auto &product : currentCashier->getcart()) {
        double total = (product.get_salePrice() * product.getquantity()) -
                       ((product.get_salePrice() * product.getquantity()) * (product.get_discountRate() / 100.0));
        receipt += QString::fromStdString(product.getname()) + "\t" +
                   QString::number(product.getquantity()) + "\t" +
                   QString::number(product.get_salePrice()) + "\t" +
                   QString::number(total) + "\n";
        subtotal += total;
    }

    receipt += "--------------------------------------\n";
    receipt += "Subtotal: " + QString::number(subtotal) + "\n";
    receipt += "**************************************\n";
    receipt += "     Thank you for shopping with us!     \n";
    receipt += "**************************************\n";
    return receipt;
}

void cashierwindow::printReceipt(const QString &receiptContent)
{
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec() == QDialog::Accepted) {
        QTextDocument doc;
        doc.setPlainText(receiptContent);
        doc.print(&printer);
        QMessageBox::information(this, "Success", "Receipt printed successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Printing canceled.");
    }
}

void cashierwindow::updateinventorytable(const std::vector<productmain>& products)
{
    ui->tableWidget->setRowCount(0);  // Clear existing data
    for (const auto& product : products) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(product.getid())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(product.getname())));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(product.get_salePrice())));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(product.getquantity())));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(product.getdr())));
    }
}




string cashierwindow::capturebarcode()
{

    QString caffee=getAssetPath("sr.caffemodel");
    QString path=getAssetPath("sr.prototxt");



    cv::barcode::BarcodeDetector barcodeDetector(path.toStdString(),
                                                 caffee.toStdString());
    cv::namedWindow("Barcode Scanner", cv::WINDOW_NORMAL);

    std::vector<cv::Point> corners;
    std::vector<std::string> decoded_info;
    std::vector<std::string> decoded_type;

    cap.open(0);
    if (!cap.isOpened()) {
        QMessageBox::critical(this, "Error", "Cannot open camera!");
        return "";
    }

    cv::Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        // Detect and decode the barcode
        barcodeDetector.detectAndDecodeWithType(frame, decoded_info, decoded_type, corners);

        if (!decoded_info.empty() && !decoded_info[0].empty()) {
            std::string barcodeData = decoded_info[0];

            // Display the detected barcode on the frame
            cv::putText(frame, "Barcode: " + barcodeData, cv::Point(10, 50), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);
            cv::imshow("Barcode Scanner", frame);
            cv::waitKey(500);  // Show the result briefly

            // Properly release resources before returning
            cap.release();
            cv::destroyAllWindows();
            return barcodeData;
        }

        // Display the camera frame while scanning
        cv::imshow("Barcode Scanner", frame);
        if (cv::waitKey(1) == 27) { // Press 'Esc' to exit
            cap.release();
            cv::destroyAllWindows();

        }
    }

    // Properly release resources at the end
    cap.release();
    cv::destroyAllWindows();
    return"";
}


void cashierwindow::on_pushButton_clicked()
{
    // Capture the barcode
    QString barcodeStr = QString::fromStdString(capturebarcode());

    if (barcodeStr.isEmpty()) {
        QMessageBox::warning(this, "Error", "Barcode not detected or invalid.");
        return;
    }

    // Print the captured barcode for debugging
    qDebug() << "Captured Barcode: " << barcodeStr;

    // Search for the product using the captured barcode ID (as QString)
    int row = -1;
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        if (ui->tableWidget->item(i, 0)->text() == barcodeStr) {
            row = i;
            break;
        }
    }

    if (row < 0) {
        QMessageBox::warning(this, "Error", "Product not found for the scanned barcode.");
        return;
    }

    // Prompt for the quantity once here
    bool ok;
    int quantity = QInputDialog::getInt(this, "Enter Quantity", "Quantity:", 1, 1, 100, 1, &ok);
    if (!ok) return;

    // Extract product details from the table
    long long int id = barcodeStr.toLongLong();
    std::string name = ui->tableWidget->item(row, 1)->text().toStdString();
    double salePrice = ui->tableWidget->item(row, 2)->text().toDouble();
    double discountRate = ui->tableWidget->item(row, 4)->text().toDouble();

    productmain product(id, name, quantity, salePrice, discountRate);
    addtocart(product, quantity);  // Pass the quantity directly
    updatecarttable();
    updatetotals();

    QMessageBox::information(this, "Success", "Product added to cart successfully!");
}


void cashierwindow::on_pushButton_3_clicked()
{
    if (currentCashier) {
        currentCashier->clearcart();
        updatecarttable();
        updatetotals();
        QMessageBox::information(this, "Cart Cleared", "The cart has been cleared successfully.");
    } else {
        QMessageBox::warning(this, "Error", "No active cashier session.");
    }
}

// Checkout Button (Save Transaction to CSV)
void cashierwindow::on_pushButton_2_clicked()
{

    QString product=getAssetPath("cashier_products.csv");

    std::ofstream file(product.toStdString(), std::ios::app);  // Corrected file name
    if (!file) {
        QMessageBox::warning(this, "Error", "Unable to open the cashier products file.");
        return;
    }

    for (int i = 0; i < ui->tableWidget_2->rowCount(); ++i) {
        long long int id = ui->tableWidget_2->item(i, 0)->text().toInt();
        std::string name = ui->tableWidget_2->item(i, 1)->text().toStdString();
        int quantity = ui->tableWidget_2->item(i, 3)->text().toInt();  // Corrected quantity column
        double finalPrice = ui->tableWidget_2->item(i, 4)->text().toDouble();  // Final price column

        file << id << "," << name << "," << quantity << "," << finalPrice << "\n";
    }

    file.close();
    QMessageBox::information(this, "Checkout", "Transaction completed and saved to cashier_products.csv.");

    // Clear the cart after successful checkout
    currentCashier->clearcart();
    updatecarttable();
    updatetotals();
}

// Receipt Button (Placeholder)
void cashierwindow::on_pushButton_4_clicked()
{
    QString receiptContent = generatereceipt();

    // Save to file
    saveReceiptToFile(receiptContent);

    // Print the receipt
    printReceipt(receiptContent);
}


void cashierwindow::on_pushButton_5_clicked()
{
    this->close();
}
