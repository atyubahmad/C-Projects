// Author: Atyub Ahmad
// Project: Merkle Tree
// File: MerkleTree.cpp
// Contains the function definitions from MerkleTree.h

#include <sstream>
#include "MerkleTree.h"


//Overloaded cout
ostream &operator<<(ostream &output, Employee &myEmployee) {
    string job = (myEmployee.GetEmployed() > 0) ? "Yes" : "No";
    output << "Name: " <<myEmployee.GetName() << " | Age: " << myEmployee.GetAge() << " | Employed? " << job <<
           " | Income: " << myEmployee.GetIncome() << " | Employee ID: " << myEmployee.GetEmployeeID() << endl;

    return output;
}

//Overloaded equals
MerkleTree &MerkleTree::operator=(MerkleTree &tree) {
    m_size = tree.m_size;
    for(int i = 0; i < MAX; i++) {
        arr[i] = tree.arr[i];
    }
    return *this;
}

//Constructor
MerkleTree::MerkleTree() {
    //Initializing array and size
    init();
}

//Overloaded Constructor
MerkleTree::MerkleTree(vector<string> users) {
    //Initializing array and size
    init();
    //Unloaded the info from the vector
    Unload(users);
}

//Destructor
MerkleTree::~MerkleTree() {
    //Emptying the tree
    Empty();
}


//Goes through the array and displays the content from the tree that exist
void MerkleTree::Display() {
    //Looping through the array
    for(int i = 0; i < MAX; i++){
        Node *root = arr[i].head;

        //Checking to see if the node inside the array is NULL
        if(root != NULL){
            //Passing in the nodes that actually have content
            DisplayTree(root);

        }
    }
}

//Displays the content within the tree
void MerkleTree::DisplayTree(Node* tree) {
    //Checking to see if the node is NULL
    if(tree == NULL){
        return;
    }
    //Displaying the node's info
    cout << *tree->value;

    //Checking to see if there is a left node
    if(tree->left != NULL){
        //Displaying that node
        DisplayTree(tree->left);
    }
    //Checking to see if there is a right node
    if(tree->right != NULL){
        //Displaying that node
        DisplayTree(tree->right);
    }

}

//Initializing the array and size of tree
void MerkleTree::init(){
    //Default value
    m_size = 0;

    //Looping through the array and setting every index to NULL
    for(int i = 0; i < MAX; i++){
        arr[i].head = NULL;
    }
}


//Empties the trees
void MerkleTree::Empty() {
    //Looping through the array's size
    for(int i = 0; i < MAX; i++){
        //Passing in each index
        Delete(i);
    }

}

//Goes through the tree's nodes until it hits the desired last node
Node* MerkleTree::Traverse(Node *lastNode) {
    //Checking to see if the node is NULL
    if(lastNode == NULL){
        return NULL;
    }

    //Checking to see if the node's left and right is NULL
    if(lastNode->left == NULL and lastNode->right == NULL){
        //Returning the original node
        return lastNode;

    //Checking to see if the node's left exist but the right does not
    } else if(lastNode->left != NULL and lastNode->right == NULL){
        //Returning the original node
        return lastNode;

    //Checking to see if the node's right exists
    }else if(lastNode->right != NULL){
        //Traversing the original node's right
        return Traverse(lastNode->right);

    //Traversing the original node's right
    }else {
        return Traverse(lastNode->left);
    }

}

//Inserts an Employee into the tree
void MerkleTree::Insert(Employee *myEmployee) {

    //Hashing the employee's ID
    int index = Hash(myEmployee->GetEmployeeID());

    //Creating a root node at that specific hashed index
    Node *root = (Node*) arr[index].head;

    //Creating a new node for later
    Node* newNode = new Node();

    //Storing the new node's info
    newNode->value = myEmployee;

    //Setting the new node's left and right
    newNode->left = NULL;
    newNode->right = NULL;

    //Letting you know which User is being inputted and User ID and then incrementing the size
    cout << "Inserting User: " << myEmployee->GetName() << " with User ID: " << myEmployee->GetEmployeeID() << endl;
    m_size++;

    //Checking to see if the root exists
    if(root == NULL){
        //Adding the newNode
        arr[index].head = newNode;
    }else{
        //Call traverse to find the last node
        Node *lastNode = Traverse(root);

        //Checking if the node has a left or right and then inserting the newNode in the proper place
        if(lastNode->left == NULL) {
            lastNode->left = newNode;
        } else {
            lastNode->right = newNode;
        }
    }

}

//Takes in a integer that determines which node is being deleted
void MerkleTree::Delete(int employeeID) {
    //Checking the hash
    int index = Hash(employeeID);

    //Creating a node
    Node *root = (Node*)arr[index].head;

    //If the node exists then remove it
    if(root != NULL){
        RemoveElement(root);
    }
    //Setting the Node to NULL
    arr[index].head = NULL;

}

void MerkleTree::RemoveElement(Node *user) {
    //Checking if the node is NULL
    if(user == NULL){
        return;
    }
    //Letting us know which User is being deleted
    cout << "Deleting User: " << user->value->GetName() << " with User ID: " << user->value->GetEmployeeID() << endl;

    //Deleting the node's info and setting it to NULL
    delete user->value;
    user->value = NULL;

    //Checking if the node's left exists
    if(user->left != NULL){
        //Removing the node's left and setting it to NULL
        RemoveElement(user->left);
        user->left = NULL;
    }
    //Checking if the node's right exists
    if(user->right != NULL){
        //Removing the node's right and setting it to NULL
        RemoveElement(user->right);
        user->right = NULL;
    }

    //Deleting the node and setting it to NULL
    delete user;
    user = NULL;
}

//Hashes the Employee's ID
int MerkleTree::Hash(int hashKey) {

    //Creating a unique hash based of the Employee's ID and the maximum Employees allowed
    int hash = (hashKey % MAX);

    //Returning the hash
    return hash;
}

//Parses information from a vector of users
void MerkleTree::Unload(vector<string> users) {

    //Variables to store each aspect of an Employee
    string name, age, employed, income, employeeID;

    //Bool for job status
    bool job = true;

    //Looping through the vector
    for(unsigned int i = 0; i < users.size(); i++) {
        istringstream ss(users[i]); //converting each line of the vector to a string stream

        //Getting each information
        getline(ss, name, ',');
        getline(ss, age, ',');
        getline(ss, employed, ',');
        getline(ss, income, ',');
        getline(ss, employeeID, ',');

        //Setting the proper job status
        if(employed == "false"){
            job = false;
        } else{
            job = true;
        }

        //Creating a new Employee and then inserting it into the tree
        Employee *myEmployee = new Employee(name, stoi(age), job, stoi(income), stoi(employeeID));
        Insert(myEmployee);
    }


}

//Finds the latest node added to the tree
Node* MerkleTree::GetLatestNode(int index) {
    //Making a new Node and passing in the desired node from the array
    Node *latestNode = Traverse((Node*) arr[index].head);

    //Checking to see if the right of the node exists
    if (latestNode->right != NULL) {
        //Setting the latest node to that
        latestNode = latestNode->right;

    //Checks if teh left exists if the right does not
    } else if (latestNode->left != NULL) {
        //Setting the latest node to that
        latestNode = latestNode->left;
    }
    //Returns the latest node
    return latestNode;
}

//Compares the income of two users within the trees
void MerkleTree::CompareIncome(int user1, int user2) {
    //Checking the hashes
    int index = Hash(user1);
    int index1 = Hash(user2);

    //Getting the latest nodes of each user
    Node *employee1 = GetLatestNode(index);
    Node *employee2 = GetLatestNode(index1);


    //Comparing the incomes and outputting the correct statement
    if(employee1->value->GetIncome() > employee2->value->GetIncome()){
        cout << employee1->value->GetIncome() << " > " << employee2->value->GetIncome()<< endl;
        cout << "User: " << employee1->value->GetName() << " has a greater income than User: " <<  employee2->value->GetName() << endl;
    }else{
        cout << employee1->value->GetIncome() << " < " << employee2->value->GetIncome()<< endl;
        cout << "User: " << employee1->value->GetName() << " has a lesser income than User: " <<  employee2->value->GetName() << endl;
    }
}

//Setting Size
void MerkleTree::SetSize(int size) {
    m_size = size;
}

//Getting Size
int MerkleTree::GetSize() {
    return m_size;
}
