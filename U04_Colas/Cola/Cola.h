#ifndef COLA_H
#define COLA_H

#include "nodo.h"
#include "../../U03_Pilas/Pila/Pila.h"

/**
 * Clase que implementa una Cola generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Cola {
private:
    Nodo<T> *frente, *fondo;

public:
    Cola();

    ~Cola();

    //Cola (const Cola&);

    //T funct(Pila<T> &p, Cola<T> &c);

    void encolar(T dato);

    T desencolar();

    bool esVacia();

    T peek();
};


/**
 * Constructor de la clase Cola
 * @tparam T
 */
template<class T>
Cola<T>::Cola() {
    frente = nullptr;
    fondo = nullptr;
}

// live.marku.me
/**
 * Destructor de la clase Cola, se encarga de liberar la memoria de todos los nodos
 * utilizados en la Cola
 * @tparam T
 */
template<class T>
Cola<T>::~Cola() {

    while (!esVacia())
        desencolar();

}
//template<class T>
//Cola<T>::Cola(const Cola<T> &c):Cola(c.Cola){}


/**
 * Inserta un dato en la Cola
 * @tparam T
 * @param dato  dato a insertar
 */
template<class T>
void Cola<T>::encolar(T dato) {

    auto *nuevo = new Nodo<T>();
    nuevo->setDato(dato);
    nuevo->setSiguiente(nullptr);

    if (fondo == nullptr) {
        frente = nuevo;
    } else {
        fondo->setSiguiente(nuevo);
    }

    fondo = nuevo;
}


/**
 * Obtener el dato de la Cola
 * @tparam T
 * @return dato almacenado en el nodo
 */
template<class T>
T Cola<T>::desencolar() {
    T aux;
    Nodo<T> *aBorrar;

    if (frente == nullptr)
        throw 404;

    aux = frente->getDato();

    aBorrar = frente;
    frente = frente->getSiguiente();

    if (frente == nullptr) {
        fondo = nullptr;
    }

    delete aBorrar;

    return aux;
}

/**
 * Responde si la Cola se encuentra Vacía
 * @tparam T
 * @return
 */
template<class T>
bool Cola<T>::esVacia() {
    return frente == nullptr;
}

template<class T>
T Cola<T>::peek() {
    if (frente == nullptr)
        throw 404;

    return frente->getDato();
}

//extras
/*
template<class T>
T Cola<T>::funct(Pila <T> &p, Cola<T> &c) {
    p=c;
    while (!p.esVacia()) {
        return p.pop();
    }
}*/

template<class T>
int sonIguales(Cola<T> a, Cola<T> b){

    T auxa, auxb;
    while(!a.esVacia() && !b.esVacia()){
        auxa=a.desencolar();
        auxb=b.desencolar();
        if(auxa != auxb) return false;
    }
    return true;
}

#endif //LISTA_H