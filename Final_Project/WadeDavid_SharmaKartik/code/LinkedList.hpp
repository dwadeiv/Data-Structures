/*
---------------------------------------------------------------------------------------------------
Purpose: This has the method defenitions for the LinkedList.cpp file.
Authors: David and Kartik
Date: April 25 2020
---------------------------------------------------------------------------------------------------
*/

#pragma once

struct Node //defines the structure of each node in the linked list
{
    int key; //each node comprises of a interger
    Node * next; //each node has a next pointer. 
};
class LinkedList
{
    private:
        Node* head; //points to the first element in the list
    
    public: 
        LinkedList(); //defualt contructer sets head and tail to zero

        ~LinkedList(); //decontructer, which frees memoery leaks

        void traverse(); //traverses the tree by going through each node and printing its key

        Node* search(int item); //searches an item in the list

        void insert(int item); //inserts an item in the list. 



};
