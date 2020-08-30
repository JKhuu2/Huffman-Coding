//Jennifer Khuu, jtk2eh, April 14, 2020
//heap.h

// I modified this code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository


#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include "huffmanNode.h"

using namespace std;

class heap{
 public:
  heap();
  ~heap();
  void insert(huffmanNode* n);
  huffmanNode* findMin();
  void deleteMin();
  int getSize();
  void makeEmpty();
  bool isEmpty();
  vector<huffmanNode*> getVector();
 private:
  vector<huffmanNode*> myHeap;
  int currSize;
};
#endif
