//
// Created by Ticiana Cobresi on 5/10/2019.
//

#ifndef PROGRAMACION3_REPASOXD_H
#define PROGRAMACION3_REPASOXD_H

#endif //PROGRAMACION3_REPASOXD_H

//para una lista enlazada creo metodo que sea moverultimo(int pos);

void Lista <T> moverult( int pos){

    Nodo <T> *aux=inicio     ;
    posicion=0;

    while(aux!= nullptr && posicion <pos-1){
        aux=aux->getsig();
        posicion++;
    }

    if(pos==0){

    }
    if (aux->getsig()== nullptr) thorw 404;


}

//recorrer lista hasta sierto umbral(todos loas mayores del umbral) e ir sumando los valores de los nodos
int Lista<T>::sumavalor( int umbral){
    Nodo <T> *aux=inicio;
    int cant=0;
    while(aux!= nullptr){
        if(aux->getdato()>umbral){
        cant=cant+aux->getdato;}
    aux=aux->getsig();
    }
    if (aux== nullptr) throw 404;
}

//recibe como parametro un dato, lo busca  y mueve a la ult posicion

void Lista <T> alfinal(T dato){

    Nodo <T> *aux=inicio ,*amover=inicio , *final=inicio   ;
    posicion=0;
    cant=0;

    while(amover != nullptr && amover->getdato()!= dato ){
        amover=amover->getsig();
        cant++;
    }
    while (aux!=nullptr && posicion<cant){
        aux=aux->getsig();
        posicion++;
    }
    if(aux->getsig()== nullptr)throw 404;
    if (aux==nullptr)throw 404;

    while (final != nullptr){
        final = final->getsig();
    }
    aux->setsig(amover->getsig());
    amover->setsig(nullptr);
    final->setsig(amover);
    return;

}







void Lista<T>::remover(int pos) {

    Nodo<T> *aux=inicio, aborrar;
    posicion=0;
    while (posicion<pos-1 && aux != nullptr){
        aux=aux->getsig()
        posicion++;
    }
    if (pos==0){
        inicio=inicio->getsigu();
        delete aux;
        return;
    }
    if (aux== nullptr)throw 404;
    if (aux-getsig()== nullptr)

        aborrar=aux->getsiguiente();
    aux=aux->setsig(aborrar-getsig());
    delete aborrar;

