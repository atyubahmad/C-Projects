// Author: Atyub Ahmad
// Project: Merkle Tree
// File: User.cpp
// Contains the function definitions from User.h

#include "User.h"

//Constructor
User::User() {
    //Default values
    m_name = "";
    m_age = 0;
}

//Overloaded Constructor
User::User(string name, int age) {
    //Setting the member variables
    SetName(name);
    SetAge(age);
}

//Destructor
User::~User() {}

//Setting name
void User::SetName(string name) {
    m_name = name;
}

//Setting age
void User::SetAge(int age) {
    m_age = age;
}


//Getting name
string User::GetName() {
    return m_name;
}

//Getting age
int User::GetAge() {
    return m_age;
}
