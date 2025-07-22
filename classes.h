#ifndef CLASSES_H
#define CLASSES_H
#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
#include"opencv2/opencv.hpp"
using namespace cv;
using namespace std;

class admin;

class person{
    protected:
        string username;
        string password;
        string role;


    public:
        person(string u="", string p="", string r="") : username(u), password(p), role(r) {}

        friend class admin;

        void generate_password(){
            srand(time(0));
            int num[5];
            password = username;
            for(int i=0;i<3;i++){
                num[i] = rand()%10; //(0-9) Range
                password = password + to_string(num[i]);
            }
        }
};



class productmain{
    protected:
        int id;
        string name;
        int quantity;
        double price;
        const int threshold =2 ;
        double discountRate;
        double set_discount;
        // image
    public:
        friend class admin;
        friend class user;
        productmain(string n="", int q=0, double p=0.0) : name(n), quantity(q), price(p) {}

        int get_quantity(){return quantity;}
};

class user : public person{
    protected:
        vector<productmain> cart;
        int userid;

    public:
        user(string u, string p, string r) : person(u, p, r) {}

        void addtocart(productmain p);

        void removefromcart(int id){
            for(int i=0;i<cart.size();i++){
                if(cart[i].id == id){
                    cart.erase(cart.begin() + i);
                    // cout<<"Product removed from cart successfully!"<<endl;
                    return;
                }
            }
            // cout<<"Product not found in cart!"<<endl;
        }

        void checkout(){
            double total = 0;
            for(auto &productmain : cart){
                total += productmain.price;
                // product.quantity-=cart.quantity;

            }
            // cout<<"Total amount: "<<total<<endl;
        }

        void viewcart(){
            for(auto &productmain: cart){
                // cout<<"Product: "<<product.name<<" | Price: "<<product.price<<endl;
            }
        }

        void refund(int id, admin & a);
};

class admin : public person{
    protected:
        vector<user> cashiers;
        vector<productmain> inventory;
        // static int totalpurchase;
        // image

        bool checkCashier(string u){
            for (int i = 0; i < cashiers.size(); i++){
                if (cashiers[i].username == u){
                    cashiers.erase(cashiers.begin() + i);
                    return true;
                }
            }
            return false;
        }

    public:

        admin(string u, string p, string r) : person(u, p, r) {}
        // friend class product;

        void addproduct(int id, int q, string name1, double p){
            productmain temp;
            temp.id = id;
            temp.quantity = q;
            temp.name = name1;
            temp.price = p;

            inventory.push_back(temp);
        }

        void updateProduct(int id, double newprice, int newstock){
            for(auto &productmain: inventory){
                if(productmain.id == id){
                    productmain.price=newprice;
                    productmain.quantity=newstock;
                    // cout<<"Product updated successfully!"<<endl;
                    return;
                }
            }
        }

        void processRefund(int id, int quantity){
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

        void deleteproduct(int id){
            for(int i=0;i<inventory.size();i++){
                if(inventory[i].id == id){
                    inventory.erase(inventory.begin() + i);
                    // cout<<"Product deleted successfully!"<<endl;
                    return;
                }
            }
            // cout<<"Product not found!"<<endl;
        }

        void addcashier(string u, string p, string r){
            user temp(u, p, r);
            cashiers.push_back(temp);
        }

        void deletecashier(string u){
            if(checkCashier(u)){
                // cout<<"Cashier Deleted. Successfully!\n"<<endl;
            }
            else{
                // cout<<"Cashier not Found!\n"<<endl;
            }
        }
        void updatecashier(string u, string newpass){
            for(auto &cashier : cashiers){
                if(cashier.username == u){
                    cashier.password = newpass;
                    // cout<<"Cashier updated successfully!\n"<<endl;

                    return;
                }
            }
            // cout<<"Cashier not found!\n"<<endl;
        }

        void updateAdmin(string u, string newPass){
            this->password = newPass;
            this->username = u;
            // cout<<"Admin details updated successfully!"<<endl;
        }

        void lowstock(){
            for(auto &productmain : inventory){
                if(productmain.quantity <= productmain.threshold){
                    // cout<<"\tProduct: "<<product.name<<" is low in stock!"<<endl;
                }
            }
        }

        static void incrementpurchase(int p);
        // int totalsales(){}

        double discount_price(int id){
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
};

int admin::totalpurchase=0;

class Dashboard : public admin, public user, public productmain{
    protected:

    public:

};

void admin::incrementpurchase(int p){
    totalpurchase += p;
}

void user::addtocart(productmain p){
        cart.push_back(p);
        admin::incrementpurchase(p.get_quantity());
}

void user::refund(int id, admin & a){
    for(int i=0;i<cart.size();i++){
        if(cart[i].id == id){
            int rQuantity = 1;
            if(cart[i].quantity>=rQuantity){
                rQuantity = cart[i].quantity;
                a.processRefund(id, rQuantity);
                // cout<<"Refunding Product: "<<cart[i].name<<" | Price: "<<cart[i].price<<" | Quantity: "<<cart[i].quantity<<endl;
                cart.erase(cart.begin() + i);
                // cout<<"Product refunded successfully!"<<endl;
            }
            else{
                // cout<<"Cannot refund more than you have in the cart!"<<endl;
            }
            return;
        }
    }
    // cout<<"Product not found in cart!"<<endl;
}

#endif // CLASSES_H
