#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h>
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define TODOOK 0

/** \brief Pide entero al usuario y lo valida
 * \param int* numeroBuffer valor donde quedara el valor validado
 * \param int intentos intentos que se podran hacer
 * \param int maximo maximo aceptado
 * \param int minimo minimo aceptado
 * \param char* mensaje mensaje para pedir
 * \param char* mensajeError mensaje en caso de error
 * \return 0 en caso de error, 1 en caso de que este todo ok
 */
int utn_getEntero(int* numeroBuffer, int intentos, int maximo, int minimo, char* mensaje, char* mensajeError);

/** \brief Pide decimal al usuario y lo valida
 * \param float* numeroBuffer valor donde quedara el valor validado
 * \param int intentos intentos que se podran hacer
 * \param int maximo maximo aceptado
 * \param int minimo minimo aceptado
 * \param char* mensaje mensaje para pedir
 * \param char* mensajeError mensaje en caso de error
 * \return 0 en caso de error, 1 en caso de que este todo ok
 */
int utn_getDecimal(float* numeroBuffer, int intentos, int maximo, int minimo, char* mensaje, char* mensajeError);

/** \brief Pide cadena de caracteres al usuario y lo valida
 * \param char* numeroBuffer valor donde quedara el valor validado
 * \param int len longitud de la cadena de caracteres
 * \param int intentos intentos que se podran hacer
 * \param char* mensaje mensaje para pedir
 * \param char* mensajeError mensaje en caso de error
 * \return 0 en caso de error, 1 en caso de que este todo ok
 */
int utn_getCadena(char* cadenaBuffer, int len, int intentos, char* mensaje, char* mensajeError);
//void limpiarNumero(char* cadena);
//int esCuit(char* cuit, int len);
void limpiarScreen(void);
#endif // UTN_H_INCLUDED
