//Jennifer Khuu, jtk2eh, April 14, 2020
//huffmanNode.cpp

#include "huffmanNode.h"
using namespace std;

huffmanNode::huffmanNode(){
  frequency=1;
  character='\0';
  left=NULL;
  right=NULL;
  prefix="";
}

huffmanNode::huffmanNode(int freq, char ch){
  frequency = freq;
  character = ch;
  left=NULL;
  right=NULL;
  prefix="";
}

huffmanNode::~huffmanNode(){
  delete left;
  delete right;
}

int huffmanNode::getFreq() const{
  return frequency;
}

char huffmanNode::getChar(){
  return character;
}

string huffmanNode::getPrefix(){
  return prefix;
}

bool huffmanNode::operator<(const huffmanNode& n) const{
  return(this->getFreq()<n.getFreq());
}
