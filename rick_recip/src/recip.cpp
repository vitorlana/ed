#include <iostream>
#include "recip.h"



int resultado(int Quant_esp, Lista<int>* recipientes)
{
    if (recipientes->existe(Quant_esp))
    {
        
        return 1;
    }else
    {
        return resultado(Quant_esp,recipientes,recipientes,1);
    }
    
   
}


int resultado(int Quant_esp, Lista<int>* original, Lista<int>* nova, int oper)
{       
        //original->mostra();
        oper++; 
        Lista<int>* nova_lista = new Lista<int>();
        
        for(int j = 0; j<original->tamanho_lista();j++)
        {

            //cout << original->tamanho_lista() << " ";
            //cout <<"\n j " <<j << "\n";
        
                for (int i = 0; i<=nova->tamanho_lista();i++)
                {   
                    nova_lista->InsereFim(original->get(j) + nova->get(i));
                    //cout <<original->get(j) << " + " <<nova->get(i) << " = " <<original->get(j) + nova->get(i) << " \n";
                    
                    if (original->get(j) - nova->get(i) > 0)
                    {
                        nova_lista->InsereFim(original->get(j) - nova->get(i));
                    //cout <<original->get(j) << " - " <<nova->get(i) << " = " <<original->get(j) + nova->get(i) << " \n";
                    }

                    //cout <<"i " <<i << " ";
                }
           

            //cout << nova_lista->tamanho_lista() << "\n";
        }

        //cout <<"\n qt: "<< Quant_esp << " lista: ";
        //original->mostra();
        //nova_lista->mostra();
        
        if (nova_lista->existe(Quant_esp))
        {
            //free (nova_lista);
            //free (nova);
            return oper;    
        }
        else
        {   
            resultado(Quant_esp,original,nova_lista,oper);
        } 
    //cout << recipientes->tamanho_lista();
    //return oper;

}
