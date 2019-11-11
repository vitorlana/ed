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
        vt_planeta[i].num_mes = 0;
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
        cout << l_planeta[i].num_mes << " ";
        cout << l_planeta[i].tn_planeta << " ";
        cout << l_planeta[i].n_planeta << "\n";
    }
}

void mergeSort(planeta *vetor, int posicaoInicio, int posicaoFim) {
    if(posicaoInicio == posicaoFim) return;
    //int i, j, k, metadeTamanho;
    planeta* vetorTemp;
    int metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);
    int i=posicaoInicio,j=metadeTamanho+1;
    int l=posicaoFim-posicaoInicio+1;

    

    //i = posicaoInicio;
    //j = metadeTamanho + 1;
    //k = 0;
    vetorTemp = new planeta [posicaoFim - posicaoInicio + 1];




    for (int k=0;k<l;k++){
        if (j>posicaoFim || (i<=metadeTamanho && vetor[i].tn_planeta<=vetor[j].tn_planeta)){
            vetorTemp[k].tn_planeta=vetor[i].tn_planeta;
            vetorTemp[k].n_planeta=vetor[i].n_planeta;

            i++;
        }
        else{
            vetorTemp[k].tn_planeta=vetor[j].tn_planeta;
            vetorTemp[k].n_planeta=vetor[j].n_planeta;
            j++;
        }
    }
    for (int k=0,i=posicaoInicio;k<l;k++,i++){
        vetor[i].tn_planeta=vetorTemp[k].tn_planeta;
        vetor[i].n_planeta=vetorTemp[k].n_planeta;
    }
    delete[] vetorTemp;







//    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
//        if (i == metadeTamanho + 1 ) {
//
//            vetorTemp[k].tn_planeta = vetor[j].tn_planeta;
//            vetorTemp[k].n_planeta = vetor[j].n_planeta;
//            j++;
//            k++;
//        }
//        else {
//            if (j == posicaoFim + 1) {
//                vetorTemp[k].tn_planeta = vetor[i].tn_planeta;
//                //vetorTemp[k].n_planeta.clear();
//                vetorTemp[k].n_planeta = vetor[i].n_planeta;
//                i++;
//                k++;
//            }
//            else {
//                if (vetor[i].tn_planeta < vetor[j].tn_planeta) {
//                    vetorTemp[k].tn_planeta = vetor[i].tn_planeta;
//                    vetorTemp[k].n_planeta = vetor[i].n_planeta;
//                    i++;
//                    k++;
//                }
//                else {
//                    vetorTemp[k].tn_planeta = vetor[j].tn_planeta;
//                    vetorTemp[k].n_planeta = vetor[j].n_planeta;
//                    j++;
//                    k++;
//                }
//            }
//        }
//
//    }
//    for(i = posicaoInicio; i <= posicaoFim; i++) {
//        vetor[i].tn_planeta = vetorTemp[i - posicaoInicio].tn_planeta;
//        vetor[i].n_planeta = vetorTemp[i - posicaoInicio].n_planeta;
//    }
//    delete[] vetorTemp;    
}


planeta* organiza_agenda(planeta* o_planetas, int* o_mes, entrada o_entrada)
{
    int tam_vec = o_entrada.planetas;
    int o_aux =0, aux = 0, j=1, i=1;
    planeta* vetorTemp = new planeta[o_entrada.planetas+1];

    //for (int p = 1; p <= o_entrada.planetas; p++)
    //{
    //    vetorTemp[p].tn_planeta = o_planetas[p].tn_planeta;
    //    vetorTemp[p].n_planeta = o_planetas[p].n_planeta;
    //}
    
    //listar_planetas(vetorTemp,o_entrada.planetas);

    while (tam_vec != 0)
    {
        o_aux = 0;
        j =1;
        while (tam_vec != 0)
        {
            if(o_aux + o_planetas[j].tn_planeta <= o_entrada.temp_min)
            {
                aux++;
                o_aux = o_aux + o_planetas[j].tn_planeta;
                //o_aux = o_aux + o_planetas[j].tn_planeta;
                //cout << i << " " <<  o_planetas[j].n_planeta << " " << o_planetas[j].tn_planeta << "\n";
                //cout << " remove \n";

                vetorTemp[aux].num_mes = i;
                vetorTemp[aux].n_planeta = o_planetas[j].n_planeta;
                vetorTemp[aux].tn_planeta = o_planetas[j].tn_planeta;

                remover_planeta(o_planetas,j,tam_vec);
                tam_vec--;
                j--;
                
                //listar_planetas(o_planetas,tam_vec);
            }
            j++;
            if(j>tam_vec) break;
        }
        i++;
        //cout << "for externo mes : "<< i << " tempo gasto: " << o_aux <<" \n";
        if(tam_vec == 0) break;
        
    }
    //cout <<" " << aux << " ";
    delete[] o_planetas;
    *o_mes = i-1;
    return vetorTemp;
    



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

void countSort(planeta* a, int size, int k){
    size++;
    planeta *b = NULL;
    int *c = NULL;
    b = new planeta[size];
    //b = new string[size];
    c = new int[257];



    for (int i = 0; i <257; i++){
        c[i] = 0;
        //cout << c[i] << "\n";
    }
    for (int j = 0; j <size; j++){   
        c[k < a[j].n_planeta.size() ? (int)(unsigned char)a[j].n_planeta[k] + 1 : 0]++;            //a[j].n_planeta is a string
        //cout << c[j] << endl;
    }

    for (int f = 1; f <257; f++){
        c[f] += c[f - 1];
    }

    for (int r = size - 1; r >= 0; r--){
        b[c[k < a[r].n_planeta.size() ? (int)(unsigned char)a[r].n_planeta[k] + 1 : 0] - 1].n_planeta = a[r].n_planeta;
        b[c[k < a[r].n_planeta.size() ? (int)(unsigned char)a[r].n_planeta[k] + 1 : 0] - 1].num_mes = a[r].num_mes;
        b[c[k < a[r].n_planeta.size() ? (int)(unsigned char)a[r].n_planeta[k] + 1 : 0] - 1].tn_planeta = a[r].tn_planeta;
        c[k < a[r].n_planeta.size() ? (int)(unsigned char)a[r].n_planeta[k] + 1 : 0]--;
    }

    for (int l = 0; l < size; l++){
        a[l].n_planeta = b[l].n_planeta;
        a[l].tn_planeta = b[l].tn_planeta;
        a[l].num_mes = b[l].num_mes;
        //cout << a[l].n_planeta << " ";
    }

    // avold memory leak
    delete[] b;
    delete[] c;
}


void radixSort(planeta* b, int r, int max){
    for (int digit = max; digit > 0; digit--){ // int is unsigned, so avoid using digit >= 0, which is always true
        countSort(b, r, digit - 1);
    }

}


void listar_ordenado(planeta *lo_planetas, int meses, int planetas)
{
    for (int i = 1; i <= meses ; i++)
    {
        for (int j = 1; j <= planetas; j++)
        {
            if (lo_planetas[j].num_mes == i)
            {
                cout << lo_planetas[j].num_mes << " " <<  lo_planetas[j].n_planeta << " " << lo_planetas[j].tn_planeta << "\n";
            }
        }
        
        
        //if(lo_planetas[i].num_mes == 0 || lo_planetas[i].num_mes > meses) break;
        
    }
    
}



#endif