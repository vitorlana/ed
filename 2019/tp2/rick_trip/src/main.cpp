#include <iostream>
#include "base.h"

using namespace std;

int main()
{   
    entrada e_entrada;
    planeta* lista_planetas = new planeta;
    int* meses =  new int;

    cin >> e_entrada.temp_min >> e_entrada.planetas >> e_entrada.numero_caract;

    lista_planetas = insere_planetas(e_entrada);

    //listar_planetas(lista_planetas,e_entrada.planetas);


    mergeSort(lista_planetas,1,e_entrada.planetas);

    //listar_planetas(lista_planetas,e_entrada.planetas);

    
    lista_planetas = organiza_agenda(lista_planetas,meses,e_entrada);
    
    radixSort(lista_planetas,(int)(((sizeof(lista_planetas[0].n_planeta) * e_entrada.planetas))/sizeof(lista_planetas[0].n_planeta)),e_entrada.planetas);


    //listar_planetas(lista_planetas,e_entrada.planetas);
   
    mergeSort_mes(lista_planetas,1,e_entrada.planetas);

    listar_planetas(lista_planetas,e_entrada.planetas);

    //listar_ordenado(lista_planetas,*meses,e_entrada.planetas); 

    return 0;
}