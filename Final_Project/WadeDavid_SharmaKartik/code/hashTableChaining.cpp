/*
---------------------------------------------------------------------------------------------------
Purpose: This is the cpp file for the hash table chaining methods, where it will add an item in the hash table, search for an item, and print the table. Uses the method defenitions in the hashTableChaining.hpp file. 
Authors: David and Kartik
Date: April 27 2020
---------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include "hashTableChaining.hpp"

HashTable::HashTable(int bsize){ //contructor of hash table, sets each item in the hash table to be zero 
    size = bsize; //makes the parameter size the actual size of the hash table
    table = new nodeTable *[bsize]; //creates a new hash table

    for(int i =0; i < bsize; i++){ //makes each value in the hash table zero
        table[i]=0;
    }
}
HashTable::~HashTable(){ //defualt deconstructor
    for(int p =0; p < size; p++){
        nodeTable* curr = table[p];
        while(curr !=0){ //if there is a linked list delete every node
            nodeTable* tmp = curr;
            curr = curr->next;
            delete tmp;
        }
    }
    delete[] table; //delete the whole table
}
bool HashTable :: insertItem(int key){ //inserts an item into a hash table

    nodeTable *search = searchItem(key); //search for the item, to see if its in the hash table if its not then we add it to the table
    if(search == 0){ //if the search returns not found then we add the item into the hash table
    
    nodeTable* newItem = new nodeTable; //create a new object for the new item 
    newItem->key = key; //make the new items value equal to the new value that is being added to the hash table
    newItem->next = NULL;
    int index = hashFunction(key); //find its position by using the hash table function

    if(table[index] == 0){ //if the index of the hash table function is zero, meaning its empty at that position, then we add that value to that particular index
        table[index] = newItem;
       
    }
    else{ //else that meaans that at that index it is already taken by another item, so we then add it to the linked list at that index. 
        newItem->next = table[index];
        table[index] = newItem;
        numOfcolision++; //increment the number of collisions when there is a linked list node added.
       
    }
    
    return true; //return true since its added 
    }
    else{//we return false if the item is already in the list. 
        return false;
    }
}

 unsigned int HashTable :: hashFunction(int key){ //creates a hash table index by dividing the key passed to the function by the total size of the hash table.
    return (key % size);
 }


void HashTable :: printTable(){ //this function prints the table by going through each element and printing its value and if it has a linked list then we also print the linked list. 
    for(int i = 0; i < size; i++){
        cout<<"["<<i<<"]";
        if(table[i] != 0){
            nodeTable* tmp = table[i];
            while(tmp!=0){
                cout<<" -->"<<tmp->key;
                tmp = tmp->next;
            }
            cout<<""<<endl;
        }
        else{
            cout<<"--> No chains";
            cout<<""<<endl;
        }
    }
}
int HashTable :: getNumOfCollision(){//returns the number of collisions caused
    return numOfcolision;
}

nodeTable* HashTable :: searchItem(int key){ //searches for an item in the hash table.
    int index = hashFunction(key); //find the index of the element by pasing that value to the hash function

    if(table[index] == 0){ //if the index found is zero that means that the item doesnt exisit so we return zero
        return 0;
    }

    else{ //else we find the element at that particular index by traversing its linked list.
        nodeTable* temp = table[index];

        while(temp !=0){
            if(temp->key == key){
                return temp;
            }
            else{
                temp = temp->next;
            }
        }
    return 0;
    }
}