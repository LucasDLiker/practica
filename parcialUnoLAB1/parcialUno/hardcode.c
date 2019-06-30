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


void hardcodePeliculas(sPeliculas* arrayPeliculas, int capacidad, int id, int auxActor, char auxTitulo[], int auxGenero, int auxDia, int auxMes, int auxAnio, int datoOcupado)
{
    int index = buscarLibrePeliculas(arrayPeliculas, capacidad);
    arrayPeliculas[index].id= id;
    strcpy(arrayPeliculas[index].titulo, auxTitulo);
    arrayPeliculas[index].actor = auxActor;
    arrayPeliculas[index].genero = auxGenero;
    arrayPeliculas[index].dia = auxDia;
    arrayPeliculas[index].mes = auxMes;
    arrayPeliculas[index].anio = auxAnio;
    arrayPeliculas[index].datoOcupado = OCUPADO;

}

void hardcodeActores(sActores* arrayActores, int capacidad, int id, char auxNombre[], char auxNacionalidad[], int datoOcupado)
{
    int index = buscarLibreActores(arrayActores, capacidad);
    arrayActores[index].id= id;
    strcpy(arrayActores[index].nombre, auxNombre);
    strcpy(arrayActores[index].nacionalidad, auxNacionalidad);
    arrayActores[index].datoOcupado = OCUPADO;

}

void hardcodeGeneros(sGeneros* arrayGeneros, int capacidad, int id, char auxGenero[], int datoOcupado)
{
    int index = buscarLibreGeneros(arrayGeneros, capacidad);
    arrayGeneros[index].id= id;
    strcpy(arrayGeneros[index].genero, auxGenero);
    arrayGeneros[index].datoOcupado = OCUPADO;

}

