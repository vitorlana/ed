#include <iostream>
#include "base.h"

using namespace std;

int main()
{   
    entrada e_entrada;
    planeta *lista_planetas = new planeta;

    cin >> e_entrada.temp_min >> e_entrada.planetas >> e_entrada.numero_caract;
    
    insere_planetas(e_entrada, lista_planetas);

    
    

    return 0;
}