#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "menu.h"
#include "peliculas.h"


int main()
{

    //VARIABLES
    int opcion;
    int freeSlot;

    //INICIAR ESTADO
    sPeliculas arrayPeliculas[MAX];


    do
    {
     opcion=mainMenu();
     switch(opcion)
     {
      case 1:
          freeSlot=buscarLibrePeliculas(arrayPeliculas, MAX);
          if(freeSlot != -1)
          {
              agregarPelicula(arrayPeliculas, MAX);
          }
      break;
      case 2:
      break;
      case 3:
      break;
      case 4:
          mostrarListaPeliculas(arrayPeliculas, MAX);
          system("pause");
      break;
      case 5:
      break;
      case 6:
      break;
      case 7:
      break;
      case 8:
      break;
      case 9:
      printf("Bye\n");
      break;



     }

    }while(opcion!=9);


    return 0;
}
