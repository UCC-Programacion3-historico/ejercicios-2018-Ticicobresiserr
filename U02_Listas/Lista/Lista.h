#ifndef LISTA_H
#define LISTA_H

//#include <d2d1helper.h>
#include "nodo.h" /**incluye nodos porque voy a usar nodos*/
/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Lista {
private:
    nodo<T> *inicio;
public:
    Lista();

    Lista(const Lista<T> &li);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(unsigned int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    void remover(int pos);

    T getDato(int pos);

    void reemplazar(int pos, T dato);/*reemplazar dato de una nueva posicion*/

    void vaciar();

    void moverultimo(int pos);

    void moverPri (T dato);
    //extras

    void moverult (int pos);
    int sumavalor(int umbral);
    void alfinal (T dato);

};



/**
 * Constructor de la clase Lista
 * @tparam T
 */
template<class T>
Lista<T>::Lista() {
    inicio= nullptr; /**apunto a el coso vacio*/
}


/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template<class T>
Lista<T>::Lista(const Lista<T> &li) {
    inicio=li.inicio;
}


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
    return (inicio== nullptr); /*si la lista esta vacia apunta a null*/
}


/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template<class T>
int Lista<T>::getTamanio() {
    nodo<T> *aux= inicio; /*creo un auxiliar al primer nodo*/
    int cantidad=0;/*cuento los nodos y recorro la lista, utilizo while*/
    while(aux!= nullptr) /*si llega a nulo es que llegue al final*/
    {
        aux= aux->getSiguiente(); /*aux apunta al siguente*/
        cantidad++;
    }
    return cantidad;
}

/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 *
 * agrago nodos!!!*/
template<class T>
void Lista<T>::insertar(unsigned int pos, T dato) {/*funcion mas imortante, lleno de datos*/
    int posicion=0;
    nodo<T> *aux=inicio, *nuevo;
    /*en listas el primero y el ultimo elemento se tratan distintos, y verificar si esta vacia*/
    if (pos==0){   //para ingresar en la posicion 1
        nuevo= new nodo<T>;
        nuevo->setDato(dato);
        nuevo->setSiguiente(inicio);
        inicio=nuevo;
        return;
    }

    while(posicion<pos-1 && aux != nullptr) // busca la posición del nodo y que el aux no sea nulo serio llego a la ultima posicion
    {
        aux=aux->getSiguiente();
        posicion++;
    }
    if (aux== nullptr) throw 404; // es una excepción que el trycatch lee el error, si se pasa en posiciones lanza error


    nuevo=new nodo<T>; // creo un nuevo nodo y le valor inicial
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
    insertar (0,dato); /**sino puedo hacer el if de posicion cero aca*/
}


/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarUltimo(T dato) { /**hago esta funcion aca para mejorar rendimiento y no lo hago llamando a insertar con getTamanio */
    nodo<T> *aux= inicio,*nuevo;
    while(aux->getSiguiente()!= nullptr)
    {
        aux=aux->getSiguiente();
    }
    if(aux== nullptr){
        nuevo=new nodo<T>; /**creo un nuevo nodo y le inicializo valor*/
        nuevo->setDato(dato);
        nuevo->setSiguiente(aux->getSiguiente());
        aux->setSiguiente(nuevo);
    }
    nuevo= new nodo<T>;
    nuevo->setDato(dato);
    nuevo->setSiguiente(inicio);// de aux?
    inicio=nuevo;   //aux==nuevo?
    return;

}


/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template<class T>
void Lista<T>::remover(int pos) {
    nodo<T> *aux=inicio, *aborrar;
    int posActual =0;

    while(aux!= nullptr && posActual<pos-1)
    {
        aux= aux->getSiguiente();
        posActual++;
    }
    if (aux== nullptr) {
        throw 404;
    }
    if (pos==0){
        inicio = inicio->getSiguiente();
        delete aux;
        return;
    }
    if (aux->getSiguiente()== nullptr) throw 404;
    aborrar=aux->getSiguiente();
    aux->setSiguiente(aborrar->getSiguiente());
    delete aborrar;

}

/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template<class T>
T Lista<T>::getDato(int pos) {
    nodo<T> *aux=inicio;
    int posActual=0;

    while (aux!= nullptr&& posActual< pos-1)
    {
        aux= aux->getSiguiente();
        posActual++;
    }
    if (aux== nullptr){
        throw 404;
    }
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
    int posicion=0;
    nodo<T> *aux=inicio, *nuevo;
    while(aux!= nullptr&& posicion <pos-1)
    {
        aux=aux->getSiguiente();
        posicion++;
    }
    if (aux== nullptr) throw 404;

    aux->setDato(dato);

}


/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template<class T>
void Lista<T>::vaciar() { //borra todos los datos
    nodo<T> *aux=inicio, *aborrar;
    while(aux!= nullptr)
    {
        aborrar=aux;
        aux=aux->getSiguiente();
        delete aborrar;
    }
    inicio= nullptr;
}

template<class T>
void Lista<T>::moverultimo( int pos) //si lo dejo en funcion insertar, tardaria mucho en que amaño reccorra oda la lista, por eso hago funcion aparte
{
    nodo<T> *aux= inicio, *amover;
    int PosActual=0;
    while (aux!= nullptr && PosActual < pos -1)
    {
        aux=aux->getSiguiente();
        PosActual++;
    }
    if (aux != nullptr) throw 404;
    if (pos==0){
        amover=inicio;
        inicio=inicio->getSiguiente();
        aux=inicio;
    }
    else{
        amover= aux->getSiguiente();
        aux->getSiguiente(amover->getSiguiente());
    }
    amover= aux->getSiguiente();
    aux->setSiguiente(amover->getSiguiente());
    amover->setSiguiente(nullptr);
    while(aux->getSiguiente() != nullptr)
        aux=aux->getSiguiente();
    aux->setSiguiente(amover); /** seteo al siguiente del aux que apuntaba al null ahora lo hago apuntar a amover*/


}
<T>
void Lista <T>::moverPri (Tdato){
    Nodo <T> *aux =inicio *aMover;  //tengfo 3 etiquetas
    //si la lista esta vacia
    if (aux== nullptr) throw 404;

    //si el dao ya esta en primer lugar
    if(aux->getDato() == dato)
        return;

    while (aux->getSiguiente() != nullptr && aux-> getSiguiente()-> getDato() != dato){
        aux=aux->getSiguiente();
    }
    if (aux->getSiguiente() == nullptr){
        throw 404;
    }
    aMover= aux->getSiguiente();
    aux->setSiguiente(aMover->getSiguiente())

    aMover->setSiguiente(inicio);

    inicio=aMover;

}
template <class T>
void Lista <T>::print (){
    Nodo <T> *aux =inicio;

    while (aux != nullptr){
        std:: cout<< aux->getDato << "->";
        aux=aux->setSiguiente();
    }
    std:: cout<<"NULL"<<std ::endl;
}
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

#endif //LISTA_H


