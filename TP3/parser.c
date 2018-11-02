#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char bufferInt[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    int retorno=-1;
    int flagOnce=1;
    Employee *pEmpleado;

    if(pFile != NULL && pArrayListEmployee!=NULL)
    {
        retorno=0;

        printf("Procesando archivo...\n");

        while(!feof(pFile))
        {
            if(flagOnce)
            {
                flagOnce=0;
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferInt, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferInt, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
            pEmpleado=Employee_newConParametros(bufferInt, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
            if(pEmpleado!=NULL)
            {
                ll_add(pArrayListEmployee, pEmpleado);
            }
        }
        printf("Archivo cargado exitosamente\n");

    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    Employee *pEmpleado;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        retorno=TODOOK;
        do
        {
            pEmpleado = Employee_new();
            fread(pEmpleado, sizeof(pEmpleado), 1, pFile);
            ll_add(pArrayListEmployee, pEmpleado);
        }
        while(!feof(pFile));
    }
    return retorno;
}
