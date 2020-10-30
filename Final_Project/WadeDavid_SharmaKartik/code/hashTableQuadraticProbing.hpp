/*
---------------------------------------------------------------------------------------------------
Purpose: This is the hpp file that has all the method defentions that are used in the hashTablQuadtraticProbing.cpp.
Authors: David and Kartik
Date: April 28 2020
---------------------------------------------------------------------------------------------------
*/

#ifndef HTQ_HPP
#define HTQ_HPP

struct newNodeTable //defins what each element in the hash table comprises of 
{
    int key;
    struct newNodeTable* next;
};

class hashTableQuadraticProbing
{
    int tableSize;  // No. of buckets (linked lists)
    int size; //size of the table. 

    // Pointer to an array containing buckets
    newNodeTable** table;

    int numOfcolision =0;
    newNodeTable* createNode(int key, newNodeTable* next);
public:
    hashTableQuadraticProbing(int bsize);  // Constructor
     ~hashTableQuadraticProbing();

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    newNodeTable* searchItem(int key);
};

#endif