#include "Fila.h"

void Fila::addFila(int ident){
	Nave *temp = new Nave;
	if(temp==NULL)
		return;
	temp->_ident = ident;
	temp->prox = NULL;

	if (inicio == NULL)
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

	
	Nave *temp = inicio;
	Pilha impInversa;

	if (inicio == NULL)
		return;

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

void Fila::busRemFila(int ident){
	Nave *temp = inicio;

	if (inicio == NULL)
		std::cout << " 1 ";
	return;

	if (temp->_ident == ident)
	{
		std::cout << " 2 ";
		temp = temp->prox;
		inicio = temp;
		return;
	}

	while (temp)
	{
		if (temp->_ident == ident)
		{
		std::cout << " inside ";

			temp->_ident = temp->prox->_ident;
			temp->prox = temp->prox->prox;
			break;
		}
		std::cout << " 3 ";

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