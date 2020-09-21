//Implementacao da pilha
#include <stdlib.h>
#include <iostream>
#include "nave.h"

using namespace std;

struct Nave
{
    int _ident;
    Nave *prox;
};
Nave *topo;

void _Nave::addNave(int ident){
    struct Nave *novaNave =  new Nave;
    //preencher dados
    novaNave->_ident = ident;
    novaNave->prox = topo;
    topo = novaNave;
}

void _Nave::remNave(){
    if (topo == NULL){
        return;
    }
    cout << "nave " << topo->_ident <<" removida" << endl;    
    topo = topo->prox;
}

void _Nave::imprimeNave(){
    if (topo==NULL){
        return;
    }
    struct Nave *temp = topo;
    while (temp != NULL){
        cout << temp->_ident << endl;
        temp = temp->prox;
    }
    cout << endl;
}