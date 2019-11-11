#ifndef BASE_CPP
#define BASE_CPP

#include "base.h"

planeta* insere_planetas(entrada ent)
{   
    planeta *vt_planeta;
    vt_planeta  = new planeta[ent.planetas+1];

    for(int i = 1; i<=ent.planetas; i++)
    {
        
        cin >> vt_planeta[i].tn_planeta;
        cin >> vt_planeta[i].n_planeta;
        vt_planeta[i].n_planeta.resize(ent.numero_caract);
        //cout << "loop \n";

    }


    return vt_planeta;
   // for(int i = 0; i<ent.planetas; i++){
   // cout << p_planeta[i].tn_planeta << " ";
   // cout << p_planeta[i].n_planeta << "\n";}
}

void listar_planetas(planeta* l_planeta, int plan)
{
    for (int i =1; i<= plan;i++)
    {
        //cout << i << " ";
        cout << l_planeta[i].tn_planeta << " ";
        cout << l_planeta[i].n_planeta << "\n";
    }
}

void mergeSort(planeta *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho;
    planeta* vetorTemp;
    if(posicaoInicio == posicaoFim) return;
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = new planeta [posicaoFim - posicaoInicio + 1];

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) {

            vetorTemp[k].tn_planeta = vetor[j].tn_planeta;
            vetorTemp[k].n_planeta = vetor[j].n_planeta;
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) {
                vetorTemp[k].tn_planeta = vetor[i].tn_planeta;
                //vetorTemp[k].n_planeta.clear();
                vetorTemp[k].n_planeta = vetor[i].n_planeta;
                i++;
                k++;
            }
            else {
                if (vetor[i].tn_planeta < vetor[j].tn_planeta) {
                    vetorTemp[k].tn_planeta = vetor[i].tn_planeta;
                    vetorTemp[k].n_planeta = vetor[i].n_planeta;
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k].tn_planeta = vetor[j].tn_planeta;
                    vetorTemp[k].n_planeta = vetor[j].n_planeta;
                    j++;
                    k++;
                }
            }
        }

    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i].tn_planeta = vetorTemp[i - posicaoInicio].tn_planeta;
        vetor[i].n_planeta = vetorTemp[i - posicaoInicio].n_planeta;
    }
    delete[] vetorTemp;    
}


void organiza_agenda(planeta* o_planetas, mes* o_mes, entrada o_entrada)
{
    int tam_vec = o_entrada.planetas;
    int o_aux =0, aux = 0, j=1, i=1;
    planeta* vetorTemp = new planeta[o_entrada.planetas+1];

    for (int p = 1; p <= o_entrada.planetas; p++)
    {
        vetorTemp[p].tn_planeta = o_planetas[p].tn_planeta;
        vetorTemp[p].n_planeta = o_planetas[p].n_planeta;
    }
    
    //listar_planetas(vetorTemp,o_entrada.planetas);

    while (tam_vec != 0)
    {
        while (tam_vec != 0 || j<=tam_vec)
        {
            if(o_aux + o_planetas[j].tn_planeta <= o_entrada.temp_min)
            {

                o_aux = o_aux+ o_planetas[j].tn_planeta;
                cout << i << " " <<  o_planetas[j].n_planeta << " " << o_planetas[j].tn_planeta << "\n";
                //cout << " remove \n";
                remover_planeta(o_planetas,j,tam_vec);
                tam_vec--;
                j--;
                aux++;
                //listar_planetas(o_planetas,tam_vec);
            }
            j++;
            if(j>tam_vec) break;
        }
        i++;
        //cout << "for externo mes : "<< i << " tempo gasto: " << o_aux <<" \n";
        o_aux = 0;
        j =1;
        
        if(tam_vec == 0) break;
        //cout << i << " ";
    }

    o_planetas = vetorTemp;
    delete[] vetorTemp;

    //listar_planetas(o_planetas,o_entrada.planetas);

}

void remover_planeta(planeta* r_planeta, int pos, int tam)
{
    for(int i =pos; i<tam;i++)
    {
        r_planeta[i].n_planeta = r_planeta[i+1].n_planeta;
        r_planeta[i].tn_planeta = r_planeta[i+1].tn_planeta;
    }

}








#endif