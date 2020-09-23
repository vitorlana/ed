#ifndef __FILA_CLASS__
#define __FILA_CLASS__

#include "Nave.h"
#include "Fila.h"

class Fila{
	public:
	void addFila(int ident);
	int remFila();
	void impFila();
	void impFilaInv();
	int busRemFila(int ident);
	~Fila();
};

#endif
