#include <iostream>
#include "../Lista/Lista.h"

/*
##  Ejercicio N°2.
Escribir un programa que permita agregar no enteros a una lista de números aceptada por
        teclado. El programa pregunta si debe agregar al principio, al final o en el medio y agrega el
elemento a la lista.
*/


int main() {
    int main() {

        Lista<int> a, b;

        a.insertarUltimo(4.2);
        a.insertarUltimo(9.3);
        a.insertarUltimo(41.4);
        a.insertarUltimo(43);
        a.insertarUltimo(42);

        cout<<"Desea agregar nuevo elemento al principio(1), al medio(2), o al final (3)"<<endl;
        cin>>x;
        if(x==1){
            a.insertarPrimero(1);
        }
        int tam= a.getTamanio();
        if(x==2){
            a.insertar(tam/2, 2);
        }
        if(x==1){
            a.insertarUltimo(3);
        }

        a->print();

        std::cout << "Ejercicio 01/02\n" << std::endl;
        return 0;
    }