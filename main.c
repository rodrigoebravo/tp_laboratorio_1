#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main()
{

    float num1;
    float num2;
    char* mensaje;
    char* mensajeError;
    int reintentos;
    //float res;
    mensaje="Ingrese numero";
    mensajeError="El valor ingresado no es correcto";
    reintentos=3;
    calc_getDecimal(&num1, reintentos, mensaje, mensajeError);
    calc_getDecimal(&num2, reintentos, mensaje, mensajeError);

    /*
    if(calc_getSuma(num1, num2, &res)==0)
    {
        printf("el resultado es: %f", res);
    }
    */
    return 0;
}

