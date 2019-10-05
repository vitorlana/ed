#ifndef DADOS_H
#define DADOS_H

struct valor_celula
{
    int quantidade;
    char operacao;
};

typedef struct lista_celula* Lista_celula;

Lista_celula* cria_lista();
bool lista_vazia(Lista_celula* lista);
void libera_lista(Lista_celula* lista);
int adiciona_celula(Lista_celula* lista, valor_celula Celula);
int adiciona_celula_s_ord(Lista_celula* lista, valor_celula Celula);
void verifica_lista(Lista_celula* lista);
void remove_celula(Lista_celula* lista, int a_quantidade);
int realiza_medicao(Lista_celula* lista,int a_quantidade);




#endif