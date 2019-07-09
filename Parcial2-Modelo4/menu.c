#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"
#include "validaciones.h"




int menu()
{
    int opcion;
    fflush(stdin);
    printf("MENU:\n"
            "1. Cargar empleados.\n"
            "2. Listar y ordenar por nombre.\n"
            "3. Calcular sueldos.\n"
            "4. Listar con sueldos.\n"
            "5. Crear lista filtrada.\n"
            "6. Guardar nueva lista.\n"
            "7. Salir\n"
           "Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion < 0 || opcion > 7)
    {
        printf("Por favor, ingrese una opcion valida\n");
        system("pause");
        system("cls");
        fflush(stdin);
        printf("MENU:\n"
            "1. Cargar empleados.\n"
            "2. Listar y ordenar por nombre.\n"
            "3. Calcular sueldos.\n"
            "4. Listar con sueldos.\n"
            "5. Crear lista filtrada.\n"
            "6. Guardar nueva lista.\n"
            "7. Salir\n"
           "Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}

int subMenuModificar()
{
    int opcion;
    opcion = getInt("1. Nombre\n"
                    "2. Horas Trabajadas\n"
                    "3. Sueldo\n"
                    "Ingrese una opcion: ");

    while(opcion < 0 || opcion > 3)
    {
        opcion = getInt("Por favor, ingrese una opcion valida\n"
                        "1. Nombre\n"
                        "2. Horas Trabajadas\n"
                        "3. Sueldo\n"
                        "Ingrese una opcion: ");
    }
    return opcion;
}

int subMenuOrdenar()
{
    int opcion;
    opcion = getInt("Ingrese de que manera desea ordenar a los empleados: \n"
                    "1. ID\n"
                    "2. Nombre\n"
                    "3. Horas Trabajadas\n"
                    "4. Sueldo\n"
                    "Ingrese una opcion: ");

    while(opcion < 0 || opcion > 4)
    {
        opcion = getInt("Por favor, ingrese una opcion valida\n"
                        "1. ID\n"
                        "2. Nombre\n"
                        "3. Horas Trabajadas\n"
                        "4. Sueldo\n"
                        "Ingrese una opcion: ");
    }
    return opcion;
}


