#include <iostream>
#include "huffman.h"
#include <map>
using namespace std;

map<char, string> codes;

void build_codes(huff_node *root, string code = ""){
    if(root->l_child == NULL && root->r_child == NULL){
        if(code == "") //file contains only 1 unique character
            codes[root->sign] = "0";
        else
            codes[root->sign] = code;
        
        return;
    }

    build_codes(root->l_child, code + '0');
    build_codes(root->r_child, code + '1');
}
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

    if(tab.empty()){//File was empty. There is nothing to compress.
        cout<<"You can't compress empty file!\n";
        return;
    }

    //create single nodes for every character in file
    prior_q queue;
    for(auto p: tab){
        huff_node *node = (huff_node*)malloc(sizeof(huff_node));
        node->sign = p.first;
        node->occurance = p.second;
        node->l_child = node->r_child = NULL;
        queue.insert(node);
    }

    //create huffman tree
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

    huff_node *root = queue.tab[1];
    codes.clear(); //clear code map after last encode
    build_codes(root);

    file.clear(); //reset all state bits (EOF etc.)
    file.seekg(0); //go back to the begining of the file

    char s; 
    unsigned char buff = 0;
    int bit_count = 0;
    ofstream compF("compressed.huff", ios::binary);
    if(!compF.good())
        return;

    while(file.get(s)){
        string code = codes[s];
        for(int i = 0; i < (int)code.size(); i++){
            if(code[i] == '0')
                buff = buff << 1;
            else{
                buff = buff << 1;
                buff = buff | 1;
            }

            bit_count++;
            if(bit_count == 8){
                compF.write((char*)&buff, 1);
                buff = 0;
                bit_count = 0;
            }
        }
    }
    if(bit_count > 0){
        buff <<= (8 - bit_count);
        compF.write((char*)&buff, 1);
    }
    compF.close();
}