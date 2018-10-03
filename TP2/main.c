#include "Employee.h"
#include "utn.h"
#define CANTIDAD_EMPLEADOS 1000
void llenarEmpleadosTest(Employee* empleados);
int printMenu(int* opcionIngresada);
int printEmpleadosOrderApellidoSector(Employee* em, int len);
void printTotalPromedioSalarios(Employee* em, int len);
int printInformes(Employee* em, int len);
int main()
{
    int opcionIngresada;
    int hayEmpleados;
    Employee empleados[CANTIDAD_EMPLEADOS];
    initEmployees(empleados, CANTIDAD_EMPLEADOS);

    do
    {
        printMenu(&opcionIngresada);

        switch(opcionIngresada)
        {
            case 1:
                if(altaEmpleados(empleados, CANTIDAD_EMPLEADOS)==TODOOK)
                {
                    hayEmpleados=TRUE;
                    limpiarScreen();
                }
                break;
            case 2:
                if(hayEmpleados==TRUE)
                {
                    if(modificarEmpleados(empleados, CANTIDAD_EMPLEADOS)!=TODOOK)
                    {
                        limpiarScreen();
                        printf("Error al modificar registro\n");
                    }
                }
                else
                {
                    printf("No se pueden modificar datos, debe dar de alta antes.\n");
                }
                break;
            case 3:
                if(hayEmpleados==TRUE)
                {
                    if(bajaEmpleados(empleados, CANTIDAD_EMPLEADOS)!=TODOOK)
                    {
                        printf("Error al eliminar registro\n");
                    }
                }
                else
                {
                    printf("No se pueden modificar datos, debe dar de alta antes.\n");
                }
                break;
            case 4:
                if(hayEmpleados==TRUE)
                {
                    if(printInformes(empleados, CANTIDAD_EMPLEADOS)!=TODOOK)
                    {
                        printf("No se pudo imprimir informes\n");
                    }
                }
                break;
            default:
                break;
        }
    }
    while(opcionIngresada!=5);

    return 0;
}

void llenarEmpleadosTest(Employee* empleados)
{
    addEmployee(empleados, CANTIDAD_EMPLEADOS, 1, "Rodrigo", "Bravo", 1, 10);
    addEmployee(empleados, CANTIDAD_EMPLEADOS, 2, "Rodrigo", "Bravo", 25000, 1);
    addEmployee(empleados, CANTIDAD_EMPLEADOS, 3, "Rodrigo", "Bravo", 12, 9);
    addEmployee(empleados, CANTIDAD_EMPLEADOS, 4, "Rodrigo", "Mar", 25000, 10);
    addEmployee(empleados, CANTIDAD_EMPLEADOS, 5, "Rodrigo", "Aaa", 25000, 1);
    addEmployee(empleados, CANTIDAD_EMPLEADOS, 6, "Rodrigo", "Car", 25000, 2);
    addEmployee(empleados, CANTIDAD_EMPLEADOS, 7, "Rodrigo", "Cor", 25000, 2);
    addEmployee(empleados, CANTIDAD_EMPLEADOS, 8, "Rodrigo", "Pir", 25000, 2);
    addEmployee(empleados, CANTIDAD_EMPLEADOS, 9, "Rodrigo", "Zor", 25000, 1);
    addEmployee(empleados, CANTIDAD_EMPLEADOS, 10, "Rodrigo", "Zur", 25000, 2);
    addEmployee(empleados, CANTIDAD_EMPLEADOS, 11, "Rodrigo", "Zar", 25000, 3);
    addEmployee(empleados, CANTIDAD_EMPLEADOS, 12, "Rodrigo", "Abo", 25000, 9);
    addEmployee(empleados, CANTIDAD_EMPLEADOS, 13, "Rodrigo", "Mer", 25000, 1);
    addEmployee(empleados, CANTIDAD_EMPLEADOS, 14, "Rodrigo", "Sor", 25000, 8);
    addEmployee(empleados, CANTIDAD_EMPLEADOS, 15, "Rodrigo", "Asdqwe", 25000, 5);
}

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

