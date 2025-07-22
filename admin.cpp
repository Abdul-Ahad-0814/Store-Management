#include "admin.h"
#include "inventory.h"
#include<QFile>
#include"utils.h"
#include"database.h"
#include<QDebug>
admin::admin(string u, string p) : person(u, p) {}

string admin:: getcurrentdate() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    return string(buf);
}



bool admin:: checkCashier(string u){
    for (size_t i = 0; i < cashiers.size(); i++){
        if (cashiers[i].username == u){
            cashiers.erase(cashiers.begin() + i);
            return true;
        }
    }
    return false;
}

void admin:: addproduct(long long int id, int q, string name1,double sp,  double p, double dr){
    productmain temp;
    temp.id = id;
    temp.quantity = q;
    temp.name = name1;
    temp.price = p;
    temp.saleprice=sp;
    temp.discountrate=dr;
    inventory.push_back(temp);
    string date= getcurrentdate();
    addPurchaseRecord(to_string(id),name1,q,p,date);
}

void admin:: updateProduct(long long int id, double newprice,double newsp, int newstock,string newname){
    for(auto &productmain: inventory){
        if(productmain.id == id){
            productmain.price=newprice;
            productmain.saleprice=newsp;
            productmain.quantity=newstock;
            productmain.name=newname;
            // cout<<"Product updated successfully!"<<endl;
            return;
        }
    }

}

void admin:: processRefund(long long int id, int quantity){
    for(auto &productmain : inventory){
        if(id == productmain.id){
            productmain.quantity += quantity;
            // cout<<"Product refunded"<<endl;
            // cout<<"Name: "<<product.name<<endl;
            // cout<<"Quantity: "<<product.quantity<<endl;
            return;
        }
    }
    // cout<<"Product not found!"<<endl;
}


void admin:: deleteproduct(long long int id){
        if(inventory.size() > id){
            inventory.erase(inventory.begin() + id);
            // cout<<"Product deleted successfully!"<<endl;
            return;
        }

    // cout<<"Product not found!"<<endl;
}

void admin:: addcashier(string u, string p){
    user temp(u, p);
    cashiers.push_back(temp);
}

void admin::deletecashier(string u){
    if(checkCashier(u)){
        // cout<<"Cashier Deleted. Successfully!\n"<<endl;
    }
    else{
        // cout<<"Cashier not Found!\n"<<endl;
    }
}

void admin::updatecashier(string u, string newpass){
    for(auto &cashier : cashiers){
        if(cashier.username == u){
            cashier.password = newpass;
            // cout<<"Cashier updated successfully!\n"<<endl;

            return;
        }
    }
    // cout<<"Cashier not found!\n"<<endl;
}

void admin:: updateAdmin(string u, string newPass){
    this->password = newPass;
    this->username = u;
    // cout<<"Admin details updated successfully!"<<endl;
}

void admin:: lowstock(){
    for(auto &productmain : inventory){
        if(productmain.quantity <= productmain.threshold){
            // cout<<"\tProduct: "<<product.name<<" is low in stock!"<<endl;
        }
    }
}

double admin:: discount_price(long long int id){
    for(auto &productmain : inventory){
        if(productmain.id == id){
            if(productmain.quantity>=10 && productmain.quantity<20){
                return productmain.price*0.05;
            }
            else if(productmain.quantity>=20 && productmain.quantity<30){
                return productmain.price*0.10;
            }
            else if(productmain.quantity>=30 && productmain.quantity<40){
                return productmain.price*0.15;
            }
            else if(productmain.quantity>=40 && productmain.quantity<50){
                return productmain.price*0.20;
            }
            else{
                return productmain.price*0.40;
            }
        }
    }
}

int admin::totalpurchase=0;

void admin::incrementpurchase(int p){
    totalpurchase += p;
}

int admin::show_purchases(){
    return totalpurchase;
}

vector<productmain> admin::getInventory(){
    return inventory;
}

vector<user>& admin::getCashiers(){
    return cashiers;
}
vector<productmain> admin::displaycart(){
    return inventory;
}

vector<productmain>& admin::display(){
    return inventory;
}

void admin::addSaleRecord(string id, string name, int quantity, double price, string date) {
    SaleRecord record = {id, name, quantity, price, date};
    salehistory.push_back(record);
}

void admin::addPurchaseRecord(string id, string name, int quantity, double cost, string date) {
    PurchaseRecord record = {id, name, quantity, cost, date};
    purchasehistory.push_back(record);
}

void admin::updatePurchaseRecord(const std::string& id, int newQuantity, double newCost, const std::string& newDate) {
    for (auto& record : getPurchaseHistory()) {
        if (record.product_id == id) {
            record.product_id=id;
            record.quantity = newQuantity;
            record.cost_price = newCost;
            record.date = newDate;
            return;
        }
    }
}

void admin::deletePurchaseRecord(const std::string& id) {
    for (auto it = purchasehistory.begin(); it != getPurchaseHistory().end(); ++it) {
        if (it->product_id == id) {
            purchasehistory.erase(it);
                        return;
        }
    }

}

void admin::updateSaleRecord(const std::string& id, int newQuantity, double newCost, const std::string& newDate) {
    for (auto& record : getSalesHistory()) {
        if (record.product_id == id) {
            record.product_id=id;
            record.quantity = newQuantity;
            record.selling_price = newCost;
            record.date = newDate;
            return;
        }
    }
}

void admin::deleteSaleRecord(const std::string& id) {
    for (auto it = getSalesHistory().begin(); it != getSalesHistory().end(); ++it) {
        if (it->product_id == id) {
            salehistory.erase(it);
            return;
        }
    }

}







vector<SaleRecord>& admin::getSalesHistory() {
    return salehistory;
}

vector<PurchaseRecord>& admin::getPurchaseHistory() {
    return purchasehistory;
}


void admin::updatediscount(long long int id, double dr){
    for(auto &productmain: inventory){
        if(productmain.id==id){
            productmain.setdr(dr);
        }
    }
}


void admin::loadCashiersFromFile()
{


    QString product=getAssetPath("cashiers.csv");

    QFile file(product);
if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qDebug() << "Error: Cannot open cashier file.";
    return;
}

QTextStream in(&file);
while (!in.atEnd()) {
    QString line = in.readLine();
    QStringList parts = line.split(",");
    if (parts.size() == 2) {
        // Add cashier to the global admin object
        qDebug() << "Loaded cashier:" << parts[0];
        addcashier(parts[0].toStdString(), parts[1].toStdString());
    } else {
        qDebug() << "Invalid cashier entry:" << line;
    }
}
file.close();
}
