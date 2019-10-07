#include <iostream>
#include "recip.h"
#include "lista.h"

using namespace std;

int main()
{

    Lista_celula entrada;

    Lista<int> *recipientes = new Lista<int>();

    while ((cin >> entrada.quantidade >> entrada.op))
    {
        if (entrada.op == 'i')
        {
            //Inserir recipiente
            recipientes->InsereFim(entrada.quantidade);
            //cout << "i \n";
        }
        else if (entrada.op == 'r')
        {
            //Remover recipiente
            recipientes->Remove(entrada.quantidade);
            //cout << "r \n";
        }
        else if (entrada.op == 'p')
        {
            //Realizar medição
            cout << resultado(entrada.quantidade, recipientes) << "\n";
            //recipientes->mostra();
            //cout << recipientes->tamanho_lista();
            //cout << "p \n";
        }
        else if (cin.eof())
        {
            return 0;
        }
        else if (entrada.op == 'm')
        {
            recipientes->mostra();
        }
        else
        {
            return 0;
        }
    }
    return 0;
}