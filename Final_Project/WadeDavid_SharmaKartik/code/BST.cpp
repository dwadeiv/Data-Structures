/*

---------------------------------------------------------------------------------------------------
Purpose: This is the cpp file for BST, this creates tha binary search tree and adds integer values, searches for values, and prints out the tree. This uses the hpp file called BST.hpp that has the method defenitions
Authors: David and Kartik
Date: April 27 2020
---------------------------------------------------------------------------------------------------
*/


#include <iostream>
#include "BST.hpp"
using namespace std;

BST::BST() //default contructor
{
    root = 0; //setting root be 0, which means the tree is empty.
}
void destructerHelper(node *P)
{
    if (P == 0) //if the tree is empty then dont do anything
    {           //tree is empty
        return;
    }
    else //else if its not empty then delete every tree node
    {
        destructerHelper(P->left);  //recursively decontruct right tree
        destructerHelper(P->right); //recursively decontruct the left tree
        delete P;
        return;
    }
}
BST::~BST()                 //decontructor to go through the whole tree and remove the nodes to free memory
{                          
    destructerHelper(root); //pass the helper function with root
}

void addNodeToTree(node *&curr, node *&root) //helper function to add a node to the tree
{

    if (curr->key < root->key) //checks is the current's node that needs to be added is less than the new node passed in the function 
    {
        if (root->left != NULL) //if the nodes left pointer doesn't equal to 0
        {
            addNodeToTree(curr, root->left); //we recursively call the function again to find the new nodes position
        }
        else //else we found the position of the node and we add it to the tree
        {
            root->left = curr; 
        }
    }

    else if (curr->key > root->key)  //checks is the current's node that needs to be added is greater than the new node passed in the function 
    {
        if (root->right != NULL) //if the right pointer of that node is not 0, then we need to recursively call the function to find the new node's position
        {
            addNodeToTree(curr, root->right); //recursively call the function. 
        }
        else //else we found the new position of the node
        {
            root->right = curr; //set the node's right pointer to the new node.
        }
    }
}

void BST::insert(int val) //inserts a node into the tree with the new node's key
{
    ////delcaring a new node and setting it's key to the value and settings its next pointers to NULL.
    node *currNode = new node;
    currNode->key = val;
    currNode->left = NULL;
    currNode->right = NULL;
    if (root == NULL)//if the root is zero than the tree is empty meaning that the new node will be root of the tree.
    {
        root = currNode; //set the root to the new node.
    }
    else //else we call the helper function to find the position of the new node.
    {
        addNodeToTree(currNode, root);
    }
}

node *searchHelper(node *P, int value)
{
    if (P == 0) //if the tree is empty, then we cannot search for a node
    {
        return 0;
    }
    else //else we recursively trasverse the subtrees by checking if the node is smaller or greater than the key to be found
    {
        if (P->key == value)
        {
            return P;
        }
        else if (value < P->key)
        {
            return searchHelper(P->left, value);
        }
        else
        {
            return searchHelper(P->right, value);
        }
    }

    return 0;
}
node *BST::search(int key) //search the tree for a particular node by its value
{
    return searchHelper(root, key); //pass the search helper functions with the root and the key to be searched
}

void traverseHelper(node *P)
{
    if (P == 0)
    { //if the tree is empty we cannot print
        return;
    }
    else
    { //else recursively print the nodes in order (smallest -> greatest)

        traverseHelper(P->left);
        cout << P->key << " --> ";
        traverseHelper(P->right);
    }
}
void BST::traverse()
{                         //traverse tree
    traverseHelper(root); //pass the helper function with root
}
