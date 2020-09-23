#ifndef __PILHA_CLASS__
#define __PILHA_CLASS__

#include <stdlib.h>
#include <iostream>

#include "Nave.h"
#include "Fila.h"

class Pilha
{
	public:

	Nave *topo;
	Pilha() { topo = NULL; }

	void addPilha(int ident);
	int remPilha();
	void impPilha();
	void impPilhaInv();
	~Pilha();
};

#endif
