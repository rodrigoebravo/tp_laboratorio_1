#include "ArrayEmployees.h"
#include "utn.h"
#include "informar.h"
#define CANTIDAD_EMPLEADOS 1000

int main()
{
    int opcionIngresada;
    int hayEmpleados=FALSE;
    Employee empleados[CANTIDAD_EMPLEADOS];
    initEmployees(empleados, CANTIDAD_EMPLEADOS);
    llenarEmpleadosTest(empleados, &hayEmpleados, CANTIDAD_EMPLEADOS);

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
                    else
                    {
                        printf("ID eliminado correctamente!\n");
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
                else
                {
                    printf("No se pueden imprimir datos, debe dar de alta antes.\n");
                }
                break;
            default:
                printf("Bye!");
                break;
        }
    }
    while(opcionIngresada!=5);

    return 0;
}
