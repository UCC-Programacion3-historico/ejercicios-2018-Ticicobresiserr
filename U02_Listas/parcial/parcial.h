//
// Created by Ticiana Cobresi on 5/10/2019.
//

#ifndef PROGRAMACION3_REPASOXD_H
#define PROGRAMACION3_REPASOXD_H

#include "../../U03_Pilas/Pila/Pila.h"
#include "../Lista/Lista.h"



//implementar un metodo de la clase lista que reciba parametro N y que mueva el primer elemento a la posicion N. Si la posicion no existe tira excepcion.

template <class T>
void moverpri(int pos) {
    Nodo<T> *aux, *amover;
    int posAct=0;

    //if(pos > getTamanio()) throw 404;

    while (amover != nullptr && posAct<pos-1){
        amover=amover->getsig();
        posAct++;
    }
    if(amover == nullptr)throw 404;

    if(aux == nullptr)throw 404;

    aux->setsig(aux->getsig());
    aux->setsig(amover->getsig());
    amover->setsig(aux);
}



//metodo que reciba una lista y una pila, el metodo debera modificar la lista original, eliminando las posiciones indicadas por cada nodo de la pila


template <class T>
void modifica(Lista<T> &lis, Pila<T> pil){

    Nodo<T> *aux, *aborrar;
    int posAct=0;

    while (aux != nullptr   &&   posAct< pil.pop()-1){
        aux=aux->getsig();
        posAct++;
    }
    if(aborrar== nullptr)throw 404;

    if(aux== nullptr)throw 404;

    aborrar=aux->getSiguiente();
    aux-> setSiguiente (aborrar-> getSiguiente());

    delete aborrar;

    if ( pil.pop() != nullptr){
        modifica(lis, pil);
    }

}




#endif PROGRAMACION3_REPASOXD_H