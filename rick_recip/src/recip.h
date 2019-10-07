#ifndef RECIP_H
#define RECIP_H

#include "lista.h"

struct Lista_celula
{
    int quantidade;
    char op;
};

int resultado(int Quant_esp, Lista<int> *original);
int resultado(int Quant_esp, Lista<int> *original, Lista<int> *nova, int oper);

#endif