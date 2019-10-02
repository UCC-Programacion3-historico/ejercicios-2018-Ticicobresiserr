#ifndef NODOARBOL_H
#define NODOARBOL_H

template<class T>
class NodoArbol { //creo otro nodo pq neccesito nodo con dos punteros
private:

    T dato;
    NodoArbol *izq, *der;

public:

    NodoArbol(T d){
        dato=d;
        izq= nullptr;
        der= nullptr;
    }
    NodoArbol(){
        izq= nullptr;
        der= nullptr;
    }

    void setDato (T Dato){
        NodoArbol::dato =dato;
    }

    void setIzq (NodoArbol *izq){
        NodoArbol::izq =izq;
    }

    void setDer (NodoArbol *der){
        NodoArbol::der=der;
    }

    T getDato() const {
        return dato;
    }

    NodoArbol *getIzq() const{
        return izq;
    }
    NodoArbol *getDer() const{
        return der;
    }





};

#endif //HASHENTRY_H