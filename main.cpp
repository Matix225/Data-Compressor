#include <iostream>

using namespace std;

int main(){
    while(true){
        cout<<"Podaj nazwe lub sciezke do pliku: \n";

        string f_name;
        cin>>f_name;

        cout<<"Podaj alogrytm kompresji: \n";
        cout<<"1. Huffman\n";
        
        string alg_name;
        cin>>alg_name;
        if(alg_name == "Huffman"){
            //wywolaj algorytm
        }
        else{
            cout<<"Bledna nazwa!";
            continue;
        }
    }
    
    return 0;
}