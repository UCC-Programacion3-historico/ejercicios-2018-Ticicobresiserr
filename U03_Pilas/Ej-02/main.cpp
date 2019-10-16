
#include "../Pila/Pila.h"
#include <iostream>

/*
##  Ejercicio N°2.
Escriba una función que indique si dos pilas son iguales. Se entiende que dos pilas son
iguales cuando sus elementos son idénticos y aparecen en el mismo orden.
*/
using namespace std;

int main() {
    Pila<int> a, b;

    a.push(2);
    a.push( 3);
    a.push( 5);
    a.push( 6);

    b.push( 3);
    b.push( 9);
    b.push( 8);
    b.push( 5);



    cout<<"Son iguales : "<<sonIguales(a,b)<<endl;


    std::cout << "Ejercicio 03/02\n" << std::endl;



    return 0;
}