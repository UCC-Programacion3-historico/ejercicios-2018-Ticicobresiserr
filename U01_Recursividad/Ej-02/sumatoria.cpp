#include <iostream>

using namespace std;
/*
##  Ejercicio N°2.
Implemente una función recursiva que, teniendo un array
ingresado por teclado, me devuelva la suma de todos sus elementos*/


int sumatoria(int *arr, int size){

    for (int i = 1; i <= size; ++i) {

        if (size ==0) return 0;

        else return arr[i] + sumatoria(arr, size);
    }
}


int main() {
    std::cout << "Ejercicio 01/02\n" << std::endl;
    int arr[3];
    for (int i=1;i<=3;i++){
        cout<<"arr["<<i<<"]= ";
        cin>>arr[i];
    }

    cout <<sumatoria(arr, 3);

    return 0;
}