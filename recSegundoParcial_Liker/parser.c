#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "pelicula.h"
#include "parser.h"

int parser_moviesFromText(FILE* pFile, LinkedList* pArrayListMovie)
{
    char buffer[3][20];

    ePelicula* newPelicula;
    int cant;
    int retorno;

    fscanf(pFile, "%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2]);

    while( !feof(pFile) )
    {

        cant = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", buffer[0],  buffer[1], buffer[2]);

        if( cant == 3)
        {

            newPelicula = ePelicula_newParametros(buffer[0],buffer[1],buffer[2]);

            ll_add(pArrayListMovie,newPelicula);
            retorno=1;

        }
        else
        {
            retorno=-1;

        }

    }

    return retorno;
}
