#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "estructuraUno.h"
#include "estructuraDos.h"
#include "funcionesGenericas.h"
#include "menu.h"
#include "hardcode.h"
#include "validaciones.h"

int inicializarEstadoActores (sActores* arrayActores, int capacidad)
{
    int retorno = ILOGICO;
    int i;
    if(arrayActores != NULL && capacidad != 0)
    {
        retorno = OCUPADO;
        for (i=0; i<capacidad; i++)
        {
            arrayActores[i].datoOcupado = LIBRE;
        }
    }
    return retorno;
}

int buscarLibreActores(sActores* arrayActores, int capacidad)
{
    int retorno = ILOGICO;
    int i;
    if(capacidad > 0 && arrayActores != NULL)
    {
        for(i=0; i<capacidad; i++)
        {
            if(arrayActores[i].datoOcupado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int datoCargadoActores(sActores* arrayActores, int capacidad)
{
    int retorno = 1;
    int i;
    if(capacidad > 0 && arrayActores != NULL)
    {
        for(i=0; i<capacidad; i++)
        {
            if(arrayActores[i].datoOcupado == OCUPADO)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int encontrarActorPorID(sActores* arrayActores, int capacidad, int id)
{
    int i;
    for(i=0; i<capacidad; i++)
    {
        if(arrayActores[i].id == id && arrayActores[i].datoOcupado == 0)
        {
            return i;
            break;
        }
    }
    return -1;
}

int agregarActor(sActores* arrayActores, int capacidad)
{

    int retorno = -1;
    int index = buscarLibreActores(arrayActores, capacidad);
    char auxNombre[51];
    char auxNacionalidad[51];
    char buffer[51];
    int i;
    if(capacidad > 0 && arrayActores != NULL)
    {
        if(index != -1)
        {
            /*----------------ID---------------------------*/
            arrayActores[index].id=index+1;
            /*---------------NOMBRE------------------------*/
            getString("Ingrese el nombre del Actor: ", buffer);
            while(strlen(buffer)>51)
            {
                getString("El nombre es demasiado largo, ingreselo nuevamente: ", buffer);
            }
            strcpy(auxNombre, buffer);
            strcpy(strlwr(auxNombre), auxNombre);
            auxNombre[0]=toupper(auxNombre[0]);
            for(i=0; i < strlen(auxNombre); i++)
            {
                if(auxNombre[i] == ' ')
                {
                    auxNombre[i+1]=toupper(auxNombre[i+1]);
                }
            }
            strcpy(arrayActores[index].nombre, auxNombre);
            /*-------------------NACIONALIDAD-------------*/
            getString("Ingrese la nacionalidad del Actor: ", buffer);
            while(strlen(buffer)>51)
            {
                getString("La nacionalidad es demasiado larga, ingreselo nuevamente: ", buffer);
            }
            strcpy(auxNacionalidad, buffer);
            strcpy(strlwr(auxNacionalidad), auxNacionalidad);
            auxNacionalidad[0]=toupper(auxNacionalidad[0]);
            for(i=0; i < strlen(auxNacionalidad); i++)
            {
                if(auxNacionalidad[i] == ' ')
                {
                    auxNacionalidad[i+1]=toupper(auxNacionalidad[i+1]);
                }
            }
            strcpy(arrayActores[index].nacionalidad, auxNacionalidad);
            /*------------------INT------------------------*/
//            auxInt = getValidInt("Ingrese el dato entero: ","Solamente puede ingresar numeros.", 0, 10);
//            arrayActores[index].datoInt = auxInt;
            /*-----------------CHAR-------------------------*/
//            auxChar = getChar("Ingrese el dato char: ");
//            arrayActores[index].datoChar = auxChar;
            /*-----------------FLOAT-------------------------*/
//            auxFloat = getValidFloat("Ingrese el dato float: ", "Solamente puede ingresar numeros", 0, 100);
//           arrayActores[index].datoFloat = auxFloat;
            /*------------------ESPACIO-----------------------*/
            arrayActores[index].datoOcupado = OCUPADO;

            retorno = 0;
            printf("Datos cargados correctamente.\n");
            system("pause");
            system("cls");
        }
    }
    return retorno;
}

void ordenarActoresPorNacionalidad(sActores* listaActores, int cantidad)
{
    int i;
    int j;
    sActores auxActores;

    for (i=0; i< cantidad; i++)
    {
        for(j = i+1; j < cantidad; j++)
        {
            if(strcmp(listaActores[j].nacionalidad,listaActores[i].nacionalidad)<0)
            {
                auxActores = listaActores[i];
                listaActores[i] = listaActores[j];
                listaActores[j] = auxActores;
            }
        }
    }
}

void mostrarListaActores(sActores* arrayActores, int cantidad)
{
    int i;
    printf("=====================================================================\n"
           "||                              Listado:                           ||\n"
           "=====================================================================\n");
    for(i=0; i<cantidad; i++)
    {
        if(arrayActores[i].datoOcupado == OCUPADO)
        {
            printf(" %10d | %30s | %20s               \n", arrayActores[i].id, arrayActores[i].nombre, arrayActores[i].nacionalidad);
        }
    }
    printf("=====================================================================\n");
}

int eliminarActor(sActores* arrayActores, int capacidad)
{
    int retorno = ILOGICO;
    int auxiliarId;
    char opcion;

    auxiliarId = getInt("Ingrese el ID a buscar: ");
    int idActor=encontrarActorPorID(arrayActores, LIMITE, auxiliarId);
    if (idActor>=0)
    {
        do
        {
            opcion = getChar("Confirma la baja? S/N\n");
            switch(opcion)
            {
            case 's':
                arrayActores[idActor].datoOcupado = LIBRE;
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


void modificarActores(sActores* arrayActores, int capacidad)
{
    char auxNombre[51];
    char auxNacionalidad[51];
    char buffer[51];
    int auxId;
    int opcion;
    char confirmacion;
    int i;

    auxId = getInt("Ingrese el ID a buscar: ");
    int idActor = encontrarActorPorID(arrayActores, LIMITE, auxId);
    if (idActor>=0)
    {
        printf("ID encontrado, indique que dato desea modificar: \n");
        opcion = subMenuModificarActor();
        switch(opcion)
        {
        case 1:
            getString("Ingrese el nombre del Actor: ", buffer);
            while(strlen(buffer)>51)
            {
                getString("El nombre es demasiado largo, ingreselo nuevamente: ", buffer);
            }
            strcpy(auxNombre, buffer);
            strcpy(strlwr(auxNombre), auxNombre);
            auxNombre[0]=toupper(auxNombre[0]);
            for(i=0; i < strlen(auxNombre); i++)
            {
                if(auxNombre[i] == ' ')
                {
                    auxNombre[i+1]=toupper(auxNombre[i+1]);
                }
            }
            strcpy(arrayActores[idActor].nombre, auxNombre);
            do
            {
                confirmacion = getChar("Confirma la modificacion? S/N ");
                switch(confirmacion)
                {
                case 's':
                    strcpy(arrayActores[idActor].nombre, auxNombre);
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
            getString("Ingrese la nacionalidad: ", buffer);
            while(strlen(buffer)>50)
            {
                getString("La nacionalidad es demasiado larga, ingresela nuevamente: ", buffer);
            }
            strcpy(auxNacionalidad, buffer);
            strcpy(strlwr(auxNacionalidad), auxNacionalidad);
            auxNacionalidad[0]=toupper(auxNacionalidad[0]);
            for(i=0; i < strlen(auxNacionalidad); i++)
            {
                if(auxNacionalidad[i] == ' ')
                {
                    auxNacionalidad[i+1]=toupper(auxNacionalidad[i+1]);
                }
            }
            strcpy(arrayActores[idActor].nacionalidad, auxNacionalidad);
            do
            {
                confirmacion = getChar("Confirma la modificacion? ");
                switch(confirmacion)
                {
                case 's':
                    strcpy(arrayActores[idActor].nacionalidad, auxNacionalidad);
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
/*        case 3:
            auxChar = getChar("Ingrese el char: ");
            do
            {
                confirmacion = getChar("Confirma la modificacion? ");
                switch(confirmacion)
                {
                case 's':
                    arrayActores[idCosa].datoChar = auxChar;
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
        case 4:
            auxFloat = getValidFloat("Ingrese el dato float: ", "Solamente puede ingresar numeros", 0, 100);
            do
            {
                confirmacion = getChar("Confirma la modificacion? ");
                switch(confirmacion)
                {
                case 's':
                    arrayActores[idCosa].datoFloat = auxFloat;
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
