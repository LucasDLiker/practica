#ifndef GENERO_H_INCLUDED
#define GENERO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
int genreId;
char descripcion[50];
int isEmpty;
}eGenero;

int generatesNextIdGenres();
int initGenre(eGenero *generos, int GENRESMAX);




#endif

