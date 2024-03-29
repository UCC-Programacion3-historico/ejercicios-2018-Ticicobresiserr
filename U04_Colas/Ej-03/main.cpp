//
// Created by ticiana cobresi serravalle on 2019-10-15.
//

//crear una funcion cola que  se invierta


#include "../Cola/Cola.h"
#include <iostream>

template<class T>
Cola<T> invertir(Pila<T> c, Cola<T> d){

    while(!c.esVacia()){
        d.encolar(c.pop());
    }

    return d;

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

    return 0;

}


