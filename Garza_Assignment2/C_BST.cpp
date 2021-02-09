#include "C_BST.h"
#include <stddef.h>

using namespace std;

C_BST::C_BST()
{
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

C_BST::~C_BST()
{
}
