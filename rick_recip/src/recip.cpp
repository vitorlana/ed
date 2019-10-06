#include <iostream>
#include "recip.h"



int resultado(int Quant_esp, Lista<int>* atual, int oper)
{
    while (!atual->existe(Quant_esp))
    {   
        int indice = 0;
        Lista<int>* nova_lista = new Lista<int>();
        
     
        for (int i = 0; !nova_lista->existe(Quant_esp); i++)
        {
            nova_lista->InsereOrdem(atual->get(indice) + atual->get(i));
            cout << atual->get(indice) + atual->get(i) << " ";
            if (atual->get(indice) - atual->get(i) > 0)
            {
                nova_lista->InsereOrdem(atual->get(indice) - atual->get(i));
                cout << atual->get(indice) - atual->get(i) << " ";
            }
        }

        indice++;
        
        nova_lista->mostra();
        
        oper++;
        resultado(Quant_esp,nova_lista,oper);

    }   
    
    return oper;
}

