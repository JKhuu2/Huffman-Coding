//Jennifer Khuu, jtk2eh, April 14, 2020
//heap.cpp

// I modified this code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository


#include "heap.h"

using namespace std;

heap::heap():myHeap(101){
  currSize=0;
  }

heap::~heap(){
  makeEmpty();
}

void heap::insert(huffmanNode* n){
  int hole = ++currSize;
  
  //double size if currSize==myHeap.size()-1
  if(currSize==myHeap.size()-1) {
    myHeap.resize(myHeap.size()*2);
  }

  //while haven't run off top and value<parent
  for(; (hole>1) && (*n<*myHeap[hole/2]);hole/=2) {
    myHeap[hole] = myHeap[hole/2];
  }
  // correct position found! insert at that spot
  myHeap[hole] = n;
}

void heap::deleteMin(){
  //make sure heap isn't empty
  if(isEmpty()) {
    cout << "can't findMin() because there's an empty heap" << endl; 
  }
  myHeap[1] = myHeap[currSize--];
  int hole = 1;
  huffmanNode* n = myHeap[hole];
  int child;

  while(currSize>=hole*2) {
    child = hole*2;
    if((*(myHeap[child+1])) < (*(myHeap[child])) && (child != currSize)) {
      child++;
    }
    if((*myHeap[child]) < (*n)) {
      myHeap[hole] = myHeap[child];
      hole = child;			
    }
    else 
      break;   
  }
  // correct position found! insert at that spot
  myHeap[hole] = n;
}
    
huffmanNode* heap::findMin(){
  return myHeap[1];
}

int heap::getSize(){
  return currSize;
}

void heap::makeEmpty() {
  currSize=0;
  myHeap.clear();
}

bool heap::isEmpty() {
  return currSize==0;
}

vector<huffmanNode*> heap::getVector(){
  return myHeap;
}
