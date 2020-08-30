//Jennifer Khuu, jtk2eh, April 14, 2020
//tree.h

#ifndef TREE_H
#define TREE_H

#include "heap.h"
#include "huffmanNode.h"

using namespace std;

class tree{
 public:
  tree();
  ~tree();
  huffmanNode *root;
  heap huffTree(heap h);
  huffmanNode* merge(huffmanNode* a, huffmanNode* b);
  void setPrefix(huffmanNode* root, string s);
  void printPrefix(huffmanNode* root, string s);
};
#endif
