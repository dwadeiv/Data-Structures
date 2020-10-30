/*
---------------------------------------------------------------------------------------------------
Purpose: This has the method defenitions for the hashTableChaining.cpp file
Authors: David and Kartik
Date: April 25 2020
---------------------------------------------------------------------------------------------------
*/

#ifndef HTC_HPP
#define HTC_HPP

#include <string>


using namespace std;

struct nodeTable //defins what each element in the hash table comprises of 
{
    int key;
    struct nodeTable* next;
};

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)
    int size; //size of the table. 

    // Pointer to an array containing buckets
    nodeTable** table;

    int numOfcolision =0;
    nodeTable* createNode(int key, nodeTable* next);
public:
    HashTable(int bsize);  // Constructor
     ~HashTable(); //defualt decontructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    nodeTable* searchItem(int key);
};

#endif
