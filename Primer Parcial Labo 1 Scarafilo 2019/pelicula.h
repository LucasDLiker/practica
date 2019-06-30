#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

#include "pelicula.h"
#include "fecha.h"
#include "genero.h"
#include "actor.h"


typedef struct
{
int id;
char titulo[50];
eDate fechaDeEstreno;
int actor;
int genero;
int isEmpty;
}ePelicula;

int generatesNextIdpeliculas();
int initPeliculas(ePelicula *peliculas, int PELISMAX);
int obtainFreeSpacePeliculas(ePelicula* peliculas, int PELISMAX);
int addPelicula (ePelicula *peliculas, int PELISMAX, eGenero *generos, int GENRESMAX, eActor *actores, int ACTORESMAX);
int removePeli(ePelicula* peliculas, int PELISMAX, eGenero *generos, int GENRESMAX, eActor *actores, int ACTORESMAX);
int findPeliById(ePelicula* peliculas, int PELISMAX,int id);
int modifyPeli(ePelicula* peliculas, int PELISMAX, eGenero *generos, int GENRESMAX, eActor *actores, int ACTORESMAX);

#endif

