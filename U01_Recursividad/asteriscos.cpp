//
// Created by Ticiana Cobresi on 7/10/2019.
//

#include <iostream>
using namespace std;

//funcion recursiva con parametro positivo y que despliegue en pantalla la cantidad de esos asteriscos

void asteriscos(int n){

    if (n>0)
        return '*';
    n--;
    asteriscos(n);

    else
        return 0;

    }
}