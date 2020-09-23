#include <stdlib.h>
#include <iostream>

#include "Nave.h"
#include "Fila.h"
#include "Pilha.h"

Nave *inicio=NULL, *final = NULL;

void Fila::addFila(int ident){
	Nave *temp = new Nave;
	if(temp==NULL)
		return;
	temp->_ident = ident;
	temp->prox = NULL;

	if (inicio ==NULL)
	{
		inicio = final = temp;
	}else
	{
		final->prox = temp;
		final = temp;
	}
}

void Fila::impFila(){
	if (inicio == NULL)
		return;

	Nave *temp = inicio;
	while (temp)
	{
		std::cout << temp->_ident << std::endl;
		temp = temp->prox;
	}
}

void Fila::impFilaInv(){

	Pilha impInversa;

	if (inicio == NULL)
		return;

	Nave *temp = inicio;
	while (temp)
	{
		impInversa.addPilha(temp->_ident);
		temp = temp->prox;
	}
	impInversa.impPilha();
	impInversa.~Pilha();
}

int Fila::remFila(){
	int temp = inicio->_ident;
	if (inicio == NULL)
		return EOF;
	if (inicio == final){	
		inicio = final = NULL;
		return temp;
	}else{
		inicio = inicio->prox;
		return temp;
	}
}

int Fila::busRemFila(int ident){
	int tempValue;
	if (inicio == NULL)
		return EOF;

	Nave *temp = inicio;

	if (temp->_ident == ident)
	{
		tempValue = temp->_ident;
		temp = temp->prox;
		inicio = temp;
		return tempValue;
	}

	while (temp)
	{
		if (temp->_ident == ident)
		{
			tempValue = temp->_ident;
			temp->_ident = temp->prox->_ident;
			temp->prox = temp->prox->prox;
			return tempValue;
			break;
		}
		temp = temp->prox;
	}
}
 
Fila ::~Fila()
{
	while (inicio != NULL)
	{
		Nave *temp = inicio;
		inicio = inicio->prox;
		delete temp;
	}
	final = NULL;
} 