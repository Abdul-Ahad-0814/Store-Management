#ifndef PERSON_H
#define PERSON_H
#include<string>
#include<ctime>
using namespace std;
class person
{
protected:
    string username;
    string password;

public:
    person(){}
    person(string u, string p);

    friend class admin;
    string getusername() const;
    string getpassword() const;
    virtual  string generate_password();
    void setusername(string username);
    void setpassword(string password);
};

#endif // PERSON_H
