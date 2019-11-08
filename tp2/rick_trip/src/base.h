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
    };

    planeta *Lista_planetas;

    void insere_planetas(entrada ent, planeta *p_planeta);
    
    struct mes 
    {
        int num_mes;
        planeta d_visitar;
    };






#endif