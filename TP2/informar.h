#ifndef INFORMAR_H_INCLUDED
#define INFORMAR_H_INCLUDED
#include "ArrayEmployees.h"
/** \brief Funcion para imprimir el menu y recibir la opcion ingresada por el usuario
 * \param len int Opcion ingresada
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printMenu(int* opcionIngresada);
/** \brief Se imprimen los empleados por orden apellido y sector
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printEmpleadosOrderApellidoSector(Employee* em, int len);
/** \brief Funcion que calcula e imprime del array de empleados el promedio de los salarios
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 */
void printTotalPromedioSalarios(Employee* em, int len);
/** \brief Funcion que imprime las opciones de informes y permite al usuario elegir el informe a imprimir.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printInformes(Employee* em, int len);
#endif // INFORMAR_H_INCLUDED
