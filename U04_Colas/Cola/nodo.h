# ifndef PROGRAMACION3_NODO_H
# define  PROGRAMACION3_NODO_H

template<class  T>
        class nodo {
private:
    T dato;
    nodo <T> * siguiente;
public:

    T getDato () const {
        return dato;
    }

    void  setDato (T dato) {
        this -> dato = dato;
    }

    nodo <T> * getSiguiente () const {
        return siguiente;
    }

    void setSiguiente (nodo <T> * siguiente) {
        this -> siguiente = siguiente;
    }

};
# endif  // PROGRAMACION3_NODO_H