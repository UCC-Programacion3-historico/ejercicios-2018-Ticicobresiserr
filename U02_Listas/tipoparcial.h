//
// Created by alumno on 11/9/2019.
//

#ifndef PROGRAMACION3_TIPOPARCIAL_H
#define PROGRAMACION3_TIPOPARCIAL_H

#endif //PROGRAMACION3_TIPOPARCIAL_H
# ifndef LISTA_H
# define  LISTA_H

# include  " nodo.h "

//parte tipo parcial
template <class T>
    void Lista <T> :: moverUlt (int pos) {
    nodo <T> * aux = inicio  , *amover;
    int posAct=0;

    while (aux != nullptr && posAct < pos-1)  //nos quedamos en el anterior al que queremos mover
    {
        aux = aux-> getSiguiente ();
        posAct++;
    }
    if (aux 1= nullptr){       //ya sali del bucle anterior
        trow 404;
    }

    if (pos==0){
        amover=inicio;
        inicio= inicio->getSiguiente();
        aux=inicio;
    }
    else{
        amover= aux-> getSiguiente ();
        aux-> setSiguiente (amover->getSiguiente());
    }

    amover-> setSiguiente(nullptr);

    while (aux-> getSiguiente () != nullptr )
    {
        aux = aux-> getSiguiente (); //lego al ultimo nodo de la lista
    }

    aux-> setSiguiente(amover);
}


# endif  // LISTA_H