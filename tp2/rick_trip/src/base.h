#ifndef BASE_H
#define BASE_H

using namespace std;

#include <iostream>
#include <string>


    struct entrada
    {
        int temp_min;
        int planetas;
        int numero_caract;
    };

    struct planeta
    {
        int tn_planeta;
        string n_planeta;
        int num_mes;
    };

    struct mes 
    {
        int num_mes;
        planeta *d_visitar;
    };

    planeta* insere_planetas(entrada ent);
    void listar_planetas(planeta* l_planeta, int plan);
    void mergeSort(planeta *vetor, int posicaoInicio, int posicaoFim);
    planeta* organiza_agenda(planeta* o_planeta, int* o_mes, entrada o_entrada);
    void remover_planeta(planeta* r_planeta, int pos, int tam);
    void realiza_copia(planeta* o_planeta, planeta* c_planeta, int tam);

    void countSort(planeta* a, int size, int k);
    void radixSort(planeta* b, int r, int max);

    void listar_ordenado(planeta* lo_planetas, int meses, int planetas);


    
   






#endif