#include "LinkedList.h"

using namespace std;

// Add a new node to the list
void LinkedList::insert(Node* prev, int newKey){

  //Check if head is Null i.e list is empty
  if(head == NULL){
    head = new Node;
    head->key = newKey;
    head->next = NULL;
  }

  // if list is not empty, look for prev and append our node there
  else if(prev == NULL)
  {
      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = head;
      head = newNode;
  }

  else{

      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = prev->next;
      prev->next = newNode;

    }
  }


// TODO: SILVER PROBLEM
// Delete node at a particular index
bool LinkedList::deleteAtIndex(int n)
{
  bool isDeleted = false;

  if(head == NULL){
    cout<< "List is already empty"<<endl;
    return isDeleted;
  }

  // Special case to delete the head
    if (n == 0) {
      //TODO
      Node* temp = head;
      head = head->next;
      free(temp);
      return isDeleted = true;
    }

  Node *pres = head;
	Node *prev = NULL;

  // TODO
  while(pres->next != NULL && n != 0){
    prev = pres;
    pres = pres->next;
    n--;
  }
  if(n != 0){
    return isDeleted;
  }
  prev->next = prev->next->next;
  free(pres);
  isDeleted = true;
  

	return isDeleted;
}

// TODO: GOLD PROBLEM
// Swap the first and last nodes (don't just swap the values)
bool LinkedList::swapFirstAndLast()
{
    bool isSwapped = false;

    if(head == NULL) {
        cout << "List is empty. Cannot swap" << endl;
        return false;
    }

    Node* temp_1 = head;
    Node* second_to_last = NULL;
    int count = 0;
    while(temp_1->next != NULL){
      second_to_last = temp_1;
      temp_1 = temp_1->next;
      count ++;
    }
    Node* temp_2 = head;
    head = temp_1;
    second_to_last->next = temp_2;
    head->next = second_to_last->next->next;
    second_to_last->next->next = NULL;


    // TODO (take care of the edge case when your linkedlist has just 2 nodes)
    Node* new_head = head->next;
    if(count == 2){
      head->next = head->next->next;
      new_head->next = head;
      return isSwapped = true;
    }
    isSwapped = true;
    return isSwapped;
}

// Print the keys in your list
void LinkedList::printList(){
  Node* temp = head;

  while(temp->next != NULL){
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}

// Search for a specified key and return a pointer to that node
Node* LinkedList::searchList(int key) {

    Node* ptr = head;
    while (ptr != NULL && ptr->key != key)
    {
        ptr = ptr->next;
    }
    return ptr;
}
