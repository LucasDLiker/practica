#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

/*------------------ENTEROS-----------------*/

int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&auxiliar);
    return auxiliar;
}

int esNumerico(char* str)
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int getStringNumeros(char* mensaje,char* input)
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getValidInt(char* requestMessage,char* errorMessage, int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        auxInt = atoi(auxStr);
        if(auxInt <= lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        return auxInt;
    }
}


/*-----------------FLOTANTES---------------------------*/

float getFloat(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%f",&auxiliar);
    return auxiliar;
}

int esNumericoFlotante(char* str)
{
    int i=0;
    int cantidadPuntos=0;
    while(str[i] != '\0')
    {
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;
        }
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int getStringNumerosFlotantes(char* mensaje,char* input)
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getValidFloat(char* requestMessage,char* errorMessage, int lowLimit, int hiLimit)
{
    char auxStr[256];
    float auxFloat;
    while(1)
    {
        if (!getStringNumerosFlotantes(requestMessage, auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        auxFloat = atof(auxStr);
        if(auxFloat <= lowLimit || auxFloat > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        return auxFloat;
    }
}

/*-----------------------STRING--------------------------------*/

char getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

void getString(char* mensaje,char* input)
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}

int esSoloLetras(char* str)
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int esAlfaNumerico(char* str)
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

int getStringLetras(char* mensaje,char* input)
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

void getValidString(char* requestMessage,char* errorMessage, char* input)
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        fflush(stdin);
        break;
    }

}

void validarMayusculas (char* buffer, char* nombre)
{
    int i;

    strcpy(nombre, buffer);
    strcpy(strlwr(nombre), nombre);
    nombre[0]=toupper(nombre[0]);
    for(i=0; i < strlen(nombre); i++)
    {
        if(nombre[i] == ' ')
        {
            nombre[i+1]=toupper(nombre[i+1]);
        }
    }
}
