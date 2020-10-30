/*

---------------------------------------------------------------------------------------------------
Purpose: This has the method defenitions for the BST.cpp file
Authors: David and Kartik
Date: April 27 2020
---------------------------------------------------------------------------------------------------
*/

#ifndef BST_HPP
#define BST_HPP

struct node{ // strcuture of each node in the tree, which has a key and points to its left and right nodes if it has any
    int key;
    node * left;
    node * right;

};

class BST{ //class of the BST
    private:
    node* root; //pointer to the root of the tree.

    public:
    BST();  //contructer
    ~BST(); //decontructer
   
    void insert(int val);  //insert node into tree
    
    node* search(int key); //search key value in tree
   
    void traverse(); //traverse tree in order.
    



};

#endif