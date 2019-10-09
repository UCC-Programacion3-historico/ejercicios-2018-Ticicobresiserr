#include <iostream>
#include <stdlib.h>
#include <string>
#include "../Arbol/ArbolBinario.h"

/*
class Persona{
public:
    string nombre;
    string apellido;
    int dni;
    Persona(string n, string a, int d){
        nombre=n;
        apellido=a;
        dni=d;
    }
};*/
/*int main(){
    ArbolBinario<Persona> a;
    Persona b ("Juan", "Perez", 1230);
    //etc
    a.put(b);

    quiero buscar ese dni

    Persona dummy("",""" 1230)
    a.search();
    a.print();    //me devuelve juan de persona b, no dummy

    bool operator ==(Persona p){
    return this->dni == p.dni;
    }
    bool operator >(Persona p){
        return this->dni == p.dni;
    }
}*/

int main() {
    ArbolBinario <int> a;
    //srand(0);

    for (int i=0; i<20; i++){
        //a.put(rand());
        a.put(2); //asi con cada nodo
        a.remove(2);

        a.print()
    }
    std::cout << "Ejercicio 05/01\n" << std::endl;
    return 0;
}



