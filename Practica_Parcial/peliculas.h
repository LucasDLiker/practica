#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#define ILOGICO -1
#define LIBRE 0
#define OCUPADO 1
#define MAX 1000

#ifndef arrayPeliculas

typedef struct
{
    int id;
    char titulo[51];
    int dia;
    int mes;
    int anio;
    int genero;
    int actor;
    int isEmpty;

}sPeliculas;

#endif // arrayPeliculas


int inicioEstadoPeliculas(sPeliculas* arrayPeliculas, int capacidad);
int buscarLibrePeliculas(sPeliculas* arrayPeliculas, int capacidad);
int agregarPelicula(sPeliculas* arrayPeliculas, int capacidad);
void mostrarListaPeliculas(sPeliculas* listaPeliculas, int cantidad);
