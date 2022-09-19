#include "Employee.h"

//Constructor
Employee::Employee() {
    //Default Values
    m_employed = false;
    m_income = 0;
}

//Overloaded constructor with Initialization list
Employee::Employee(string name, int age, bool employed, int income, int employeeID): User(name, age) {
    //Setting the member variables
    SetEmployed(employed);
    SetIncome(income);
    SetEmployeeID(employeeID);
}

//Destructor
Employee::~Employee() {}

//Setting employed statues
void Employee::SetEmployed(bool employed) {
    m_employed = employed;
}

//Setting income
void Employee::SetIncome(int income) {
    m_income = income;
}

//Setting ID
void Employee::SetEmployeeID(int ID) {
    m_employeeID = ID;
}

//Getting employed status
bool Employee::GetEmployed() {
    return m_employed;
}

//Getting Income
int Employee::GetIncome() {
    return m_income;
}

//Getting ID
int Employee::GetEmployeeID() {
    return m_employeeID;
