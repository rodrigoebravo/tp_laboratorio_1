int calc_getSuma(float numeroUno, float numeroDos, float* resultado)
{
    int retorno=0;
    *resultado=numeroUno+numeroDos;
    return retorno;
}
int calc_getResta(float numeroUno, float numeroDos, float* resultado)
{
    int retorno=0;
    return retorno;
}
int calc_getMultiplicacion(float numeroUno, float numeroDos, float* resultado)
{
    int retorno=0;
    return retorno;
}
int calc_getDivision(float dividendo, float divisor, float* resultado)
{
    int retorno=0;
    return retorno;
}
int calc_getFactorial(float numeroUno, float* resultado)
{
    int retorno=0;

    return retorno;
}

int calc_getEntero(float* pNumeroIngresado, int reintentos, char* mensaje, char* mensajeError)
{

    return 0;
}

int calc_getDecimal(float* pDecimal, int reintentos, char* mensaje, char* mensajeError)
{

    int retorno=-1;
    int ingreso;
    float auxiliarDecimal;

    printf(mensaje);

    for(;reintentos>0;reintentos--)
    {
        printf("");
    }


    return retorno;

}

static int getFloat(float* pResultado)
{
    int retorno=-1;

    if(scanf("%f", pResultado)==1)
    {
        retorno=0;
    }

    return retorno;
}

