#include <iostream>
#include "../Lista/Lista.h"
#include "nodo.h"

##  Ejercicio N°2.
Escribir un programa que permita agregar no enteros a una lista de números aceptada por
        teclado. El programa pregunta si debe agregar al principio, al final o en el medio y agrega el
elemento a la lista.

void Lista<T>::agregarxlugar(unsigned float num, int pos){
    Nodo <T> *aux=inicio, *nuevo;
    switch (x){
        case 1:{   //al principio
            nuevo=new Nodo<T>;
            nuevo->setDato(num);
            nuevo->setSiguiente(aux);
            nuevo=inicio;
        }
        case 2:{   //al final
            while (aux!= nullptr){
                aux=aux->getSiguiente();
            }
            nuevo=new Nodo<T>;
            nuevo->setDato(num);
            aux->setSiguiente(nuevo);
            nuevo->setSiguiente(nullptr);
        }
        case 3:{ //en el medio


        }
    }
};
int main() {
    std::cout << "Ejercicio 01/02\n" << std::endl;
    return 0;
}