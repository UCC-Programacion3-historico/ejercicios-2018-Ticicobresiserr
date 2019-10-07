#ifndef CALCULOS_H
#define CALCULOS_H
/*##    Ejercicio N°5.
Escribir segmentos de programa que lleven a cabo de forma
recursiva, cada una de las siguientes tareas:

1. Calcule la parte entera del cociente, cuando
el entero a se divide por el entero b.
2. Calcule el resto entero, cuando el entero a es
 dividido por el entero b.
3. Utilice los módulos 1. y 2. para escribir una función recursiva que dado un entero no negativo lo imprima como una serie de dígitos separados por espacios.

 Ej: dado el entero 1024, debe escribir     "1 0 2 4 "
*/

unsigned int cociente(unsigned int a, unsigned int b);
unsigned int resto(unsigned int a, unsigned int b);

void escribir_espaciado(unsigned int num);


#endif //INC_01_RECURSIVIDAD_CALCULOS_H
