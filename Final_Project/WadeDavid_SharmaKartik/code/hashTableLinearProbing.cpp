/*
---------------------------------------------------------------------------------------------------
Purpose: This is the cpp file for hash table with linear probing collision technique method. This file creates a hash table, searches for an element, and adds an element to the hash table. 
Authors: David and Kartik
Date: April 28 2020
---------------------------------------------------------------------------------------------------
*/
#include "hashTableLinearProbing.hpp"
#include <iostream>
using namespace std;

hashTableLinearProbing::hashTableLinearProbing(int bsize){ //contructor of hash table, sets each item in the hash table to be zero 
    size = bsize;//makes the parameter size the actual size of the hash table
    table = new tableNode *[bsize];//creates a new hash table

    for(int i =0; i < size; i++){  //makes each value in the hash table zero
        table[i]=0;
    }
}

hashTableLinearProbing::~hashTableLinearProbing(){ //default deconstructor

    delete[] table;  //delete the hash table

}
bool hashTableLinearProbing :: insertItem(int key){ //inserts an item into the hash table with its key

  tableNode* findItem = searchItem(key); //search for the item to see if its in the hash table already

  if(findItem == 0){ //if the search results in a zero, that means that the element is not found, thus we can add it to the hash table. 
        tableNode* newItem = new tableNode; //create a new node for that new item.
       newItem->key = key; //set the key to the parameter 
       int newIndex = hashFunction(key); //find the index where the the new element should reside by sending its key to the hash function 

       if(table[newIndex] == 0){ //if at that particular index there is no element already there, then we can simply just add the element to that point.
           table[newIndex] = newItem;
           return true;
           
       }
       else if(table[newIndex] != 0){ //else if there is already an element in that position in the hash table, then we need to find it a new spot.
          for (int k = (newIndex + 1) % size; k != newIndex; k = (k + 1) % size){ //this for loop will go through each value in the hash table after the index found until there is an empty space, if there is no empty space then the element will never be added.
               if(table[k] == 0){ //if there is no element in that particular index then we add the node there 
                   table[k] = newItem;
                    numOfcolision++; //increment the number of collisions. 
                   return true;
               }
           }
       }
    }
    return false; //if the element is already in the hash table then we do not add it.

}



 unsigned int hashTableLinearProbing :: hashFunction(int key){ //creates a hash table index by dividing the key passed to the function by the total size of the hash table.
    return (key % size);
 }

 void hashTableLinearProbing::printTable(){ //this function simply goes through the whole hash table and prints its value at each index. 

    
     for(int k =0; k < size; k++){
        cout<<"["<<k<<".] -->";
        if(table[k] != 0){
            cout<<" "<<table[k]->key;
        }
        else if(table[k] == 0){
            cout<<" empty"<<endl;
        }
        cout<<""<<endl;
     }

     
 }

 int hashTableLinearProbing::getNumOfCollision(){ //returns the number of collisions
     return numOfcolision;
 }

 tableNode* hashTableLinearProbing::searchItem(int key){ //searches for an item in the hash table with a given value.

     int foundIndex = hashFunction(key); //finds value of where the index should be located with its key.
     if(table[foundIndex] == 0){ //if the index at that point is zero then that means that the element is not present in the table.
         return 0;
     }
     else if(table[foundIndex]->key == key){ //if the index's key at that point equals to the key then we return that element.
         return table[foundIndex];
     }
     else{ //else now we have to traverse every element after the index found to see if the key is in the hash table, until the we get to an empty spot
         for(int k = (foundIndex + 1) %size; k != foundIndex; k = (k + 1) % size){
             if(table[k] == 0){ //if the spot if empty then we didn't find the item 
                 return 0;
             }
             else if(table[k]->key == key){ //else if index's key equals to the value passed then the we return that particular element. 
                 return table[k];
             }
         }
     }

     return 0;
 }