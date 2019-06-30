#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "pelicula.h"
#include "actor.h"
#include "genero.h"
#include "controlfoos.h"
#include "utn.h"


void Actors_Name_Alphabetically_orderByInsertion(eActor *actores, int ACTORESMAX);   ///A-Z
void Actors_Name_Descendent_Alphabetically_orderByInsertion(eActor *actores, int ACTORESMAX);   ///Z-A
void Pelis_Name_Alphabetically_orderByInsertion(ePelicula* peliculas, int PELISMAX);   ///A-Z
void Pelis_Name_Z_2_A_Alphabetically_orderByInsertion(ePelicula* peliculas, int PELISMAX);   ///Z-A
void find_Movies_By_Year(ePelicula *peliculas, int PELISMAX, eActor *actores, int ACTORESMAX, eGenero *generos, int GENRESMAX);        ///IMPRIME LAS PELICULAS Q CORRESPONE AL AÑO BUSCADO
int genreWithTheMostMovies (ePelicula* peliculas, int PELISMAX, eGenero *generos, int GENRESMAX);
int genreWithTheLeastMovies (ePelicula* peliculas, int PELISMAX, eGenero *generos, int GENRESMAX);
int actorWithTheMostMovies (ePelicula* peliculas, int PELISMAX, eActor *actores, int ACTORESMAX);
int actorWithTheLeastMovies (ePelicula* peliculas, int PELISMAX, eActor *actores, int ACTORESMAX);
void AmountOfMoviesByGenreInAGivenYear (ePelicula* peliculas, int PELISMAX, eGenero *generos, int GENRESMAX);
void moviesOrderByGenre(ePelicula* peliculas, int PELISMAX, eGenero *generos, int GENRESMAX);
void moviesOrderByGenre(ePelicula* peliculas, int PELISMAX, eGenero *generos, int GENRESMAX); ///1 a 5
void moviesOrderByGenreFrom5to1 (ePelicula* peliculas, int PELISMAX, eGenero *generos, int GENRESMAX); ///5 a 1
void MoviesStartingWithAGivenLetter (ePelicula *peliculas, int PELISMAX);
void moviesPlayedBySomeActor (ePelicula* peliculas, int PELISMAX, eActor *actores, int ACTORESMAX);
#endif
