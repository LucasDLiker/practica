#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "actor.h"
#include "genero.h"
#include "pelicula.h"
#include "avramidesjulian1C.h"
#include "controlfoos.h"

///MEJOR VISUALIZADO EN ANCHO 120 - ALTO 80


#define PELISMAX 1000
#define ACTORESMAX 50
#define GENRESMAX 5


int main()
{

    int mainMenuSelection=0;
    int control_Alta=-1;
    int isHarcodedAlready=0;

    ePelicula peliculas [PELISMAX];
    eActor actores [ACTORESMAX];
    eGenero generos [GENRESMAX];
    initPeliculas(peliculas, PELISMAX);
    initActores(actores, ACTORESMAX);
    initGenre(generos, GENRESMAX);

    do
    {
        mainMenuSelection=mainMenu();

        switch (mainMenuSelection)
        {
        case 1: ///ALTA
        {
             control_Alta=addPelicula (peliculas, PELISMAX, generos, GENRESMAX, actores, ACTORESMAX);
            if(control_Alta)
            {
                printf("\nPelicula agregada exitosamente\n");
                system("pause");
            }
            else
            {
                printf("\nNO se agrego pelicula\n");
            }
            break;
        }
        case 2: ///BAjA
        {
            removePeli(peliculas, PELISMAX,generos, GENRESMAX, actores, ACTORESMAX);
            break;
        }
        case 3  : ///MODIFY
        {
            modifyPeli(peliculas, PELISMAX, generos, GENRESMAX, actores, ACTORESMAX);
            break;
        }
        case 4: ///LIST
        {     printf("\n\nHardcoded Data\n");
              printsPelis(peliculas, PELISMAX, generos, GENRESMAX, actores, ACTORESMAX);
            ///  Actors_Nationality_Alphabetically_orderByInsertion(actores, ACTORESMAX);
             /// Movies_By_Year_orderByInsertion(peliculas, PELISMAX);
            ///  genreWithTheMostMovies (peliculas, PELISMAX, generos, GENRESMAX);
         ///     actorWithTheMostMovies (peliculas, PELISMAX, actores, ACTORESMAX);
            ///  genreWithTheLeastMovies (peliculas, PELISMAX, generos, GENRESMAX);
            ///  actorWithTheLeastMovies (peliculas, PELISMAX, actores, ACTORESMAX);
              AmountOfMoviesByGenreInAGivenYear (peliculas, PELISMAX, generos, GENRESMAX);
              ///moviesOrderByGenre(peliculas, PELISMAX, generos, GENRESMAX); ///1 a 5
              ///moviesOrderByGenreFrom5to1 (peliculas, PELISMAX, generos, GENRESMAX); ///5 a 1
              ///MoviesStartingWithAGivenLetter (peliculas, PELISMAX);
              ///moviesPlayedBySomeActor (peliculas, PELISMAX, actores, ACTORESMAX);
              system("pause");
                break;
        }
        case 5: ///SALIR
        {
            break;
        }
        case 6: ///HARDCODE
        {
            if (isHarcodedAlready==0)
            {
            hardcodedPelis(peliculas, PELISMAX);
            hardcodedActors(actores, ACTORESMAX);
            hardcodedGenres(generos, GENRESMAX);
            isHarcodedAlready=1;
            system("pause");
            }
            break;
        }
        }///CLOSES SWITCH
    }
    while (mainMenuSelection!=5);
    return 0;
}
