
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "pelicula.h"
#include "actor.h"

///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------
/** \brief Generates a unique ID identifier for each ACTOR added
*
* \param NO parameters are received
* \return ID is the number of ID a rental will have
*
*/

int generates_Next_Id_Actor()
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

int initActores(eActor *actores, int ACTORESMAX)
{
    int rtn=-1;
    if (actores!=NULL && ACTORESMAX>0)
    {
        for (int i=0; i<ACTORESMAX; i++)
        {
            actores[i].isEmpty=1;
        }
        rtn=0;
    }
    return rtn;
}
///--------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------

