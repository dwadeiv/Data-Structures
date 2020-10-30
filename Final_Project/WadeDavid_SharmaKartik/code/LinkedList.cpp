/*
---------------------------------------------------------------------------------------------------
Purpose: This is the cpp file for the LinkedList.hpp file, this creates a linked list data structure, that adds a new node in the list, searches for an element, and prints the table.
Authors: David and Kartik
Date: April 25 2020
---------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include "LinkedList.hpp"
using namespace std;


LinkedList::LinkedList() { //default contructer, sets head and tail to zero meaning the list is empty
    head = NULL;
}

LinkedList::~LinkedList() { //decontructer going through the whole list and deleteing every linked list node and then setting the list's head and tail to 0.
    Node* tmp = head;
    Node* tmp_prev = NULL;
    while(tmp){
        tmp_prev = tmp;
        tmp = tmp->next;
        delete tmp_prev;
    }
    delete tmp;
    head = NULL;
}
void LinkedList::traverse() { //traverses each node in the list and prints its data
  
    for (Node* tmp = head; tmp != 0; tmp = tmp->next) {
        cout << tmp->key << " --> ";
    }
    
}

void LinkedList::insert(int item){ //inserts an item into the list

    if(head == NULL){ //if the list it empty then the node will be added to the front 
        head = new Node; //head pointer will point to the first element
        head->key = item; //sets its key to the parameter 
        head->next = NULL; //sets its next to NULL for now
    }
    else{ //else tadd new element at end of LL
        Node* new_node = new Node; //creates a new node
        new_node->key = item; //sets its key to the parameter 
        new_node->next = NULL; //sets its next to NULL for now
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

Node* LinkedList:: search(int item){ //searches an element in the linked list.
    for (Node* tmp = head; tmp != 0; tmp = tmp->next) { //goes through each linked list and checks its node's value to see if it matches the parameter
      if(tmp->key == item){//if it does matches then we return that node. 
          return tmp;
      }
    }
   
   return 0;//if not found then return zero.

}