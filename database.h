#ifndef DATABASE_H
#define DATABASE_H
#include<string>
#include<QString>
#include"productmain.h"
#include<vector>
#include"user.h"

void writeToCSV(const std::string& filename, const std::vector<productmain>& products);
void writecashiersToCSV(const std::string& filename, const user& cashiers);
std::vector<productmain> readProductsFromCSV(const std::string& filename);
std::vector<user> readCashiersFromCSV(const std::string& filename);
void deleteCashierFromCSV(const std::string& filename, const std::string& cashierName);
void updateCashierPassword(const std::string& filename, const std::string& cashierName, const std::string& newPassword);
#endif // DATABASE_H
