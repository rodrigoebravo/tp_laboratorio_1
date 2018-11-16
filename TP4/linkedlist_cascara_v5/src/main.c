/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
void printMenu(int* option);
int main(void)
{

        //startTesting(1);  // ll_newLinkedList
        //startTesting(2);  // ll_len
        //startTesting(3);  // getNode - test_getNode
        //startTesting(4);  // addNode - test_addNode
        //startTesting(5);  // ll_add
        //startTesting(6);  // ll_get
        //startTesting(7);  // ll_set
        //startTesting(8);  // ll_remove
        //startTesting(9);  // ll_clear
        //startTesting(10); // ll_deleteLinkedList
        //startTesting(11); // ll_indexOf
        //startTesting(12); // ll_isEmpty
        //startTesting(13); // ll_push
        //startTesting(14); // ll_pop
        //startTesting(15); // ll_contains
        //startTesting(16); // ll_containsAll
        //startTesting(17); // ll_subList
        //startTesting(18); // ll_clone
        //startTesting(19); // ll_sort

    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int hayDatosEnLista=FALSE;
    int esArchivoTexto=FALSE;
    int esArchivoBin=FALSE;

    do{
        printMenu(&option);
        switch(option)
        {
            case 1:
                limpiarScreen();
                if(controller_loadFromText("data.csv",listaEmpleados)==TODOOK)
                {
                    hayDatosEnLista=TRUE;
                    esArchivoTexto=TRUE;
                }
                break;
            case 2:
                limpiarScreen();
                if(controller_loadFromBinary("data.b",listaEmpleados)==TODOOK)
                {
                    hayDatosEnLista=TRUE;
                    esArchivoBin=TRUE;
                }
                break;
            case 3:
                limpiarScreen();
                if(controller_addEmployee(listaEmpleados)==TODOOK)
                {
                    hayDatosEnLista=TRUE;
                    printf("Dato ingresado correctamente\n");
                }
                else
                {
                    printf("No hay datos para procesar\n");
                }
                break;
            case 4:
                limpiarScreen();
                if(hayDatosEnLista && controller_editEmployee(listaEmpleados)==TODOOK)
                    printf("Modificacion exitosa\n");
                else
                    printf("No hay datos para procesar\n");
                break;
            case 5:
                limpiarScreen();
                if(hayDatosEnLista && controller_removeEmployee(listaEmpleados)==TODOOK)
                    printf("Dato eliminado correctamente\n");
                else
                    printf("No hay datos para procesar\n");
                break;
            case 6:
                limpiarScreen();
                if(!hayDatosEnLista || controller_ListEmployee(listaEmpleados)!=TODOOK)
                    printf("No es posible listar datos\n");
                break;
            case 7:
                limpiarScreen();
                if(hayDatosEnLista && controller_sortEmployee(listaEmpleados)==TODOOK)
                    printf("Ordenamiento exitoso\n");
                else
                    printf("No fue posible ordenar\n");
                break;
            case 8:
                limpiarScreen();
                if(hayDatosEnLista && controller_saveAsText("data.csv", listaEmpleados)==TODOOK)
                    printf("El archivo fue grabado exitosamente\n");
                else
                    printf("No fue posible grabar datos\n");

                break;
            case 9:
                limpiarScreen();
                if(hayDatosEnLista && controller_saveAsBinary("data.b", listaEmpleados)==TODOOK)
                    printf("Creado exitosamente\n");
                else
                    printf("No fue posible grabar datos\n");

                break;
            case 10:
                limpiarScreen();
                if(hayDatosEnLista && controller_limpiarLista(listaEmpleados)==TODOOK)
                    printf("Se vacio la lista corractamente\n");
                else
                    printf("No fue posible limpiar la lista\n");
                break;
            case 11:
                limpiarScreen();
                if(hayDatosEnLista && esArchivoTexto)
                {
                    listaEmpleados=controller_ResetLista(listaEmpleados, "data.csv");
                    printf("Lista de empleados reiniciada\n");
                }
                else if(hayDatosEnLista && esArchivoBin)
                {

                    listaEmpleados=controller_ResetLista(listaEmpleados, "data.b");
                    printf("Lista de empleados reiniciada\n");
                }
                else
                {
                    printf("No fue posible reiniciar la lista\n");
                }
                break;
            case 12:
                limpiarScreen();
                if(hayDatosEnLista)
                    controller_printSubLista(listaEmpleados);
                else
                    printf("No existen datos para mostrar\n");
                break;
        }
    }while(option != 13);
    return 0;
}

/** \brief Muestra menu y pide opcion.
 * \param int* option
 * \return void
 */
void printMenu(int* option)
{
    char menu[]="1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Limpiar lista de empleados\n11. Reiniciar lista\n12. Mostrar SubLista\n13. Salir\n";
    utn_getEntero(option, 3, 101, 0, menu, "Opcion incorrecta\n");
}
