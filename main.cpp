#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream plik;
    string f_name;
    string alg_name;

    while(true){
        cout<<"Podaj nazwe lub sciezke do pliku: \n";
        cin>>f_name;

        cout<<"Podaj alogrytm kompresji: \n";
        cout<<"1. Huffman\n";
        cin>>alg_name;

        if(alg_name == "Huffman"){
            //check if file was correctly open
            plik.open(f_name);
            if(!plik.is_open()){
                cout<<"Couldn't open a file!\n";
                continue;
            }

            plik.close();
        }
        else{
            cout<<"Wrong encoding!";
            continue;
        }
    }
    
    return 0;
}