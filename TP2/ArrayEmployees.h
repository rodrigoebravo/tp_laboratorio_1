#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define TODOOK 0

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len, int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief Imprime el array de Employee si el dato tiene el alta logica
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printEmployees(Employee* list, int length);

/** \brief Genera ID nuevo
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (>-1) if Ok
 *
 */
int generarID(void);

/** \brief Pide al usuario los datos a dar de alta como empleado
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (>-1) if Ok
 *
 */
int altaEmpleados(Employee* em, int len);

/** \brief Pide al usuario los datos a modificar como empleado, solo modifica de a un campo del empleado
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (>-1) if Ok
 *
 */
int modificarEmpleados(Employee* em, int len);

/** \brief Pide al usuario el id a eliminar como empleado
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (>-1) if Ok
 *
 */
int bajaEmpleados(Employee* em, int len);

/** \brief Funcion de test para agregar empleados a la lista inicial, para usarla en este caso se debe descomentar la linea numero:12 de la funcion Main
 * \param list Employee* Pointer to array of employees
 * \param int hayEmpleados usado como booleano, pudiendo ser TRUE o FALSE, esta funcion lo convierte en TRUE para seguir probando el resto de las funcionalidades del menu
 * \param in cantEmpleados longitud del array empleados
 */
void llenarEmpleadosTest(Employee* empleados, int* hayEmpleados, int cantEmpleados);



#endif // ARRAYEMPLOYEES_H_INCLUDED
