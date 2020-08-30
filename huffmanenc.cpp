//Jennifer Khuu, jtk2eh, April 14, 2020
//huffmanenc.cpp

#include "heap.h"
#include "tree.h"
#include "huffmanNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main (int argc, char **argv) {

    if ( argc != 2 ) {
        cout << "Input filename as only parameter" << endl;
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");

    if ( file == NULL ) {
        cout << "File '" << argv[1] << "' wasn't found" << endl;
        exit(2);
    }

    int freq[128];
    for(int i=0;i<128;i++){
      freq[i]=0;
    } 

    int tot_symb = 0;
    int ascii;
    char g;
    
    while ((g = fgetc(file)) != EOF ){
      ascii =(int) g;
      if(ascii < 128 && ascii > 31){
	freq[ascii]++;
	tot_symb++;
      }
    }

    huffmanNode* n;
    heap h;
    int d = 0;
    
    for(int i=1; i<128; i++){
      if(freq[i] > 0){
	n = new huffmanNode(freq[i],(char)i);
	h.insert(n);
	d++;
       }
    }

    tree* t;
    t = new tree();
    heap h2 = t->huffTree(h);
    t->printPrefix(h2.findMin(),"");
    
cout << "----------------------------------------" << endl;

    t->setPrefix(h2.findMin(),"");
    rewind(file);
    vector<huffmanNode*> v = h.getVector();
    int uncomp=0;
    int comp=0;
    while ((g = fgetc(file)) != EOF ){
      for(int i=1; i <= h.getSize(); i++){
          if(v[i]->getChar() == g){
	    comp += v[i]->getPrefix().size();
            cout << v[i]->getPrefix() << " ";
	  }
      }
    }
    cout << endl;
    fclose(file);

cout << "----------------------------------------" << endl;

     uncomp = tot_symb*8;
     double comp_ratio=(double)uncomp/comp;
     double cost=(double)comp/tot_symb;
     cout<<"This gives a compression ratio of "<<comp_ratio<<"."<<endl;
     cout<<"The cost of the Huffman tree is "<<cost<<" bits per character."<<endl;
    
    return 0;
}
