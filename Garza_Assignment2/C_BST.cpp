#include "C_BST.h"
#include <stddef.h>
#include <iomanip>
#include <iostream>
#include <math.h>

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

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Rotates a given node to the left
**    Function Output: The new node that is rotated
**    Side Effects: Changes the given nodes pointers and nodes around it
*/
S_NODE *C_BST::p_rotateLeft(S_NODE *node) {
    S_NODE *rightNode;
    S_NODE *rightNodeLeft;

    //If the given node or the given nodes right is null, stop
    //We cannot continue if either of these are true
    if ((node == NULL) || (node->right == NULL))
    {
        return node;
    }

    //Assign right node to point to given nodes right child
    rightNode = node->right;
    rightNodeLeft = rightNode->left;

    rightNode->left = node;
    node->right = rightNodeLeft;

    return rightNode;
}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Rotates a given node to the right
**    Function Output: The new rotated node
**    Side Effects: Changes the given nodes pointers and nodes around it
*/
S_NODE *C_BST::p_rotateRight(S_NODE *node) {
    S_NODE *leftNode;
    S_NODE *leftNodeRight;

    //If the given node or the given nodes left is null, stop
    //We cannot continue if either of these are true
    if ((node == NULL) || (node->left == NULL))
    {
        return node;
    }

    //Assign right node to point to given nodes right child
    leftNode = node->left;
    leftNodeRight = leftNode->right;

    leftNode->right = node;
    node->left = leftNodeRight;

    return leftNode;
}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Creates the vine for the DSW algorithm
**    Function Output: Pointer to the root of the starting node
**    Side Effects: "Shifts" all nodes to the right, creating a right leaning tree
*/
S_NODE* C_BST::p_createVine(S_NODE *node) {

    S_NODE *pointer;
    S_NODE *right = new S_NODE;

    //right->left = NULL;
    right->right = node;

    pointer = right;
    while (pointer->right != NULL) {
        if (pointer->right->left == NULL) {
            pointer = pointer->right;
        }
        else {
            pointer->right = this->p_rotateRight(pointer->right);
        }
    }

    return right->right;
}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Does step 2 of the DSW algorithm. The initial rotations needed to balance given
          a calculated count of how many are needed.
**    Function Output: A "pseudo" root node of where we left off
**    Side Effects: Does rotations where needed leaving the tree modified
*/
S_NODE *C_BST::p_initialRotations(S_NODE* node, int rotations) {
    S_NODE *crawler = node;

    //While we still have rotations left
    while (rotations)
    {
        //Rotate left and crawl to the right as needed
        crawler->right = this->p_rotateLeft(crawler->right);
        crawler = crawler->right;

        --rotations;
    }

    return node;
}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Balances the tree by creating a vine, and doing rotations
**    Function Output: void
**    Side Effects: Balances the BST starting with the root node
*/
void C_BST::sortTree() {
    this->root = this->p_createVine(this->root);

    int log2Value;
    int initialLeftRotations;
    int height = this->getHeight();

    //Floored since log2Value is an integer
    log2Value = log2(height + 1);

    //Step 2 of DSW
    initialLeftRotations = height + 1 - (pow(2, log2Value));
    this->root = this->p_initialRotations(this->root, initialLeftRotations);

    //Final steps in DSW
    height -= initialLeftRotations;
    while (height > 1)
    {
        height /= 2;
        this->root = p_initialRotations(this->root, height);
    }
}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Deletes a given node from the tree recursively
**    Function Output: None
**    Side Effects: Deletes all nodes below a given node
*/
void C_BST::p_deleteNode(S_NODE *node) {
    //If the node we were given is null, stop
    if (node == NULL) return;

    //If it is not null, go to its children and delete them
    p_deleteNode(node->right);
    p_deleteNode(node->left);

    //Delete the given node after going to its children
    delete node;
}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Deletes all nodes within the tree starting with the root node
**    Function Output: None
**    Side Effects: Root is set back to a new node and all nodes beneath the old root are deleted
*/
void C_BST::deleteTree() {
    this->p_deleteNode(this->root);

    //Assign null to the root for future construction
    this->root = NULL;
}

C_BST::~C_BST()
{
}
