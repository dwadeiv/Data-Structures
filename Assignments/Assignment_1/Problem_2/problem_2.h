#include <string>

using namespace std;

struct Park{
    string parkname;
    string state;
    int area;
};

void addPark(Park parks[], string parkname, string state, int area, int length);

void printList(const Park parks[], int length);