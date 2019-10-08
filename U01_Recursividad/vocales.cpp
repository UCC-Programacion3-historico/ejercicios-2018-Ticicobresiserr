//
// Created by Ticiana Cobresi on 7/10/2019.
//
#include <iostream>

using namespace std;

int vocales(char * cd){

    for(int i; cd[i]!='\0' ; i++){

        if ( cd[i] == 'a' && 'e' && 'i' && 'o' && 'u'){

            return 1 + vocales(cd);}

        else
            return 0;
}}

int main(){
    char arr[6];
    cin.getline(arr,6);

    cout<<"hay "<< vocales(arr);
    return 0;
}