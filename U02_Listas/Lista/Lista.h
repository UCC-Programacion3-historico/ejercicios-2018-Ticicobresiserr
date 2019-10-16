#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"
#include <iostream>

/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Lista {
private:
    Nodo<T> *inicio;

public:
    Lista();

    Lista(const Lista<T> &li);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(unsigned int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    T getDato(int pos);

    void remover(int pos);


    void reemplazar(int pos, T dato);

    void vaciar();

    void moverUlti(int pos);

    void moverPri(T dato);

    void print();

    //extras
    void insertAfter2(int, int, int);

    void moverpri(T dato);

    int sumavalor( int umbral);

    void alfinal(T dato);

    int getposicion(T dato);

};


/**
 * Constructor de la clase Lista
 * @tparam T
 */
template<class T>
Lista<T>::Lista() {
    inicio = nullptr;
}


/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template<class T>
Lista<T>::Lista(const Lista<T> &li) {}


/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los nodos
 * utilizados en la lista
 * @tparam T
 */
template<class T>
Lista<T>::~Lista() {
    vaciar();
}


/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template<class T>
bool Lista<T>::esVacia() {
    return inicio == nullptr;

}


/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template<class T>
int Lista<T>::getTamanio() {
    Nodo<T> *aux = inicio;
    int cant = 0;


    while (aux != nullptr) {
        aux = aux->getSiguiente();
        cant++;
    }
    return cant;

}


/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template<class T>
void Lista<T>::insertar(unsigned int pos, T dato) {
    int posActual = 0;
    Nodo<T> *aux = inicio, *nuevo;


    if (pos == 0) {
        nuevo = new Nodo<T>;
        nuevo->setDato(dato);
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }


    while (posActual < pos - 1 && aux != nullptr) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr)
        throw 404;

    nuevo = new Nodo<T>;
    nuevo->setDato(dato);
    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);


}


/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarPrimero(T dato) {
    insertar(0, dato);
}


/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarUltimo(T dato) {
    Nodo<T> *aux = inicio, *nuevo;

    if (aux == nullptr) {
        nuevo = new Nodo<T>;
        nuevo->setDato(dato);
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while (aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }


    nuevo = new Nodo<T>;
    nuevo->setDato(dato);
    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}


/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template<class T>
void Lista<T>::remover(int pos) {
    Nodo<T> *aux = inicio, *aBorrar;
    int posActual = 0;


    while (aux != nullptr && posActual < pos - 1) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr)
        throw 404;

    if (pos == 0) {
        inicio = inicio->getSiguiente();
        delete aux;
        return;
    }

    if (aux->getSiguiente() == nullptr)
        throw 405;


    aBorrar = aux->getSiguiente();
    aux->setSiguiente(aBorrar->getSiguiente());

    delete aBorrar;


}


/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template<class T>
T Lista<T>::getDato(int pos) {
    Nodo<T> *aux = inicio;
    int posActual = 0;

    while (aux != nullptr && posActual < pos) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr)
        throw 404;

    return aux->getDato();


}


/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template<class T>
void Lista<T>::reemplazar(int pos, T dato) {
    Nodo<T> *aux = inicio;
    int posActual = 0;

    while (aux != nullptr && posActual < pos) {
        aux = aux->getSiguiente();
        posActual++;
    }
    if (aux == nullptr)
        throw 404;

    aux->setDato(dato);


}


/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template<class T>
void Lista<T>::vaciar() {
    Nodo<T> *aux = inicio, *aBorrar;

    while (aux != nullptr) {
        aBorrar = aux;
        aux = aux->getSiguiente();
        delete aBorrar;
    }
    inicio = nullptr;

}

template<class T>
void Lista<T>::moverUlti(int pos) {
    Nodo<T> *aux = inicio, *aMover;
    int posActual = 0;
    while (aux != nullptr && posActual < pos - 1) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux != nullptr) {
        throw 404;
    }

    if (pos == 0) {
        aMover = inicio;
        inicio = inicio->getSiguiente();
        aux = inicio;
    } else {
        aMover = aux->getSiguiente();
        aux->setSiguiente(aMover->getSiguiente());
    }


    aMover->setSiguiente(nullptr);

    while (aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }

    aux->setSiguiente(aMover);


}


template<class T>
void Lista<T>::moverPri(T dato) {
    Nodo<T> *aux = inicio, *aMover;

    // si la lista esta vacia tiro exp
    if (aux == nullptr)
        throw 404;

    // Si el dato ya está en el primer lugar no hago nada
    if (aux->getDato() == dato)
        return;

    while (aux->getSiguiente() != nullptr && aux->getSiguiente()->getDato() != dato) {
        aux = aux->getSiguiente();
    }
    if (aux->getSiguiente() == nullptr)
        throw 404;

    aMover = aux->getSiguiente();
    aux->setSiguiente(aMover->getSiguiente());

    aMover->setSiguiente(inicio);

    inicio = aMover;
}

template<class T>
void Lista<T>::print() {
    Nodo<T> *aux = inicio;

    while (aux != nullptr) {
        std::cout << aux->getDato() << "->";
        aux = aux->getSiguiente();
    }
    std::cout << "NULL" << std::endl;
}

//extra
template<class T>
void Lista<T>::insertAfter2(int oldValue, int n, int newValue){

    Nodo<T> *aux= inicio, *nuevo;
    Nodo<T> *aux2=inicio;

    int cant =0;
    int posvalor=0;
    int posagregar=0;

    if (aux== nullptr) throw 404;

    while (aux!= nullptr && cant<n){
        if(aux->getDato()==oldValue){
            cant ++;
        }
        aux=aux->getSiguiente();
        posvalor++;
    }

    while (aux2!= nullptr && posagregar< posvalor-1){
        aux2=aux2->getSiguiente();
        posagregar++;
    }

    if (aux2== nullptr) throw 404;

    nuevo= new Nodo<T>;
    nuevo->setDato(newValue);
    nuevo->setSiguiente(aux2->getSiguiente());
    aux2->setSiguiente(nuevo);
}


//escribir funcion que busque en lista un valor y lo mueva a la primera posicion

template <class T>
void Lista <T>::moverpri(T dato){

    Nodo <T> *aux=inicio, *amover=inicio;
    int cant =0;
    int posact =0;

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
}

//recorrer lista hasta sierto umbral(todos loas mayores del umbral) e ir sumando los valores de los nodos
template <class T>
int Lista<T>::sumavalor( int umbral){
    Nodo <T> *aux=inicio;
    int cant=0;

    if (aux == nullptr) throw 404;

    while(aux!= nullptr){
        if(aux->getDato()>umbral){
            cant=cant+ aux->getDato();}
        aux=aux->getSiguiente();
    }
    return  cant;
}

//recibe como parametro un dato, lo busca  y mueve a la ult posicion

template <class T>
void Lista<T>::alfinal(T dato){

    Nodo <T> *final=inicio, *aux=inicio ,*amover=inicio ;
    int posicion=0;
    int cant=0;

    if (final==nullptr)throw 404;
    if(final->getSiguiente()== nullptr) throw 404;

    while (final != nullptr){
        final = final->getSiguiente();
    }

    if (amover==nullptr)throw 404;
    if(amover->getSiguiente()== nullptr) throw 404;

    while(amover != nullptr && amover->getDato()!= dato ){
        amover=amover->getSiguiente();
        cant++;
    }

    if (aux==nullptr)throw 404;
    if(aux->getSiguiente()== nullptr) throw 404;

    while (aux!=nullptr && posicion<cant-1){
        aux=aux->getSiguiente();
        posicion++;
    }

    aux->setSiguiente(amover->getSiguiente());
    amover->setSiguiente(final->getSiguiente());
    final->setSiguiente(amover);
}
template<class T>
int Lista<T>::getposicion(T dato){
    Nodo<T> *aux=inicio;
    int pos=1;

    while(aux != nullptr && aux->getDato() != dato){
        aux=aux->getSiguiente();
        pos++;
    }
    if(aux== nullptr) throw 404;

    return pos-1;
};


#endif //LISTA_H