#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "toolbox.h"
#include "peliculas.h"


/** \brief Inicializa el estado de las peliculas
 *
 * \param array de peliculas
 * \param capacidad
 * \return devuelve el estado
 *
 */

int inicioEstadoPeliculas(sPeliculas* arrayPeliculas, int capacidad)
{
    int retorno=ILOGICO;
    int i;
    if (arrayPeliculas != NULL && capacidad != 0)
    {
        retorno = OCUPADO;
        for (i=0 ; i<capacidad; i++)
        {
            arrayPeliculas[i].isEmpty = LIBRE;
        }//FIN DEL FOR
    }//FIN DEL IF
    return retorno;
}//FIN DE FUNCION

/** \brief Busca espacio libre para las peliculas
 *
 * \param array
 * \param capacidad
 * \return devuelve el espacio
 *
 */

 int buscarLibrePeliculas(sPeliculas* arrayPeliculas, int capacidad)
 {
     int retorno = ILOGICO;
     int i;
     if(capacidad > 0 && arrayPeliculas != NULL)
     {
         for(i=0;i<capacidad;i++)
         {
           if (arrayPeliculas[i].isEmpty == LIBRE)
           {
               retorno = i;
               break;
           }
         }//FIN DEL FOR
     }//FIN DEL if
     return retorno;
 }

 int agregarPelicula(sPeliculas* arrayPeliculas, int capacidad)
 {

     int retorno = -1;
    int index = buscarLibrePeliculas(arrayPeliculas, capacidad);
    char auxTitulo[51];
    char buffer[256];
    int i;
    if(capacidad > 0 && arrayPeliculas != NULL)
    {
        if(index != -1)
        {
            /*----------------ID---------------------------*/
            arrayPeliculas[index].id=index+1000;
            /*---------------TITULO------------------------*/
            getString("Ingrese el titulo de la pelicula: ", buffer);
            while(strlen(buffer)>51)
            {
                getString("El titulo es demasiado largo, ingreselo nuevamente: ", buffer);
            }
            strcpy(auxTitulo, buffer);
            strcpy(strlwr(auxTitulo), auxTitulo);
            auxTitulo[0]=toupper(auxTitulo[0]);
            for(i=0; i < strlen(auxTitulo); i++)
            {
                if(auxTitulo[i] == ' ')
                {
                    auxTitulo[i+1]=toupper(auxTitulo[i+1]);
                }
            }
            strcpy(arrayPeliculas[index].titulo, auxTitulo);
            arrayPeliculas[index].isEmpty = OCUPADO;


            retorno = 0;
            printf("Datos cargados correctamente.\n");
            system("pause");
            system("cls");
        }
    }
return retorno;
 }

 int encontrarPeliculaPorID(sPeliculas* arrayPeliculas, int capacidad, int id)
{
    int i;
    for(i=0; i<capacidad; i++)
    {
        if(arrayPeliculas[i].id == id && arrayPeliculas[i].isEmpty == 0)
        {
            return i;
            break;
        }
    }
    return ILOGICO;
}

void mostrarListaPeliculas(sPeliculas* listaPeliculas, int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        if(listaPeliculas[i].isEmpty == OCUPADO)
        {

            printf(" %4d | %35s\n",listaPeliculas[i].id, listaPeliculas[i].titulo);

        }
    }
}


