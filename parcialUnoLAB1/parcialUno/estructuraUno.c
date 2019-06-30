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

int inicializarEstadoGeneros (sGeneros* arrayGeneros, int capacidad)
{
    int retorno = ILOGICO;
    int i;
    if(arrayGeneros != NULL && capacidad != 0)
    {
        retorno = OCUPADO;
        for (i=0; i<capacidad; i++)
        {
            arrayGeneros[i].datoOcupado = LIBRE;
        }
    }
    return retorno;
}

int buscarLibreGeneros(sGeneros* arrayGeneros, int capacidad)
{
    int retorno = ILOGICO;
    int i;
    if(capacidad > 0 && arrayGeneros != NULL)
    {
        for(i=0; i<capacidad; i++)
        {
            if(arrayGeneros[i].datoOcupado == LIBRE)
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

void mostrarListaGeneros(sGeneros* arrayGeneros, int cantidad)
{
    int i;
    printf("=====================================================================\n"
           "||                      Listado de Generos                         ||\n"
           "=====================================================================\n");
    for(i=0; i<cantidad; i++)
    {
        if(arrayGeneros[i].datoOcupado == OCUPADO)
        {
            printf(" %4d | %20s                      \n",arrayGeneros[i].id, arrayGeneros[i].genero);
            //printf(" %4d | %50s | %d   | %2d |                \n", listaPeliculas[i].id, listaPeliculas[i].titulo, listaPeliculas[i].genero, /*relacion*/, listaPeliculas[i].actor);/*listaPeliculas[i].fecha*/
        }


    }
    printf("=====================================================================\n");
}


int agregarPelicula(sPeliculas* arrayPeliculas, int capacidad, sActores* arrayActores, sGeneros* arrayGeneros)
{

    int retorno = -1;
    int index = buscarLibrePeliculas(arrayPeliculas, capacidad);
    char auxTitulo[51];
    char buffer[256];
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
            for(i=0; i < strlen(auxTitulo); i++)
            {
                if(auxTitulo[i] == ' ')
                {
                    auxTitulo[i+1]=toupper(auxTitulo[i+1]);
                }
            }
            strcpy(arrayPeliculas[index].titulo, auxTitulo);
            /*------------------GENERO------------------------*/
            mostrarListaGeneros(arrayGeneros, LIMITE);
            auxGenero = getValidInt("Ingrese el ID del genero: ", "Solamente puede ingresar numeros.", 0, 5);
            arrayPeliculas[index].genero = auxGenero;
            /*-----------------ACTOR-------------------------*/
            mostrarListaActores(arrayActores, LIMITE);
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

void mostrarPelicula(sPeliculas* listaPeliculas, int lugar, int cantidadPeliculas, sActores* listaActores, int cantidadActores, sGeneros* listaGeneros, int cantidadGeneros)
{
    int j;
    int k;
    char relacionActor[20];
    char relacionGenero[20];
    printf("\nUsted selecciono: \n\n");

        if(listaPeliculas[lugar].datoOcupado == OCUPADO)
        {
            for(j=0; j<cantidadActores; j++)
            {
                if(listaPeliculas[lugar].actor == listaActores[j].id)
                {
                    strcpy(relacionActor, listaActores[j].nombre);
                }
            }

            for(k=0; k<cantidadGeneros; k++)
            {
                if(listaPeliculas[lugar].genero == listaGeneros[k].id)
                {
                    strcpy(relacionGenero, listaGeneros[k].genero);
                }
            }
            printf(" %4d | %10s | %10s  | %10s |  %2d/%2d/%4d  \n\n",listaPeliculas[lugar].id, listaPeliculas[lugar].titulo, relacionGenero, relacionActor,/* listaPeliculas[lugar].genero,listaPeliculas[lugar].actor,*/ listaPeliculas[lugar].dia, listaPeliculas[lugar].mes, listaPeliculas[lugar].anio);
        }

}

void mostrarUnaPelicula(sPeliculas* listaPeliculas, int indice, sActores* listaActores, int cantidadActores, sGeneros* listaGeneros, int cantidadGeneros)
{
    int j;
    int k;
    char relacionActor[20];
    char relacionGenero[20];
    if(listaPeliculas!= NULL)
    {

        if(listaPeliculas[indice].datoOcupado==0)
        {
            for(j=0; j<cantidadActores; j++)
            {
                if(listaPeliculas[indice].actor == listaActores[j].id  && listaPeliculas[indice].datoOcupado == OCUPADO && listaActores[j].datoOcupado == OCUPADO)
                {
                    strcpy(relacionActor, listaActores[j].nombre);
                }
            }

            for(k=0; k<cantidadGeneros; k++)
            {
                if(listaPeliculas[indice].genero == listaGeneros[k].id && listaPeliculas[indice].datoOcupado == OCUPADO && listaGeneros[k].datoOcupado == OCUPADO)
                {
                    strcpy(relacionGenero, listaGeneros[k].genero);
                }
            }
            printf(" %4d | %25s | %10s  | %25s |           %2d/%2d/%4d                     \n",listaPeliculas[indice].id, listaPeliculas[indice].titulo, relacionGenero, relacionActor, listaPeliculas[indice].dia, listaPeliculas[indice].mes, listaPeliculas[indice].anio);
        }
    }

}

void mostrarTodasLasPeliculas(sPeliculas* listaPeliculas, int cantidadPeliculas, sActores* listaActores, int cantidadActores, sGeneros* listaGeneros, int cantidadGeneros)
{
    int i;
    printf("=====================================================================================================\n"
           "||                                          Listado:                                               ||\n"
           "=====================================================================================================\n");
    if (listaPeliculas != NULL)
    {
        for(i=0;i<cantidadPeliculas;i++)
        {
            if (listaPeliculas[i].datoOcupado == 0)
            {
                mostrarUnaPelicula(listaPeliculas, i, listaActores, LIMITE, listaGeneros, LIMITE);
            }
        }
    }
    printf("=====================================================================================================\n");
}


void mostrarListaPeliculas(sPeliculas* listaPeliculas, int cantidadPeliculas, sActores* listaActores, int cantidadActores, sGeneros* listaGeneros, int cantidadGeneros)
{
    int i;
    int j;
    int k;
    char relacionActor[256];
    char relacionGenero[256];
    printf("=====================================================================================================\n"
           "||                                          Listado:                                               ||\n"
           "=====================================================================================================\n");
    for(i=0; i<cantidadPeliculas; i++)
    {
        if(listaPeliculas[i].datoOcupado == OCUPADO)
        {
            for(j=0; j<cantidadActores; j++)
            {
                if(listaPeliculas[i].actor == listaActores[j].id  && listaPeliculas[i].datoOcupado == OCUPADO && listaActores[j].datoOcupado == OCUPADO)
                {
                    strcpy(relacionActor, listaActores[j].nombre);
                }
            }

            for(k=0; k<cantidadGeneros; k++)
            {
                if(listaPeliculas[i].genero == listaGeneros[k].id && listaPeliculas[i].datoOcupado == OCUPADO && listaGeneros[k].datoOcupado == OCUPADO)
                {
                    strcpy(relacionGenero, listaGeneros[k].genero);
                }
            }
            printf(" %4d | %25s | %10s  | %25s |           %2d/%2d/%4d                     \n",listaPeliculas[i].id, listaPeliculas[i].titulo, relacionGenero, relacionActor, listaPeliculas[i].dia, listaPeliculas[i].mes, listaPeliculas[i].anio);

        }


    }
    printf("=====================================================================================================\n");
}

int eliminarPelicula(sPeliculas* listaPeliculas, int cantidadPeliculas, sActores* listaActores, int cantidadActores, sGeneros* listaGeneros, int cantidadGeneros)
{
    int retorno = ILOGICO;
    int auxiliarId;
    char opcion;

    auxiliarId = getInt("Ingrese el ID a buscar: ");
    int idPelicula=encontrarPeliculaPorID(listaPeliculas, LIMITE, auxiliarId);
    mostrarPelicula(listaPeliculas, idPelicula, LIMITE, listaActores, LIMITE, listaGeneros, LIMITE);
    if (idPelicula>=0)
    {
        do
        {
            opcion = getChar("Confirma la baja? S/N\n");
            switch(opcion)
            {
            case 's':
                listaPeliculas[idPelicula].datoOcupado = LIBRE;
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


void modificarPelicula(sPeliculas* arrayPeliculas, int capacidad, sActores* arrayActores, int capacidadActores, sGeneros* arrayGeneros, int capacidadGeneros)
{
    char auxTitulo[51];
    char buffer[256];
    int auxDia;
    int auxMes;
    int auxAnio;
    int auxActor;
    int auxId;
    int opcion;
    char confirmacion;
    int i;


    auxId = getValidInt("Ingrese el ID a buscar: ", "Id incorrecto, intentelo nuevamente", 999, 2001);
    int idPelicula = encontrarPeliculaPorID(arrayPeliculas, LIMITE, auxId);
    mostrarPelicula(arrayPeliculas, idPelicula, LIMITE, arrayActores, LIMITE, arrayGeneros , LIMITE);
    if (idPelicula>=0)
    {
        printf("ID encontrado, indique que dato desea modificar: \n");
        opcion = subMenuModificarPelicula();
        switch(opcion)
        {
        case 1:
            getString("Ingrese el Titulo: ", buffer);
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
            mostrarListaActores(arrayActores, LIMITE);
            auxActor = getValidInt("Ingrese el ID del actor: ", "Solamente puede ingresar numeros.", 0, 10);
            mostrarActor(arrayActores, auxActor);
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
        case 3:
            auxDia = getValidInt("Ingrese el dia del estreno ", "Solamente puede ingresar numeros.", 0, 31);
            auxMes = getValidInt("Ingrese el mes del estreno ", "Solamente puede ingresar numeros.", 0, 12);
            auxAnio = getValidInt("Ingrese el anio del estreno ", "Solamente puede ingresar numeros.", 1989, 2019);
            do
            {
                confirmacion = getChar("Confirma la modificacion? ");
                switch(confirmacion)
                {
                case 's':
                    arrayPeliculas[idPelicula].dia = auxDia;
                    arrayPeliculas[idPelicula].mes = auxMes;
                    arrayPeliculas[idPelicula].anio = auxAnio;
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
        }
    }
    else
    {
        printf ("ID vacio, intente nuevamente.\n");
    }
}
