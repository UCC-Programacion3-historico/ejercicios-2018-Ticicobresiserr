//
// Created by Ticiana Cobresi on 7/10/2019.
//

#include <iostream>
using namespace std;

//funcion void recursiva que reciba un entero positivo n y que de tpdps los enteros impares menores a n

void enteroimpar(int n){

    if (n%2 == 0) return 0;

    n=n-2;
    if(n>0) return n;
    enteroimpar(n);
}