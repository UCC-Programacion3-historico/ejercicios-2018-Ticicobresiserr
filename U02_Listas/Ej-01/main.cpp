#include <iostream>
#include "../Lista/Lista.h"
#include "fnInvierte.h"

using namespace std;

int main() {
    std::cout << "Ejercicio 02/01\n" << std::endl;
    Lista<int> a, *listap;
    listap=&a;

    a.insertarUltimo(4);
    a.insertarUltimo(9);
    a.insertarUltimo(41);
    a.insertarUltimo(43);
    a.insertarUltimo(42);

    fnInvierte(listap);

    a.print();
    return 0;
}