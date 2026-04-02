#pragma once
#include <fstream>
using namespace std;

struct huff_node{
    long long occurance;
    char sign;
    huff_node *l_child;
    huff_node *r_child;
};
struct prior_q{
    //priority queue stores huffman nodes in non_decreasing order.
    //In each step we will take 2 smallest nodes(n1, n2) and create a new
    //node with occurence = n1.oc + n2.oc and then ad him to queue

    huff_node **tab;
    int size;
    int capacity;

    prior_q(){
        size = 0;
        capacity = 1;
        tab = (huff_node**)malloc((capacity + 1) * sizeof(huff_node*));
    }
    void expand(){
        huff_node **new_tab = (huff_node**)malloc((2*capacity + 1) * sizeof(huff_node*));
        for(int i = 1; i <= size; i++)
            new_tab[i] = tab[i];
        capacity *= 2;
        
        free(tab);
        tab = new_tab;
    }
    void insert(huff_node *node){
        if(size == capacity)
            expand();
        size++;
        tab[size] = node;

        shift_up();
        return;
    }
    void shift_up(){ //build min heap
        for(int i = size; i > 1;){
            if(tab[i]->occurance < tab[i/2]->occurance){
                swap(tab[i], tab[i/2]);
                i = i / 2;
            }
            else    
                break;
        }
    }
    void shift_down(){
        for(int i = 1; i <= size;){
            int swap_ind = i;
            if( (2*i <= size) && (tab[i] > tab[2*i]) )
                swap_ind = 2*i;

            if( (2*i + 1 <= size) && (tab[i] > tab[2*i+1]) )
                swap_ind = 2*i + 1;

            if(swap_ind == i)
                return;
            else{
                swap(tab[i], tab[swap_ind]);
                i = swap_ind;
            }
        }
    }
    huff_node* extract_min(){
        huff_node *tmp;
        swap(tab[1], tab[size]);
        
        tmp = tab[size];
        size--;
        shift_down();

        return tmp;
    }
};
void huffman(ifstream &file, string op);
void encode(ifstream &file);
void decode(ifstream &file);