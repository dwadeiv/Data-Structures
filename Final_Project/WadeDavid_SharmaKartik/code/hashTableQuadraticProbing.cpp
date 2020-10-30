/*
---------------------------------------------------------------------------------------------------
Purpose: This is the cpp file that creates a hash table that uses quadratic probing techniques to resolve collisions, this file contains methods that add, search, and prints the hash table.
Authors: David and Kartik
Date: April 28 2020
---------------------------------------------------------------------------------------------------
*/


#include<iostream>
#include<iostream>
#include "hashTableQuadraticProbing.hpp"
#include <math.h>
using namespace std;


hashTableQuadraticProbing::hashTableQuadraticProbing(int bsize){
    size = bsize; //makes the parameter size the actual size of the hash table
    table = new newNodeTable *[bsize]; //creates a new hash table

    for(int i =0; i < bsize; i++){ //makes each value in the hash table zero
        table[i]=0;
    }
}
hashTableQuadraticProbing::~hashTableQuadraticProbing(){
    delete[] table;
}

bool hashTableQuadraticProbing::insertItem(int key){

        newNodeTable* newItem = new newNodeTable; //create a new node for that new item.
       newItem->key = key; //set the key to the parameter 
       int newIndex = hashFunction(key); //find the index where the the new element should reside by sending its key to the hash function 
       if(table[newIndex] == 0){ //if at that particular index there is no element already there, then we can simply just add the element to that point.
           table[newIndex] = newItem;
           return true;
           
       }
       else if(table[newIndex] != 0 && table[newIndex]->key == key){ //if the item exist already then do not add the item
           return false;
       }
       else if(table[newIndex] != 0){ //else if there is already an element in that position in the hash table, then we need to find it a new spot.
            int limit = size; //set the incrementer to the size of the hash table
            int i =1;
            int newPosition = 0;

            while(i <= size){ //increment till we go through all the spots in the hash table
                newPosition = hashFunction(newIndex + (int)pow(i,2)); //create a new position of where the item can reside
                if(table[newPosition] != 0 && table[newPosition]->key == key){ //check if the new position index is equal to the key that we are passing through, if it is then we know that the item already exisits so we return false
                    return false; 
                }
                if(table[newPosition] == 0){ //if the new position index is zero then we add the item there
                    numOfcolision++; //we increment the number of colisions
                    table[newPosition] = newItem; //make that index of the hash table the new element
                    return true; //return true
                }
                else{
                    i++; //increment i
                }
            }
       }
return false;

}

 unsigned int hashTableQuadraticProbing::hashFunction(int key){ //returns the hash table index by dividing key by size of the table
        return (key % size);
 }

 void hashTableQuadraticProbing::printTable(){ //prints the hash table
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
 int hashTableQuadraticProbing::getNumOfCollision(){ //returns the number
     return numOfcolision;
 }
 newNodeTable* hashTableQuadraticProbing::searchItem(int key){
      int foundIndex = hashFunction(key); //finds value of where the index should be located with its key.
     if(table[foundIndex] == 0){ //if the index at that point is zero then that means that the element is not present in the table.
         return 0;
     }
     else if(table[foundIndex]->key == key){ //if the index's key at that point equals to the key then we return that element.
         return table[foundIndex];
     }
     else if(table[foundIndex]->key != key){ //else now we have to traverse every element after the index found to see if the key is in the hash table, until the we get to an empty spot
           int limit = size;
            int i =1;
            int newPosition = 0;

            while(i <= size){ //while the increment is less than the size:
                newPosition = hashFunction(foundIndex + (int)pow(i,2)); //we create a new position
                if(table[newPosition]->key == key){ //if that particular position's key is equal to the key
                    return table[newPosition]; //return that element at that particular hash table
                }
                else{ //else increment
                    i++;
                }
            }


     }

     return 0; //return zero if still nothing is found


 }




