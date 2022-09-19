// Author: Atyub Ahmad
// Project: Merkle Tree
// File: Employee.h
// Contains the function prototypes for the Employee class that inherits from User class

#ifndef EMPLOYED_H
#define EMPLOYED_H
#include "User.h"

class Employee: public User{
public:
    //Constructor, Overloaded Constructor, Destructor
    Employee();
    Employee(string, int, bool, int, int);
    ~Employee();

    //Setters
    void SetEmployed(bool);
    void SetIncome(int);
    void SetEmployeeID(int);


    //Getters
    bool GetEmployed();
    int GetIncome();
    int GetEmployeeID();

private:
    bool m_employed; //Employment status
    int m_income; //Income
    int m_employeeID; //Employee ID
};

#endif
