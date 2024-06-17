#ifndef auxiliares_h
#define auxiliares_h

#include <cstring>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void clear(){
	printf("\033c");
}


void menu(const vector<string>& textos, bool numerar=false, bool clear_console=true){
    if(clear_console){clear();}
    for(int i=0; i<textos.size(); i++){
        if(numerar){
            cout << "[" << i+1 << "] ";
        }
        cout << "----- " << textos[i] << " -----" << endl;
    }
}

int escolha(){
    int escolha;
    cout << "Digite sua escolha: ";
    cin >> escolha;
    cin.ignore();
    return escolha;
}


#endif