//
// Created by Ticiana Cobresi on 5/10/2019.
//

#ifndef PROGRAMACION3_REPASOXD_H
#define PROGRAMACION3_REPASOXD_H

#endif //PROGRAMACION3_REPASOXD_H


//implementar un metodo de la clase lista que reciba parametro N y que mueva el primer elemento a la posicion N. Si la posicion no existe tira excepcion.
template <class T>
class Lista {
private:
    Nodo<T> *inicio;
public:
    Lista();
    ~Lista();
    int gettamanio();
    void moverpri(int pos)
}

int Lista<T>::gettamanio() {
    Nodo<T> *aux=inicio;
    int cantidad=0;

    if(aux== nullptr) throw 404;

    while( aux!= nullptr){
        aux=aux->getsig();
        cantidad++;
    }
    return cantidad;
}

void Lista<T>::moverpri(int pos) {
    Nodo<T> *aux=inicio, *amover=inicio;
    int posAct=0;

    if(pos>gettamanio())throw 404;

    while (amover!= nullptr && posAct<pos-1){
        amover=amover->getsig();
        posAct++;
    }
    if(aux== nullptr)throw 404;

    if(amover== nullptr)throw 404;

    inicio->setsig(aux->getsig());
    aux->setsig(amover->getsig());
    amover->setsig(aux);
}



//metodo que reciba una lista y una pila, el metodo debera modificar la lista original, eliminando las posiciones indicadas por cada nodo de la pila

template <class T>
class Lista{
private:
    Nodo <T> *nuevo;
public:
    Lista();
    ~Lista();
    T pop( Pila<T> *pil);
    void modifica(Lista<T> *lis, Pila<T> *pil);
};


template <class T>
T Lista<T>::pop( Pila<T> *pil) {

    Nodo<T> *aborrar= tope;      //mi inicio sera mi tope en pilas

    if (aborrar== nullptr) throw 404;

    T dato= tope->getdato();
    tope=tope->getsig() //      pop, salta el nodo
    delete aborrar;

    return dato;

}

template <class T>
void Lista<T>::modifica(Lista<T> *lis, Pila<T> *pil){

    Nodo<T> *aux=inicio, *aborrar;
    int posAct=0;

    if(aborrar== nullptr)throw 404;
    if(aux== nullptr)throw 404;

    while (aux != nullptr   &&   posAct< pop(Pila<T> pil)-1){
        aux=aux->getsig();
        posAct++;
    }
    aborrar=aux->getsig();
    aux->setsig(aborrar-getsig());

    delete aborrar;

    if (pop(Pila<T> pil)!= nullptr){
        modifica(lis, pil);
    }

}


//escribir funcion que busque en lista un valor y lo mueva a la primera posicion

void Lista<T>::moverpri(T dato){

    Nodo <T> *aux=inicio, *amover=inicio;
    int cant =0;

    if(amover->getdato()== dato) throw 202;

    while (amover != nullptr && amover->getdato()!= dato){
        amover=amover->getsig();
        cant ++;
    }

    if (aux== nullptr) throw 404;

    while (aux != nullptr && 0<posact<cant-1){
        aux=aux->getsig();
        posact++;
    }

    if( amover->getsig()== nullptr){
        aux->setsig(nullptr);
    }
    else aux->setsig(amover->getsig());

    amover->setsig(inicio);
    amover=inicio;

}
}


//para una lista enlazada creo metodo que sea moverultimo(int pos);

void Lista <T> moverult( int pos){

    Nodo <T> *aux=inicio     ;
    posicion=0;

    while(aux!= nullptr && posicion <pos-1){
        aux=aux->getsig();
        posicion++;
    }

    if(pos==0){

    }
    if (aux->getsig()== nullptr) thorw 404;


}



//recorrer lista hasta sierto umbral(todos loas mayores del umbral) e ir sumando los valores de los nodos
int Lista<T>::sumavalor( int umbral){
    Nodo <T> *aux=inicio;
    int cant=0;

    if (aux== nullptr) throw 404;

    while(aux!= nullptr){
        if(aux->getdato()>umbral){
        cant=cant+aux->getdato;}
    aux=aux->getsig();
    }

}



//recibe como parametro un dato, lo busca  y mueve a la ult posicion

void Lista <T> alfinal(T dato){

    Nodo <T> *aux=inicio ,*amover=inicio , *final=inicio   ;
    posicion=0;
    cant=0;

    while(amover != nullptr && amover->getdato()!= dato ){
        amover=amover->getsig();
        cant++;
    }
    while (aux!=nullptr && posicion<cant){
        aux=aux->getsig();
        posicion++;
    }
    if(aux->getsig()== nullptr)throw 404;
    if (aux==nullptr)throw 404;

    while (final != nullptr){
        final = final->getsig();
    }
    aux->setsig(amover->getsig());
    amover->setsig(nullptr);
    final->setsig(amover);
    return;

}


//probando
void Lista<T>::remover(int pos) {

    Nodo<T> *aux=inicio, aborrar;
    posicion=0;
    while (posicion<pos-1 && aux != nullptr){
        aux=aux->getsig()
        posicion++;
    }
    if (pos==0){
        inicio=inicio->getsigu();
        delete aux;
        return;
    }
    if (aux== nullptr)throw 404;
    if (aux-getsig()== nullptr)

        aborrar=aux->getsiguiente();
    aux=aux->setsig(aborrar-getsig());
    delete aborrar;

