//
// Created by ticiana cobresi serravalle on 2019-10-15.
//

//crear una funcion cola que  se invierta

#include <iostream>
#include "../Cola/Cola.h"

template<class T>
void invertir(Pila<T> c, Cola<T> d){

    while(!c.esVacia()){
        d.encolar(c.pop());
    }
}

using namespace std;
int main(){

    Cola<int> d;
    Pila<int> c;

    c.push(1);
    c.push(2);
    c.push(3);
    c.push(4);
    c.push(5);

    invertir(c,d);

    while(!d.esVacia()){
        d.desencolar();
    }
    return 0;

}


