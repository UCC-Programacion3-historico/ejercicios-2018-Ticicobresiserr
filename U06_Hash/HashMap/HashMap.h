#ifndef HASHMAP_H
#define HASHMAP_H

#include "HashEntry.h

template<class K, class T>
class HashMap {
private:
    unsigned int hashFunc(K clave);

    unsigned int (*hashFuncP)(K clave);

    HashEntry<T,K> **tabla;   //mi tabla es un arreglo

    unsigned int tamanio;

public:
    HashMap(unsigned int k);

    HashMap(unsigned int k, unsigned int (*hashFuncP)(K clave));

    T get(K clave);

    void put(K clave, T valor);

    void remove(K clave);

    ~HashMap();

    bool esVacio();

};

template<class K, class T>
HashMap<K, T>::HashMap(unsigned int k) {
    tabla = new *HashEntry<K,T> *[k] ;
    tamanio =k;
    for (int i = 0; i < tamanio; ++i) {  //cre una tabla de punteros en donde todos apuntan a null
        tabla= nullptr;

    }

}

template<class K, class T>
HashMap<K, T>::~HashMap() {

}

template<class K, class T>
T HashMap<K, T>::get(K clave) {
    T temp;

    unsigned int idx;
    idx= Hashfunc(clave);
    if (tabla[idx] == nullptr || tabla[idx]->getClave() == clave){
        throw 404;
    }
        return tabla[idx]->getDato();
}

template<class K, class T>
void HashMap<K, T>::put(K clave, T valor) {     //a partir de mi tabla de punteros un putero apunta a los parametros que voy pasando

    unsigned int idx;
    idx= hashFunc(clave);

    if (tabla[idx]== nullptr)  //si no hay nada en mi tabla
    tabla[idx]=new HashEntry<K,T> (valor, clave);         //creo uno nuevo
    else
        throw  404;      //hay excepcion



}

template<class K, class T>
void HashMap<K, T>::remove(K clave) {

}

template<class K, class T>
bool HashMap<K, T>::esVacio() {
    return false;
}

template<class K, class T>
unsigned int HashMap<K, T>::hashFunc(K clave) {
    return clave %  tamanio;
}

template<class K, class T>
HashMap<K, T>::HashMap(unsigned int k, unsigned int (*fp)(K)) {

}


#endif //HASHMAP_H