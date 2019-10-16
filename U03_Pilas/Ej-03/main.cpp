#include <iostream>
#include "../Pila/Pila.h"

using namespace std;
//"  una imagen vale por mil palabras" converir a
// "palabras mil por vale imagen una

int main() {
    char arr[100];
    char arrf[100];

    Pila<char> p;

    cout << "Introduzca una palabra" << endl;
    cin >> arr;

    for (int j = 0; arr[j] !=  '\t' ; ++j) {

        for (int i = 0; arr[i] != ' ' ; ++i)
        {
            arrf[j]= arr[i];
        }

        p.push(arrf[j]);
    }

    while (!p.esVacia()) {
        cout<<p.pop();
    }

    return 0;
}