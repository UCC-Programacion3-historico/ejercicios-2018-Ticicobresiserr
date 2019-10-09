#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include <opencl-c.h>
#include "NodoArbol.h"

template<class T>
class ArbolBinario {
private:
    NodoArbol<T> *raiz;

public:
    ArbolBinario();

    void put(T dato);

    T search(T dato); //porej, tengo en un nodo una case auto con mil atributos, ingreso en x dato de esos atributos y me los devuleve a todos completos.

    void remove(T dato);

    void preorder();

    void inorder();

    void postorder();

    ~ArbolBinario();

    bool esVacio();

    void print();

private: //por que no quiero mostrarle los nodos al usuario

    NodoArbol<T> *put(T dato,NodoArbol<T> *r );

    T search(T dato, NodoArbol<T> *r);

    void preorder(NodoArbol<T> *r);

    void inorder(NodoArbol<T> *r);

    void posorder(NodoArbol<T> *r);

    NodoArbol<T> * remover(T dato, NodoArbol<T> *r);

    NodoArbol<T> *  ArbolBinario<T>::Buscarmax(T dato, NodoArbol<T> *r);

};


/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template<class T>
ArbolBinario<T>::ArbolBinario() {
    raiz= nullptr;
}


/**
 * Destructor del Arbol
 */
template<class T>
ArbolBinario<T>::~ArbolBinario() {

}


/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template<class T>
T ArbolBinario<T>::search(T dato) {
    return search(dato, raiz);
}


/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template<class T>
void ArbolBinario<T>::put(T dato) {
     raiz= put(dato, raiz);
}
template<class T>
NodoArbol<T> * ArbolBinario<T>::put(T dato,NodoArbol<T> *r ){
    //estoy haciendo recursividad hasta un nodo nulo
    //si llego al  ult nodo y no tiene hijo creo nuevo nodo
    if (r== nullptr) {
        return new NodoArbol <T> (dato);          //1!* y crea el nodo

    }
    if( r->getDato() ==dato){ //no puedo tener datos iguales
        throw 200;  //lo encontre
    }

    if( r->getDato() > dato) {

        r->setIzq (put(dato, r->getIzq()));}  //ve que la raiz no tiene un nodo a la izq con put() tal que sube a 1!*
    else
            {
                r->setDer(put(dato, r->getDer()));}
                return r;  //en la recursividad se retorna la raiz a si mismo, entonces la recursividad sigue con la sig raiz
    }


        //dato raiz es mayor que el que insete
        /*if (r->getIzq() == nullptr) {  //si a la izq no tengo nodo, lo creo
            r->setIzq(new NodoArbol<T>(dato));
        } else //existe el nodo
        {
            put(dato, r->getIzq())
        }
    }
    else{
            if (r->getDer() == nullptr){  //si a la izq no tengo nodo, lo creo
                r->setDer(new NodoArbol <T> (dato));
            }
            else //existe el nodo
            {
                put(dato, r->getDer())
            }
    }

    }*/

template<class T>
T ArbolBinario<T>::search(T dato,NodoArbol<T> *r ) { //es recursiva
    if(r== nullptr){
        throw 404;
    }
    if( r->getDato() ==dato){
        return r->getDato();
    }
            if( r->getDato() >dato)
                return search(dato, r->getIzq());
            else
                return search(dato, r->getDer());
}


template<class T>
void ArbolBinario<T>::remove(T dato) {
    raiz=remover(T dato,NodoArbol<T> *r );
}
/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
template<class T>
NodoArbol<T> *  ArbolBinario<T>::remove(T dato, NodoArbol<T> *r) {

    NodoArbol<T> *aux;

    if(r== nullptr){
        throw 404;
    }
    if( r->getDato() ==dato){
        //borrar
        if(r->getIzq()== nullptr && r->getDer() == nullptr){
            delete r;
            return nullptr; //ese nodo no existe mas
        }

        else if(r->getIzq()== nullptr && r->getDer() != nullptr){  //en el caso de que no tenga uno de  los dos hijos
            aux= r->getDer();
            delete r;
            return aux;
        }
        else if(r->getIzq()!= nullptr && r->getDer() == nullptr){  //en el caso de que no tenga uno de los dos hijos
            aux= r->getIzq();
            delete r;
            return aux;
        }
        else if(r->getIzq()!= nullptr && r->getDer() != nullptr){
            bool enc;

            if(r->getIzq()->getDer()!= nullptr){

                aux= Buscarmax(r->getIzq(), &enc);
                aux= setDer(r->getDer());
                aux= setIzq(r->getIzq());
            }
            else{
                aux=r->getIzq()
                r->getIzq()->getDer(r->getDer());
            }
        }
            delete r;
            return aux;

        }

        else if( r->getDato() >dato){
        r->setIzq(remover(dato, r->getIzq())     );//ahora retorna un puntero en la recursividad
        //pongo como hijo izq el puntero que me devuelve la recursividad

    }
    else ( r->getDato() <dato){
        r->setDer(remover(dato, r->getDer()));
    }
    return r;

}
template<class T>
NodoArbol<T> *  ArbolBinario<T>::Buscarmax(NodoArbol<T> *r, bool *encontre ) {  //remover llamo a partir del que quiero borrar

        NodoArbol<T> *ret;
        *encontre=false;

        if(r->getDer()== nullptr){   //quiere decir que es el maximo
            *encontre=true;
            return r;
        }

        ret= return Buscarmax(r->getDer(), encontre);
        if (*encontre){

            r->setDer(nullptr);  //seteo el anterior a mi maximo a nullptr
            *encontre= false;
        }

        return ret;
    }


/**
 * Informa si un árbol esta vacío
 * @return
 */
template<class T>
bool ArbolBinario<T>::esVacio() {
    return r== nullptr;
}


/**
 * Recorre un árbol en preorden
 */
template<class T>
void ArbolBinario<T>::preorder() {
    preorder(raiz);
}

/**
 * Recorre un árbol en orden
 */
template<class T>
void ArbolBinario<T>::inorder() {

}

/**
 * Recorre un árbol en postorden
 */
template<class T>
void ArbolBinario<T>::postorder() {

}
template<class T>
void ArbolBinario<T>::preorder(NodoArbol<T> *r){
    if (r== nullptr){
        return;

        std:: cout<< r->getDato()<<" ";
        preorder(r->getIzq());
        preorder(r->getDer())

    }
}
template<class T>
void ArbolBinario<T>::inorder(NodoArbol<T> *r){
    if (r== nullptr){
        return;

        inorder(r->getIzq());
        std:: cout<< r->getDato()<<" ";
        inorder(r->getDer())

    }
}
template<class T>
void ArbolBinario<T>::posorder(NodoArbol<T> *r){
    if (r== nullptr){
        return;

        std:: cout<< r->getDato()<<" ";
        posorder(r->getIzq());
        posorder(r->getDer())

    }
}

/**
 * Muestra un árbol por consola
 */
template<class T>
void ArbolBinario<T>::print() {

}



#endif //HASHMAP_H