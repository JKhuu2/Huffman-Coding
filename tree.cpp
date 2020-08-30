//Jennifer Khuu, jtk2eh, April 14, 2020
//tree.cpp

#include "tree.h"

using namespace std;

tree::tree(){
  root=NULL;
}

tree::~tree(){
  delete root;
}

//huffTree
heap tree::huffTree(heap h){
  while(h.getSize()>1){
    huffmanNode* a = h.findMin();
    h.deleteMin();
    huffmanNode* b = h.findMin();
    h.deleteMin();
    huffmanNode* m = merge(a,b);
    h.insert(m);
  }
  return h;
}

//merge

huffmanNode* tree::merge(huffmanNode* a, huffmanNode* b) {
  int a_freq = a->getFreq();
  int b_freq = b->getFreq();
  int total_freq = a_freq + b_freq;
  huffmanNode* m = new huffmanNode(total_freq, '0');
  m->left = a;
  m->right = b;
  return m;
}

//setPrefix

void tree::setPrefix(huffmanNode *root, string s){
  if (root->left==NULL && root->right==NULL){
    root->prefix=s;
  }
  if (root->left){
    setPrefix(root->left, s+"0");
  }
  if (root->right) {
    setPrefix(root->right, s+"1");
  }
}

//printPrefix
    
void tree::printPrefix(huffmanNode *root, string s){
  if (root->left == NULL && root->right == NULL){
    cout<<root->character<<"  "<<s<<endl;
  }
  if (root->left){
    printPrefix(root->left, s +"0");
  }
  if (root->right) {
    printPrefix(root->right, s +"1");
  }
}
