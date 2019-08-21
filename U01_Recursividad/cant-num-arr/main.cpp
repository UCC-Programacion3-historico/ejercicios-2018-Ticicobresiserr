#include <iostream>

using namespace std;


int contar(int *arr, int num, int tam) {
    if (tam == 1) {
        if (arr[0] == num)
            return 1;
        else
            return 0;
    }

    if (arr[tam - 1] == num) {
        return 1 + contar(arr, num, tam - 1);
    }


}


int main() {
    int a[5];
    a[0] = 1;
    a[1] = 3;
    a[2] = 2;
    a[3] = 3;
    a[4] = 2;
    cout << "Hay " << contar(a, 3, 5) << " tres en el arreglo " << endl;
    return 0;
}
// Created by Alumno on 14/08/2019.
//
//Para contar cuantas letras hay en una cadena de caracteres:
/*#include <iostream>
using namespace std;
int contar(char *arr, char l) {
    if (arr[0] == '\0')
        return 0;
    if (arr[0] == l)
        return 1 + contar(arr+1 , l);
    else
        return 0 + contar(arr+1, l);
}
int main() {
    char a[] = "Hola Mundo Lindo";
    cout << "Hay " << contar(a, 'o') << " os en el arreglo " << endl;
    return 0;
}*/

//Para que separe con espacios cada letra
/*#include <iostream>
using namespace std;
void contar(char *arr) {
    if (arr[0] != '\0') {
        cout << arr[0] << " ";
        contar(arr + 1);
    }
}
int main() {
    char a[] = "Hola Mundo Lindo";
    contar(a);
    return 0;
}*/

//Para que invierta
/*#include <iostream>
using namespace std;
void mostrar(char *arr) {
    if (arr[0] != '\0') {
        mostrar(arr + 1);
        cout << arr[0] << " ";
    }
}
int main() {
    char a[] = "Hola Mundo Lindo";
    mostrar(a);
    return 0;
}*/
