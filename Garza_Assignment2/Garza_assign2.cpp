#include <iostream>
#include <fstream>
#include "customErrorClass.h"
#include "C_BST.h"

using namespace std;

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Runs the program
**    Function Output: Depends how you use this program, prints numbers and sorts them
**    Side Effects: Many
*/
int main(int argc, char *argv[])
{
    string line;
    ifstream inputFile;
    inputFile.open("input-small.dat");

    if (!inputFile.is_open())
    {
        //TODO: Throw exception
        exit(-1);
    }

    //Make BST object
    C_BST tree;

    //Read values into BST from file
    while (getline(inputFile, line))
    {
        // cout << line << endl;
        //Insert values into BST, convert them to integers first
        tree.insertValue(stoi(line));
    }

    tree.printTree();

    cout << "-------------------------------------" << endl;

    tree.sortTree();

    tree.printTree();

    //Uncomment this code to test deleting the tree
    //Should not print anything for printing the tree
    // cout << "------- deleted ----------" << endl;
    
    // tree.deleteTree();

    // tree.printTree();

    return 0;
}