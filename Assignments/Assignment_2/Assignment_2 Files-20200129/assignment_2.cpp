#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "assignment_2.h"

using namespace std;

void getStopWords(const char *ignoreWordFileName, string ignoreWords[]) {
    ifstream in_file;
    in_file.open(ignoreWordFileName); 
    if(in_file.fail()){
        cout << "Failed to open  " << ignoreWordFileName << endl;
    }
    int i = 0;
    string line;
    // Parse through lines of input file
    while(getline(in_file,line)){
        ignoreWords[i] = line;
        i ++;
    }   
    in_file.close();
}

bool isStopWord(string Word, string ignoreWords[]) {
    for(int i = 0; i < 50; i ++){
        if(Word == ignoreWords[i]){
            return true;
        }
    }
    return false;
}

void add_word_item(wordItem words[], string word, int count, int &length) {
    words[length].word = word;
    words[length].count = count;
    length += 1;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length) {
    int count = 0;
    for(int i = 0; i < length; i++){
        wordItem temp = uniqueWords[i];
        count += temp.count;
    }
    return count;
}

void arraySort(wordItem uniqueWords[], int length) {
    for(int i = 0; i < length; i ++){
        for(int j = 0; j < length; j++){
            if(uniqueWords[j].count < uniqueWords[j+1].count){
                wordItem temp = uniqueWords[j];
                uniqueWords[j] = uniqueWords[j+1];
                uniqueWords[j+1] = temp;
            }
        }
    }
}

void printNext10(wordItem uniqueWords[], int N, int totalNumWords) {
    for(int j = N; j < (N + 10); j++){
        wordItem temp = uniqueWords[j];
        float temp_float = float(temp.count);
        float probability = temp_float / totalNumWords;
        // Round to 4 places
        cout << fixed << setprecision(4)  << probability  << " - " << temp.word << endl;  
    }
}

wordItem* resize(wordItem* arrayPtr, int &capacity) {
    int newCapacity = capacity * 2;

    wordItem *newArray = new wordItem[newCapacity];

	for(int i = 0; i < capacity; i ++){
		newArray[i] = arrayPtr[i];
	}

	delete [] arrayPtr;

	capacity = newCapacity;

	return newArray;
}