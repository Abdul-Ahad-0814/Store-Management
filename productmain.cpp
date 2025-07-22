#include "productmain.h"
#include "functions.h"


// productmain::productmain(int i,string n, int q,double sp, double p): threshold(2), discountRate(1){

// Constructor for admin (includes purchase price)

productmain::productmain(long long int i, string n, int q, double sp, double p, double discountrate)
    : threshold(2), discountrate(discountrate) {
    this->id = i;
    this->name = n;
    this->quantity = q;
    this->saleprice = sp;
    this->price = p;
}

// Constructor for cashier (excludes purchase price)
productmain::productmain(long long int i, string n, int q, double sp, double discountrate)
    : threshold(2), discountrate(discountrate) {
    this->id = i;
    this->name = n;
    this->quantity = q;
    this->saleprice = sp;
    this->price = 0.0; // Set purchase price to 0 or a default value
}

int productmain::getquantity() const{
    return this->quantity;
}

double productmain:: getprice()const{
    return this->price;
}


long long int productmain:: getid() const{
    return id;
}

string productmain::getname() const{
    return this->name;
}

void productmain::set_discount_new(string rate){
    lower(rate);
    if(rate == "no"){

    }
    else{
        this->discountrate = stof(rate);
    }
}

double productmain::get_salePrice() const{
    return saleprice;
}

float productmain::get_discountRate()const{
    return discountrate;
}
double productmain::getsellingprice()const{
    return this->saleprice;
}

double productmain::getdr()const{
    return this->discountrate;
}


void productmain::setid(long long int  id){
    this->id=id;
}

void productmain::setname(string name){
    this->name=name;
}


void productmain::setquantity( int id){
    this->quantity=id;
}

void productmain::setprice(double id){
    this->price=id;
}

void productmain::setsaleprice(double id){
    this->saleprice=id;
}

void productmain::setdr(double id){
    this->discountrate=id;
}



