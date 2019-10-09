#include <iostream>
#include "sumatoria.h"
using namespace std;

int main() {
    std::cout << "Ejercicio 01/02\n" << std::endl;
    int arr[3];
    for (int i=0;i<=3;i++){
        cout<<"arr["<<i<<"]= ";
        cin>>arr[i];
    }

    cout <<sumatoria(arr, 3);

    return 0;
}