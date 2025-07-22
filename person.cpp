#include "person.h"
#include<cstdlib>
#include<string>
using namespace std;
person::person(string u, string p){
    this->username=u;
    this->password=p;
}


 string  person:: generate_password() {
    srand(time(0));
    int num[5];
    password = username;
    for(int i=0;i<3;i++){
        num[i] = rand()%10; //(0-9) Range
        password = password + to_string(num[i]);
    }
    return password;
}


void person:: setusername(string username){
    this->username=username;
}

void person::setpassword(string password){
    this->password=password;
}

string person::getpassword() const{
    return this->password;
}

string person::getusername() const{
    return this->username;
}
