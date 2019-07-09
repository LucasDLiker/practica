#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "menu.h"
#include "validaciones.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadEmpleados(char* path, LinkedList* pArrayListEmpleados)
{
    int retorno = FALSE;
    FILE* pFile;

    pFile = fopen (path, "r");
    if(pFile!=NULL)
    {
        parserEmpleados(pFile,pArrayListEmpleados);
        retorno = TRUE;
    }
    fclose(pFile);
    return retorno;
}

void controller_listOne(LinkedList* pArrayListEmployee, int index)
{
    eEmpleado* auxEmpleado;
    int auxId;
    char auxNombre[50];
    char auxEmpleo[50];
    int auxEdad;
    int auxHoras;

    auxEmpleado = ll_get(pArrayListEmployee, index);

    employee_getId(auxEmpleado, &auxId);
    employee_getNombre(auxEmpleado,auxNombre);
    employee_getEmpleo(auxEmpleado,auxEmpleo);
    employee_getEdad(auxEmpleado,&auxEdad);
    employee_getHorasTrabajadas(auxEmpleado,&auxHoras);


    printf("| %-4d | %-11s | %-15s | %-4d | %-19d |\n", auxId, auxNombre, auxEmpleo, auxEdad, auxHoras);

}

void controller_listOneConSueldo(LinkedList* pArrayListEmployee, int index)
{
    eEmpleado* auxEmpleado;
    int auxId;
    char auxNombre[50];
    char auxEmpleo[50];
    int auxEdad;
    int auxHoras;
    int auxSueldo;

    auxEmpleado = ll_get(pArrayListEmployee, index);

    employee_getId(auxEmpleado, &auxId);
    employee_getNombre(auxEmpleado,auxNombre);
    employee_getEmpleo(auxEmpleado,auxEmpleo);
    employee_getEdad(auxEmpleado,&auxEdad);
    employee_getHorasTrabajadas(auxEmpleado,&auxHoras);
    employee_getSueldo(auxEmpleado,&auxSueldo);


    printf("| %-4d | %-11s | %-15s | %-4d | %-19d | %-10d |\n", auxId, auxNombre, auxEmpleo, auxEdad, auxHoras, auxSueldo);

}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    int i;

    int retorno = FALSE;
    printf("=====================================================================\n"
           "|                       LISTADO                                     |\n"
           "=====================================================================\n"
           "|  ID  |    NOMBRE   |       EMPLEO    | EDAD |  HORAS TRABAJADAS   |\n"
           "=====================================================================\n");

    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        controller_listOne(pArrayListEmployee,i);
        retorno = TRUE;
    }
    printf("=====================================================================\n");
    return retorno;
}

int controller_ListEmployeeConSueldo(LinkedList* pArrayListEmployee)
{

    int i;
    int retorno = FALSE;
    printf("==================================================================================\n"
           "|                       LISTADO                                                  |\n"
           "==================================================================================\n"
           "|  ID  |    NOMBRE   |       EMPLEO    | EDAD |  HORAS TRABAJADAS   |   SUELDO   |\n"
           "==================================================================================\n");

    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        controller_listOneConSueldo(pArrayListEmployee,i);
        retorno = TRUE;
    }
    printf("==================================================================================\n");
    return retorno;
}
/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    //int opcion;
    int retorno = FALSE;
    if(pArrayListEmployee!=NULL)
    {
        printf("Aguarde unos segundos...\n");
        ll_sort(pArrayListEmployee,sortEmployeeByName,1);
        retorno = TRUE;
    }
//    opcion = subMenuOrdenar();
//    switch(opcion)
//    {
//    case 1:
//        printf("Aguarde unos segundos...\n");
//        ll_sort(pArrayListEmployee,sortEmployeeById,1);
//        retorno = TRUE;
//        break;
//    case 2:

//        break;
//    case 3:
//        printf("Aguarde unos segundos...\n");
//        ll_sort(pArrayListEmployee,sortEmployeeByHorasTrabajadas,1);
//        retorno = TRUE;
//        break;
//    case 4:
//        printf("Aguarde unos segundos...\n");
//        ll_sort(pArrayListEmployee,sortEmployeeBySueldo,1);
//        retorno = TRUE;
//        break;
    return retorno;
}


int controller_guardarTexto(char* path, LinkedList* this)
{
    FILE* pFileText;
    eEmpleado* employee;

    int auxId;
    char auxNombre[50];
    char auxEmpleo[50];
    int auxEdad;
    int auxHoras;
    int auxSueldo;

    int retorno = FALSE;
    int i;


    pFileText = fopen(path, "w");
    if(pFileText != NULL && this != NULL)
    {
        fprintf(pFileText, "id,nombre,empleo,edad,horasTrabajadas,sueldo\n");
        for(i=0; i < ll_len(this); i++)
        {
            employee = ll_get(this,i);
            if(employee!=NULL)
            {
                employee_getId(employee, &auxId);
                employee_getNombre(employee,auxNombre);
                employee_getEmpleo(employee,auxEmpleo);
                employee_getEdad(employee,&auxEdad);
                employee_getHorasTrabajadas(employee,&auxHoras);
                employee_getSueldo(employee,&auxSueldo);
                fprintf(pFileText, "%d,%s,%s,%d,%d,%d\n", auxId, auxNombre,auxEmpleo,auxEdad, auxHoras, auxSueldo);
            }

        }
        retorno = TRUE;
    }
    fclose(pFileText);
    return retorno;
}




