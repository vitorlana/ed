#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;

template <class T>

class Lista
{
private:
    //Declaração da struct 'nó'
    //T é um tipo genérico que será definido no momento de instanciar um objeto do tipo Lista
    //prox é um ponteiro para o próximo elemento da lista
    struct no
    {
        T x;
        struct no *prox;
    };
    //O nó que sera instanciado no momento de inserção na lista
    no *novo;
    //O nó inicial da lista
    no *lista;

public:
    //Construtor da classe
    Lista()
    {
        //Instancia o nó inicial da lista
        lista = new no;
        lista->prox = NULL;
    }

    //Método para inserção no final da lista
    void InsereFim(T x)
    {
        if (Lista::existe(x))
        {
            return;
        }

        novo = new no;
        novo->x = x;
        novo->prox = NULL;
        //Utilizamos um nó auxiliar para não corrompermos a lista original ao percorrê-la
        no *aux = lista;

        while (aux->prox)
        {
            aux = aux->prox;
        }

        aux->prox = novo;
    }

    void Remove(T x)
    {
        no *ant = new no;
        no *aux;

        aux = lista;
        int i = 0;

        while (aux->x != x)
        {
            //cout << i++;
            ant = aux;
            aux = aux->prox;
        }
        if (x == aux->x)
        {

            ant->prox = aux->prox;
            free(aux);
            //cout <<ant->x << " "<< aux->x << " " << aux->prox->x <<" ";
            return;
        }
    }

    
    //Método que verifica se determinado elemento existe na lista
    bool existe(T x)
    {
        no *aux = lista;

        while (aux->prox)
        {
            if (aux->prox->x == x)
                return true;
            aux = aux->prox;
        }

        return false;
    }

    //Método para retornar um elemento em determinada posição na lista (começando em 0)
    T get(int indice)
    {
        no *aux = lista;
        int i = 0;

        while (i <= indice && aux->prox)
        {
            aux = aux->prox;
            i++;
        }

        return aux->x;
    }

    //Mostra
    void mostra()
    {
        cout << endl;

        if (lista->prox == NULL)
        {
            cout << "Lista vazia";
            return;
        }

        no *aux = lista;

        while (aux->prox)
        {
            cout << aux->prox->x << " ";
            aux = aux->prox;
        }
        cout << "\n";
    }

    int tamanho_lista()
    {
        int count = 0;

        if (lista->prox == NULL)
        {
            return 0;
        }

        no *aux = lista;

        while (aux->prox)
        {
            count++;
            aux = aux->prox;
        }

        return count;
    }
};

#endif