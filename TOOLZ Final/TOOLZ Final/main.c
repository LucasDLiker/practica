#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

int main()
{
    char mainMenuSelection;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int isEmpty=0;

    int horasMaximo=0;
    int horasMinimo=0;
    int horasTotal=0;
    float sueldosTotal=0;
    float salaryPromedio;
    LinkedList *new_Filtered_List=ll_newLinkedList();
///    int new_Reduced_List;
    int cuentaFinal=-100;
    do
    {
        isEmpty=ll_isEmpty(listaEmpleados);
        mainMenu ();
        mainMenuSelection=getche();

        switch (mainMenuSelection)
        {
        case '1':
        {

            if(isEmpty)
            {
                controller_loadFromText("data.csv",listaEmpleados);
            }
            else
            {
                printf("\n\nYa se han cargado los datos anteriormente\n\n");
            }
            system("pause");
            break;
        }
        case '2':
        {
            if(isEmpty)
            {
                controller_loadFromBinary("data.bin",listaEmpleados);
            }
            else
            {
                printf("\n\nYa se han cargado los datos anteriormente\n\n");
            }
            system("pause");
            break;
        }
        case '3':
        {
            if(!isEmpty)
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("\n\nNo se han cargado datos aun. Debes cargar un archivo primero.\n\n\n\n");
            }
            system("pause");
            break;
        }
        case '4':
        {
            if(!isEmpty)
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("\n\nNo se han cargado datos aun. Debes cargar un archivo primero.\n\n\n\n");
            }
            system("pause");
            break;
        }
        case '5':
        {
            if(!isEmpty)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("\n\nNo se han cargado datos aun. Debes cargar un archivo primero.\n\n\n\n");
            }
            system("pause");
            break;
        }
        case '6':
        {
            if(!isEmpty)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("\n\nNo se han cargado datos aun. Debes cargar un archivo primero.\n\n\n\n");
            }
            system("pause");
            break;
        }
        case '7':
        {
            if(!isEmpty)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("\n\nNo se han cargado datos aun. Debes cargar un archivo primero.\n\n\n\n");
            }
            system("pause");
            break;
        }
        case '8':
        {
            if(!isEmpty)
            {
                controller_saveAsText("data.csv",listaEmpleados);
            }
            else
            {
                printf("\n\nNo se han cargado datos aun. Debes cargar un archivo primero.\n\n\n\n");
            }

            system("pause");
            break;
        }
        case '9':
        {
            if(!isEmpty)
            {
                controller_saveAsBinary("data.bin",listaEmpleados);
            }
            else
            {
                printf("\n\nNo se han cargado datos aun. Debes cargar un archivo primero.\n\n\n\n");
            }

            system("pause");
            break;
        }
        case 's':
        {
            printf("\n\nUd Eligio Salir\n\n");
            system("pause");
            break;
        }
        case 'S':
        {
            printf("\n\nUd Eligio Salir\n\n");
            system("pause");
            break;
        }
        case 'y':///HS TOTAL   /// SUELDOS TOTAL
        {
            horasTotal=sumadorDeEnteros(listaEmpleados);
            printf("\n\nMAIN horasTotal: %d\n\n", horasTotal);

            sueldosTotal=sumadorDeFloat(listaEmpleados);
            printf("\n\nMAIN sueldosTotal: %.2f\n\n", sueldosTotal);
            system("pause");
            break;
        }
        case 't':///HS MAXIMO       HS MINIMO
        {
            horasMaximo=maximoHoras (listaEmpleados);
            horasMinimo=minimoHoras (listaEmpleados);
            printf("\n\nhorasMaximo: %d     horasMinimo: %d\n\n", horasMaximo, horasMinimo);
            system("pause");
            break;
        }
        case 'r':///SUELDO PROMEDIO
        {
            salaryPromedio=promedioSueldos(listaEmpleados);
            printf("\n\nMAIN SUELDOS PROMEDIO: %.2f \n", salaryPromedio);
            system("pause");
            break;
        }
        case 'e':///FILTER
        {
            if (new_Filtered_List!=NULL)
            {
                new_Filtered_List=ll_filter(listaEmpleados, FilteredList);
                controller_ListEmployee(new_Filtered_List);
                system("pause");
                controller_ListEmployee(listaEmpleados);
                system("pause");
            }
            else
            {
                printf("\n\nNo hay lista para mostrar\n\n");
                system("pause");
            }
            break;
        }
        case 'w':
        {

            reduceList(listaEmpleados);
            controller_ListEmployee(listaEmpleados);
            system("pause");
            break;

        }
        case 'q':
        {
            ll_Name_Compare (listaEmpleados, foo_Compara_Letras);
            system("pause");
            break;
        }
        case 'p':
        {
            cuentaFinal=ll_counter (listaEmpleados, foo_Contador);
            printf("cuentaFinal: %d", cuentaFinal);
            system("pause");
            break;
        }
        default:
        {
            break;
        }
        }
    }
    while (mainMenuSelection!='s' && mainMenuSelection!='S');

    return 0;

}
///-------------------------------------------------------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------------------------------------------------------

