#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED
void calc_mostrarMenu(float valorIngresadoUno, float valorIngresadoDos, int* contadorMenu, int* respuesta);
int calc_getSuma(float numeroUno, float numeroDos, float* resultado);
int calc_getResta(float numeroUno, float numeroDos, float* resultado);
int calc_getMultiplicacion(float numeroUno, float numeroDos, float* resultado);
int calc_getDivision(float dividendo, float divisor, float* resultado);
int calc_getFactorial(float numeroUno, float numeroDos, int* resultadoA, int* resultadoB);
int calc_getEntero(float* pNumeroIngresado, int reintentos, char* mensaje, char* mensajeError);
int calc_getDecimal(float* pDecimal, int reintentos, char* mensaje, char* mensajeError);

#endif // CALC_H_INCLUDED

