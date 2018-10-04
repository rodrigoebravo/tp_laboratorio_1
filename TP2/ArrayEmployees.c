#include "ArrayEmployees.h"


static int emp_getIndexVacio(Employee* emp, int len);
static void swapEmployees(Employee* list, int i);

int initEmployees(Employee* list, int len)
{
    int i;
    int retorno=ERROR;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty=TRUE;
        }
        retorno=TODOOK;
    }
    return retorno;
}


int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int retorno=TODOOK;
    int indexVacio;
    int i;
    if(list!=NULL && len>0 && name!=NULL && lastName!=NULL && salary>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].id==id && list[i].isEmpty==FALSE)
            {
                retorno=ERROR;
                break;
            }

        }

        if(retorno==TODOOK)
        {
            indexVacio=emp_getIndexVacio(list, len);
            list[indexVacio].id=id;
            strncpy(list[indexVacio].name, name, strlen(name));
            strncpy(list[indexVacio].lastName, lastName, strlen(lastName));
            list[indexVacio].salary=salary;
            list[indexVacio].sector=sector;
            list[indexVacio].isEmpty=FALSE;
        }
    }
    return retorno;
}


int findEmployeeById(Employee* list, int len, int id)
{
    int index=ERROR;
    int i;
    if(list!=NULL && len>0 && id>-1)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].id==id && list[i].isEmpty==FALSE)
            {
                index=i;
                break;
            }
        }
    }
    return index;
}


int removeEmployee(Employee* list, int len, int id)
{
    int retorno=ERROR;
    int index;
    index = findEmployeeById(list, len, id);

    if(index!=ERROR)
    {
        list[index].isEmpty=TRUE;
        retorno=TODOOK;
    }
    return retorno;
}


int sortEmployees(Employee* list, int len, int order)
{
    int retorno=ERROR;
    int i;
    int flag=TRUE;


    if(list!=NULL && len>0)
    {
        retorno=TODOOK;

        flag=TRUE;
        while(flag==TRUE)
        {
            flag=FALSE;
            for(i=0; i<(len-1); i++)
            {
                if((order==1 && strcmp(list[i].lastName, list[i+1].lastName) > 0) ||
                        (order==0 && strcmp(list[i].lastName, list[i+1].lastName) < 0))
                {
                    flag=TRUE;
                    swapEmployees(list, i);

                }
                else if(((order==1 && list[i].sector > list[i+1].sector) ||
                         (order==0 && list[i].sector < list[i+1].sector)) &&
                         strcmp(list[i].lastName, list[i+1].lastName) == 0)
                {
                    flag=TRUE;
                    swapEmployees(list, i);
                }
            }
        }
    }

    return retorno;
}

static void swapEmployees(Employee* list, int i)
{
    Employee aux;
    aux=list[i];
    list[i]=list[i+1];
    list[i+1]=aux;
}

int printEmployees(Employee* list, int length)
{
    int retorno=ERROR;
    int i;
    if(list!=NULL && length > 0)
    {
        for(i=0; i<length; i++)
        {
            if(list[i].isEmpty==FALSE)
            {
                printf("ID: %d  NAME: %s  LASTNAME: %s  SALARY: %.0f  SECTOR: %d\n",
                       list[i].id,
                       list[i].name,
                       list[i].lastName,
                       list[i].salary,
                       list[i].sector);
            }
        }
    }

    return retorno;
}
/* ************************************************************* */
static int emp_getIndexVacio(Employee* emp, int len)
{
    int i=0;
    int retorno;
    if(emp !=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(emp[i].isEmpty==TRUE)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
int generarID(void)
{
    static int id=-1;
    id++;
    return id;
}
int bajaEmpleados(Employee* em, int len)
{
    int retorno=ERROR;
    int idBaja;
    int indexBaja;

    if(em!=NULL && len>0)
    {
        printEmployees(em, len);
        if(utn_getEntero(&idBaja, 3, len, -1, "Ingrese ID a eliminar\n", "Error en ID a eliminar\n")==TODOOK)
        {
            indexBaja=findEmployeeById(em, len, idBaja);
            if(indexBaja!=ERROR)
            {
                em[indexBaja].isEmpty=TRUE;
                retorno=TODOOK;
                limpiarScreen();
            }
        }
    }
    return retorno;
}
int modificarEmpleados(Employee* em, int len)
{
    int retorno=ERROR;
    int idModificar;
    int varModificar;
    int indexModificar;
    Employee emAux[1];
    if(em!=NULL && len>0)
    {
        printEmployees(em, len);
        if(utn_getEntero(&idModificar, 3, len, -1, "Ingrese ID a modificar\n", "Error en ID a modificar\n")==TODOOK)
        {
            limpiarScreen();
            indexModificar=findEmployeeById(em, len, idModificar);

            if(utn_getEntero(&varModificar, 3, 6, 0, "1- Nombre\n2- Apellido\n3- Salario\n4- Sector\n5- Atras\nIngrese: ", "Opcion incorrecta\n")==TODOOK)
            {
                limpiarScreen();
                if(indexModificar!=ERROR)
                {
                    switch(varModificar)
                    {
                    case 1:
                        if(utn_getCadena(emAux[0].name, 51,3,"Ingrese nuevo nombre:\n", "Error en nombre ingresado\n")==TODOOK)
                        {
                            strncpy(em[indexModificar].name, emAux[0].name, strlen(emAux[0].name));
                            limpiarScreen();
                            printf("Registro modificado correctamente!\n");
                            retorno=TODOOK;
                        }
                        break;
                    case 2:
                        if(utn_getCadena(emAux[0].lastName, 51,3,"Ingrese nuevo apellido:\n", "Error en apellido ingresado\n")==TODOOK)
                        {
                            strncpy(em[indexModificar].lastName, emAux[0].lastName, strlen(emAux[0].lastName));
                            limpiarScreen();
                            printf("Registro modificado correctamente!\n");
                            retorno=TODOOK;
                        }
                        break;
                    case 3:
                        if(utn_getDecimal(&emAux[0].salary, 3, 100000,0,"Ingrese nuevo salario\n","Error en salario ingresado\n")==TODOOK)
                        {
                            em[indexModificar].salary=emAux[0].salary;
                            limpiarScreen();
                            printf("Registro modificado correctamente!\n");
                            retorno=TODOOK;
                        }
                        break;
                    case 4:
                        if(utn_getEntero(&emAux[0].sector, 3, 1000, 0, "Ingrese nuevo sector\n", "Error en sector ingresado\n")==TODOOK)
                        {
                            em[indexModificar].sector=emAux[0].sector;
                            limpiarScreen();
                            printf("Registro modificado correctamente!\n");
                            retorno=TODOOK;
                        }
                        break;
                    case 5:
                        retorno=TODOOK;
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }

    return retorno;
}
int altaEmpleados(Employee* em, int len)
{
    int retorno=ERROR;
    Employee emAux[1];
    if(em!=NULL && len>0 &&
        utn_getCadena(emAux[0].name, 51, 3, "Ingrese nombre:\n", "Error en nombre ingresado\n")==TODOOK &&
        utn_getCadena(emAux[0].lastName, 51, 3, "Ingrese apellido:\n", "Error en apellido ingresado\n")==TODOOK &&
        utn_getDecimal(&emAux[0].salary, 3, 100000, 0, "Ingrese salario:\n", "Error en salario ingresado\n")==TODOOK &&
        utn_getEntero(&emAux[0].sector, 3, 1000, -1, "Ingrese sector:\n", "Error en sector ingresado\n")==TODOOK)
        {
            emAux[0].id=generarID();
            retorno=addEmployee(em, len, emAux[0].id, emAux[0].name, emAux[0].lastName, emAux[0].salary, emAux[0].sector);
        }
    return retorno;
}

void llenarEmpleadosTest(Employee* empleados, int* hayEmpleados, int cantEmpleados)
{
    addEmployee(empleados, cantEmpleados, 1, "Rodrigo", "Bravo", 1, 10);
    addEmployee(empleados, cantEmpleados, 2, "Rodrigo", "Bravo", 25000, 1);
    addEmployee(empleados, cantEmpleados, 3, "Rodrigo", "Bravo", 12, 9);
    addEmployee(empleados, cantEmpleados, 4, "Rodrigo", "Mar", 25000, 10);
    addEmployee(empleados, cantEmpleados, 5, "Rodrigo", "Aaa", 25000, 1);
    addEmployee(empleados, cantEmpleados, 6, "Rodrigo", "Car", 25000, 2);
    addEmployee(empleados, cantEmpleados, 7, "Rodrigo", "Cor", 25000, 2);
    addEmployee(empleados, cantEmpleados, 8, "Rodrigo", "Pir", 25000, 2);
    addEmployee(empleados, cantEmpleados, 9, "Rodrigo", "Zor", 25000, 1);
    addEmployee(empleados, cantEmpleados, 10, "Rodrigo", "Zur", 25000, 2);
    addEmployee(empleados, cantEmpleados, 11, "Rodrigo", "Zar", 25000, 3);
    addEmployee(empleados, cantEmpleados, 12, "Rodrigo", "Abo", 25000, 9);
    addEmployee(empleados, cantEmpleados, 13, "Rodrigo", "Mer", 25000, 1);
    addEmployee(empleados, cantEmpleados, 14, "Rodrigo", "Sor", 25000, 8);
    addEmployee(empleados, cantEmpleados, 15, "Rodrigo", "Asdqwe", 25000, 5);
    *hayEmpleados=TRUE;
}
