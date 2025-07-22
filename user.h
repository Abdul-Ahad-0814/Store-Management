#ifndef USER_H
#define USER_H
#include<vector>
#include"productmain.h"
#include"person.h"
#include"admin.h"
class admin;
class user: public person
{
protected:
    std::vector<productmain> cart;


public:
    user(){}
    user(string u, string p);
    void clearcart();
    void updateCartItem(const productmain& updatedProduct);
    void addtocart(const productmain& p);
    void checkout();
    void viewcart();
     void refund(int id, admin & a);
    void removefromcart(long long int id);

     void refund(long long int id, admin & a);
    string getusername() const { return username; }
    string getpassword() const { return password; }
    vector<productmain> getcart(){return cart;}
};

#endif // USER_H
