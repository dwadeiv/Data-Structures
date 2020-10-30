/*
---------------------------------------------------------------------------------------------------
Purpose: This has the method defenitions for the hashTableLinearProbing.cpp file.
Authors: David and Kartik
Date: April 27 2020
---------------------------------------------------------------------------------------------------
*/

#ifndef HTL_HPP
#define HTL_HPP

struct tableNode
{
    int key;
};

class hashTableLinearProbing
{ 
    int size;
    // Pointer to an array containing buckets
    tableNode **table;
    int numOfcolision = 0;

public:
    hashTableLinearProbing(int bsize);  // Constructor
     ~hashTableLinearProbing();

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    tableNode* searchItem(int key);
};

#endif