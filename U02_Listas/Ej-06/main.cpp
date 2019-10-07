#include <iostream>
#include "../Lista/Lista.h"

##    Ejercicio N°6.
Agregue el método: insertAfter2(int oldValue, int n, int newValue) que inserte un nodo
con el valor newValue después de la enésima ocurrencia de oldValue.
( 3,2,7,busco el valor numero 3, busco la ocurrencia num dos, segundo nodo en el que se encuentre un 3 y lo cambio


void Lista <T>::insertAfter2(int oldValue, int n, int newValue){
    Nodo <T> *aux=inicio;
    int cant =0;
    while (aux!= nullptr && cant<n){
        if(aux->getdato()==oldValue){
            cant ++;
        }
        aux=aux->getsig();
    }
    aux=setdato(newValue);
    return;
};

int main() {
    std::cout << "Ejercicio 01/05\n" << std::endl;
    return 0;
}