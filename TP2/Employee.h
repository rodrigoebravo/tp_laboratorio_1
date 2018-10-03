#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

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

int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int findEmployeeById(Employee* list, int len, int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
int generarID(void);
int altaEmpleados(Employee* em, int len);
int modificarEmpleados(Employee* em, int len);
int bajaEmpleados(Employee* em, int len);


#endif // EMPLOYEE_H_INCLUDED
