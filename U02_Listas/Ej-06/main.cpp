#include <iostream>
#include "../Lista/Lista.h"

/*

##    Ejercicio N°6.
Agregue el método: insertAfter2(int oldValue, int n, int newValue) que inserte un nodo
con el valor newValue después de la enésima ocurrencia de oldValue.
( 3,2,7,busco el valor numero 3, busco la ocurrencia num dos, segundo nodo en el que se encuentre un 3 y lo cambio
*/

int main() {

    Lista<int> a;

    a.insertarUltimo(4);
    a.insertarUltimo(41);
    a.insertarUltimo(2);
    a.insertarUltimo(41);
    a.insertarUltimo(42);

    a.insertAfter2(41,2, 8);

    a.print();

    std::cout << "Ejercicio 01/05\n" << std::endl;
    return 0;
}