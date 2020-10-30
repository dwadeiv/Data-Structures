#include <iostream>
#include <string>

using namespace std;

bool append(string* &str_arr, string s, int &numEntries, int &arraySize){
    bool doubled = false;
    if(numEntries == arraySize){
        int new_capacity = arraySize * 2;
        string *new_array = new string[new_capacity];
        for(int i = 0; i < arraySize; i ++){
		    new_array[i] = str_arr[i];
	    }
        str_arr = new_array;
        str_arr[numEntries] = s;
        numEntries ++;
        arraySize = new_capacity;
        delete [] new_array;
        doubled = true;
    }
    else{
        str_arr[numEntries] = s;
    }
    return doubled;
}

int main(){
    int capacity = 3;
    string *str_arr = new string[capacity];
    str_arr[0] = "hello";
    str_arr[1] = "you";
    str_arr[2] = "bitch";
    int numEntries = 3;
    for(int i = 0; i < numEntries; i++){
        cout << str_arr[i] << endl;
    }
    bool doubled = append(str_arr, "!!", numEntries, capacity);
    cout << doubled << ", " << numEntries << ", " << capacity << endl; 
    for(int i = 0; i < numEntries; i++){
        cout << str_arr[i] << endl;
    }
}