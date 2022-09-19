// Author: Atyub Ahmad
// Project: Merkle Tree
// File: driver.cpp
// driver file that runs the project

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
    MerkleTree myTree = MerkleTree(users);

    //Displaying the content within the tree
    myTree.Display();
    cout << endl;

    //Deleting a user within the tree
    myTree.Delete(3);

    //Displaying the content within the tree
    myTree.Display();
    cout << endl;

    //Comparing two users' incomes from within the tree
    myTree.CompareIncome(1, 2);
    cout << endl;

    return 0;
}
