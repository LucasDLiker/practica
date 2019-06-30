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
//    sFecha* arrayFecha;
    int genero;
    int actor;
    int datoOcupado;
} sPeliculas;

typedef struct
{
    int id;
    char genero[20];
    int datoOcupado;
}sGeneros;






int inicializarEstadoPeliculas(sPeliculas* arrayPeliculas, int capacidad);//
int inicializarEstadoGeneros (sGeneros* arrayGeneros, int capacidad);
int buscarLibreGeneros(sGeneros* arrayGeneros, int capacidad);
int buscarLibrePeliculas(sPeliculas* arrayPeliculas, int capacidad);//
int datoCargado(sPeliculas* arrayPeliculas, int capacidad);//
int encontrarPeliculaPorID(sPeliculas* arrayPeliculas, int capacidad, int id);//
void mostrarListaGeneros(sGeneros* arrayGeneros, int cantidad);
int agregarPelicula(sPeliculas* arrayPeliculas, int capacidad, sActores* arrayActores, sGeneros* arrayGeneros);//
void ordenarPeliculasPorFecha(sPeliculas* listaPeliculas, int cantidad);
void mostrarListaPeliculas(sPeliculas* listaPeliculas, int cantidadPeliculas, sActores* listaActores, int cantidadActores, sGeneros* listaGeneros, int cantidadGeneros);
int eliminarPelicula(sPeliculas* listaPeliculas, int cantidadPeliculas, sActores* listaActores, int cantidadActores, sGeneros* listaGeneros, int cantidadGeneros);
void modificarPelicula(sPeliculas* arrayPeliculas, int capacidad, sActores* arrayActores, int capacidadActores, sGeneros* arrayGeneros, int capacidadGeneros);


void mostrarUnaPelicula(sPeliculas* listaPeliculas, int indice, sActores* listaActores, int cantidadActores, sGeneros* listaGeneros, int cantidadGeneros);
void mostrarTodasLasPeliculas(sPeliculas* listaPeliculas, int cantidadPeliculas, sActores* listaActores, int cantidadActores, sGeneros* listaGeneros, int cantidadGeneros);

#endif
