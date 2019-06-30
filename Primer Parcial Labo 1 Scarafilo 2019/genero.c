#include <stdio.h>
#include <stdlib.h>


#include "genero.h"





///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------
/** \brief Generates a unique ID identifier for each rental added
*
* \param NO parameters are received
* \return ID is the number of ID a rental will have
*
*/

int generatesNextIdGenres()
{
    static int id = 0;
    id ++;
    return id;
}

///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------
/** \brief Initializes all position in the actores Array to Empty.
 *isEmpty=0 FALSE (POSITION TAKEN) / isEmpty=1  TRUE (EMPTY ARRAY POSITION)
 * \param eactores* actores, Pointer to Array of actores
 * \param GAMESMAX int length of the Array of actores
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int initGenre(eGenero *generos, int GENRESMAX)
{
    int rtn=-1;
    if (generos!=NULL && GENRESMAX>0)
    {
        for (int i=0; i<GENRESMAX; i++)
        {
            generos[i].isEmpty=1;
        }
        rtn=0;
    }
    return rtn;
}
///--------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------

