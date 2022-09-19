// Author: Atyub Ahmad
// Project: Merkle Tree
// File: extra_driver.cpp
// extra driver file that runs the unit testing for the project

#include <iostream>
#include "Employee.h"
#include "MerkleTree.h"
#include "Loadfile.h"
#include "User.h"

int main(){
    //Creating a Loadfile object and saving all the info from the passed in file in a vector
    Loadfile myLoad = Loadfile();
    vector<string> users = myLoad.LoadDirectory();

    //Adding the info into the tree
    cout << "Adding Employees to the Record:" << endl;
    MerkleTree myTree = MerkleTree(users);
    cout << endl;

    //Displaying the content within the tree
    cout << "Employee Records: " << endl;
    myTree.Display();
    cout << endl;

    //Deleting a user within the tree
    cout << "Deleting an Employee from the record" << endl;
    myTree.Delete(3);
    //Displaying the content within the tree
    myTree.Display();
    cout << endl;

    //Comparing two users' incomes from within the tree
    cout << "Comparing two incomes from the record: " << endl;
    myTree.CompareIncome(1, 2);
    cout << endl;

    //Updating a user's info within the tree
    cout << "Updating an Employee's record: " << endl;
    Employee *myEmployee = new Employee ("John Smith",26,false,1000,1);
    myTree.Insert(myEmployee);
    myTree.Display();
    cout << endl;

    //Comparing the users' from earlier again to show the updated record
    cout << "Comparing the same two user's income from earlier but with the updated record: " << endl;
    myTree.CompareIncome(1, 2);
    cout << endl;

    cout << "Updating Emily Keller's name and age" << endl;
    Employee *myEmployee1 = new Employee ("Emily Smith",46,true,250000,4);
    myTree.Insert(myEmployee1);
    myTree.Display();
    cout << endl;

    cout << "Testing Destructor: " << endl;
    return 0;
}
