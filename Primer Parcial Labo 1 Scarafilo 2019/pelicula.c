#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///#include <ctype.h>
#include <conio.h>

#include "pelicula.h"
#include "fecha.h"
#include "utn.h"
#include "AvramidesJulian1C.h"
#include "controlfoos.h"
#include "genero.h"

///#define ACTORESMAX 50
///#define GENRESMAX 5


///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------
/** \brief Generates a unique ID identifier for each rental added
*
* \param NO parameters are received
* \return ID is the number of ID a rental will have
*
*/

int generatesNextIdpeliculas()
{
    static int id = 999;
    id ++;
    return id;
}

///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------

/** \brief Initializes all position in the peliculas Array to Empty.
 *isEmpty=0 FALSE (POSITION TAKEN) / isEmpty=1  TRUE (EMPTY ARRAY POSITION)
 * \param epeliculas* peliculas, Pointer to Array of peliculas
 * \param GAMESMAX int length of the Array of peliculas
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int initPeliculas(ePelicula *peliculas, int PELISMAX)
{
    int rtn=-1;
    if (peliculas!=NULL && PELISMAX >0)
    {
        for (int i=0; i<PELISMAX; i++)
        {
            peliculas[i].isEmpty=1;
        }
        rtn=0;
    }
    return rtn;
}

///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------

/** \brief Returns the first free index in the employees array
*
* \param eGames* games: Pointer to Array of employees
* \param ELEMENTS int: length of the Array of employees
*\return rtn int returns first free position in the employees array
*
*/

int obtainFreeSpacePeliculas(ePelicula* peliculas, int PELISMAX)
{
    int i;
    int rtn = -1;

    for(i=0; i<PELISMAX; i++)
    {
        if(peliculas[i].isEmpty == 1)
        {
            rtn = i;
            break;
        }
    }
    return rtn;
}

///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------
int addPelicula (ePelicula *peliculas, int PELISMAX, eGenero *generos, int GENRESMAX, eActor *actores, int ACTORESMAX)
{
    char auxiliarInput [60];
    int validationResult, peliId, indexIs, rtn=-1;
    int actorId;
    int day, month, year, ValidDate, generoId;


    system("cls");
    printf("\n\t\t\t\t ALTA PELICULAS\n\n");
    indexIs=obtainFreeSpacePeliculas (peliculas, PELISMAX);

    if (indexIs ==-1)
    {
        printf("\n\n No hay espacio libre para realizar un alta\n\n");
    }
    else if (peliculas!=NULL && PELISMAX>0)
    {
        peliId=generatesNextIdpeliculas();
        peliculas[indexIs].id= peliId;
        do
        {
            fflush(stdin);
            validationResult= getStringLetras("Ingrese Titulo de la pelicula:",auxiliarInput);
        }
        while (validationResult==0);

        changeCase (auxiliarInput);
        strcpy (peliculas[indexIs].titulo, auxiliarInput);

        do
        {
            fflush(stdin);
            day=getValidInt("Ingrese el dia del estreno: ","ERROR", 1, 31);
            fflush(stdin);
            month=getValidInt("Ingrese el mes del estreno: ","ERROR", 1, 12);
            fflush(stdin);
            year=getValidInt("Ingrese el anio del estreno: ","ERROR", 1895, 2020);
            ValidDate=isValidDate(day, month, year);
        }
        while (ValidDate!=0);
        peliculas[indexIs].fechaDeEstreno.day=day;
        peliculas[indexIs].fechaDeEstreno.month=month;
        peliculas[indexIs].fechaDeEstreno.year=year;


        do
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
        peliculas[indexIs].genero=generoId;

        do
        {
            printf("\n");
            for (int q=0; q<ACTORESMAX; q++)
            {
                printf("%d-%s\n", actores[q].id, actores[q].nombre);
            }
            printf("\n");
            fflush(stdin);
            validationResult=getValidInt("Seleccione el actor de la pelicula:","Error", 1, 10);                     ///EN LUGAR DE 10 DEBE SER ACTORESMAX
            actorId=validationResult;
        }
        while (validationResult==0);

///    peliculas[indexIs].genero=generoId;
        peliculas[indexIs].actor=actorId;
        peliculas[indexIs].isEmpty=0;
        rtn=1;
    }
    return rtn;           ///RETURN PASSES 1 AS OK VALUE
}

///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------
/** \brief Remove a eEmployee  by Id (put isEmpty Flag in 1)
*
* \param eEmployee  *list: Pointer to Array of employees
* \param len int: length of the Array of employees
* \param id int: Unique identifier for each employee
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/

int removePeli(ePelicula* peliculas, int PELISMAX, eGenero *generos, int GENRESMAX, eActor *actores, int ACTORESMAX)
{
    int id;
    int confirmErase;
    int indexIs=-1;

    system("cls");
    printf("\t\t\t BAJAS PELICULAS\n");
    printsPelis(peliculas, PELISMAX, generos, GENRESMAX, actores, ACTORESMAX);

    id=getValidInt("\n Ingrese el ID de la pelicula a eliminar:\n\n","ERROR", 1000, 1000+PELISMAX);

    indexIs=findPeliById(peliculas, PELISMAX,id);

    if (indexIs==-1)
    {
        printf("\nLa pelicula no existe");
        system("pause");
    }
    else
    {
        system("cls");
        ///ACA VA TAGS PELIS
        printsSinglePeli(peliculas,indexIs, generos, GENRESMAX, actores, ACTORESMAX);

        printf("\n\n\n Esta seguro que desea eliminar %s\n\n",peliculas[indexIs].titulo);
        printf("\n\t 1-Si \t\t 2-No  \n\n? ");

        confirmErase=getche();

        while (confirmErase!=49&&confirmErase!=50)
        {
            printf("? ");
            confirmErase=getche();
        }

        if (confirmErase==49)
        {
            printf("\n\n %s ha sido eliminado!\n\n", peliculas[indexIs].titulo);
            peliculas[indexIs].isEmpty=1;
            system("pause");
        }
        else
        {
            printf("\n\n Ninguna pelicula ha sido eliminada!\n\n");
            system("pause");
        }
    }

    return 0;           /// EL RETURN NO SIRVE PA NADA

}///CIERRA FUNCION

///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------
/** \brief find an employee by Id and returns the index position in employees array
 *
 * \param eGames* games: Pointer to Array of employees
 * \param GAMESMAX int: length of the Array of employees
 * \param id int: Unique identifier for each employee
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */

int findPeliById(ePelicula* peliculas, int PELISMAX,int id)
{
    int index=-1;

    for (int i=0; i<PELISMAX; i++)
    {
        if (peliculas[i].id==id && peliculas[i].isEmpty==0)
        {
            index=i;
            break;
        }
    }
    return index;
}

///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------
int modifyPeli(ePelicula* peliculas, int PELISMAX, eGenero *generos, int GENRESMAX, eActor *actores, int ACTORESMAX)
{
    int validationResult;
    int day, month, year, ValidDate, actorId;
    char auxiliarInput [60];
    int indexIs;
    int modifyselected;
    int modifyId;

    system("cls");
    printf("\n\t\t\tMODIFICA PELICULAS\n\n ");
    printsPelis(peliculas, PELISMAX, generos, GENRESMAX, actores, ACTORESMAX);
    printf("\n\nIngrese Nro de Legajo: ");
    scanf("%d", &modifyId);
    indexIs=findPeliById(peliculas, PELISMAX,modifyId);
    if (indexIs==-1)
    {
        printf("\nLa peli no existe");
    }
    else
    {
        system("cls");
        printsSinglePeli(peliculas,indexIs, generos, GENRESMAX, actores, ACTORESMAX);
        modifyselected=getValidInt("\n\n\n\nIngrese lo q desea modificar: \n\n1-Titulo\t2-fecha de estreno\t3-Actor\t4-SALIR\n\n\n? ","ERROR", 1, 4);
        switch (modifyselected)
        {
        case 1:   ///TITULO
        {
            do
            {
                fflush(stdin);
                validationResult= getStringLetras("\nIngrese Titulo de la pelicula:",auxiliarInput);
            }
            while (validationResult==0);

            changeCase (auxiliarInput);
            strcpy (peliculas[indexIs].titulo, auxiliarInput);
            break;
        }
        case 2:   ///FECHA
        {
            do
            {
                fflush(stdin);
                day=getValidInt("Ingrese el dia del estreno: ","ERROR", 1, 31);
                fflush(stdin);
                month=getValidInt("Ingrese el mes del estreno: ","ERROR", 1, 12);
                fflush(stdin);
                year=getValidInt("Ingrese el anio del estreno: ","ERROR", 1895, 2020);
                ValidDate=isValidDate(day, month, year);
            }
            while (ValidDate!=0);
            peliculas[indexIs].fechaDeEstreno.day=day;
            peliculas[indexIs].fechaDeEstreno.month=month;
            peliculas[indexIs].fechaDeEstreno.year=year;
            break;
        }
        case 3:   ///ACTOR
        {
            do
            {
                printf("\n");
                for (int q=0; q<ACTORESMAX; q++)
                {
                    printf("%d-%s\n", actores[q].id, actores[q].nombre);
                }
                printf("\n");
                fflush(stdin);
                validationResult=getValidInt("Seleccione el actor de la pelicula:","Error", 1, 10);                     ///EN LUGAR DE 10 DEBE SER ACTORESMAX
                actorId=validationResult;
            }
            while (validationResult==0);

            peliculas[indexIs].actor=actorId;
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            break;
        }
        }
    }
    return 0;           ///RETURN SIN VALOR
}
///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------
