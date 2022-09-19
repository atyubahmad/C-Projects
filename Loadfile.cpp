// Author: Atyub Ahmad
// Project: Merkle Tree
// File: Loadfile.cpp
// Contains the function definitions from Loadfile.h

#include "Loadfile.h"

//Constructor
Loadfile::Loadfile(){
    //Setting the member variable
    m_fileName = "directory.txt";
}

//Destructor
Loadfile::~Loadfile() {}

//Takes info from a file and saves it into a vector
vector<string> Loadfile::LoadDirectory() {

    string item; //Variable to store a line of info from the file
    vector<string> items; //Vector to hold all the info from the file

    //Opening and reading the file
    ifstream itemfile(m_fileName);

    //Checking if file is open
    if(itemfile.is_open()){

        //Keeps running till it reaches the end of the file
        while(itemfile.peek() != EOF){
            //Saving the line from the file into the variable
            getline(itemfile, item);
            //Saving the variable into the vector
            items.push_back(item);

        }
        //Closing the file
        itemfile.close();

    //Error Statement
    } else{
        cout << "Directory file did not open" << endl;
    }
    //Returning the vector
    return items;
}
