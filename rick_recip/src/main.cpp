#include <iostream>
#include "recip.h"
#include "lista.h"

using namespace std;

int main()
{

     
    Lista_celula entrada;
    
    Lista<int>* recipientes = new Lista<int>();
    

    while ((cin >> entrada.quantidade >> entrada.op))
    {
        if (entrada.op == 'i')
        {
            //Inserir recipiente
            recipientes->InsereOrdem(entrada.quantidade);
            cout << "i \n";
        }else if(entrada.op == 'r')
        {   
            //Remover recipiente
            cout << "r \n";
        }else if(entrada.op == 'p')
        {
            //Realizar medição
            recipientes->mostra();
            cout << "p \n";
        }else if (cin.eof())
        {
            exit;
        }else exit;
    }
    return 0;
}