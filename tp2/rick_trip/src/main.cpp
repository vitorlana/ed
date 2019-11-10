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
    //cout << lista_planetas[0].n_planeta;

    mergeSort(lista_planetas,0,e_entrada.planetas-1);

    organiza_agenda(lista_planetas,meses,e_entrada);

    //listar_planetas(lista_planetas, e_entrada.planetas);   


    return 0;
}