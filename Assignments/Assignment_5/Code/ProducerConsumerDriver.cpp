/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
#include <string>
// you may include more libraries as needed

using namespace std;

void menu();
void handleUserInput(ProducerConsumer& Pro_Co);

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

void handleUserInput(ProducerConsumer& Pro_Co){
  bool quit = false;
  string s_input;
  int input;
  string s_answer;
  int answer;
  string item;
  int size;

  // loop until the user quits
  while (!quit)
  {
    menu();

    // read in input, assuming a number comes in
    getline(cin, s_input);
    try
    {
      input = stoi(s_input);
    }
    catch (exception& e)
    {
      // non-numeric input. trigger the default switch case.
      input = 5;
    }

    switch (input){
        case 1:               
          std::cout << "Enter the number of items to be produced:" << std::endl;
          getline(cin, s_answer);
          answer = stoi(s_answer);
          for(int i = 0; i < answer; i++){
            std::cout << "Item" << (i+1) << ":" << std::endl;
            getline(cin, item);
            Pro_Co.enqueue(item);
          }
          break;

        case 2:      
          std::cout << "Enter the number of items to be consumed:" << std::endl;
          getline(cin, s_answer);
          answer = stoi(s_answer);
          size = Pro_Co.queueSize();
          for(int i = 0; i < answer; i++){
            if(i == size){
              std::cout << "No more items to consume from queue" << std::endl;
              break;
            }
            std::cout << "Consumed: " << Pro_Co.peek() << std::endl;
            Pro_Co.dequeue();
          }
          break;

        case 3:
          std::cout << "Number of items in the queue:" << Pro_Co.queueSize() << endl;
          quit = true;
          break;

        default:     // invalid input
          cout << "Invalid Input" << endl;
          break;
    }
  }
}

// Use getline for reading
int main(int argc, char const *argv[])
{
	ProducerConsumer Pro_Co;
  handleUserInput(Pro_Co);
}
