#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"
/**
 * Clase que implementa una Pila generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Pila {
private:


public:
    Pila();

    ~Pila();

    void push(T dato);

    T pop();

    T peek();

    bool esVacia();
};


/**
 * Constructor de la clase Pila
 * @tparam T
 */
template<class T>
Pila<T>::Pila() {}


/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los nodos
 * utilizados en la lista
 * @tparam T
 */
template<class T>
Pila<T>::~Pila() { //destruir cada nodo de la pila
    while (tope != nullptr)
        pop();
}


/**
 * Inserta un dato en la pila
 * @tparam T
 * @param dato  dato a insertar
 */
template<class T>
void Pila<T>::push(T dato) {

    nodo<T> *nuevo;
    nuevo= new nodo<T>;
    nuevo -> setDato(dato);
    nuevo -> setSiguiente(tope);     //tope sera mi inicio
    tope=nuevo;
}


/**
 * Obtener el dato de la pila
 * @tparam T
 * @return dato almacenado en el nodo
 */
template<class T>
T Pila<T>::pop() {

    nodo <T> *aborrar= tope;       //guardo tope en un nodo nuevo variable nueva
    if (tope != nullptr){
        trow 404;
    }
    T dato= tope->getDato();
    tope= tope->getSiguiente();     //tope ahora apunta al siguiente del tope antrerior
    delete aborrar;
    return dato;
}

/**
 * Responde si la pila se encuentra Vacía
 * @tparam T
 * @return
 */
template<class T>
bool Pila<T>::esVacia() {
    return tope == nullptr; //retorna verdadero o falso

}

template<class T>
bool Pila<T>::peek() {
    if (tope == nullptr)
        trow 404;
    return tope -> getDato();
}

#endif //LISTA_H