#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"
#include "validaciones.h"
int main()
{
    int option;
    int test;
    int flag=0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleadosFiltrada = ll_newLinkedList();

    do
    {
        option = menu();

        switch(option)
        {
        case 1:
            test = controller_loadEmpleados("datos.csv",listaEmpleados);
            if(test==TRUE)
            {
                printf("\nEmpleados cargados con exito.\n\n");

            }
            else
            {
                printf("\nError, no se pudo cargar los datos.\n\n");
                system("pause");
                exit(EXIT_FAILURE);
            }
            system("pause");
            system("cls");
            break;
        case 2:
            if(ll_isEmpty(listaEmpleados) == 1)
            {
                printf("\nNo hay datos cargados.\n\n");
            }
            else
            {
                controller_sortEmployee(listaEmpleados);
                controller_ListEmployee(listaEmpleados);
            }

            system("pause");
            system("cls");
            break;
        case 3:
            if(ll_isEmpty(listaEmpleados) == 1)
            {
                printf("\nNo hay datos cargados.\n\n");
            }
            else
            {
                ll_map(listaEmpleados,employee_calcularSueldo);
                printf("\nSueldos calculados con exito.\n\n");
            }

            system("pause");
            system("cls");
            break;
        case 4:
            if(ll_isEmpty(listaEmpleados) == 1)
            {
                printf("\nNo hay datos cargados.\n\n");
            }
            else
            {
                controller_ListEmployeeConSueldo(listaEmpleados);
            }

            system("pause");
            system("cls");
            break;
        case 5:
            if(ll_isEmpty(listaEmpleados) == 1)
            {
                printf("\nNo hay datos cargados.\n\n");
            }
            else
            {
                listaEmpleadosFiltrada = ll_filter(listaEmpleados,employee_empleadosProgramadores);
                printf("\nLista filtrada con exito.\n\n");
            }

            system("pause");
            system("cls");
            break;
        case 6:
            if(ll_isEmpty(listaEmpleadosFiltrada) == 1 || ll_isEmpty(listaEmpleados) == 1)
            {
                printf("\nNo hay datos cargados.\n\n");
            }
            else
            {
                controller_guardarTexto("resultados.csv",listaEmpleadosFiltrada);
                printf("\nLista nueva impresa con exito.\n\n");
            }

            system("pause");
            system("cls");
            break;
        case 7:
            printf("\nGracias por utilizar el sistema.\n\n");
            system("pause");
            system("cls");
            break;
//        case 5:
//            listaEmpleadosDos = ll_filter(listaEmpleados,employee_empleadosPlatudos);
//            test = controller_guardarSueldos("platudos.csv",listaEmpleadosDos);
//            if(test==TRUE)
//            {
//                printf("Archivo guardado con exito.\n");
//            }
//            else
//            {
//                printf("Error, no se pudo guardar los datos.\n");
//            }
//            system("pause");
//            system("cls");
//            break;
        }
    }
    while(option != 7);
    return 0;
}
