#include "RPNCalculator.hpp"
#include <string>

using namespace std;


RPNCalculator::RPNCalculator(){
    stackHead = NULL;
}

RPNCalculator::~RPNCalculator(){
    while(!isEmpty())
        pop();
}

bool RPNCalculator::isEmpty(){
    return(stackHead==NULL);
}

void RPNCalculator::push(float num){
    Operand* nn = new Operand;
    nn->number = num;
    nn->next = NULL;
    nn->next = stackHead;
    stackHead = nn;
}

void RPNCalculator::pop(){
    if(!isEmpty())
    {
        Operand* temp = stackHead;
        stackHead = stackHead->next;
        delete temp;
    }
    else
    {
        cout << "Stack empty, cannot pop an item."<< endl;
    }
}

Operand* RPNCalculator::peek(){
    if(!isEmpty()){
        return stackHead;
    }
    else{
        cout << "Stack empty, cannot peek."<< endl;
        return NULL;
    }

}

bool RPNCalculator::compute(std::string symbol){
    bool computation = false;

    if(isEmpty()){
        cout << "err: not enough operands" << endl;
        return computation;
    }
    Operand* operand_1 = peek();
    float num_1 = operand_1->number;
    float num_2 = 0;
    Operand* operand_2 = new Operand;

    if(symbol != "+" && symbol != "*"){
        cout << "err: invalid operation" << endl;
        return computation;
    }

    else if(!isEmpty()){
        pop();
        if(!isEmpty()){
            operand_2 = peek();
            num_2 = operand_2->number;
            pop();
        }
        else{
            push(num_1);
            cout << "err: not enough operands" << endl;
            return computation;
        }
    }
    else{
        cout << "err: not enough operands" << endl;
        return computation;
    }


    if(symbol == "*"){
        float answer = (num_1 * num_2);
        push(answer);
        return computation = true;
    }
    else if(symbol == "+"){
        float answer = (num_1 + num_2);
        push(answer);
        return computation = true; 
    }
}
