#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "toolbox.h"

int mainMenu()
{
    int opcion;
    opcion=getInt("----------------------------\n"
                  "|          MENU:            |\n"
                  "|   1: Alta Pelicula        |\n"
                  "|   2: Modificar            |\n"
                  "|   3: Baja                 |\n"
                  "|   4: Listar               |\n"
                  "|   5: informes             |\n"
                  "|   6:                      |\n"
                  "|   7:                      |\n"
                  "|   8:                      |\n"
                  "|   9: Salir                |\n"
                  "|                           |\n"
                  "----------------------------\n"
                  "Ingresar una opcion: ");
    while (opcion < 1 || opcion > 9)
    {
        printf("Error. Ingrese una opcion valida.");
        system("pause");
        system("cls");
        opcion=getInt("----------------------------\n"
                     "|          MENU:            |\n"
                     "|   1: Alta                 |\n"
                     "|   2: Modificar            |\n"
                     "|   3: Baja                 |\n"
                     "|   4: Listar               |\n"
                     "|   5: informes             |\n"
                     "|   6:                      |\n"
                     "|   7:                      |\n"
                     "|   8:                      |\n"
                     "|   9: Salir                |\n"
                     "|                           |\n"
                     "----------------------------\n"
                     "Ingresar una opcion: ");

    }

    return opcion;
}
