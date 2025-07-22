#include "user.h"
#include<QDebug>
user::user(string u, string p): person(u,p) {}

void user::removefromcart(long long int id){
    for(size_t i=0;i<cart.size();i++){
        if(cart[i].id == id){
            cart.erase(cart.begin() + i);
            // cout<<"Product removed from cart successfully!"<<endl;
            return;
        }
    }
    // cout<<"Product not found in cart!"<<endl;
}

void user::clearcart() {
    cart.clear();
}

void user::updateCartItem(const productmain& updatedProduct)
{
    for (auto &item : cart) {
        if (item.getid() == updatedProduct.getid()) {
            item.setquantity(updatedProduct.getquantity());
            return;
        }
    }
}


void user:: checkout(){
    double total = 0;
    for(auto &productmain : cart){
        total += productmain.price;
        // product.quantity-=cart.quantity;

    }
    // cout<<"Total amount: "<<total<<endl;
}

void user:: viewcart(){
    for(auto &item:  cart){
        // cout<<"Product: "<<product.name<<" | Price: "<<product.price<<endl;
    }
}


void user::addtocart(const productmain &product) {
    try {
        cart.push_back(product);
        admin::incrementpurchase(product.getquantity());
        qDebug() << "Product added to cart successfully!";
    } catch (const std::exception& e) {
        qDebug() << "Error adding product to cart:" << e.what();
    }
}

void user::refund(long long int id, admin & a){
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
