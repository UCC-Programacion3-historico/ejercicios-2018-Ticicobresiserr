#ifndef POTENCIA_H
#define POTENCIA_H

/*## Ejercicio N°1.
Implemente una función para potencias enteras con recursividad.
        Definición recursiva para elevar un número a una potencia:
Un número elevado a la potencia cero produce la unidad; la
potencia de un número se obtiene multiplicándolo por sí mismo
elevando a la potencia menos uno.
        Por ejemplo:

3<sup>2</sup>=3*(3<sup>1</sup>)=3*[3*(3<sup>0</sup>)]=3*(3*1)=9*/

unsigned int potencia(unsigned int base, unsigned int exp);