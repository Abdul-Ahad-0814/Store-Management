#ifndef PRODUCTMAIN_H
#define PRODUCTMAIN_H
#include<string>
using namespace std;


class productmain
{
protected:



    long long int id;

    string name;
    int quantity;
    double saleprice;
    double price;
     int threshold;
    double discountrate;
    // image
public:
    friend class admin;
    friend class user;
    // productmain(){}
    // productmain() : id(0), name(""), quantity(0), saleprice(0), price(0), threshold(2), discountRate(1) {}
    productmain() : id(0), name(""), quantity(0), saleprice(0), price(0), threshold(2),discountrate(1) {}
    void  setquantity(int q);
    productmain(long long int i, string n, int q,double sp,  double p, double disocuntrate);
    // Use the cashier-specific constructor (no purchase price)
    productmain(long long int id, string name, int quantity, double salePrice, double discountRate);
    void  setid(long long int id);
    void  setname(string name);
    void  setsaleprice(double sp);
    void  setprice(double pr);
    void  setdr(double dr);

    int getquantity() const;

    long long int getid() const;
    string getname() const;
    double getprice() const;
    void set_discount_new(string rate);
    double get_salePrice() const;
    float get_discountRate()const;
    double getsellingprice()const;
    double getdr()const;
};

#endif // PRODUCTMAIN_H
