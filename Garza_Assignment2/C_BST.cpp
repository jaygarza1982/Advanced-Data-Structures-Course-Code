#include "C_BST.h"
#include <stddef.h>
#include <iomanip>
#include <iostream>

using namespace std;

C_BST::C_BST()
{
    //Define our root node when constructing a new BST
    this->root = NULL;
}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Inserts a node into the BST at the root
**    Function Output: None
**    Side Effects: Inserts a node into the BST from the root
*/
void C_BST::insertValue(int data) {
    //If our root is null, create a new node
    if (this->root == NULL) {
        this->root = new S_NODE;
        this->root->data = data;
        this->root->left = this->root->right = NULL;
    }
    //If root is not null, recursively add nodes
    else {
        this->insertValue(data, this->root);
    }
}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        inserts a node into the binary search tree
**    Function Output: struct node
**    Side Effects: Changes the tree and root nodes children
*/
S_NODE* C_BST::insertValue(int data, S_NODE* node)
{
    // If the node we are at is null, we have reached where we should insert
    //So we create a new node and insert into the tree
    if(node == NULL)
    {
        node = new S_NODE;
        node->data = data;
        node->left = node->right = NULL;
    }
    // Go left
    else if(data < node->data) {
        node->left = insertValue(data, node->left);
    }
    // Go right
    else if(data > node->data) {
        node->right = insertValue(data, node->right);
    }

    return node;
}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Finds a node given a "root" or starting node
**    Function Output: A pointer to a node that we found or NULL if we did not find
**    Side Effects: None
*/
S_NODE* C_BST::findNode(S_NODE* node, int data)
{
    //If the node we are on is null, return it
    if(node == NULL) return NULL;

    //Search the tree accordingly
    else if(data < node->data) return findNode(node->left, data);
    else if(data > node->data) return findNode(node->right, data);
    
    //If none of the above cases meet, we have found our node!
    return node;
}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Calls the helper get height function
**    Function Output: Height of the BST
**    Side Effects: None
*/
int C_BST::getHeight() {
    //Get the height of the tree
    int privateHeight = this->p_getHeight(this->root);

    //If we returned something less than 0 (if our root node is null), return 0
    //If we did not return something less than 0, return the height found
    return  privateHeight < 0 ? 0 : privateHeight;
}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Gets the height of the BST
**    Function Output: The height of the BST
**    Side Effects: None
*/
int C_BST::p_getHeight(S_NODE *root) {
    //Do not add 1, minus 1 since we went a layer too deep
    //Or a layer that does not exist because root is null
    if (root == NULL) return -1;

    //Go down each sub tree
    int leftTreeHeight = this->p_getHeight(root->left);
    int rightTreeHeight = this->p_getHeight(root->right);

    //Take which ever one is greater
    if (leftTreeHeight > rightTreeHeight) return 1 + leftTreeHeight;

    return 1 + rightTreeHeight;
}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Calls the print helper function to print BST
**    Function Output: None (void, but prints to screen)
**    Side Effects: None, prints the BST to the screen, does not write to variables
*/
void C_BST::printTree() {
    p_formattedPrint(this->root, 4);
}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Prints the BST in a formatted mannor
**    Function Output: None (void, but prints to screen)
**    Side Effects: Prints the binary to screen, does not write to any variables
*/
void C_BST::p_formattedPrint(S_NODE *node, int indent) {
    if (NULL == node) return;

    this->p_formattedPrint(node->left, indent+4);

    if (indent) {
        cout << setw(indent) << " ";
    }

    cout << node->data << endl;

    this->p_formattedPrint(node->right, indent+4);
}

C_BST::~C_BST()
{
}
