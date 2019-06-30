#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "pelicula.h"
#include "actor.h"
#include "genero.h"
#include "controlfoos.h"
#include "informes.h"
#include "utn.h"
#include "AvramidesJulian1C.h"

///-----------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------
void Actors_Name_Alphabetically_orderByInsertion(eActor *actores, int ACTORESMAX)   ///A-Z
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
        while (strcmp(actoresAux[j].nombre,auxActor.nombre)>0 && j>=0)
        {
            actoresAux[j+1] = actoresAux[j];
            j--;
        }
        actoresAux[j+1] = auxActor;
    }

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
void Actors_Name_Descendent_Alphabetically_orderByInsertion(eActor *actores, int ACTORESMAX)   ///Z-A
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
        while (strcmp(actoresAux[j].nombre,auxActor.nombre)<0 && j>=0)
        {
            actoresAux[j+1] = actoresAux[j];
            j--;
        }
        actoresAux[j+1] = auxActor;
    }
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
void Pelis_Name_Alphabetically_orderByInsertion(ePelicula* peliculas, int PELISMAX)   ///A-Z
{
    int i=0, j=0, largo=0;
    ePelicula auxPelicula;
    ePelicula peliculasAux[PELISMAX];

    for (int h=0; h<PELISMAX; h++)
    {
        peliculasAux[h]=peliculas[h];
    }
    printf ("\n\n");

    for (i=1; i < PELISMAX; i++)
    {
        auxPelicula= peliculasAux[i];
        j = i-1;
        while (strcmp(peliculasAux[j].titulo,auxPelicula.titulo)>0 && j>=0)
        {
            peliculasAux[j+1] = peliculasAux[j];
            j--;
        }
        peliculasAux[j+1] = auxPelicula;
    }
    printf("\nID ");
    printf("\t\tTitulo");
    printf("\t\t\t Estreno ");
    printf("\tGenero ");
    printf("\t\tActor\t ");

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
            printf("%d/",peliculasAux[k].fechaDeEstreno.day);
            printf("%d/",peliculasAux[k].fechaDeEstreno.month);
            printf("%d\t",peliculasAux[k].fechaDeEstreno.year);
            printf("   %d\t",peliculasAux[k].genero);
            printf("\t  %d",peliculasAux[k].actor);
        }
    }
    printf ("\n\n");
    system("pause");
}
///----------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------

void Pelis_Name_Z_2_A_Alphabetically_orderByInsertion(ePelicula* peliculas, int PELISMAX)   ///Z-A
{
    int i=0, j=0, largo=0;
    ePelicula auxPelicula;
    ePelicula peliculasAux[PELISMAX];

    for (int h=0; h<PELISMAX; h++)
    {
        peliculasAux[h]=peliculas[h];
    }
    printf ("\n\n");

    for (i=1; i < PELISMAX; i++)
    {
        auxPelicula= peliculasAux[i];
        j = i-1;
        while (strcmp(peliculasAux[j].titulo,auxPelicula.titulo)<0 && j>=0)
        {
            peliculasAux[j+1] = peliculasAux[j];
            j--;
        }
        peliculasAux[j+1] = auxPelicula;
    }
    printf("\nID ");
    printf("\t\tTitulo");
    printf("\t\t\t Estreno ");
    printf("\tGenero ");
    printf("\t\tActor\t ");

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
            printf("%d/",peliculasAux[k].fechaDeEstreno.day);
            printf("%d/",peliculasAux[k].fechaDeEstreno.month);
            printf("%d\t",peliculasAux[k].fechaDeEstreno.year);
            printf("   %d\t",peliculasAux[k].genero);
            printf("\t  %d",peliculasAux[k].actor);
        }
    }
    printf ("\n\n");
    system("pause");
}
///----------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------
void find_Movies_By_Year(ePelicula *peliculas, int PELISMAX, eActor *actores, int ACTORESMAX, eGenero *generos, int GENRESMAX)        ///IMPRIME LAS PELICULAS Q CORRESPONE AL AÑO BUSCADO
{
/// int auxDay, auxMonth, auxYear;
    int day=1, month=1, year;   ///day & month set to 1 to be able to use this same function without modification
    int ValidDate;

    if (peliculas!= NULL && peliculas>0)
    {
        printf("\n\nBuscar peliculas por fecha\n\n");
        do
        {
            //          fflush(stdin);
//           day=getValidInt("Ingrese el dia del estreno: ","ERROR", 1, 31);
            //          fflush(stdin);
//           month=getValidInt("Ingrese el mes del estreno: ","ERROR", 1, 12);
            fflush(stdin);
            year=getValidInt("Ingrese el anio a buscar: ","ERROR", 1895, 2020);
            ValidDate=isValidDate(day, month, year);
        }
        while (ValidDate!=0);

        printf("Peliculas estrenadas en el: %d\n\n", /*auxDay, auxMonth,*/ year);
        tagsMovies();
        for (int i=0; i<PELISMAX; i++)
        {
            if (peliculas[i].isEmpty==0)
            {
                if (peliculas[i].fechaDeEstreno.year==year)
                {
                    printsSinglePeli (peliculas, i, generos, GENRESMAX, actores, ACTORESMAX);
                }
            }
        }
        printf ("\n\n");
        system("pause");
    }
    else
    {
        printf("No hay informacion que mostrar");
    }
}
///----------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------

int genreWithTheMostMovies (ePelicula* peliculas, int PELISMAX, eGenero *generos, int GENRESMAX)
{
    int mostApparences=-1, peliculasByGenre=0, rtn=-1;

    if (generos!= NULL && generos >0 && peliculas!=NULL && peliculas>0)
    {
        for (int i=0; i<GENRESMAX; i++)
        {
            peliculasByGenre=0;
            for (int j=0; j <21; j++)     ///Debe ir PELISMAX
            {
                if (generos[i].isEmpty==0)
                {
                    if (generos[i].genreId==peliculas[j].genero && peliculas[j].isEmpty==0)
                    {
                        peliculasByGenre++;
                    }
                }
            }///FOR J

            if (peliculasByGenre>mostApparences)
            {
                mostApparences=peliculasByGenre;
            }
        }///FOR I

        printf("\nGenero con mas peliculas: ");

        for (int i=0; i<GENRESMAX; i++)
        {
            peliculasByGenre=0;
            for (int j=0; j <PELISMAX; j++)
            {
                if (generos[i].isEmpty==0)
                {
                    if (generos[i].genreId==peliculas[j].genero && peliculas[j].isEmpty==0 && generos[i].isEmpty==0)
                    {
                        peliculasByGenre++;
                    }
                }
            }
            if (peliculasByGenre==mostApparences)
            {
                printf ("\t %s %d", generos[i].descripcion, mostApparences);
                rtn=0;
            }
        }
    }
    else
    {
        printf("No hay informacion que mostrar");
    }
    printf ("\n\n");
    system("pause");

    return rtn;     ///0=OK    -1=FOUL

}

///----------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------
int genreWithTheLeastMovies (ePelicula* peliculas, int PELISMAX, eGenero *generos, int GENRESMAX)
{
    int leastApparences=1000, peliculasByGenre=0, rtn=-1;

    if (generos!= NULL && generos >0 && peliculas!=NULL && peliculas>0)
    {
        for (int i=0; i<GENRESMAX; i++)
        {
            peliculasByGenre=0;
            for (int j=0; j <21; j++)     ///Debe ir PELISMAX
            {
                if (generos[i].isEmpty==0)
                {
                    if (generos[i].genreId==peliculas[j].genero && peliculas[j].isEmpty==0)
                    {
                        peliculasByGenre++;
                    }
                }
            }///FOR J

            if (peliculasByGenre<leastApparences)
            {
                leastApparences=peliculasByGenre;
            }
        }///FOR I

        printf("\nGenero con menos peliculas: ");

        for (int i=0; i<GENRESMAX; i++)
        {
            peliculasByGenre=0;
            for (int j=0; j <PELISMAX; j++)
            {
                if (generos[i].isEmpty==0)
                {
                    if (generos[i].genreId==peliculas[j].genero && peliculas[j].isEmpty==0)
                    {
                        peliculasByGenre++;
                    }
                }
            }
            if (peliculasByGenre==leastApparences)
            {
                //    printf (" %d", peliculasByGenre);
                printf ("\t %s %d", generos[i].descripcion, leastApparences);
                rtn=0;
            }
        }
    }
    else
    {
        printf("No hay informacion que mostrar");
    }
    printf ("\n\n");
    system("pause");

    return rtn;     ///0=OK    -1=FOUL

}

///----------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------

int actorWithTheMostMovies (ePelicula* peliculas, int PELISMAX, eActor *actores, int ACTORESMAX)
{
    int mostApparences=-1, peliculasByActor=0, rtn=-1;

    if (actores!= NULL && actores >0 && peliculas!=NULL && peliculas>0)
    {
        for (int i=0; i<ACTORESMAX; i++)
        {
            peliculasByActor=0;
            for (int j=0; j <PELISMAX; j++)     ///Debe ir PELISMAX
            {
                if (actores[i].isEmpty==0)
                {
                    if (actores[i].id==peliculas[j].actor && peliculas[j].isEmpty==0)
                    {
                        peliculasByActor++;
                    }
                }
            }///FOR J

            if (peliculasByActor>mostApparences)
            {
                mostApparences=peliculasByActor;
            }
        }///FOR I

        printf("\nActor con mas peliculas: ");

        for (int i=0; i<ACTORESMAX; i++)
        {
            peliculasByActor=0;
            for (int j=0; j <PELISMAX; j++)
            {
                if (actores[i].isEmpty==0)
                {
                    if (actores[i].id==peliculas[j].actor&& peliculas[j].isEmpty==0)
                    {
                        peliculasByActor++;
                    }
                }
            }
            if (peliculasByActor==mostApparences)
            {
                //    printf (" %d", peliculasByActor);
                printf ("\t %s %d", actores[i].nombre, mostApparences);
                rtn=0;
            }
        }
    }
    else
    {
        printf("No hay informacion que mostrar");
    }
    printf ("\n\n");
    system("pause");

    return rtn;     ///0=OK    -1=FOUL

}

///----------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------

int actorWithTheLeastMovies (ePelicula* peliculas, int PELISMAX, eActor *actores, int ACTORESMAX)
{
    int leastApparences=100, peliculasByActor=0, rtn=-1;

    if (actores!= NULL && actores >0 && peliculas!=NULL && peliculas>0)
    {
        for (int i=0; i<ACTORESMAX; i++)
        {
            peliculasByActor=0;
            for (int j=0; j <21; j++)     ///Debe ir PELISMAX
            {
                if (actores[i].isEmpty==0)
                {
                    if (actores[i].id==peliculas[j].actor&& peliculas[j].isEmpty==0)
                    {
                        peliculasByActor++;
                    }
                }
            }///FOR J

            if (peliculasByActor<leastApparences)
            {
                leastApparences=peliculasByActor;
            }
        }///FOR I

        printf("\nActor con menos peliculas: ");

        for (int i=0; i<ACTORESMAX; i++)
        {
            peliculasByActor=0;
            for (int j=0; j <PELISMAX; j++)
            {
                if (actores[i].isEmpty==0)
                {
                    if (actores[i].id==peliculas[j].actor&& peliculas[j].isEmpty==0)
                    {
                        peliculasByActor++;
                    }
                }
            }
            if (peliculasByActor==leastApparences)
            {
                printf ("\t %s %d", actores[i].nombre, leastApparences);
                rtn=0;
            }
        }
    }
    else
    {
        printf("No hay informacion que mostrar");
    }
    printf ("\n\n");
    system("pause");

    return rtn;     ///0=OK    -1=FOUL

}

///----------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------
void AmountOfMoviesByGenreInAGivenYear (ePelicula* peliculas, int PELISMAX, eGenero *generos, int GENRESMAX)
{
    int auxYear, generoId=0, validationResult=0;

    int day=1, month=1, year;   ///day & month set to 1 to be able to use this same function without modification
    int ValidDate;

    do///DATE
    {
        //fflush(stdin);//day=getValidInt("Ingrese el dia del estreno: ","ERROR", 1, 31);//fflush(stdin);//month=getValidInt("Ingrese el mes del estreno: ","ERROR", 1, 12);
        fflush(stdin);
        year=getValidInt("Ingrese el anio a buscar: ","ERROR", 1895, 2020);
        ValidDate=isValidDate(day, month, year);
    }

    while (ValidDate!=0);

    auxYear=year;

    do      ///CHOSE A GENRE
    {
        printf("\n");
        for (int p=0; p<GENRESMAX; p++)
        {
            printf("%d-%s\t", generos[p].genreId, generos[p].descripcion);
        }
        printf("\n");

        fflush(stdin);
        validationResult=getValidInt("\nSeleccione el genero  de la pelicula:","Error", 1, GENRESMAX);
        generoId=validationResult;
    }
    while (validationResult==0);

    printf("\n");
    if (peliculas!=NULL && peliculas>0)
    {
        for (int i=0; i<PELISMAX; i++)
        {
            if (peliculas[i].fechaDeEstreno.year==auxYear)
            {
                if (peliculas[i].genero==generoId)
                {
///                    moviesTotal++;
                    printf("%s\n", peliculas[i].titulo);
                }
            }
        }///closes for i
    }///ELSE SALIR
}


///-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void moviesOrderByGenre(ePelicula* peliculas, int PELISMAX, eGenero *generos, int GENRESMAX) ///1 a 5
{
    int largo=0;

    printf("    PELICULAS ORDENADAS POR GENERO\n\n");
    printf("\nId");
    printf("\t\tTitulo");
    printf("\tGenero \n ");
    if (peliculas!=NULL && peliculas>0 && generos!=NULL && generos >0)
    {
        for (int i=0; i<GENRESMAX; i++)
        {
            for (int j=0; j<PELISMAX; j++)
            {
                if (generos[i].genreId==peliculas[j].genero && generos[i].isEmpty==0 && peliculas[j].isEmpty==0)
                {
                    printf("%d\t", peliculas[j].id);
                    printf("%s", peliculas[j].titulo);
                    largo=strlen(peliculas[j].titulo);
                    for(int l=0; l<30-largo; l++)
                    {
                        printf(" ");
                    }
                    printf("\t%s\n", generos[i].descripcion);
                }
            }
        }
    }
}


///-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void moviesOrderByGenreFrom5to1 (ePelicula* peliculas, int PELISMAX, eGenero *generos, int GENRESMAX) ///5 a 1
{
    int largo=0;

    printf("    PELICULAS ORDENADAS POR GENERO 5 a 1\n\n");
    printf("\nId");
    printf("\t\tTitulo");
    printf("\tGenero \n ");
    if (peliculas!=NULL && peliculas>0 && generos!=NULL && generos >0)
    {
        for (int i=GENRESMAX; i>=0; i--)
        {
            for (int j=0; j<PELISMAX; j++)
            {
                if (generos[i].genreId==peliculas[j].genero && generos[i].isEmpty==0 && peliculas[j].isEmpty==0)
                {
                    printf("%d\t", peliculas[j].id);
                    printf("%s", peliculas[j].titulo);
                    largo=strlen(peliculas[j].titulo);
                    for(int l=0; l<30-largo; l++)
                    {
                        printf(" ");
                    }
                    printf("\t%s\n", generos[i].descripcion);
                }
            }
        }
    }
}
///-----------------------------------------------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------------------------------------------
void MoviesStartingWithAGivenLetter (ePelicula *peliculas, int PELISMAX)
{
    char letraInicial;
    int resultado=-1;

    letraInicial=getChar("\n\nIngrese la letra Inicial para buscar Peliculas\n\n ? ");
    resultado=esCharAlfaNumerico(letraInicial);
    if (resultado)
    {
        if (letraInicial>57)
        {
            if (letraInicial>96 || letraInicial<123)
            {
                ///     printf("\nresultado: %d\n", resultado);
                letraInicial=letraInicial-32;
                ///     printf("\nletraInicial: %c\n", letraInicial);
            }
        }
    }
    printf("\nId");
    printf("\t\tTitulo\n");

    if (peliculas!=NULL && peliculas>0)
    {
        for (int i=0; i<PELISMAX; i++)
        {
            if (peliculas[i].titulo[0]==letraInicial)
            {
                printf("\n%d \t", peliculas[i].id);
                printf("%s", peliculas[i].titulo);
            }
        }
    }
}
///--------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------
void moviesPlayedBySomeActor (ePelicula* peliculas, int PELISMAX, eActor *actores, int ACTORESMAX)
{
    int auxActorId=0, validationResult=0;
    ///int largo=0;

    do
    {
        printf("\n");
        for (int q=0; q<ACTORESMAX; q++)
        {
            if (actores[q].isEmpty==0)
            {
                printf("%d-%s\n", actores[q].id, actores[q].nombre);
            }

        }
        printf("\n");
        fflush(stdin);
        validationResult=getValidInt("Seleccione el actor de la pelicula: \n\n? ","Error", 1, 10);                     ///EN LUGAR DE 10 DEBE SER ACTORESMAX
        auxActorId=validationResult;
    }
    while (validationResult==0);

    auxActorId=validationResult;

    printf("Peliculas protagonizadas por %d", auxActorId);  ///QUE SEA UN CHAR Y NO UN INT

    printf("\nId");
    printf("\t\tTitulo\n");


    if (peliculas!=NULL && peliculas>0 && actores!=NULL && actores >0)
    {
        for (int i=0; i<PELISMAX; i++)
        {
            if (auxActorId==peliculas[i].actor && peliculas[i].isEmpty==0)
            {
                printf("%d\t", peliculas[i].id);
                printf("%s\n", peliculas[i].titulo);
///                largo=strlen(peliculas[i].titulo);
             ///   for(int l=0; l<30-largo; l++)
             ///   {
             ///       printf(" ");
             ///   }

            }
        }
    }
}
