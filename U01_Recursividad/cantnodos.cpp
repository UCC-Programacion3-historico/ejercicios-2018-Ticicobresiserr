//
// Created by Ticiana Cobresi on 7/10/2019.
//
#ifndef LISTA_H
#define LISTA_H

#include "Lista.h"

#include <iostream>
using namespace std;

//metodo de la clase lista que de manera recursiva cuente cuantos nodos tiene la lista enlazada
template<class T>
int Lista<T>::tamanio(Nodo *n){

   // while(n!= nullptr) {
        if (n == nullptr)
            return 0;

        else
            return 1+ tamanio(n);
        //n++;
    }


}