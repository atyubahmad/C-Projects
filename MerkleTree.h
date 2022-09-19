// Author: Atyub Ahmad
// Project: Merkle Tree
// File: MerkleTree.h
// Contains the function prototypes for MerkleTree class

#ifndef MERKLETREE_H
#define MERKLETREE_H
#include "Loadfile.h"
#include "User.h"
#include "Employee.h"

//Maximum amount of employees allowed in the record
const int MAX = 1000;

//Node for storing an item in the Tree
struct Node
{
    Employee *value; //Employee's info
    struct Node *left; //Node's left pointer
    struct Node *right; //Node's right pointer

};

//BST head
struct bst{
    Node* head;
};



class MerkleTree{
public:
    //Constructor, Overloaded Constructor, Destructor
    MerkleTree();
    MerkleTree(vector<string>);
    ~MerkleTree();

    //Takes an a key to delete a specific element
    void Delete(int);
    //Removes element from tree
    void RemoveElement(Node*);

    //Displays content within the tree
    void Display();
    void DisplayTree(Node*);

    //Initializes array and size
    void init();

    //Empties the tree
    void Empty();

    //Traverses through the tree
    Node* Traverse(Node*);

    //Adds a leaf to the tree
    void Insert(Employee*);

    //Hashes ID
    int Hash(int);

    //Parses info from a vector
    void Unload(vector<string>);

    //Compares two incomes of users within the tree
    void CompareIncome(int, int);

    //Gets the most recently added node
    Node* GetLatestNode(int);

    //Set and Get size
    void SetSize(int);
    int GetSize();

    //Overloaded cout
    friend ostream &operator<< (ostream &output, Employee &myEmployee);

    //Overloaded equal
    MerkleTree &operator=(MerkleTree &tree);


private:

    struct bst arr[MAX]; //array of trees

    int m_size; //size

};




#endif
