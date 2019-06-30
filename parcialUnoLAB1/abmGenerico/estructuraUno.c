#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "estructuraDos.h"
#include "estructuraUno.h"
#include "funcionesGenericas.h"
#include "menu.h"
#include "hardcode.h"
#include "validaciones.h"

int inicializarEstadoPeliculas (sPeliculas* arrayPeliculas, int capacidad)
{
    int retorno = ILOGICO;
    int i;
    if(arrayPeliculas != NULL && capacidad != 0)
    {
        retorno = OCUPADO;
        for (i=0; i<capacidad; i++)
        {
            arrayPeliculas[i].datoOcupado = LIBRE;
        }
    }
    return retorno;
}

int buscarLibrePeliculas(sPeliculas* arrayPeliculas, int capacidad)
{
    int retorno = ILOGICO;
    int i;
    if(capacidad > 0 && arrayPeliculas != NULL)
    {
        for(i=0; i<capacidad; i++)
        {
            if(arrayPeliculas[i].datoOcupado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int datoCargado(sPeliculas* arrayPeliculas, int capacidad)
{
    int retorno = 1;
    int i;
    if(capacidad > 0 && arrayPeliculas != NULL)
    {
        for(i=0; i<capacidad; i++)
        {
            if(arrayPeliculas[i].datoOcupado == OCUPADO)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


int encontrarPeliculaPorID(sPeliculas* arrayPeliculas, int capacidad, int id)
{
    int i;
    for(i=0; i<capacidad; i++)
    {
        if(arrayPeliculas[i].id == id && arrayPeliculas[i].datoOcupado == 0)
        {
            return i;
            break;
        }
    }
    return ILOGICO;
}

int agregarPelicula(sPeliculas* arrayPeliculas, int capacidad)
{

    int retorno = -1;
    int index = buscarLibrePeliculas(arrayPeliculas, capacidad);
    char auxTitulo[51];
    char buffer[51];
    int auxDia;
    int auxMes;
    int auxAnio;
    int auxGenero;
    int auxActor;
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
            for(i=0;i < strlen(auxTitulo); i++)
            {
                if(auxTitulo[i] == ' ')
                {
                    auxTitulo[i+1]=toupper(auxTitulo[i+1]);
                }
            }
            strcpy(arrayPeliculas[index].titulo, auxTitulo);
            /*------------------GENERO------------------------*/
            auxGenero = getValidInt("Ingrese el ID del genero: ", "Solamente puede ingresar numeros.", 0, 5);
            arrayPeliculas[index].genero = auxGenero;
            /*-----------------CHAR-------------------------*/
            //auxChar = getChar("Ingrese el dato char: ");
            //arrayPeliculas[index].datoChar = auxChar;
            /*-----------------ACTOR-------------------------*/
            auxActor = getValidInt("Ingrese el ID del actor: ", "Solamente puede ingresar numeros.", 0, 10);
            arrayPeliculas[index].actor = auxActor;
            /*-----------------FECHA-------------------------*/
            auxDia = getValidInt("Ingrese el dia del estreno ", "Solamente puede ingresar numeros.", 0, 31);
            arrayPeliculas[index].dia = auxDia;
            auxMes = getValidInt("Ingrese el mes del estreno ", "Solamente puede ingresar numeros.", 0, 12);
            arrayPeliculas[index].mes = auxMes;
            auxAnio = getValidInt("Ingrese el anio del estreno ", "Solamente puede ingresar numeros.", 1989, 2019);
            arrayPeliculas[index].anio = auxAnio;
            /*------------------ESPACIO-----------------------*/
            arrayPeliculas[index].datoOcupado = OCUPADO;

            retorno = 0;
            printf("Datos cargados correctamente.\n");
            system("pause");
            system("cls");
        }
    }
    return retorno;
}

void ordenarPeliculasPorFecha(sPeliculas* listaPeliculas, int cantidad)
{
    int i;
    int j;
    sPeliculas auxPeliculas;

    for (i=0; i< cantidad; i++)
    {
        for(j = i+1; j < cantidad; j++)
        {
            if(listaPeliculas[j].anio < listaPeliculas[i].anio)
            {
                auxPeliculas = listaPeliculas[i];
                listaPeliculas[i] = listaPeliculas[j];
                listaPeliculas[j] = auxPeliculas;
            }
        }
    }
}

void mostrarListaPeliculas(sPeliculas* listaPeliculas, int cantidadPeliculas/*, sCosasDos* listaPeliculasDos, int cantidadCosasDos*/)
{
    int i;
    //int j;
    //char relacion[20];
    printf("=====================================================================\n"
           "||                              Listado:                           ||\n"
           "=====================================================================\n");
    for(i=0; i<cantidadPeliculas; i++)
    {
        if(listaPeliculas[i].datoOcupado == OCUPADO)
        {
//            for(j=0;j<cantidadCosasDos; j++)
//            {
//                if(listaPeliculas[i].genero == listaPeliculasDos[j].id)
//                {
//                    strcpy(relacion, listaPeliculasDos[j].titulo);
//                }
//            }
            printf(" %4d | %35s | %d | %2d | %2d/%2d/%4d                     \n",listaPeliculas[i].id, listaPeliculas[i].titulo, listaPeliculas[i].genero, listaPeliculas[i].actor, listaPeliculas[i].dia, listaPeliculas[i].mes, listaPeliculas[i].anio);
            //printf(" %4d | %50s | %d   | %2d |                \n", listaPeliculas[i].id, listaPeliculas[i].titulo, listaPeliculas[i].genero, /*relacion*/, listaPeliculas[i].actor);/*listaPeliculas[i].fecha*/
        }


    }
    printf("=====================================================================\n");
}

int eliminarPelicula(sPeliculas* arrayPeliculas, int capacidad)
{
    int retorno = ILOGICO;
    int auxiliarId;
    char opcion;

    auxiliarId = getInt("Ingrese el ID a buscar: ");
    int idPelicula=encontrarPeliculaPorID(arrayPeliculas, LIMITE, auxiliarId);
    if (idPelicula>=0)
    {
        do
        {
            opcion = getChar("Confirma la baja? S/N\n");
            switch(opcion)
            {
            case 's':
                arrayPeliculas[idPelicula].datoOcupado = LIBRE;
                printf("Baja realizada con exito.\n");
                break;
            case 'n':
                printf("Se cancelo la baja.\n");
                break;
            default:
                printf("Ingrese una opcion valida.\n");
                break;
            }
        }
        while (opcion != 's' && opcion != 'n');
    }
    else
    {
        printf ("ID vacio, intente nuevamente.\n");
    }

    return retorno;
}


void modificarPelicula(sPeliculas* arrayPeliculas, int capacidad)
{
    char auxTitulo[51];
    char buffer[51];
//    char auxFecha[11];
//    int auxGenero;
    int auxActor;
    int auxId;
    int opcion;
    char confirmacion;
    int i;


    auxId = getInt("Ingrese el ID a buscar: ");
    int idPelicula = encontrarPeliculaPorID(arrayPeliculas, LIMITE, auxId);
    if (idPelicula>=0)
    {
        printf("ID encontrado, indique que dato desea modificar: \n");
        opcion = subMenuModificarPelicula();
        switch(opcion)
        {
//        case 1:
//            auxGenero = getValidInt("Ingrese el ID del genero: ", "Solamente puede ingresar numeros.", 0, 5);
//            do
//            {
//                confirmacion = getChar("Confirma la modificacion? S/N ");
//                switch(confirmacion)
//                {
//                case 's':
//                    arrayPeliculas[idPelicula].genero = auxGenero;
//                    printf("Modificacion realizada con exito.\n");
//                    break;
//                case 'n':
//                    printf("Se cancelo la modificacion.\n");
//                    break;
//                default:
//                    printf("Ingrese una opcion valida. ");
//                    break;
//                }
//            }
//            while (confirmacion != 'n' && confirmacion != 's');
//            break;
        case 1:
            getString("Ingrese el Titulo: ", buffer);
            while(strlen(buffer)>51)
            {
                getString("El titulo es demasiado largo, ingreselo nuevamente: ", buffer);
            }
            strcpy(auxTitulo, buffer);
            strcpy(strlwr(auxTitulo), auxTitulo);
            auxTitulo[0]=toupper(auxTitulo[0]);
            for(i=0;i < strlen(auxTitulo); i++)
            {
                if(auxTitulo[i] == ' ')
                {
                    auxTitulo[i+1]=toupper(auxTitulo[i+1]);
                }
            }
            strcpy(arrayPeliculas[idPelicula].titulo, auxTitulo);
            do
            {
                confirmacion = getChar("Confirma la modificacion? ");
                switch(confirmacion)
                {
                case 's':
                    strcpy(arrayPeliculas[idPelicula].titulo, auxTitulo);
                    printf("Modificacion realizada con exito.\n");
                    break;
                case 'n':
                    printf("Se cancelo la modificacion.\n");
                    break;
                default:
                    printf("Ingrese una opcion valida. ");
                    break;
                }
            }
            while (confirmacion != 'n' && confirmacion != 's');
            break;
        case 2:
            auxActor = getValidInt("Ingrese el ID del actor: ", "Solamente puede ingresar numeros.", 0, 10);
            do
            {
                confirmacion = getChar("Confirma la modificacion? ");
                switch(confirmacion)
                {
                case 's':
                    arrayPeliculas[idPelicula].actor = auxActor;
                    printf("Modificacion realizada con exito.\n");
                    break;
                case 'n':
                    printf("Se cancelo la modificacion.\n");
                    break;
                default:
                    printf("Ingrese una opcion valida. ");
                    break;
                }
            }
            while (confirmacion != 'n' && confirmacion != 's');
            break;
/*        case 4:
            auxFloat = getValidFloat("Ingrese el dato float: ", "Solamente puede ingresar numeros", 0, 100);
            do
            {
                confirmacion = getChar("Confirma la modificacion? ");
                switch(confirmacion)
                {
                case 's':
                    arrayPeliculas[idCosa].datoFloat = auxFloat;
                    printf("Modificacion realizada con exito.\n");
                    break;
                case 'n':
                    printf("Se cancelo la modificacion.\n");
                    break;
                default:
                    printf("Ingrese una opcion valida. ");
                    break;
                }
            }
            while (confirmacion != 'n' && confirmacion != 's');
            break;*/
        }
    }
    else
    {
        printf ("ID vacio, intente nuevamente.\n");
    }
}
