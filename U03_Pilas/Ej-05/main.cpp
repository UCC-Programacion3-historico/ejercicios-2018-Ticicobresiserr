#include "../Pila/Pila.h"
#include <iostream>
/*##    Ejercicio N°5.
Se tiene la siguiente expresión infija:

(6+2)∗5−8/4*/
using namespace std;

int main() {

    char arr[20];

    Pila<char> a;
    cout<<"Introduzca elementos"<<endl;
    cin >>arr;

    for (int i = 0; arr[i] != '\0'; ++i) {
        a.push(arr[i]);
    }
    while(!a.esVacia())
    {cout<<a.pop();}


    std::cout << "Ejercicio 03/05\n" << std::endl;
    return 0;
}