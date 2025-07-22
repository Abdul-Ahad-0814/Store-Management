#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>
#include<string>
using namespace std;

void lower(string &x){
    for(int i=0;i<x.length();i++){
        if(x[i]>='A' && x[i]<='Z'){
            x[i] = x[i] + 32;
        }
    }
}

#endif // FUNCTIONS_H
