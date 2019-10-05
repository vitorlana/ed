#include <iostream>
using namespace std;
#include "dados.h"


struct lista_celula{
    valor_celula Celula;
    lista_celula *prox;
};

typedef struct lista_celula Elem_op;


Lista_celula* cria_lista()
{
    Lista_celula* lista = (Lista_celula*) new Lista_celula;
    if (lista != NULL)
        *lista = NULL;

    //cout << "Lista Criada \n";

    return lista;
};

bool lista_vazia(Lista_celula* lista)
{
    if(lista == NULL) return true;
    if(*lista == NULL) return true;
    return false;
};

void libera_lista(Lista_celula* lista)
{
    if(lista != NULL)
    {
        Elem_op* celula_op;
        while ((*lista) != NULL)
        {
            celula_op = *lista;
            *lista = (*lista)->prox;
            free(celula_op);
        }
        free(lista);
    }
    //cout << "Lista liberada \n";
};


int adiciona_celula(Lista_celula* lista, valor_celula Celula_op)
{
    if(lista == NULL) return 0;

    Elem_op *celula_op = (Elem_op*) new Elem_op;

    if(celula_op == NULL) return 0;

    celula_op->Celula = Celula_op;
    if(lista_vazia(lista))
    {
        celula_op->prox = (*lista);
        *lista = celula_op;
        //cout << "Celula Inserida V \n";
        return 1;    
    }else
    {
        Elem_op *ant, *atual = *lista;

        //cout << atual->Celula.quantidade <<" "<<Celula_op.quantidade <<"\n";

        while (atual != NULL && atual->Celula.quantidade >= Celula_op.quantidade)
        {
            if (atual->Celula.quantidade == Celula_op.quantidade)
            {
                //cout << "nao inserido \n" ; 
                return 0;
            }
            ant = atual;
            atual = atual->prox;
            //cout << "Entrou no while \n";
        }
        if (atual == *lista)
        {
            celula_op->prox = (*lista);
            *lista = celula_op;
            //cout << "Inicio da lista if \n";
        }else
        {
            celula_op->prox = ant->prox;
            ant->prox = celula_op;
            //cout << "Insere no meio \n";
        }
        return 1;   
    }
    
};

void verifica_lista(Lista_celula* lista) //verificar pq da dando segmentation faut 
{
    int count;
    if(lista == NULL) exit;
    Elem_op* celula_op = *lista;

    while (celula_op != NULL)
    {
        cout << celula_op->Celula.quantidade  <<" "<< celula_op->Celula.operacao << "\n";
        celula_op = celula_op->prox;
        count++;
    }
    
    //cout << "Fim Lista " << count << "\n";
};

void remove_celula(Lista_celula* lista, int quantidade)
{
    if(lista == NULL) exit;
    Elem_op *ant, *celula_op = *lista;
    while (celula_op != NULL && celula_op->Celula.quantidade != quantidade)
    {
        ant = celula_op;
        celula_op = celula_op->prox;
    }
    if(celula_op == NULL) exit;

    if(celula_op == *lista)
    {
        *lista = celula_op->prox;    
    }else
    {
        ant->prox = celula_op->prox;        
    }
    free(celula_op);
    
    //cout << "Removida\n";
};

int realiza_medicao(Lista_celula* lista, int a_quantidade)
{
       
};
