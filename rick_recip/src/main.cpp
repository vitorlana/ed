#include <iostream>
#include "recip.h"

using namespace std;

int main()
{
    Entrada user_ent;
    while ((cin >> user_ent.quantidade >> user_ent.operacao))
    {
        if (user_ent.operacao = "i" or "I")
        {
            //Inserir recipiente
            cout << "i \n";
        }else if(user_ent.operacao = "r" or "R")
        {   
            //Remover recipiente
            cout << "r \n";
        }else if(user_ent.operacao = "p" or "P")
        {
            //Realizar medição
            cout << "p \n";
        }else if (cin.eof())
        {
            exit;
        }else exit;
    }
    return 0;
}