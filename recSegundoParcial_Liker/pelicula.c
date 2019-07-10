#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelicula.h"
#include <ctype.h>
#include "utn.h"


ePelicula* ePelicula_new()
{
    ePelicula* newPelicula = (ePelicula*)malloc(sizeof(ePelicula));

    if(newPelicula!=NULL)
    {
        strcpy(newPelicula->nombre,"");
        newPelicula->anio= 0;
        newPelicula->id= 0;
        strcpy(newPelicula->genero,"");
    }

    return newPelicula;
}


ePelicula* ePelicula_newParametros(char* idStr,char* nombreStr,char* anioStr)
{
    ePelicula* newPeliculaParametros = ePelicula_new();
    int retorno = 0;

    if(newPeliculaParametros != NULL)
    {
        if(ePelicula_setId(newPeliculaParametros, atoi(idStr) ) )
        {
            if(ePelicula_setNombre(newPeliculaParametros, nombreStr))
            {
                if(ePelicula_setAnio(newPeliculaParametros, atoi(anioStr)) )
                {
                    retorno = 1;
                }
            }
        }

        if(retorno == 0)
        {
            free(newPeliculaParametros);
            newPeliculaParametros = NULL;
        }
    }
    return newPeliculaParametros;
}


int ePelicula_setAnio(ePelicula* this,int anio)
{
    int retorno =0;

    if(this != NULL )
    {
        this->anio = anio;

        retorno=1;
    }

    return retorno;
}


int ePelicula_getAnio(ePelicula* this,int* anio)
{
    int retorno =0;

    if(this!=NULL && anio!=NULL)
    {
        *anio=this->anio;

        retorno=1;
    }

    return retorno;
}


int ePelicula_setId(ePelicula* this,int id)
{
    int retorno =0;

    if(this != NULL)
    {
        this->id = id;
        retorno=1;
    }

    return retorno;
}


int ePelicula_getId(ePelicula* this,int* id)
{
    int retorno =0;

    if(this!=NULL && id!=NULL)
    {
        *id=this->id;

        retorno=1;
    }

    return retorno;
}


int ePelicula_setNombre(ePelicula* this,char* nombre)
{
    int retorno =0;

    if(this != NULL && nombre!=NULL)
    {

        strcpy(this->nombre,nombre);
        retorno=1;
    }

    return retorno;
}


int ePelicula_getNombre(ePelicula* this,char* nombre)
{
    int retorno =0;

    if(this != NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);

        retorno=1;
    }

    return retorno;
}


int ePelicula_setGenero(ePelicula* this,char* genero)
{
  int retorno =0;

    if(this != NULL && genero!=NULL)
    {

        strcpy(this->genero,genero);
        retorno=1;
    }

    return retorno;
}


int ePelicula_getGenero(ePelicula* this,char* genero)
{
    int retorno =0;

    if(this != NULL && genero!=NULL)
    {
        strcpy(genero,this->genero);

        retorno=1;
    }

    return retorno;
}


/*int eDominio_mapearTipo(void* pElement)
{
    int retorno = -1;
    ePelicula* auxeDominio;
    char auxDominio[20];


    if(pElement != NULL)
    {
        auxeDominio = (ePelicula*) pElement;

        eDominio_getDominio(auxeDominio,auxDominio);

        if(isalpha(auxDominio[0])!=0)
        {

            eDominio_setTipo(auxeDominio,'A');
            retorno=1;
        }
        else
        {
            eDominio_setTipo(auxeDominio,'M');
            retorno=1;
        }

    }
    return retorno;
}

int eDominio_filtrarMoto(void* pElement)
{
    int retorno = -1;
    ePelicula* auxEdominio;
    char auxTipo;

    if(pElement != NULL)
    {
        auxEdominio = (ePelicula*) pElement;
        eDominio_getTipo(auxEdominio,&auxTipo);
        if(auxTipo=='M')
        {
            retorno = 1;
        }
    }
    return retorno;
}

int eDominio_filtrarAuto(void* pElement)
{
    int retorno = -1;
    ePelicula* auxEdominio;
    char auxTipo;

    if(pElement != NULL)
    {
        auxEdominio = (ePelicula*) pElement;
        eDominio_getTipo(auxEdominio,&auxTipo);

        if(auxTipo=='A')
        {
            retorno = 1;
        }
    }
    return retorno;
}*/
