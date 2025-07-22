#ifndef ADMIN_H
#define ADMIN_H
#include"user.h"
#include"productmain.h"
#include<ctime>
#include<sstream>


struct SaleRecord {

    string product_id;
     string name;
    int quantity;
    double selling_price;
    string date;  // format "YYYY-MM-DD"
};

struct PurchaseRecord {

    string product_id;
    string name;
    int quantity;
    double cost_price;
    string date;  // format "YYYY-MM-DD"
};


class user;
class admin: public person
{
protected:
    vector<SaleRecord> salehistory;
    vector<PurchaseRecord> purchasehistory;
    vector<user> cashiers;
    vector<productmain> inventory;
    static int totalpurchase;
    // image
    bool checkCashier(string u);
public:
    admin(){}
    admin(string u, string p);
    vector<productmain> displaycart();
    void deletePurchaseRecord(const std::string& id);
    void deleteSaleRecord(const std::string& id);
    void addSaleRecord(string id, string name, int quantity, double price, string date);
    void addPurchaseRecord(string id, string name, int quantity, double cost, string date);
    vector<SaleRecord>& getSalesHistory();
    vector<PurchaseRecord>& getPurchaseHistory();
    vector<productmain>& display();
    void addproduct(long long id, int q, string name1,double sp, double p,double dr);
    void updateProduct(long long id, double newprice, double newsp, int newstock, string newname);
    void updatediscount(long long int id, double dr);
    void processRefund(long long id, int quantity);
    void deleteproduct(long long id);
    void addcashier(string u, string p);
    void deletecashier(string u);
    void updatecashier(string u, string newpass);
    void updateAdmin(string u, string newPass);
    void lowstock();
    static void incrementpurchase(int p);
    double discount_price(int id);
    double discount_price(long long id);
    int show_purchases();
    vector<productmain> getInventory();
    vector<user>& getCashiers();
    string getcurrentdate();
    void loadCashiersFromFile();
    void updatePurchaseRecord(const std::string& id, int newQuantity, double newCost, const std::string& newDate);
    void updateSaleRecord(const std::string& id, int newQuantity, double newCost, const std::string& newDate);
};

#endif // ADMIN_H
