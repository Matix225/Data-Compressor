#include <iostream>
#include "huffman.h"
#include <map>
using namespace std;

void huffman(ifstream &file, string op){ //algorythm entry point
    if(op == "Encode" || op == "encode")
        encode(file);
    else if(op == "Decode" || op == "decode"){
        //decode();
    }
    else{
        cout<<"Wrong operation. You can only encode or decode.\n";
        return;
    }
}
void encode(ifstream &file){
    map<char, int> tab; //stores sign and its number of occurance in file
    char sign;
    while(file.get(sign))
        tab[sign]++;


    //create single nodes for every character in file
    prior_q queue;
    for(auto p: tab){
        huff_node *node = (huff_node*)malloc(sizeof(huff_node));
        node->sign = p.first;
        node->occurance = p.second;
        node->l_child = node->r_child = NULL;
        queue.insert(node);
    }

    huff_node *a, *b, *tmp = NULL;
    while(queue.size > 1){
        a = queue.extract_min();
        b = queue.extract_min();

        tmp = (huff_node*)malloc(sizeof(huff_node));
        tmp->occurance = a->occurance + b->occurance;
        tmp->l_child = a;
        tmp->r_child = b;
        
        queue.insert(tmp);
    }
}