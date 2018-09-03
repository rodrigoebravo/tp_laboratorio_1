#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main()
{
    float valorIngresadoUno=0;
    float valorIngresadoDos=0;

    char* mensaje;
    char* mensajeError;
    int reintentos;

    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    int resultadoFactorialA;
    int resultadoFactorialB;
    int contadorResp;
    int respuesta;

    mensaje="Ingrese numero: ";
    mensajeError="El valor ingresado no es correcto. \n";
    reintentos=3;



    do{
        calc_mostrarMenu(valorIngresadoUno,valorIngresadoDos,&contadorResp,&respuesta);
        contadorResp++;

        switch(respuesta)
        {
            case 1:
                if(calc_getDecimal(&valorIngresadoUno, reintentos, mensaje, mensajeError)!=0)
                {
                    system("cls");
                    printf("Ha agotado los reintentos posibles\n");
                }
                break;
            case 2:
                if(calc_getDecimal(&valorIngresadoDos, reintentos, mensaje, mensajeError)!=0)
                {
                    system("cls");
                    printf("Ha agotado los reintentos posibles\n");
                }
                break;

            case 3:
                calc_getSuma(valorIngresadoUno,valorIngresadoDos,&resultadoSuma);
                calc_getResta(valorIngresadoUno,valorIngresadoDos,&resultadoResta);
                calc_getMultiplicacion(valorIngresadoUno,valorIngresadoDos,&resultadoMultiplicacion);
                calc_getDivision(valorIngresadoUno,valorIngresadoDos,&resultadoDivision);
                calc_getFactorial(valorIngresadoUno, valorIngresadoDos,&resultadoFactorialA,&resultadoFactorialB);
                break;
            case 4:
                printf("A= %f\tB= %f\n", valorIngresadoUno, valorIngresadoDos);
                printf("El resultado de A+B es: %f\n", resultadoSuma);
                printf("El resultado de A-B es: %f\n", resultadoResta);
                printf("El resultado de A/B es: %f\n", resultadoDivision);
                printf("El resultado de A*B es: %f\n", resultadoMultiplicacion);
                printf("El factorial de A es: %d y El factorial de B es: %d \n",resultadoFactorialA, resultadoFactorialB);
                respuesta=5;
                break;
            case 5:
                break;
            default:
                printf("Opcion incorrecta! Reingrese opcion\n");
                break;
        }
    }while(respuesta!=5);

    return 0;
}
