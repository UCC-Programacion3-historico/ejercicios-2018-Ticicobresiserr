#include "sumatoria.h"

using namespace std;

int sumatoria(int *arr, unsigned int size){
    /*
##  Ejercicio N°2.
Implemente una función recursiva que, teniendo un array
ingresado por teclado, me devuelva la suma de todos sus elementos*/

    i==size;
    if (size ==0)
        return arr[i];
    else
        return arr[i] + sumatoria(*arr, size+1);
}
#endif //INC_01_RECURSIVIDAD_SUMATORIA_H
}