#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "MovieTree.hpp"

using namespace std;


/* ------------------------------------------------------ */
MovieTree::MovieTree()
{
  root = NULL;
}

void deleteAllLL(TreeNode* currNode){
  if(currNode == NULL){
    return; 
  }

  LLMovieNode* temp = currNode->head;
  while(temp != NULL){
    LLMovieNode* temp_next = temp->next;
    delete temp;
    temp = temp_next;
  }


  deleteAllLL(currNode->rightChild);
  deleteAllLL(currNode->leftChild);
}
void deleteMovieTree(TreeNode* currNode){
  
  if(currNode == NULL){
    return;
  }
  deleteMovieTree(currNode->leftChild);
  deleteMovieTree(currNode->rightChild);
  
  delete currNode;

}

MovieTree::~MovieTree()
{
  deleteAllLL(root);
  deleteMovieTree(root);
}

void printMovieInventoryHelper(TreeNode* currNode){

  if(currNode->leftChild != NULL){
    printMovieInventoryHelper(currNode->leftChild);
  }
  LLMovieNode* temp = currNode->head;

  cout << "Movies starting with letter: " << currNode->titleChar << endl;
  while(temp != NULL){
    cout << " >> " << temp->title << " " << temp->rating << endl;
    temp = temp->next;
  }

  if(currNode->rightChild != NULL){
    printMovieInventoryHelper(currNode->rightChild);
  }
}

void MovieTree::printMovieInventory()
{
    if(root == NULL){
        return;
    }
    printMovieInventoryHelper(root);
}

void addMovieHelper(TreeNode* currNode, char title_char, LLMovieNode* newMovie){

  if(currNode->titleChar == title_char){
    LLMovieNode* temp = currNode->head;
    LLMovieNode* temp_prev = NULL;

    while(temp != NULL){
        if(temp->title < newMovie->title){
            if(temp->next == NULL){
                temp->next = newMovie;
                newMovie->next = NULL;
                break;
            }
        }
        if(temp->title > newMovie->title){
            if(temp == currNode->head){
                newMovie->next = currNode->head;
                currNode->head = newMovie;
                break;
            }
            newMovie->next = temp;
            temp_prev->next = newMovie;
            break;
        }
        temp_prev = temp;
        temp = temp->next;
    }
  }

  if(currNode->titleChar < title_char){
    if(currNode->rightChild == NULL){
      TreeNode* newNode = new TreeNode;
      currNode->rightChild = newNode;
      newNode->parent = currNode;
      newNode->titleChar = title_char;
      newNode->head = newMovie;
      return;
    }
    else{
      addMovieHelper(currNode->rightChild, title_char, newMovie);
    }
  }

  if(currNode->titleChar > title_char){
    if(currNode->leftChild == NULL){
      TreeNode* newNode = new TreeNode;
      currNode->leftChild = newNode;
      newNode->parent = currNode;
      newNode->titleChar = title_char;
      newNode->head = newMovie;
      return;
    }
    else{
      addMovieHelper(currNode->leftChild, title_char, newMovie);
    }
  }
}

void MovieTree::addMovie(int ranking, string title, int year, float rating)
{
  LLMovieNode* newMovie = new LLMovieNode(ranking, title, year, rating);
  char titleChar = title.at(0);
  if(root == NULL){
    TreeNode* newNode = new TreeNode;
    newNode->titleChar = titleChar;
    newNode->head = newMovie;
    root = newNode;
    return;
  }
  else{

    addMovieHelper(root, titleChar, newMovie);
  }
}

TreeNode* inorderSuccessor(TreeNode* currNode){

  if(currNode->leftChild == NULL){
    return currNode;
  }
  return inorderSuccessor(currNode->leftChild);
}

TreeNode* deleteNodeHelper(TreeNode* currNode, char first_letter)
{
  if(currNode == NULL)
  {
    return NULL;
  }
  else if(first_letter < currNode->titleChar)
  {
    currNode->leftChild = deleteNodeHelper(currNode->leftChild, first_letter);
  }
  else if(first_letter > currNode->titleChar)
  {
    currNode->rightChild = deleteNodeHelper(currNode->rightChild, first_letter);
  }
  // Found the node with the same first letter
  else
  {
    //Case : No child
    if(currNode->leftChild == NULL && currNode->rightChild == NULL)
    {
      delete currNode;
      currNode = NULL;
    }
    //Case : Only right child
    else if(currNode->leftChild == NULL)
    {
      TreeNode* temp = currNode;
      currNode = currNode->rightChild;
      currNode->parent = temp->parent;
      delete temp;
      return currNode;
    }
    //Case : Only left child
    else if(currNode->rightChild == NULL)
    {
      TreeNode* temp = currNode;
      currNode = currNode->leftChild;
      currNode->parent = temp->parent;
      delete temp;
      return currNode;

    }
    //Case: Both left and right child
    else
    {
      ///Replace with Minimum from right subtree
      TreeNode* temp = inorderSuccessor(currNode->rightChild);
      currNode->titleChar = temp->titleChar;
      currNode->head = temp->head;
      currNode->rightChild = deleteNodeHelper(currNode->rightChild, temp->titleChar);
    }
  }

  return currNode;
}

void MovieTree::deleteMovie(std::string title)
{
  if(root == NULL){
      cout << "Movie: " << title << " not found, cannot delete." << endl;
      return;
  }
  char first_letter = title.at(0);
  TreeNode* interest_node = searchChar(first_letter);
  LLMovieNode* temp = interest_node->head;
  LLMovieNode* temp_prev = NULL;
  if(temp->title == title){
      interest_node->head = interest_node->head->next;
      delete temp;
  }
  else{
    while(temp != NULL){
      if(temp->title == title){
        if(temp->next == NULL){
          temp_prev->next = NULL;
          delete temp;
          break;
        }
        temp_prev->next = temp_prev->next->next;
        delete temp;
        break;
      }
      temp_prev = temp;
      temp = temp->next;
    }
  }
  if(interest_node->head == NULL){
    root = deleteNodeHelper(root, interest_node->titleChar);
    return;
  }
  if(temp == NULL){
    cout << "Movie: " << title << " not found, cannot delete." << endl;
  }
}

void MovieTree::leftRotation(TreeNode* curr)
{
  if(curr->rightChild == NULL){
    return;
  }
  TreeNode* temp = curr->rightChild;
  if(curr == root->rightChild){
    root->rightChild = temp;
  }
  if(curr == root->leftChild){
    root->leftChild = temp;
  }
  temp->parent = curr->parent;
  curr->parent = temp;
  curr->rightChild = temp->leftChild;
  temp->leftChild = curr;
  if(curr == root){
    root = temp;
    return;
  }
}
//------ Given Methods--------//
void _grader_inorderTraversal(TreeNode * root)
{
	if (root == NULL) {
		return;
	}

	_grader_inorderTraversal(root->leftChild);
	cout << root->titleChar << " ";
	_grader_inorderTraversal(root->rightChild);
}


void MovieTree::inorderTraversal() {
	_grader_inorderTraversal(root);
	cout << endl;
}



TreeNode* searchCharHelper(TreeNode* curr, char key)
{
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchChar(char key)
{
    return searchCharHelper(root, key);
}
