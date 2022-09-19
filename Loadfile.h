// Author: Atyub Ahmad
// Project: Merkle Tree
// File: Loadfile.h
// Contains the function prototypes for the Loadfile class

#ifndef DATAFILE_H
#define DATAFILE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;



class Loadfile{
public:
    //Constructor and Destructor
    Loadfile();
    ~Loadfile();

    //Loads in info from a file
    vector<string> LoadDirectory();



private:
    //Stores the name of the file passed in
    string m_fileName;
};




#endif
