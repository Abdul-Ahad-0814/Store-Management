#include "database.h"
#include"user.h"
#include <QCoreApplication>
#include <QDir>
#include <iostream>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>




void writeToCSV(const std::string& filename, const std::vector<productmain>& products) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "ProductID,ProductName,Purchase Price, Selling Price, Quantity, Discount Rate\n";  // Header
        for (const auto& product : products) {
            file << product.getid() << "," << product.getname() << ","
                 << product.getprice() << "," <<product.get_salePrice()<< " , " << product.getquantity() << " , " <<product.getdr()<< "\n";
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
}


int safeStoi(const std::string& str) {
    try {
        if (str.empty()) {
            throw std::invalid_argument("Empty string");
        }
        return std::stoi(str);
    } catch (const std::exception& e) {
        std::cerr << "Error converting to int: " << str << " (" << e.what() << ")" << std::endl;
        return 0; // Default value, change if necessary
    }
}

long long safeStoll(const std::string& str) {
    try {
        if (str.empty()) {
            throw std::invalid_argument("Empty string");
        }
        return std::stoll(str);  // Using stoll to handle large numbers
    } catch (const std::exception& e) {
        std::cerr << "Error converting to long long: " << str << " (" << e.what() << ")" << std::endl;
        return 0;  // Default value, change if necessary
    }
}

float safeStof(const std::string& str) {
    try {
        if (str.empty()) {
            throw std::invalid_argument("Empty string");
        }
        return std::stof(str);
    } catch (const std::exception& e) {
        std::cerr << "Error converting to float: " << str << " (" << e.what() << ")" << std::endl;
        return 0.0f; // Default value, change if necessary
    }
}



std::vector<productmain> readProductsFromCSV(const std::string& filename) {
    std::vector<productmain> products;
    std::ifstream file(filename);
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, name, pprice, sprice, quantity, discount;

        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, pprice, ',');
        std::getline(ss, sprice, ',');
        std::getline(ss, quantity, ',');
        std::getline(ss, discount, ',');

        productmain p;
        p.setid(safeStoll(id));  // Using safeStoll to handle large IDs
        p.setname(name);
        p.setprice(safeStof(pprice));
        p.setsaleprice(safeStof(sprice));
        p.setquantity(safeStoi(quantity));
        p.setdr(safeStof(discount));

        products.push_back(p);
    }

    return products;
}



void writecashiersToCSV(const std::string& filename, const user& cashier) {
    // Open the file in append mode
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        // Check if file is empty to write the header once

        // Write the new cashier details
        file << cashier.getusername() << "," << cashier.getpassword() << "\n";
        file.close();
    } else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
}

void deleteCashierFromCSV(const std::string& filename, const std::string& cashierName) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
        return;
    }

    std::string tempFileName = "temp.csv"; // Temporary file to write updated content
    std::ofstream tempFile(tempFileName);
    if (!tempFile.is_open()) {
        std::cerr << "Unable to open temporary file for writing." << std::endl;
        return;
    }

    std::string line;
    bool deleted = false;

    // Read file line by line
    while (std::getline(file, line)) {
        // If the cashier's name is not in this line, write it to the temp file
        size_t pos = line.find(cashierName);
        if (pos == std::string::npos) {
            tempFile << line << "\n";  // Write the line without modification
        } else {
            deleted = true;  // Skip this line (this cashier will be deleted)
        }
    }

    file.close();
    tempFile.close();

    if (deleted) {
        // Replace the original file with the temporary file
        std::remove(filename.c_str());
        std::rename(tempFileName.c_str(), filename.c_str());
        std::cout << "Cashier " << cashierName << " deleted successfully." << std::endl;
    } else {
        std::cout << "Cashier with name " << cashierName << " not found." << std::endl;
    }
}

void updateCashierPassword(const std::string& filename, const std::string& cashierName, const std::string& newPassword) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
        return;
    }

    std::string tempFileName = "temp.csv"; // Temporary file to write updated content
    std::ofstream tempFile(tempFileName);
    if (!tempFile.is_open()) {
        std::cerr << "Unable to open temporary file for writing." << std::endl;
        return;
    }

    std::string line;
    bool updated = false;

    // Read file line by line
    while (std::getline(file, line)) {
        // Find the cashier line that needs updating
        size_t pos = line.find(cashierName);
        if (pos != std::string::npos) {
            // Update the password in that line
            size_t commaPos = line.find(',');
            if (commaPos != std::string::npos) {
                line = cashierName + "," + newPassword;
                updated = true;
            }
        }
        // Write the updated or unchanged line to the temp file
        tempFile << line << "\n";
    }

    file.close();
    tempFile.close();

    if (updated) {
        // Replace the original file with the temporary file
        std::remove(filename.c_str());
        std::rename(tempFileName.c_str(), filename.c_str());
        std::cout << "Password updated successfully for " << cashierName << std::endl;
    } else {
        std::cout << "Cashier with name " << cashierName << " not found." << std::endl;
    }
}



std::vector<user> readCashiersFromCSV(const std::string& filename) {
    std::vector<user> cashiers;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
        return cashiers;
    }

    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string username, password;

        if (std::getline(ss, username, ',') && std::getline(ss, password, ',')) {
            // Avoid adding header or empty lines
            if (username != "Username" && !username.empty() && !password.empty()) {
                user p;
                p.setusername(username);
                p.setpassword(password);
                cashiers.push_back(p);
            }
        }
    }

    file.close();
    return cashiers;
}
