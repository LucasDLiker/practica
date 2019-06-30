#ifndef CONTROLFOOS_H_INCLUDED
#define CONTROLFOOS_H_INCLUDED

int mainMenu (void);

int printsPelis(ePelicula *peliculas, int PELISMAX, eGenero *generos, int GENRESMAX, eActor *actores, int ACTORESMAX);
int printsSinglePeli (ePelicula*peliculas, int i, eGenero *generos, int GENRESMAX, eActor *actores, int ACTORESMAX);
void hardcodedPelis(ePelicula* peliculas, int PELISMAX);
void hardcodedActors(eActor* actores, int ACTORESMAX);
void hardcodedGenres(eGenero* generos, int GENRESMAX);
void Actors_Nationality_Alphabetically_orderByInsertion(eActor *actores, int ACTORESMAX);
void Movies_By_Year_orderByInsertion(ePelicula *peliculas, int PELISMAX);

void tagsMovies (void);

char* returnsGenreChar (eGenero *generos, int GENRESMAX, int idGenero);
char* returnsActorChar (eActor *actores, int ACTORESMAX, int idActor);
#endif

