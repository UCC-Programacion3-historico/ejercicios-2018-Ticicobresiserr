//
// Created by alumno on 11/9/2019.
//

#ifndef PROGRAMACION3_TIPOPARCIAL_H
#define PROGRAMACION3_TIPOPARCIAL_H

#endif //PROGRAMACION3_TIPOPARCIAL_H
# ifndef LISTA_H
# define  LISTA_H

# incluye  " nodo.h "
/ * *
//Clase que implementa una Lista Enlasada generica, ya que puede
* almacenado cualquier tipo de dato T
@tparam T cualquier tipo de dato
* /

plantilla <clase  T>
class  Lista {
private:
    nodo <T> * inicio;

public:
    Lista ();      /*lista crear*/
    Lista ( const Lista <T> & li);   /*lista por copia*/
    ~ Lista ();

    bool  esVacia ();

    int  getTamanio ();

    anular  insertar ( unsigned  int pos, T dato);

    nulo  insertarPrimero (T dato);

    nulo  insertarUltimo (T dato);

    eliminador de vacíos ( int pos);

    T getDato ( int pos);

    nulo  reemplazar ( int pos, T dato); /*reemplazar dato de una nueva posicion*/

    vaciar vacío ();
};


/ * *
* Constructor de la clase Lista
* @tparam T
* /

plantilla < clase  T >
Lista <T> :: Lista () {
    inicio = nullptr ;
}


/ * *
* Constructor por copia de la clase Lista
* @tparam T
* @param li
* /
plantilla < clase  T >
Lista <T> :: Lista ( const Lista <T> & li) {}


/ * *
* Destructor de la clase Lista, se encarga de liberar la memoria de todos los nodos
* utilizado en la lista
* @tparam T
* /

plantilla < clase  T >
Lista <T> :: ~ Lista () {
    vaciar ();
}


/ * *
* Metodo para saber si la lista esta vacia
* @tparam T
* @return true si la lista esta vacia, sino false
* /

plantilla < clase  T >
bool Lista <T> :: esVacia () {
    return (inicio == nullptr );   /*si la lista esta vacia apunta a null*/
}


/ * *
* Metodo para obtener la cantidad de nodos de la lista
* @tparam T
* @return la cantidad de nodos de la lista
* /
plantilla < clase  T >
int Lista <T> :: getTamanio () {
    nodo <T> * aux = inicio;   /*creo un auxiliar al primer nodo*/
    int cantidad = 0 ;         /*cuento los nodos y recorro la lista, utilizo while*/
    while (aux! = nullptr )    /*si llega a nulo es que llegue al final*/
    {
        aux = aux-> getSiguiente ();    /*aux apunta al siguente*/
        cantidad ++;
    }
    return cantidad;
}


/ * *
* Inserta un nodo con el dato en la posición pos
* @tparam T
* @param pos lugar donde será insertado el dato
* @param dato dato a insertar
* /
plantilla < clase  T >
void Lista <T> :: insertar ( unsigned  int pos, T dato) { /*funcion mas imortante, lleno de datos*/
    int posicion = 0 ;                               /*en listas el primero y el ultimo elemento se tratan distintos, y verificar si esta vacia*/
    nodo <T> * aux =inicio, * nuevo;

    if (pos == 0 ) {                    /*para la posicion 1*/
        nuevo = nuevo nodo <T>;
        nuevo-> setDato (dato);
        nuevo-> setSiguiente (inicio);
        inicio = nuevo;
        volver ;
    }
    while (posicion <pos- 1 && aux != nullptr ) // busca la posición del nodo y que el aux no sea nulo serio llego a la ultima posicion
    {
        aux = aux-> getSiguiente ();
        posicion ++;
    }
    if (aux == nullptr ) arroja  404 ; // es una excepción que el trycatch lee el error, si se pasa en posiciones lanza error


    nuevo = nuevo nodo <T>; // creo un nuevo nodo y le valor inicial
    nuevo-> setDato (dato);
    nuevo-> setSiguiente (aux-> getSiguiente ());
    aux-> setSiguiente (nuevo);

}


/ * *
* Inserta un nodo con el dato en la primera posición
* @tparam T
* @param dato dato a insertar
* /
plantilla < clase  T >
void Lista <T> :: insertarPrimero (T dato) {
insertar ( 0 , dato); // sino puedo hacer el if de posicion cero aca
}


/ * *
* Inserta un nodo con el dato en la última posición
* @tparam T
* @param dato dato a insertar
* /

plantilla < clase  T >
void Lista <T> :: insertarUltimo (T dato) {   //si lo dejo en funcion insertar, tardaria mucho en que amaño reccorra oda la lista, por eso hago funcion aparte

nodo <T> * aux = inicio, * nuevo;

if (aux == nullptr ) {
nuevo = nuevo nodo <T>; // creo un nuevo nodo y le valor inicial
nuevo-> setDato (dato);
nuevo-> setSiguiente (aux-> getSiguiente ());
aux-> setSiguiente (nuevo);
}

while (aux-> getSiguiente ()! = nullptr )
{
aux = aux-> getSiguiente ();
}

nuevo = nuevo nodo <T>;
nuevo-> setDato (dato);
nuevo-> setSiguiente (inicio);
inicio = nuevo;
volver ;

}


/ * *
* Eliminar el nodo en la posición 'pos' de la lista enlasada
* @tparam T
* @param pos posicionamiento del nodo a eliminar
* /
plantilla < clase  T >
        nulo Lista <T> :: removedor ( int pos) {
    nodo <T> * aux = inicio, * aborrar;

    int posActual = 0 ;

    while (aux! = nullptr && posActual < pos- 1)
    {
        aux = aux-> getSiguiente ();
        posActual ++;
    }
    if (aux == nullptr ) {
        lanzar  404 ;
    }
    if (posActual == 0 ) {          //si quiero borrar el primer elemento
        inicio = inicio-> getSiguiente ();
        eliminar aux;
        volver ;
    }
    if (aux-> getSiguiente () == nullptr ) arroja  404 ;

    aborrar = aux-> getSiguiente ();
    aux-> setSiguiente (aborrar-> getSiguiente ());
    eliminar aborrar;

}


/ * *
* Obtener el dato del nodo en la posición pos
* @tparam T
* @param pos posicion del dato
* @return dato almacenado en el nodo
* /
plantilla < clase  T >
        T Lista <T> :: getDato ( int pos) {
    nodo <T> * aux = inicio;
    int posActual = 0 ;

    while (aux! = nullptr && posActual <pos- 1 )
    {
        aux = aux-> getSiguiente ();
        posActual ++;
    }
    if (aux == nullptr ) {
        lanzar  404 ;
    }
    return aux-> getDato ();
}


/ * *
* Reemplaza el dato almacenado en un nodo por este otro
* @tparam T
* @param pos posicionamiento donde se desea reemplazar
* @param dato nuevo dato a limitaciones
* /
plantilla < clase  T >
        nulo Lista <T> :: reemplazar ( int pos, T dato) {
    int posicion = 0 ;
    nodo <T> * aux = inicio, * nuevo;
    while (aux! = nullptr && posicion <pos- 1 )
    {
        aux = aux-> getSiguiente ();
        posicion ++;
    }
    if (aux == nullptr ) arroja  404 ;

    aux-> setDato (dato);

}


/ * *
* Función que vacia la lista enlazada
* @tparam T
* /
plantilla < clase  T >
  void Lista <T> :: vaciar () {        //delete de todos los nodos
    nodo <T> * aux = inicio, * aborrar;
    while (aux! = nullptr )
    {
        aborrar = aux;
        aux = aux-> getSiguiente ();
        eliminar aborrar;
    }
    inicio = nullptr ;
}

//parte tipo parcial
plantilla < clase  T >
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