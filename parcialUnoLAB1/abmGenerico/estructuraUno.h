#define ILOGICO -1
#define OCUPADO 0
#define LIBRE 1
#define LIMITE 1000

#ifndef ESTRUCTURAUNO_H_INCLUDED
#define ESTRUCTURAUNO_H_INCLUDED
#include "estructuraDos.h"


typedef struct
{
    int id;
    char titulo[51];
    int dia;
    int mes;
    int anio;
    int genero;
    int actor;
    int datoOcupado;
} sPeliculas;

//typedef struct
//{
//    int dia;
//    int mes;
//    int anio;
//}sFecha;

typedef struct
{
    int id;
    char genero[20];
    int datoOcupado;
}sGeneros;






int inicializarEstadoPeliculas(sPeliculas* arrayPeliculas, int capacidad);//
int buscarLibrePeliculas(sPeliculas* arrayPeliculas, int capacidad);//
int datoCargado(sPeliculas* arrayPeliculas, int capacidad);//
int encontrarPeliculaPorID(sPeliculas* arrayPeliculas, int capacidad, int id);//
int agregarPelicula(sPeliculas* arrayPeliculas, int capacidad);//
void ordenarPeliculasPorFecha(sPeliculas* listaPeliculas, int cantidad);
void mostrarListaPeliculas(sPeliculas* listaPeliculas, int cantidadPeliculas/*, sCosasDos* listaCosasDos, int cantidadCosasDos*/);
int eliminarPelicula(sPeliculas* arrayPeliculas, int capacidad);
void modificarPelicula(sPeliculas* arrayPeliculas, int capacidad);

#endif
