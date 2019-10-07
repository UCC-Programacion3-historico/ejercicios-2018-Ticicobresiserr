//
// Created by Ticiana Cobresi on 5/10/2019.
//

#include <iostream>
using namespace std;

int menorarray( unsigned int arr*, int ini, int fin){

    if (tam=1){
        return arr[0];
    }
    else
        if


int Menor(int s[], int ini, int fin)
{
    int menor, dev;

    if(ini == fin)
    {
        // dev = 0;   // <-- codigo original
        dev = ini; // <-- correccion
    }
    else
    {
        menor = Menor(s, ini + 1, fin);
        if(s[ini] < s[menor])
        {
            dev = ini;
        }
        else
        {
            dev = menor;
        }
    }
    return dev;
}
}