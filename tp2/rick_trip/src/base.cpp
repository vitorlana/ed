#ifndef BASE_CPP
#define BASE_CPP

#include "base.h"

void insere_planetas(entrada ent, planeta *p_planeta)
{   
    planeta vt_planeta[ent.planetas];

    for(int i = 0; i<ent.planetas; i++)
    {
        cin >> vt_planeta[i].tn_planeta;
        cin >> vt_planeta[i].n_planeta;
        vt_planeta[i].n_planeta.resize(ent.numero_caract);
    }

    p_planeta =  &vt_planeta;

    for(int i = 0; i<ent.planetas; i++)
    {
         cout << vt_planeta[i]->tn_planeta << " ";
         cout << vt_planeta[i]->n_planeta << "\n";
    }
}

#endif