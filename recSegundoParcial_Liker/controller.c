#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "pelicula.h"
#include "parser.h"
#include "utn.h"

int controller_listExist(LinkedList* pArrayListeDominio)
{
    int existe = -1;

    if(ll_len(pArrayListeDominio)>0)
    {
        existe = 1;
    }

    return existe;
}


int controller_loadFromText(char* path,LinkedList* pArrayListPelicula)
{

    int retorno=-1;
    FILE* Pfile = fopen(path,"r");

    if(Pfile!=NULL&& pArrayListPelicula !=NULL)
    {
        if(parser_moviesFromText(Pfile,pArrayListPelicula))
        {

            retorno=1;

        }

        else
        {
            retorno =-1;
        }

    }

    else
    {
        retorno =-1;
    }

    fclose(Pfile);
    free(Pfile);


    return retorno;
}

int controller_ListPelicula(LinkedList* pArrayListePelicula)
{
    ePelicula* auxPelicula = ePelicula_new();
    int auxID;
    char auxNombre[50];
    int auxAnio;
    char auxGenero[50];
    int retorno=-1;
    int i;

    if(auxPelicula!=NULL && pArrayListePelicula!=NULL)
    {
        system("cls");
        puts(" [ID]\t[TITULO]\t[ANIO]\t[GENERO]\n\n");

        for(i=0; i < ll_len(pArrayListePelicula); i++)
        {
            auxPelicula = ll_get(pArrayListePelicula, i);

            ePelicula_getId(auxPelicula, &auxID);
            ePelicula_getNombre(auxPelicula,auxNombre);
            ePelicula_getAnio(auxPelicula,&auxAnio);
            ePelicula_getGenero(auxPelicula,auxGenero);

            printf("%1d  %1s  %3d  %5s\n",auxID, auxNombre, auxAnio, auxGenero);

        }

        retorno=1;
    }

    else
    {
        retorno=-1;
    }

    printf("\n\n");

    return retorno;
}



/*int controller_saveAsText(char* path, LinkedList* pArrayListeDominio)
{
    int retorno=-1;
    int len;
    int idAuxiliar;
    char dominioAuxiliar[50];
    int anioAuxiliar;
    char tipoAuxiliar;
    int i;
    FILE* Pfile = fopen(path,"w+");
    eDominio* auxEdominio=eDominio_new();

    if(Pfile != NULL && pArrayListeDominio != NULL && auxEdominio!=NULL )
    {
        len=ll_len(pArrayListeDominio);
        fprintf(Pfile, "id,dominio,anio,tipo\n");

        for(i=0; i<len; i++)
        {
            auxEdominio= ll_get(pArrayListeDominio,i);

            eDominio_getId(auxEdominio, &idAuxiliar);
            eDominio_getDominio(auxEdominio,dominioAuxiliar);
            eDominio_getAnio(auxEdominio,&anioAuxiliar);
            eDominio_getTipo(auxEdominio,&tipoAuxiliar);

            fprintf(Pfile,"%d,%s,%d,%c\n",idAuxiliar,dominioAuxiliar,anioAuxiliar,tipoAuxiliar);

        }

        retorno = 1;

    }
    else
    {
        retorno=-1;
    }

    fclose(Pfile);

    return retorno;
}*/
