#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parserEmpleados(FILE* pFile, LinkedList* pArrayListEmpleados)
{
    char auxId[8];
    char auxNombre[128];
    char auxEmpleo[128];
    char auxEdad[4];
    char auxHorasTrabajadas[8];
    int retorno = FALSE;
    eEmpleado* auxEmpleado;

    if(pFile != NULL)
    {

        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId,auxNombre,auxEmpleo,auxEdad,auxHorasTrabajadas);
            auxEmpleado = employee_newParametros(auxId,auxNombre,auxEmpleo,auxEdad,auxHorasTrabajadas);
            if(auxEmpleado!=NULL)
            {
                ll_add(pArrayListEmpleados,auxEmpleado);
                retorno = TRUE;
            }

        }
    }
    fclose(pFile);
    return retorno;
}


