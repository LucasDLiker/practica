#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "estructuraUno.h"
#include "estructuraDos.h"
#include "funcionesGenericas.h"
#include "menu.h"
#include "hardcode.h"
#include "validaciones.h"


int main()
{
    sPeliculas arrayPeliculas[LIMITE];
    sActores arrayActores[LIMITE];


    inicializarEstadoPeliculas(arrayPeliculas, LIMITE);
    inicializarEstadoActores(arrayActores, LIMITE);

    int opcion;
    char confirmacion;
    int flagUno;
    int flagDos;
    int lugarLibre;


    do
    {
        opcion = menuPrincipal();
        switch(opcion)
        {
        case 1:
            lugarLibre=buscarLibrePeliculas(arrayPeliculas, LIMITE);
            if (lugarLibre!=-1)
            {
//                opcion = subMenuAltas();
//                switch(opcion)
//                {
//                case 1:
                    agregarPelicula(arrayPeliculas, LIMITE);
                    break;
//                case 2:
//                    agregarActor(arrayActores, LIMITE);
//                    break;
//                }
            }
            else
            {
                printf("No hay mas espacio\n");
                system("pause");
                system("cls");
            }
            break;
        case 2:
            flagUno = datoCargado(arrayPeliculas, LIMITE);
            flagDos = datoCargadoActores(arrayActores, LIMITE);
            if (flagUno == 0 || flagDos == 0)
            {
                opcion = subMenuListar();
                switch(opcion)
                {
                case 1:
                    if (flagUno == 0)
                    {
                        ordenarPeliculasPorFecha(arrayPeliculas, LIMITE);
                        mostrarListaPeliculas(arrayPeliculas,LIMITE/*,arrayActores,LIMITE*/);
                    }
                    else
                    {
                        printf("No hay datos cargados.\n");
                    }
                    break;
                case 2:
//                    if (flagDos == 0)
//                    {
//                        mostrarListaActores(arrayActores, LIMITE);
//                    }
//                    else
//                    {
//                        printf("No hay datos cargados.\n");
//                    }
                        ordenarActoresPorNacionalidad(arrayActores, LIMITE);
                        mostrarListaActores(arrayActores, LIMITE);



                    break;
                }
            }
            else
            {
                printf("No hay datos cargados.\n");
            }
            system("pause");
            system("cls");
            break;
        case 3:
            flagUno = datoCargado(arrayPeliculas, LIMITE);
            flagDos = datoCargadoActores(arrayActores, LIMITE);
            if (flagUno == 0 || flagDos == 0)
            {
//                opcion = subMenuBaja();
//                switch(opcion)
//                {
//                case 1:
                    if (flagUno == 0)
                    {
                        mostrarListaPeliculas(arrayPeliculas,LIMITE/*,arrayActores,LIMITE*/);
                        eliminarPelicula(arrayPeliculas, LIMITE);
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        printf("No hay datos cargados.\n");
                    }
                    break;
//                case 2:
//                    if (flagDos == 0)
//                    {
//                        mostrarListaActores(arrayActores, LIMITE);
//                        eliminarActor(arrayActores, LIMITE);
//                    }
//                    else
//                    {
//                        printf("No hay datos cargados.\n");
//                    }
//                    break;
//                }
            }
            else
            {
                printf("No hay datos cargados.\n");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            flagUno = datoCargado(arrayPeliculas, LIMITE);
            flagDos = datoCargadoActores(arrayActores, LIMITE);
            if (flagUno == 0 || flagDos == 0)
            {
//                opcion = subMenuModificar();
//                switch(opcion)
//                {
//                case 1:
                    if (flagUno == 0)
                    {
                        mostrarListaPeliculas(arrayPeliculas,LIMITE/*,arrayActores,LIMITE*/);
                        modificarPelicula(arrayPeliculas, LIMITE);
                        do
                        {
                            confirmacion = getChar("Desea seguir modificando datos? S/N ");
                            switch(confirmacion)
                            {
                            case 's':
                                modificarPelicula(arrayPeliculas, LIMITE);
                                system("cls");
                                break;
                            case 'n':
                                system("cls");
                                break;
                            default:
                                printf("Ingrese una opcion valida.\n");
                                break;
                            }
                        }
                        while (confirmacion != 'n');
                    }
                    else
                    {
                        printf("No hay datos cargados.\n");
                    }
                    break;
//                case 2:
//                    if (flagDos == 0)
//                    {
//                        mostrarListaActores(arrayActores, LIMITE);
//                        modificarActores(arrayActores, LIMITE);
//                        do
//                        {
//                            confirmacion = getChar("Desea seguir modificando datos? S/N ");
//                            switch(confirmacion)
//                            {
//                            case 's':
//                                modificarActores(arrayActores, LIMITE);
//                                break;
//                            case 'n':
//                                system("cls");
//                                break;
//                            default:
//                                printf("Ingrese una opcion valida.\n");
//                                break;
//                            }
//                        }
//                        while (confirmacion != 'n');
//                    }
//                    else
//                    {
//                        printf("No hay datos cargados.\n");
//                    }
//                }
            }

            else
            {
                printf("No hay datos cargados.\n");
            }
            system("pause");
            system("cls");
            break;
        case 5:
            printf("APROBAME PLS\n");
            system("pause");
            system("cls");
            break;
        case 777:
            hardcodePeliculas(arrayPeliculas, LIMITE, 1000, 2, "Avengers EndGame", 1, 20, 4, 2019, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1001, 5, "Thor", 1, 10, 6, 2013, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1002, 4, "Cellular", 1, 2, 5, 2004, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1003, 5, "Men in Black 4", 1, 10, 7, 2019, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1004, 2, "Iron Man", 1, 5, 9, 2012, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1005, 3, "13 going on 30", 4, 7, 5, 2004, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1006, 1, "Lucy", 1, 9, 2,	2014, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1007, 9, "Nace una estrella", 4, 8, 3, 2018, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1008, 4, "¿Dime con cuantos?", 4, 4, 4, 2010, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1009, 9, "Guardianes de la galaxia", 1, 20, 5, 2014, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1010, 7, "A perfect murder", 3, 6, 8, 1995, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1011, 1, "La isla", 3, 3, 10, 2005, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1012, 9, "¿Que paso ayer?", 2, 5, 2, 2013, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1013, 1, "Home Alone 3", 2, 6, 10, 1997, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1014, 10, "Deadpool", 1, 7, 12, 2015, 0 );
            hardcodePeliculas(arrayPeliculas, LIMITE, 1015, 2, "Sherlock Holmes", 1, 5, 6, 2011, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1016, 10, "Men in Black 3", 1, 2, 5, 2010, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1017, 10, "Avengers: Infinity War", 1, 6, 4, 2017, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1018, 7, "Grandes esperanzas", 4, 8, 12, 1995, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1019, 6, "SWAT", 1, 20, 2, 1998, 0);
            hardcodePeliculas(arrayPeliculas, LIMITE, 1020, 6, "XxX", 1, 11, 5, 1992, 0);

            hardcodeActores(arrayActores, LIMITE, 1, "Scarlett Johansson", "Argentina", 0);
            hardcodeActores(arrayActores, LIMITE, 2, "Robert  Downey Jr", "EEUU", 0);
            hardcodeActores(arrayActores, LIMITE, 3, "Mark Ruffalo", "Canada", 0);
            hardcodeActores(arrayActores, LIMITE, 4, "Chris Evans", "EEUU", 0);
            hardcodeActores(arrayActores, LIMITE, 5, "Chris Hemsworth", "Argentina", 0);
            hardcodeActores(arrayActores, LIMITE, 6, "Samuel L. Jackson", "EEUU", 0);
            hardcodeActores(arrayActores, LIMITE, 7, "Gwyneth Paltrow", "Canada", 0);
            hardcodeActores(arrayActores, LIMITE, 8, "Paul Rudd", "Argentina", 0);
            hardcodeActores(arrayActores, LIMITE, 9, "Bradley Cooper", "EEUU", 0);
            hardcodeActores(arrayActores, LIMITE, 10, "Josh Brolin", "Canada", 0);

            system("cls");
            break;
        }
    }
    while(opcion != 5);
    return 0;
}
