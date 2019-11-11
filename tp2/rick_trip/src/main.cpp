#include <iostream>
#include "base.h"

using namespace std;

int main()
{   
    entrada e_entrada;
    planeta* lista_planetas = new planeta;
    mes* meses =  new mes;

    cin >> e_entrada.temp_min >> e_entrada.planetas >> e_entrada.numero_caract;

    lista_planetas = insere_planetas(e_entrada);
    //cout << "saiu";
    //cout << lista_planetas[e_entrada.planetas].n_planeta;

    //listar_planetas(lista_planetas, e_entrada.planetas);   

    mergeSort(lista_planetas,1,e_entrada.planetas);
    
    //listar_planetas(lista_planetas, e_entrada.planetas);   


    organiza_agenda(lista_planetas,meses,e_entrada);

    //listar_planetas(lista_planetas, e_entrada.planetas);   


    return 0;
}