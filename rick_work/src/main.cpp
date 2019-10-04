//Bibliotecas Padrões

#include <iostream>

//Funções Específicas

#include "dados.h"

using namespace std;

int main()
{

    Lista_celula* lista;
    
    valor_celula celula_entrada;
    lista = cria_lista();

    while ((cin >> celula_entrada.quantidade >> celula_entrada.operacao))
    {
        if (celula_entrada.operacao == 'i') //Inserir recipiente
        {
            adiciona_celula(lista, celula_entrada);
        }else if(celula_entrada.operacao == 'r')
        {   //Remover recipiente
            remove_celula(lista, celula_entrada.quantidade);
        }else if(celula_entrada.operacao == 'p')
        {
            //Realizar medição
            //verifica_lista(lista);
        }else if (cin.eof())
        {
            exit;
        }else exit;
    }

    libera_lista(lista);
    return 0;
}