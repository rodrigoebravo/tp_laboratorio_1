#include "informar.h"
int printMenu(int* opcionIngresada)
{
    int retorno=ERROR;

    printf("1- Alta empleados\n2- Modificar empleados\n3- Eliminar empleados\n4- Informe empleados\n5- Salir\n");
    retorno=utn_getEntero(opcionIngresada, 3, 6, 0, "Ingrese opcion: \n", "Error al leer opcion\n");
    limpiarScreen();
    return retorno;
}

int printInformes(Employee* em, int len)
{
    int retorno=ERROR;
    int opcion;
    if(em!=NULL && len>0)
    {
        if(utn_getEntero(&opcion, 3, 3, 0, "1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\nIngrese opcion: ", "Opcion incorrecta\n")==TODOOK)
        {
            limpiarScreen();
            switch(opcion)
            {
                case 1:
                    printEmpleadosOrderApellidoSector(em, len);
                    retorno=TODOOK;
                    break;
                case 2:
                    printTotalPromedioSalarios(em, len);
                    retorno=TODOOK;
                    break;
            }
        }
    }
    return retorno;

}

int printEmpleadosOrderApellidoSector(Employee* em, int len)
{
    int retorno=ERROR;

    if(sortEmployees(em, len, 1)==TODOOK)
    {
        retorno=printEmployees(em, len);
    }
    return retorno;
}

void printTotalPromedioSalarios(Employee* em, int len)
{
    float promedioSalarios;
    float totalSalarios=0;
    int contEmpleados=0;
    int cantidadEmpleadosSuperanPromedio=0;
    int i;
    if(em!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(em[i].isEmpty==FALSE)
            {
                totalSalarios+=em[i].salary;
                contEmpleados++;
            }
        }
        promedioSalarios=totalSalarios/(float)contEmpleados;

        for(i=0; i<len; i++)
        {
            if(em[i].isEmpty==FALSE && em[i].salary>promedioSalarios)
            {
                cantidadEmpleadosSuperanPromedio++;
            }
        }

        printf("Total salarios: %f\n", totalSalarios);
        printf("Promedio Salarios: %f\n", promedioSalarios);
        printf("Cantidad empleados que superan el promedio: %d\n", cantidadEmpleadosSuperanPromedio);

    }
}

