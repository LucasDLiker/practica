#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "pelicula.h"
#include "actor.h"
#include "genero.h"
#include "controlfoos.h"


///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------
int mainMenu (void)
{
    char menuChoice;
    int usersChoice;

    do
    {
        system("cls");
        printf("\t\t\t\tMENU PELICULAS\n\n\n");
        printf("1-Alta\n");
        printf("2-Baja\n");
        printf("3-Modifica\n");
        printf("4-Listar\n");
        printf("5-SALIR\n");
        printf("6-HardCoded Data \n\n\n");
        printf("Que es lo que desea hacer? ");

        menuChoice= getche();

        switch (menuChoice)
        {

        case '1':
        {
            usersChoice=1;
            break;
        }

        case '2':
        {
            usersChoice=2;
            break;
        }

        case '3':
        {
            usersChoice=3;
            break;
        }

        case '4':
        {
            usersChoice=4;
            break;
        }
        case '5':
        {
            usersChoice=5;
            break;
        }
        case '6':
        {
            usersChoice=6;
            break;
        }
        default :
        {
            break;
        }

        }

    }
    while (usersChoice<1 || usersChoice>6);

    return usersChoice;
}
///---------------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------------

/** \brief Hardcoded game values
 * \param games: games array list
 */

void hardcodedPelis(ePelicula* peliculas, int PELISMAX)
{
    ePelicula hcd[]=
    {
        {generatesNextIdpeliculas(), "Avengers EndGame", 20, 4, 2019, 2,1,0},
        {generatesNextIdpeliculas(), "Thor", 10, 6, 2013, 5,1,0},
        {generatesNextIdpeliculas(), "Cellular", 2, 5, 2004, 4,1,0},
        {generatesNextIdpeliculas(), "Men in Black 4", 10,	7, 2019, 5, 1,0},
        {generatesNextIdpeliculas(), "IronMan", 5, 9, 2012, 2, 1,0},
        {generatesNextIdpeliculas(), "13 Going on 30", 7, 5, 2004, 3, 4,0},
        {generatesNextIdpeliculas(), "Lucy", 9,2,2014, 1,1,0},
        {generatesNextIdpeliculas(), "Nace una estrella", 8, 3, 2018, 9, 4,0},
        {generatesNextIdpeliculas(), "Dime con cuantos?", 4, 4, 2010, 4, 4,0},
        {generatesNextIdpeliculas(), "Guardianes de la galaxia", 20, 5, 2014, 9, 1,0},
        {generatesNextIdpeliculas(), "A perfect murder", 6, 8, 1995, 7, 3,0},
        {generatesNextIdpeliculas(), "La isla", 3, 10, 2005, 1, 3,0},
        {generatesNextIdpeliculas(), "Que paso ayer", 5, 2, 2013, 9, 2,0},
        {generatesNextIdpeliculas(), "Home Alone 3", 6, 10, 1997, 1, 2,0},
        {generatesNextIdpeliculas(), "Deadpool", 7, 12, 2015, 10, 1,0},
        {generatesNextIdpeliculas(), "Sherlock Holmes", 5, 6, 2011, 2, 1,0},
        {generatesNextIdpeliculas(), "Men in Black 3", 2, 5, 2010, 10, 1,0},
        {generatesNextIdpeliculas(), "Avengers infinity war", 6, 4, 2017, 10, 1,0},
        {generatesNextIdpeliculas(), "Grandes esperanzas", 8, 12, 1995, 7, 4,0},
        {generatesNextIdpeliculas(), "SWAT", 20, 2, 1998, 6, 1,0},
        {generatesNextIdpeliculas(), "XxX", 11, 5, 1992, 6, 1,0},
    };

    for(int i=0; i<21; i++)
    {
        peliculas [i] = hcd[i];
    }
        system("cls");
        printf("**********************************************************************");
        printf("\n\n\n\n\n\n\n");
        printf("harcoded OK\n");
}
///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------
void hardcodedActors(eActor* actores, int ACTORESMAX)
{
    eActor hcd[]=
    {
        {generates_Next_Id_Actor(), "Scarlett Johansson","Argentina",0},
        {generates_Next_Id_Actor(), "Robert Downey Jr", "EEUU",0},
        {generates_Next_Id_Actor(), "Mark Ruffalo", "Canada",0},
        {generates_Next_Id_Actor(), "Chris Evans", "EEUU",0},
        {generates_Next_Id_Actor(), "Chris Hemsworth", "Argentina",0},
        {generates_Next_Id_Actor(), "Samuel Jackson", "EEUU",0},
        {generates_Next_Id_Actor(), "Gwyneth Paltrow", "Canada",0},
        {generates_Next_Id_Actor(), "Paul Rudd", "Argentina",0},
        {generates_Next_Id_Actor(), "Bradley Cooper", "EEUU",0},
        {generates_Next_Id_Actor(), "Josh Brolin", "Canada",0},
    };

    for(int i=0; i<10; i++)
    {
        actores [i] = hcd[i];

        system("cls");
        printf("**********************************************************************");
        printf("\n\n\n\n\n\n\n");
        printf("harcoded OK\n");
    }
}
///-----------------------------------------------------------------------------------
void hardcodedGenres(eGenero* generos, int GENRESMAX)
{
    eGenero hcd[]=
    {
        {generatesNextIdGenres(), "Accion", 0},
        {generatesNextIdGenres(), "Comedia",0},
        {generatesNextIdGenres(), "Drama",0},
        {generatesNextIdGenres(), "Romance",0},
        {generatesNextIdGenres(), "Terror",0},
    };

    for(int i=0; i<5; i++)
    {
        generos [i] = hcd[i];

        system("cls");
        printf("**********************************************************************");
        printf("\n\n\n\n\n\n\n");
        printf("harcoded OK\n");
    }
}
///----------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------
void Actors_Nationality_Alphabetically_orderByInsertion(eActor *actores, int ACTORESMAX)
{
    int i=0, j=0, largo=0;
    eActor auxActor;
    eActor actoresAux[ACTORESMAX];

     for (int h=0; h<ACTORESMAX; h++)
    {
        actoresAux[h]=actores[h];
    }
    printf ("\n\n");

    for (i=1; i < ACTORESMAX; i++)
    {
        auxActor= actoresAux[i];
        j = i-1;
        while (strcmp(actoresAux[j].origen,auxActor.origen)>0 && j>=0)
        {
            actoresAux[j+1] = actoresAux[j];
            j--;
        }
        actoresAux[j+1] = auxActor;
    }
printf("\n\n\nActores Por Origen\n");
    printf("\nID ");
    printf("\t\tActor ");
    printf("\t\tNacionalidad\n ");

    for (int k=0; k<ACTORESMAX; k++)
    {
        if (actoresAux[k].isEmpty==0)
        {
            printf("\n%d    ",actoresAux[k].id);
            printf("%s   ",actoresAux[k].nombre);
            largo=strlen(actoresAux[k].nombre);
            for(int l=0; l<25-largo; l++)
            {
                printf(" ");
            }
            printf("%s   ",actoresAux[k].origen);
        }
    }
    printf ("\n\n");
    system("pause");
}
///----------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------

void Movies_By_Year_orderByInsertion(ePelicula *peliculas, int PELISMAX)
{
    int i=0, j=0, largo=0;
    ePelicula auxPelicula;
    ePelicula peliculasAux[PELISMAX];

    printf("\n\n\n    Peliculas Por Fecha");

    for (int h=0; h<PELISMAX; h++)
    {
        peliculasAux[h]=peliculas[h];
    }
    printf ("\n\n");

    for (i=1; i < PELISMAX; i++)
    {
        auxPelicula= peliculasAux[i];
        j = i-1;
        while ((peliculasAux[j].fechaDeEstreno.year<auxPelicula.fechaDeEstreno.year) && j>=0)
        {
            peliculasAux[j+1] = peliculasAux[j];
            j--;
        }
        peliculasAux[j+1] = auxPelicula;
    }

///ARMAR PARA QUSE MES Y DIA

    printf("\nID ");
    printf("\t\tTitulo");
    printf("\t\t\tEstreno ");

    for (int k=0; k<PELISMAX; k++)
    {
        if (peliculasAux[k].isEmpty==0)
        {
            printf("\n%d    ",peliculasAux[k].id);
            printf("%s   ",peliculasAux[k].titulo);
            largo=strlen(peliculasAux[k].titulo);
            for(int l=0; l<30-largo; l++)
            {
                printf(" ");
            }
            ///    printf("%d/",peliculas[k].fechaDeEstreno.day);
            ///    printf("%d/",peliculas[k].fechaDeEstreno.month);
            printf("%d",peliculasAux[k].fechaDeEstreno.year);
        }
    }
    printf ("\n\n");
    system("pause");
}

///----------------------------------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------
///----------------------------------------------------------
/** \brief Prints all active employees on screen
 *
 * \param eEmployee  *list: Pointer to Array of employees
 * \param PELISMAX int: length of the Array of employees
 * \return int to verify correct output
 *
 */

int printsPelis(ePelicula *peliculas, int PELISMAX, eGenero *generos, int GENRESMAX, eActor *actores, int ACTORESMAX)
{
  tagsMovies ();

    if (peliculas!= NULL && PELISMAX > 0)
    {
        for (int i=0; i<PELISMAX; i++)
        {
            if (peliculas[i].isEmpty==0)
            {
                printsSinglePeli (peliculas, i, generos, GENRESMAX, actores, ACTORESMAX);
            }
        }
    }
    else
    {
        printf("No hay peliculas que mostrar");
    }
    printf("\n\n\n\n");
    system("pause");
    return 1;
}
///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------

int printsSinglePeli (ePelicula*peliculas, int i, eGenero *generos, int GENRESMAX, eActor *actores, int ACTORESMAX)
{
    int largo=0, j=0, k=0;
    char *generoChar=NULL;
    char *actorChar=NULL;
    int generoInt=0, actorInt=0;

    if (i==-1)
    {
        printf("\nLa pelicula no existe");
    }
    else
    {
        printf("\n%d    ",peliculas[i].id);
        printf("%s   ",peliculas[i].titulo);
        largo=strlen(peliculas[i].titulo);
        for(j=0; j<29-largo; j++)
        {
            printf(" ");
        }
        printf("%d/", peliculas[i].fechaDeEstreno.day);
        printf("%d/", peliculas[i].fechaDeEstreno.month);
        printf("%d", peliculas[i].fechaDeEstreno.year);

        generoInt=peliculas[i].genero;
        generoChar=returnsGenreChar (generos, GENRESMAX, generoInt);
        printf("\t %s", generoChar);
        largo=strlen(generoChar);
        for(k=0; k<10-largo; k++)
        {
            printf(" ");
        }


        actorInt=peliculas[i].actor;
        actorChar=returnsActorChar (actores, ACTORESMAX, actorInt);
        printf("\t\t  %s", actorChar);
    }
    return 1;
}

///--------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------
void tagsMovies (void)
{

    printf("\nID ");
    printf("\tTitulo");
    printf("\t\t\t\tEstreno ");
    printf("\t Genero\t ");
    printf("\t\t\tActor ");



}
///--------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------
char* returnsGenreChar (eGenero *generos, int GENRESMAX, int idGenero)
{
    char *genreDescripcion=NULL;

    if (generos!= NULL && generos >0 )
    {
        for (int i=0;i<GENRESMAX;i++)
        {
            if (idGenero==generos[i].genreId && generos[i].isEmpty==0)
            {
               genreDescripcion=generos[i].descripcion;
           ///    printf("\n%s\n", generos[i].descripcion);
          ///     printf("\n%s\n", genreDescripcion);
            }
        }
    }
    return genreDescripcion;
}

///--------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------
char* returnsActorChar (eActor *actores, int ACTORESMAX, int idActor)
{
    char *genreDescripcion=NULL;

    if (actores!= NULL && actores >0 )
    {
        for (int i=0;i<ACTORESMAX;i++)
        {
            if (idActor==actores[i].id && actores[i].isEmpty==0)
            {
               genreDescripcion=actores[i].nombre;
           ///    printf("\n%s\n", actores[i].descripcion);
          ///     printf("\n%s\n", genreDescripcion);
            }
        }
    }
    return genreDescripcion;
}
///--------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------
