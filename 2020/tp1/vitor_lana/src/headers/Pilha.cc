#include "Pilha.h"

void Pilha::addPilha(int ident){
	struct Nave *novaNave = new Nave;
	//preencher dados
	novaNave->_ident = ident;
    novaNave->prox = topo;
    topo = novaNave;
}

int Pilha::remPilha(){
    int temp = topo->_ident;
    if (topo == NULL)
        return EOF;
    topo = topo->prox;
    return temp;
}

void Pilha::impPilha(){

    if (topo==NULL){
        return;
    }
    
    struct Nave *temp = topo;
    while (temp != NULL){
        std::cout << temp->_ident << std::endl;
        temp = temp->prox;
    }
    std::cout << std::endl;
}

void Pilha::impPilhaInv(){

    Fila impInversa;

    if (topo==NULL){
        return;
    }
    struct Nave *temp = topo;
    while (temp != NULL){
        impInversa.addFila(temp->_ident);
        temp = temp->prox;
    }
    impInversa.impFila();
    impInversa.~Fila();
}

Pilha ::~Pilha(){
	while (topo != NULL)
	{
		Nave *temp = topo;
		topo = topo->prox;
		delete temp;
	}
}