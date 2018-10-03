#include "Employee.h"
static int emp_getIndexVacio(Employee* emp, int len);

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
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
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int retorno=TODOOK;
    int indexVacio;
    int i;
    if(list!=NULL && len>0 && name!=NULL && lastName!=NULL && salary>0)
    {
        for(i=0; i<len;i++)
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

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
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

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
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

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
    int retorno=ERROR;
    int i;
    int flag=TRUE;
    Employee aux[1];

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
                    strncpy(aux[0].lastName, list[i].lastName,sizeof(list[i].lastName));
                    strncpy(list[i].lastName,list[i+1].lastName,sizeof(list[i+1].lastName));
                    strncpy(list[i+1].lastName,aux[0].lastName,sizeof(aux[0].lastName));

                    aux[0].id=list[i].id;
                    list[i].id=list[i+1].id;
                    list[i+1].id=aux[0].id;

                    strncpy(aux[0].name,list[i].name,sizeof(list[i].name));
                    strncpy(list[i].name,list[i+1].name,sizeof(list[i+1].name));
                    strncpy(list[i+1].name,aux[0].name,sizeof(aux[0].name));

                    aux[0].salary=list[i].salary;
                    list[i].salary=list[i+1].salary;
                    list[i+1].salary=aux[0].salary;

                    aux[0].sector=list[i].sector;
                    list[i].sector=list[i+1].sector;
                    list[i+1].sector=aux[0].sector;

                    aux[0].isEmpty=list[i].isEmpty;
                    list[i].isEmpty=list[i+1].isEmpty;
                    list[i+1].isEmpty=aux[0].isEmpty;
                }
                else if(((order==1 && list[i].sector > list[i+1].sector) || (order==0 && list[i].sector < list[i+1].sector))
                        && strcmp(list[i].lastName, list[i+1].lastName) == 0)
                {
                    flag=TRUE;

                    strncpy(aux[0].lastName, list[i].lastName,sizeof(list[i].lastName));
                    strncpy(list[i].lastName,list[i+1].lastName,sizeof(list[i+1].lastName));
                    strncpy(list[i+1].lastName,aux[0].lastName,sizeof(aux[0].lastName));

                    aux[0].id=list[i].id;
                    list[i].id=list[i+1].id;
                    list[i+1].id=aux[0].id;

                    strncpy(aux[0].name,list[i].name,sizeof(list[i].name));
                    strncpy(list[i].name,list[i+1].name,sizeof(list[i+1].name));
                    strncpy(list[i+1].name,aux[0].name,sizeof(aux[0].name));

                    aux[0].salary=list[i].salary;
                    list[i].salary=list[i+1].salary;
                    list[i+1].salary=aux[0].salary;

                    aux[0].sector=list[i].sector;
                    list[i].sector=list[i+1].sector;
                    list[i+1].sector=aux[0].sector;

                    aux[0].isEmpty=list[i].isEmpty;
                    list[i].isEmpty=list[i+1].isEmpty;
                    list[i+1].isEmpty=aux[0].isEmpty;
                }
            }
        }
    }

    return retorno;
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
                            printf("Registro modificado correctamente!\n");
                            retorno=TODOOK;
                        }
                        break;
                    case 2:
                        if(utn_getCadena(emAux[0].lastName, 51,3,"Ingrese nuevo apellido:\n", "Error en apellido ingresado\n")==TODOOK)
                        {
                            strncpy(em[indexModificar].lastName, emAux[0].lastName, strlen(emAux[0].lastName));
                            printf("Registro modificado correctamente!\n");
                            retorno=TODOOK;
                        }
                        break;
                    case 3:
                        if(utn_getDecimal(&emAux[0].salary, 3, 100000,0,"Ingrese nuevo salario\n","Error en salario ingresado\n")==TODOOK)
                        {
                            em[indexModificar].salary=emAux[0].salary;
                            printf("Registro modificado correctamente!\n");
                            retorno=TODOOK;
                        }
                        break;
                    case 4:
                        if(utn_getEntero(&emAux[0].sector, 3, 1000, 0, "Ingrese nuevo sector\n", "Error en sector ingresado\n")==TODOOK)
                        {
                            em[indexModificar].sector=emAux[0].sector;
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
    if(em!=NULL && len>0)
    {
        if(utn_getCadena(emAux[0].name, 51, 3, "Ingrese nombre:\n", "Error en nombre ingresado\n")==TODOOK)
        {
            if(utn_getCadena(emAux[0].lastName, 51, 3, "Ingrese apellido:\n", "Error en apellido ingresado\n")==TODOOK)
            {
                if(utn_getDecimal(&emAux[0].salary, 3, 100000, 0, "Ingrese salario:\n", "Error en salario ingresado\n")==TODOOK)
                {
                    if(utn_getEntero(&emAux[0].sector, 3, 1000, -1, "Ingrese sector:\n", "Error en sector ingresado\n")==TODOOK)
                    {
                        emAux[0].id=generarID();
                        retorno=addEmployee(em, len, emAux[0].id, emAux[0].name, emAux[0].lastName, emAux[0].salary, emAux[0].sector);
                    }
                }
            }
        }
    }

    return retorno;
}
