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
    int unsigned long resultadoFactorialA;
    int unsigned long resultadoFactorialB;
    int respuesta;
    int banderaIngresoA=0;
    int banderaIngresoB=0;
    int banderaCalculo=0;
    int divisionOk;
    int factorialAOk;
    int factorialBOk;

    mensaje="Ingrese numero: ";
    mensajeError="El valor ingresado no es correcto. \n";
    reintentos=0;



    do{
        calc_mostrarMenu(valorIngresadoUno,valorIngresadoDos,banderaIngresoA,banderaIngresoB,&respuesta);

        switch(respuesta)
        {
            case 1:
                if(calc_getDecimal(&valorIngresadoUno, reintentos, mensaje, mensajeError)!=0)
                {
                    system("cls");
                    printf("Ha agotado los reintentos posibles\n");
                    banderaIngresoA=0;
                    break;
                }
                banderaIngresoA=1;
                break;
            case 2:
                if(calc_getDecimal(&valorIngresadoDos, reintentos, mensaje, mensajeError)!=0)
                {
                    system("cls");
                    printf("Ha agotado los reintentos posibles\n");
                    banderaIngresoB=0;
                    break;
                }
                banderaIngresoB=1;
                break;

            case 3:
                if(banderaIngresoA!=1 || banderaIngresoB!=1)
                {
                    printf("Debe ingresar valores de A y B antes de calcular.\n");
                    break;
                }
                calc_getSuma(valorIngresadoUno,valorIngresadoDos,&resultadoSuma);
                calc_getResta(valorIngresadoUno,valorIngresadoDos,&resultadoResta);
                calc_getMultiplicacion(valorIngresadoUno,valorIngresadoDos,&resultadoMultiplicacion);
                divisionOk=calc_getDivision(valorIngresadoUno,valorIngresadoDos,&resultadoDivision);
                factorialAOk=calc_getFactorial(valorIngresadoUno,&resultadoFactorialA);
                factorialBOk=calc_getFactorial(valorIngresadoDos,&resultadoFactorialB);
                banderaCalculo=1;
                printf("Calculos realizados exitosamente!\n");
                break;

            case 4:
                if(banderaIngresoA!=1 || banderaIngresoB!=1)
                {
                    printf("No se pueden mostrar resultados, no se ingresaron valores para A y B.\n");
                    break;
                }
                else
                {
                    if(banderaCalculo!=1)
                    {
                        printf("No se efectuaron los calculos, debe ingresar la opcion 3.\n");
                        break;
                    }

                    printf("A= %.2f\tB= %.2f\n", valorIngresadoUno, valorIngresadoDos);
                    printf("El resultado de A+B es: %.2f\n", resultadoSuma);
                    printf("El resultado de A-B es: %.2f\n", resultadoResta);
                    if(divisionOk==0)
                    {
                        printf("El resultado de A/B es: %.2f\n", resultadoDivision);
                    }
                    else
                    {
                        printf("No es posible dividir por cero\n");
                    }
                    printf("El resultado de A*B es: %.2f\n", resultadoMultiplicacion);
                    //printf("El factorial de A es: %lu y El factorial de B es: %lu \n",resultadoFactorialA, resultadoFactorialB);
                    if(factorialAOk==0)
                    {
                        printf("El factorial de A es: %lu",resultadoFactorialA);
                    }
                    else
                    {
                        if(factorialAOk==-1)
                        {
                            printf("No se pudo obtener el factorial de A, es decimal");
                        }
                        else
                        {
                            printf("No se pudo obtener el factorial de A, es negativo");
                        }
                    }
                    if(factorialBOk==0)
                    {
                        printf(" y El factorial de B es: %lu",resultadoFactorialB);
                    }
                    else
                    {
                        if(factorialBOk==-1)
                        {
                            printf(", No se pudo obtener el factorial de B, es decimal.");
                        }
                        else
                        {
                            printf(", No se pudo obtener el factorial de B, es negativo.");
                        }
                    }
                    respuesta=5;
                    break;
                }

            case 5:
                printf("Hasta pronto!");
                break;

            default:
                printf("Opcion incorrecta! Reingrese opcion\n");
                break;
        }
    }while(respuesta!=5);

    return 0;
}
