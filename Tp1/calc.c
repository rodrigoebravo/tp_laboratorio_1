#include <stdio.h>
#include <stdlib.h>

int getFloat(float* pResultado);
int esEntero(float NumeroIngresado);

int calc_getSuma(float numeroUno, float numeroDos, float* resultado)
{
    int retorno=0;
    float auxSuma;
    auxSuma=numeroUno+numeroDos;
    *resultado=auxSuma;
    return retorno;
}
int calc_getResta(float numeroUno, float numeroDos, float* resultado)
{
    int retorno=0;
    float auxResta;
    auxResta=numeroUno-numeroDos;
    *resultado=auxResta;
    return retorno;
}
int calc_getMultiplicacion(float numeroUno, float numeroDos, float* resultado)
{
    int retorno=0;
    float auxMultiplicacion;
    auxMultiplicacion=numeroUno*numeroDos;
    *resultado=auxMultiplicacion;
    return retorno;
}
int calc_getDivision(float numeroUno, float numeroDos, float* resultado)
{
    int retorno=-1;
    float auxDivision=0;

    if(numeroDos!=0)
    {
        auxDivision=numeroUno/numeroDos;
        *resultado=auxDivision;
        retorno=0;
    }
    return retorno;
}

int calc_getFactorial(float numero, int unsigned long* resultado)
{
    int retorno=-1;
    int unsigned long auxResultado=numero;

    int i;

    if(esEntero(numero)==0)
    {
        if(numero==0)
        {
            auxResultado=1;
            retorno=0;
        }
        else if(numero>0)
        {
            for(i=auxResultado-1;i>1;i--)
            {
                auxResultado*=i;
            }
            retorno=0;
        }
        else
        {
            auxResultado=0;
            retorno=-2;
        }
        *resultado=auxResultado;
    }

    return retorno;
}

int esEntero(float NumeroIngresado)
{
    float esEntero;
    int retorno=-1;
    esEntero=(int)NumeroIngresado-NumeroIngresado;

    if(esEntero==0)
    {
        retorno=0;
    }
    return retorno;
}

int calc_getDecimal(float* pDecimal, int reintentos, char* mensaje, char* mensajeError)
{
    int retorno=-1;
    float auxiliarDecimal;
    if(reintentos!=0)
    {
        for(;reintentos>0;reintentos--)
        {


            if(getFloat(&auxiliarDecimal)==0)
            {
                *pDecimal=auxiliarDecimal;
                retorno=0;
                system("cls");
                break;
            }
            else
            {
                system("cls");
                printf(mensajeError);
                fflush(stdin);
            }
        }
    }
    else
    {   printf(mensaje);
        while(scanf("%f",&auxiliarDecimal)!=1)
        {

            system("cls");
            printf(mensajeError);
            printf(mensaje);
            fflush(stdin);
        }
        *pDecimal=auxiliarDecimal;
        retorno=0;
        system("cls");
    }
    return retorno;
}

int getFloat(float* pResultado)
{
    int retorno=-1;

    if(scanf("%f", pResultado)==1)
    {
        retorno=0;
    }

    return retorno;
}

void calc_mostrarMenu(float valorIngresadoUno, float valorIngresadoDos, int ingresoA, int ingresoB, int* respuesta)
{
    int auxRespuesta=0;

    if(ingresoA==0)
    {
        printf("1. Ingresar 1er operando (A=x)\n");
    }
    else
    {
        printf("1. Ingresar 1er operando (A=%.2f)\n", valorIngresadoUno);
    }

    if(ingresoB==0)
    {
        printf("2. Ingresar 2do operando (B=y)\n");
    }
    else
    {
        printf("2. Ingresar 2do operando (B=%.2f)\n", valorIngresadoDos);
    }

    printf("3. Calcular todas las operaciones\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n");

    if(scanf("%d", &auxRespuesta)!=1)
    {
        *respuesta=0;
        fflush(stdin);
    }
    else
    {
        *respuesta=auxRespuesta;
    }

    system("cls");





}
