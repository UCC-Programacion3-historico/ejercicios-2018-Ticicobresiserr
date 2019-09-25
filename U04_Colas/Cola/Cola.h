#ifndef COLA_H
#define COLA_H
#include
/**
 * Clase que implementa una Cola generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Cola {
private:
    T dato;
    Nodo <T> *nuevo;

public:
    Cola();

    ~Cola();

    void encolar(T dato); //agrego nodo

    T desencolar();   //quito nodo

    bool esVacia();

    T Cola<T>::peek();
};


/**
 * Constructor de la clase Cola
 * @tparam T
 */
template<class T>
Cola<T>::Cola() {
    frente = nullptr;
    fondo= nullptr;
}


/**
 * Destructor de la clase Cola, se encarga de liberar la memoria de todos los nodos
 * utilizados en la Cola
 * @tparam T
 */
template<class T>
Cola<T>::~Cola() {

}


/**
 * Inserta un dato en la Cola
 * @tparam T
 * @param dato  dato a insertar
 */
template<class T>
void Cola<T>::encolar(T dato) {
    auto *nuevo=new Nodo <T> (); //asigna el tipo que va a ser nuevo automaticamente. si tengo nodo en el segundo miembro lo guarda como dato t, si tengo int crea nuevo tipo int
    nuevo->setDato(dato);
    nuevo->setSiguiente (nullptr);

    if (fondo == nullptr){
        frente =nuevo;
    }
    else {
        fondo->setSiguiente (nuevo);
    }

    fondo=nuevo;

}


/**
 * Obtener el dato de la Cola
 * @tparam T
 * @return dato almacenado en el nodo
 */
template<class T>
T Cola<T>::desencolar() {
    //desencolamos del frente, primero guardo el dato

    T aux;
    Nodo <T> *aBorrar;

    if (frente== nullptr){
        throw 404;//new std::exception("Error");
    }
    aux= frente->getDato();

    aBorrar=frente;
    frente=frente->setSiguiente();
    //cuando hay un solo nodo hay que actualizar ferente
    if (frente== nullptr){
        fondo= nullptr;
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
    return frente== nullptr;
}

template <class T>
T Cola<T>::peek(){
    if (frente== nullptr){
        throw 404;}

    return frente->getDato();
    
}

#endif //LISTA_H