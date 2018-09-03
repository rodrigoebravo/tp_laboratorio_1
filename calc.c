#include <stdio.h>
#include <stdlib.h>

int getFloat(float* pResultado);
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
    int retorno=0;
    float auxDivision=0;

    if(numeroDos==0)
    {
        retorno=-1;
    }
    else
    {
        auxDivision=numeroUno/numeroDos;
        *resultado=auxDivision;
    }

    return retorno;
}

int calc_getFactorial(float numeroUno, float numeroDos, int* resultadoA, int* resultadoB)
{
    int retorno=0;
    int auxResultadoA=numeroUno;
    float auxNumeroUno;
    int auxResultadoB=numeroDos;
    float auxNumeroDos;
    int i;

    auxNumeroUno=(int)numeroUno-numeroUno;
    if(auxNumeroUno==0)
    {
        for(i=auxResultadoA-1;i>1;i--)
        {
            auxResultadoA*=i;

        }
        *resultadoA=auxResultadoA;
    }
    else
    {
        retorno=-1;
    }
    auxNumeroDos=(int)numeroDos-numeroDos;
    if(auxNumeroDos==0)
    {
        for(i=auxResultadoB-1;i>1;i--)
        {
            auxResultadoB*=i;

        }
        *resultadoB=auxResultadoB;
    }
    else
    {
        retorno=-1;
    }


    return retorno;
}

int calc_getEntero(float* pNumeroIngresado, int reintentos, char* mensaje, char* mensajeError)
{

    return 0;
}

int calc_getDecimal(float* pDecimal, int reintentos, char* mensaje, char* mensajeError)
{
    int retorno=-1;
    float auxiliarDecimal;
    for(;reintentos>0;reintentos--)
    {

        printf(mensaje);
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

void calc_mostrarMenu(float valorIngresadoUno, float valorIngresadoDos, int* contadorMenu, int* respuesta)
{
    int auxRespuesta=0;

    if(*contadorMenu==0)
    {
        printf("1. Ingresar 1er operando (A=x)\n");
    }
    else
    {
        printf("1. Ingresar 1er operando (A=%f)\n", valorIngresadoUno);
    }

    if(*contadorMenu!=2)
    {
        printf("2. Ingresar 2do operando (B=y)\n");
    }
    else
    {
        printf("2. Ingresar 2do operando (B=%f)\n", valorIngresadoDos);
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
