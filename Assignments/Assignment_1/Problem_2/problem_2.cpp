#include <iostream>
#include <string>
#include "problem_2.h"

using namespace std;



void addPark(Park parks[], string parkname, string state, int area, int length){
    parks[length].parkname = parkname;
    parks[length].state = state;
    parks[length].area = area;
}

void printList(const Park parks[], int length){
    for(int j = 0; j < length; j++){
        cout << parks[j].parkname << " [" << parks[j].state << "] area: " << parks[j].area << endl;
    }
}

