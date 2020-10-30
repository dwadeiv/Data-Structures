#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST

MovieTree::MovieTree() {
  //write your code
  root = NULL;
}

MovieTree::~MovieTree() {
  //write your code
  delete root;
}

void printMovieInventoryHelper(MovieNode* currNode){
  if(currNode->left != NULL){
    printMovieInventoryHelper(currNode->left);
  }
  cout << "Movie: " << currNode->title << " " << currNode->rating << endl;

  if(currNode->right != NULL){
    printMovieInventoryHelper(currNode->right);
  }
}

void MovieTree::printMovieInventory() {
   //write your code
   if(root == NULL){
     cout << "Tree is empty. Cannot print" << endl;
     return;
   }
   printMovieInventoryHelper(root);
}

void addNodeHelper(MovieNode* currNode, MovieNode* newNode){
  int check = (currNode->title.compare(newNode->title));
  if(check < 0){
    if(currNode->right == NULL){
      currNode->right = newNode;
    }
    else{
      addNodeHelper(currNode->right, newNode);
    }
  }
  if(check > 0){
    if(currNode->left == NULL){
      currNode->left = newNode;
    }
    else{
      addNodeHelper(currNode->left, newNode);
    }
  }
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  //write your code
  MovieNode* newNode = new MovieNode(ranking, title, year, rating);
  if(root == NULL){
    root = newNode;
    return;
  }
  addNodeHelper(root, newNode);
}

// Traversing tree left then right
MovieNode* findMovieHelper(MovieNode* currNode, string title){
  if(currNode == NULL){
    return NULL;
  }
  if(currNode->title == title){
    return currNode;
  }
  MovieNode* found = findMovieHelper(currNode->left, title);
  if(found != NULL){
    return found;
  }
  return findMovieHelper(currNode->right, title);
}
 
void MovieTree::findMovie(string title) {
  //write your code
  MovieNode* temp = findMovieHelper(root, title);
  if(temp == NULL){
    cout << "Movie not found." << endl;
    return;
  }
  cout << "Movie Info:" << endl;
  cout << "==================" << endl;
  cout << "Ranking:" << temp->ranking << endl;
  cout << "Title  :" << temp->title << endl;
  cout << "Year   :" << temp->year << endl;
  cout << "rating :" << temp->rating << endl;
}

// Traversing tree left then right
MovieNode* queryMoviesHelper(MovieNode* currNode, float rating, int year){
  if(currNode == NULL){
    return NULL;
  }
  if(currNode->year >= year && currNode->rating >= rating && currNode != NULL){
    cout << currNode->title << "(" << currNode->year << ") " << currNode->rating << endl;
  }
  MovieNode* found = queryMoviesHelper(currNode->left, rating, year);
  if(found != NULL){
    return found;
  }
  return queryMoviesHelper(currNode->right, rating, year);
}

void MovieTree::queryMovies(float rating, int year) {
  //write your code
  if(root == NULL){
    cout << "Tree is Empty. Cannot query Movies" << endl;
    return;
  }
  cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
  queryMoviesHelper(root, rating, year);
}

// Traversing tree left then right
MovieNode* averageRatingHelper(MovieNode* currNode, float &total, int &count){
  if(currNode == NULL){
    return NULL;
  }
  if(currNode != NULL){
    total += currNode->rating;
    count ++;
  }
  MovieNode* found = averageRatingHelper(currNode->left, total, count);
  if(found != NULL){
    return found;
  }
  return averageRatingHelper(currNode->right, total, count);
}

void MovieTree::averageRating() {
  //write your code
  if(root == NULL){
    cout << "Average rating:0.0" << endl;
    return;
  }
  float total = 0.0;
  int count = 0;
  averageRatingHelper(root, total, count);
  float average = (total/count);
  cout << "Average rating:" << average << endl;
}

void printLevelNodeshelper(MovieNode* currNode, int level){
  if(currNode == NULL){
    return;
  }
  if(level == 0){
    cout << "Movie: " << currNode->title << " " << currNode->rating << endl;
    return;
  }
  else{
    printLevelNodeshelper(currNode->left, level-1);
    printLevelNodeshelper(currNode->right, level-1);
  }
}

void MovieTree::printLevelNodes(int level) {
  //write your code
  printLevelNodeshelper(root, level);
}