/*## Ejercicio N°1.
Diseñe un programa que sea capaz de leer dos colas y mediante un mensaje indicar si son
        iguales. Nota: los elementos constitutivos de las colas son caracteres.*/
#include <iostream>
#include "../Cola/Cola.h"
using namespace std;
int main() {

    char arr[100];
    Cola<char> a, b;

    cout<<"Ingresar elementos"<<endl;
    cin>>arr;

    for (int i = 0; arr[i]!='\0'; ++i) {
        a.encolar(arr[i]);
        b.encolar(arr[i]);
    }
    cout<<sonIguales(a,b)<<endl;


    std::cout << "Ejercicio 04/01\n" << std::endl;

    return 0;
}