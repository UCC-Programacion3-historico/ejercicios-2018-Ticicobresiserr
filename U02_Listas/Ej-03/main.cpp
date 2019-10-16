#include "../Lista/Lista.h"
#include <iostream>
/*##    Ejercicio N°3.
Escribir un programa que permita eliminar elementos de una lista de números aceptada por
teclado. El programa pregunta qué elemento borrar considerando que el primero por la
izquierda es el 0.*/

using namespace std;

int main() {


    std::cout << "Ejercicio 01/03\n" << std::endl;

    Lista<int> a;

    a.insertarUltimo(0);
    a.insertarUltimo(9);
    a.insertarUltimo(41);
    a.insertarUltimo(43);
    a.insertarUltimo(42);

    a.print();

    int x;
    cout<<"Ingrese num a borrar"<<endl;
    cin>>x;

    //hace una funcion int que te de la posicion para ese numero

    a.remover(a.getposicion(x));
    a.print();

    return 0;
}