#include <string>

using namespace std;

struct wordItem {
    string word;
    int count;
};

void getStopWords(char const *ignoreWordFileName, string ignoreWords[]);

bool isStopWord(string Word, string ignoreWords[]);

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length);

void arraySort(wordItem uniqueWords[], int length);

void printNext10(wordItem uniqueWords[], int N, int totalNumWords);

void add_word_item(wordItem words[], string word, int count, int &length);

wordItem* resize(wordItem* arrayPtr, int &capacity);
