#include "report.h"
#include <iomanip>
#include "admin.h"
#include"utils.h"
#include "database.h"
#include <fstream>
#include <sstream>

// Constructor
Report::Report() {}

// matchesDate function definition
bool Report::matchesDate(const std::string& recordDate, const std::string& filter, const std::string& type) {
    // recordDate and filter format: "YYYY-MM-DD"
    if (type == "Daily") {
        return recordDate == filter;
    } else if (type == "Monthly") {
        // Compare "YYYY-MM"
        return recordDate.substr(0, 7) == filter.substr(0, 7);
    } else if (type == "Yearly") {
        // Compare "YYYY"
        return recordDate.substr(0, 4) == filter.substr(0, 4);
    }
    return false;
}

// generate_report function definition
ReportData Report::generate_report(admin& a, const std::string& type, const std::string& dateFilter) {
    // Initialize data with zeros
    ReportData data = {0, 0, 0, 0, 0, 0, 0};

    // Sales Calculation
    std::vector<SaleRecord> salesHistory = a.getSalesHistory();
    std::cout << "Number of sales retrieved: " << salesHistory.size() << std::endl;

    // Validate sales data
    if (salesHistory.empty()) {
        std::cerr << "Error: No sales data found! Check file path or content." << std::endl;
    } else {
        for (const auto& sale : salesHistory) {
            std::cout << "Sale Loaded - Date: " << sale.date
                      << ", Quantity: " << sale.quantity
                      << ", Selling Price: " << sale.selling_price << std::endl;

            if (matchesDate(sale.date, dateFilter, type)) {
                data.totalItemsSold += sale.quantity;
                data.totalSales += sale.selling_price * sale.quantity;
                std::cout << "Matched Sale - Quantity: " << sale.quantity
                          << ", Total Sales: " << data.totalSales << std::endl;
            }
        }
    }

    // Purchases Calculation
    std::vector<PurchaseRecord> purchaseHistory = a.getPurchaseHistory();
    for (const auto& purchase : purchaseHistory) {
        if (matchesDate(purchase.date, dateFilter, type)) {
            data.totalItemsPurchased += purchase.quantity;
            int purchaseCost = purchase.cost_price * purchase.quantity;
            data.totalPurchaseCost += purchaseCost;
            std::cout << "Purchase - Quantity: " << purchase.quantity
                      << ", Cost Price: " << purchase.cost_price
                      << ", Total Purchase Cost: " << purchaseCost << std::endl;
        }
    }

    // Profit Calculation
    data.profit = data.totalSales - data.totalPurchaseCost;

    // Cashier Calculation
    std::vector<user>& cashiers = a.getCashiers();
    cashiers.clear();  // Clear any previous data before loading

    // Load cashiers from CSV
    QString file= getAssetPath("cashiers.csv");
    std::ifstream file1(file.toStdString());
    std::string line;
    bool isFirstLine = true;

    while (std::getline(file1, line)) {
        // Skip header or empty lines
        if (isFirstLine || line.empty()) {
            isFirstLine = false;
            continue;
        }

        // Parse cashier data
        std::stringstream ss(line);
        std::string name, password;
        if (std::getline(ss, name, ',') && std::getline(ss, password, ',')) {
            // Check for duplicate cashiers
            bool exists = false;
            for (const auto& cashier : cashiers) {
                if (cashier.getusername() == name) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                cashiers.push_back(user(name, password));

                std::cout << "Loaded cashier: " << name << std::endl;
            }
        }
    }
    file1.close();
    std::cout << "Total cashiers loaded: " << cashiers.size() << std::endl;
    data.totalCashiers=cashiers.size();
    // Inventory Size
    data.inventorySize = a.getInventory().size();

    std::cout << "Total Sales: " << data.totalSales
              << ", Total Purchase Cost: " << data.totalPurchaseCost
              << ", Profit: " << data.profit << std::endl;

    return data;
}

// show_totalPurchase function definition (not implemented yet)
void Report::show_totalPurchase() const {
    // Functionality to display total purchase information can be added here
}
