//Jennifer Khuu, jtk2eh, April 14, 2020
//huffmanNode.h

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <string>
#include <iostream>
using namespace std;

class huffmanNode {
 public:
  huffmanNode();
  huffmanNode(int freq, char ch);
  ~huffmanNode();
  huffmanNode *left, *right;
  int frequency;
  char character;
  string prefix;
  int getFreq() const;
  char getChar();
  string getPrefix();
  bool operator<(const huffmanNode& n) const;
};
#endif
