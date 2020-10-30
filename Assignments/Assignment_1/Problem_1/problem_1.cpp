#include "problem_1.h"
#include <iostream>

void swap_by_pointers(float *n1, float *n2) {
  float temp;
  temp = *n1;
  *n1 = *n2;
  *n2 = temp;
}

int insertIntoSortedArray(float myArray[], int numEntries, float newValue)
{
    myArray[numEntries] = newValue;
    float a,b;
    float temp;
    for(int i = 0; i < (numEntries); i++) {
        for(int j = 0; j < (numEntries-i); j++){
            if(myArray[j] < myArray[j+1]){
                //temp = myArray[j];
                //myArray[j+1] = myArray[j];
                //myArray[j] = temp;
                swap_by_pointers(&myArray[j],&myArray[j+1]);
            }
        }
    }
    return numEntries+1;
}