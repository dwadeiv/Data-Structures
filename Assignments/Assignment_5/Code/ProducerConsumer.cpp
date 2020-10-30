#include "ProducerConsumer.hpp"
#include <string>
#include <iostream>


ProducerConsumer::ProducerConsumer(){
    queueFront = 0;
    queueEnd = 0;
}

bool ProducerConsumer::isEmpty(){
    if(queueSize() == 0){
        return true;
    }
    else {
        return false;
    }
}

bool ProducerConsumer::isFull(){
    if(queueSize() == SIZE){
        return true;
    }
    else {
        return false;
    }
}

void ProducerConsumer::enqueue(std::string item){
    if(!isFull()){
        queue[queueEnd] = item;
        counter++;

        if(queueEnd == SIZE-1){
            queueEnd = 0;
        }
        else{
            queueEnd ++;
        }
    }
    else{
        std::cout << "Queue full, cannot add new item" << std::endl;
    }
}

void ProducerConsumer::dequeue(){
    if(!isEmpty()){
        counter --;
        if(queueFront == SIZE-1){
            queueFront = 0;
        }
        else{
            queueFront ++;
        }
    }
    else {
        std::cout << "Queue empty, cannot dequeue an item" << std::endl;
    }
}
std::string ProducerConsumer::peek(){
    if(isEmpty()){
        std::cout << "Queue empty, cannot peek" << std::endl;
    }
    else {
        return queue[queueFront];
    }
}
int ProducerConsumer::queueSize(){
    return counter;
}