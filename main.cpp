#include <iostream>
#include "huffman.h"
using namespace std;

int main(){
    ifstream plik;
    string f_name;
    string alg_name;
    string op;

    while(true){
        cout<<"Enter file name or path: ";
        cin>>f_name;
        
        plik.open(f_name);
        if(plik.good()){
            cout<<"\nChoose algorythm: ";
            cout<<"\n1. huffman\n";
            cin>>alg_name;

            cout<<"\nWhat you want to do: ";
            cout<<"\n1. encode";
            cout<<"\n2. decode\n";
            cin>>op;

            if(alg_name == "huffman")
                huffman(plik, op);
            else
                cout<<"\nWrong algorythm!";
        }
        else
            cout<<"\nFile doesn't exist!";
        
        cout<<"\n";
    }
    
    return 0;
}