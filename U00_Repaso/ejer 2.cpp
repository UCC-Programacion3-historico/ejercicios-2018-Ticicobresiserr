//
// Created by alumno on 27/9/2019.
//
using namespace std;

void funcion ( int n){  //unsigned era para restringir a numeros enteros
    if  (n % 2==0){
    n--;
    }else
        n= n-2;
cout << n <<endl;
    if (n > 1){
        funcion (n);
    }
}
//primero pensar el caso recursivo.

int main(){
    funcion(20);
}