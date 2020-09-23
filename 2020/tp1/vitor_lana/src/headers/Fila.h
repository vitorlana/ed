#ifndef __FILA_CLASS__
#define __FILA_CLASS__

#include <stdlib.h>
#include <iostream>

#include "Nave.h"
#include "Pilha.h"

class Fila{

	public:
	Nave *inicio, *final;
	Fila() { inicio = final = NULL; }

	void addFila(int ident);
	int remFila();
	void impFila();
	void impFilaInv();
	void busRemFila(int ident);
	~Fila();
};

#endif
