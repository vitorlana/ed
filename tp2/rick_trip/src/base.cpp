#ifndef BASE_CPP
#define BASE_CPP

#include "base.h"

planeta* insere_planetas(entrada ent)
{   
    planeta *vt_planeta;
    vt_planeta  = new planeta[ent.planetas];

    for(int i = 0; i<ent.planetas; i++)
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
    for (int i =0; i< plan;i++)
    {
        //cout << i << " ";
        cout << l_planeta[i].tn_planeta << " ";
        cout << l_planeta[i].n_planeta << "\n";
    }
}

void mergeSort(planeta *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho;
    planeta *vetorTemp;
    if(posicaoInicio == posicaoFim) return;
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (planeta *) malloc(sizeof(planeta) * (posicaoFim - posicaoInicio + 1));

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
    free(vetorTemp);
}

void organiza_agenda(planeta* o_planetas, mes* o_mes, entrada o_entrada)
{
    int tam_vec = o_entrada.planetas;
    int o_aux = 0;
    o_mes  =  new mes[o_entrada.planetas];


    for (int i = 1; i <= o_entrada.planetas; i++) //melhorar isso
    {
        //cout << i << " ";
        for (int j = 0; j <= tam_vec; j++)
        {
            //cout << " aif: "<< o_aux << " " << o_planetas[j].tn_planeta << " " << o_entrada.temp_min << "\n";   
            //cout << o_entrada.temp_min << " " << tam_vec <<"\n";
            //cout << j << " \n";
            if(o_aux + o_planetas[j].tn_planeta <= o_entrada.temp_min)
            {
                //cout << " a: "<< o_aux << " " << o_planetas[j].tn_planeta << " " << o_entrada.temp_min << "\n";
                o_aux =  o_aux + o_planetas[j].tn_planeta;
                //cout << " d: "<< o_aux << " " << o_planetas[j].tn_planeta << " " << o_entrada.temp_min << "\n";
                cout << i << " " <<  o_planetas[j].tn_planeta << " " << o_planetas[j].n_planeta << "\n";
                tam_vec = remover_planeta(o_planetas,j,tam_vec);
                //listar_planetas(o_planetas,tam_vec);
            }
        }
        o_aux = 0;
        //cout << o_aux <<  "\n";
        
    }
}

int remover_planeta(planeta* r_planeta, int pos, int tam)
{
    for(int i =pos; i<tam;i++)
    {
        r_planeta[i].n_planeta = r_planeta[i+1].n_planeta;
        r_planeta[i].tn_planeta = r_planeta[i+1].tn_planeta;
    }
    return tam-1;
}








#endif