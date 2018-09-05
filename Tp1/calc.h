#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED
/**
    calc_mostrarMenu: recibe dos valores decimales, dos banderas, y un puntero, finalmente muestra el menu analizando los parametros
    @param valorIngresadoUno: primer valor que ingresa el usuario
    @param valorIngresadoDos: segundo valor que ingresa el usuario
    @param ingresoA: bandera para saber si se ingreso el primer valor
    @param int ingresoB: bandera para saber si se ingreso el segundo valor
    @param pRespuesta
    @return: 0 OK, -1 error.
*/
void calc_mostrarMenu(float valorIngresadoUno, float valorIngresadoDos, int ingresoA, int ingresoB, int* pRespuesta);

/**
    calc_getSuma: recibe dos valores y un puntero, almacena la suma en el puntero.
    @param numeroUno: primer valor que ingresa el usuario
    @param numeroDos: segundo valor que ingresa el usuario
    @param pRespuesta: puntero donde se almacena el resultado
    @return: 0 OK, -1 error.
*/
int calc_getSuma(float numeroUno, float numeroDos, float* pResultado);
/**
    calc_getResta: recibe dos valores y un puntero, almacena la resta en el puntero.
    @param numeroUno: primer valor que ingresa el usuario
    @param numeroDos: segundo valor que ingresa el usuario
    @param pResultado: puntero donde se almacena el resultado
    @return: 0 OK, -1 error.
*/
int calc_getResta(float numeroUno, float numeroDos, float* pResultado);
/**
    calc_getMultiplicacion: recibe dos valores y un puntero, almacena la Multiplicacion en el puntero.
    @param numeroUno: primer valor que ingresa el usuario
    @param numeroDos: segundo valor que ingresa el usuario
    @param pResultado: puntero donde se almacena el resultado
    @return: 0 OK, -1 error.
*/
int calc_getMultiplicacion(float numeroUno, float numeroDos, float* pResultado);
/**
    calc_getDivision: recibe dos valores y un puntero, almacena la Division en el puntero.
    @param numeroUno: primer valor que ingresa el usuario
    @param numeroDos: segundo valor que ingresa el usuario
    @param pResultado: puntero donde se almacena el resultado
    @return: 0 OK, -1 error.
*/
int calc_getDivision(float dividendo, float divisor, float* pResultado);
/**
    calc_getFactorial: recibe un valor y un puntero, calcula el factorial del numero y lo almacena en el puntero.
    @param numero: primer valor que ingresa el usuario
    @param pResultado: puntero donde se almacena el resultado
    @return: 0 OK, -1 error.
*/
int calc_getFactorial(float numero, int unsigned long* pResultado);

/**
    calc_getResta: pide decimal y lo valida.
    @param pDecimal: puntero que debe almacenar el valor de ser decimal
    @param reintentos: si es 0, se pedira un numero decimal hasta que sea valido, de lo contrario se realizan los intentos que se pidan,
    @param mensaje: mensaje al pedir decimal,
    @param mensajeError: mensaje si el valor ingresado no es valido
    @return: 0 OK, -1 error.
*/
int calc_getDecimal(float* pDecimal, int reintentos, char* mensaje, char* mensajeError);

#endif // CALC_H_INCLUDED

