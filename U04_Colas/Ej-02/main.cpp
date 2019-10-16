/*##  Ejercicio N°2.
Utilizando una pila y una cola, realizar una función que reciba una cadena y devuelva el
        valor lógico verdadero si dicha cadena es un palidromo. No se deben tener en cuenta los
        espacios y signos de puntuación.

Ejemplos de palidromo:

* anita lava la tina
* la ruta natural
        * la ruta nos aporto otro paso natural*/

#include "../../U03_Pilas/Pila/Pila.h"
#include "../Cola/Cola.h"
#include <iostream>
using namespace std;
int main() {

    char arr[100];
    Cola<char> a;
    Pila<char> c,d;

    cout<<"Ingresar frase n"<<endl;
    cin>>arr;

    for (int i = 0; arr[i]!='\0'; ++i) {
        if(arr[i]!= ' ')
            a.encolar(arr[i]);  //genero la cola
        c.push(arr[i]);     //genero la pila
    }

    bool palimendro=true;

    while ( !c.esVacia() && palimendro){

        if(a.peek() != c.peek())
            palimendro= false;
        else
            a.desencolar();
        c.pop();
    }

    if (palimendro){
        cout<<"Es palimendro"<<endl;}
    else
        cout<<"No es palimendro"<<endl;




    std::cout << "Ejercicio 04/02\n" << std::endl;
    return 0;
}