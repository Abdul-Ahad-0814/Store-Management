#ifndef REPORT_H
#define REPORT_H

#include <iostream>
#include <string>
#include "admin.h"

// reportdata.h
struct ReportData {
    int totalItemsSold;
    double totalSales;
    int totalItemsPurchased;
    double totalPurchaseCost;
    double profit;
    int totalCashiers;
    int inventorySize;
};

class Report {
public:
    Report();
    ReportData generate_report(admin& a, const std::string& timeframe, const std::string& date_filter);
    void show_totalPurchase() const;
    bool matchesDate(const std::string& recordDate, const std::string& filter, const std::string& type);
};

#endif // REPORT_H
