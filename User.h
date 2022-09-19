// Author: Atyub Ahmad
// Project: Merkle Tree
// File: User.h
// Contains the function prototypes for the User class

#ifndef NAME_H
#define NAME_H
#include <string>
#include <iostream>
using namespace std;



class User{
public:
    //Constructor, Overloaded Constructor, Destructor
    User();
    User(string, int);
    ~User();

    //Setters
    void SetName(string);
    void SetAge(int);

    //Getters
    string GetName();
    int GetAge();

private:
    string m_name; //User name
    int m_age; //User age

};


#endif
