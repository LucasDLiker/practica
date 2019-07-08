#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "controller.h"
#include "utn.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*    Puntero al path donde debe buscarse el archivo
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int rtn retorna 0 si es Error y 1 si es correcto
 *
 */

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* fp = fopen(path, "r");
    int rtn= 0;
    if(fp != NULL)
    {
        parser_EmployeeFromText(fp, pArrayListEmployee);
        rtn = 1;
    }
    else
    {
        printf("\n Archivo no cargado\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    fclose(fp);

    return rtn;
}
///------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*    Puntero al path donde debe buscarse el archivo
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int  rtn retorna 0 si es Error y 1 si es correcto
 *
 */

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* fp = fopen(path, "rb");
    int rtn= 0;
    if(fp != NULL)
    {
        parser_EmployeeFromBinary(fp, pArrayListEmployee);
        rtn = 1;
    }
    else
    {
        printf("\n Archivo binario no cargado\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    fclose(fp);

    return rtn;
}

///------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------
/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int  rtn retorna -1 si es Error y 1 si es correcto
 *
 */

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int rtn=-1,  isEmpty;
    Employee* pEmployee=NULL;
    char name [50], id [5], hoursWorked [4], salary [10];
    int newID=-1, rName=-1, rHoursWorked=-1, rSalary=-1, addedOk=-1;
    system ("cls");
    printf("\n\t\t\t ALTA DE EMPLEADO\n\n");

    do
    {
        newID=generates_Next_Id_Employee(pArrayListEmployee);
        isEmpty=controller_findEmployee(pArrayListEmployee, newID);
        if (isEmpty==-1)
        {
            itoa(newID, id, 10);
        }
    }
    while (isEmpty!=-1);

    printf("\nID: %s\n\n", id);
    while (rName!=1)
    {
        rName=enterName (name);
    }
    while(rHoursWorked!=1)
    {
        rHoursWorked=enterHoursWorked (hoursWorked);
    }
    while(rSalary!=1)
    {
        rSalary=enterSalary(salary);
    }
    pEmployee=employee_newParametros(id,name,hoursWorked,salary);

    if (pEmployee!=NULL)
    {
        addedOk=ll_add( pArrayListEmployee, pEmployee);
        if (addedOk!=0)
        {
            printf ("\n\nNo se ha podido agregar un registro con exito\n\n");
        }
        else
        {
            printf ("\n\nSe ha agregado un registro con exito\n\n");
            rtn=1;
        }
    }
    return rtn;
}

///------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------
/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int  rtn retorna -1 si es Error y 1 si es correcto
 *
 */

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int rtn=-1, id=-1, indexIs=-1, choice=-1;
    char name[30], hoursWorked [5], salary [10];
    int rName=-1, rHoursWorked=-1, rSalary=-1;
   /// Node *EmployeeData=NULL;
    void *pElement=NULL;
    pElement=employee_new();

    if (pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        id=getValidInt("\nIngrese el Id del registro a modificar: ","\nIngreso un Id inexistente ", 0, 100000);
        ///FIND EMPLOYEE TIENE Q MORIR, USAR GET EMPLOYEE
        indexIs=controller_findEmployee(pArrayListEmployee, id);
        if (indexIs!=-1)
        {
            controller_ListsSingleEmployee(pArrayListEmployee, indexIs);
            choice=getInt("\nQue desea modificar?:  1-Nombre   2-Hs Trabajadas  3-Salario");
            pElement=ll_get(pArrayListEmployee, indexIs);

            rtn=1;
            switch (choice)
            {
            case 1:
            {
                while (rName!=1)
                {
                    rName=enterName (name);
                }
                employee_setname(pElement,name);
                break;
            }
            case 2:
            {
                while(rHoursWorked!=1)
                {
                    rHoursWorked=enterHoursWorked (hoursWorked);
                }
                employee_sethoursWorked(pElement, atoi(hoursWorked));
                break;
            }
            case 3:
            {
                while(rSalary!=1)
                {
                    rSalary=enterSalary(salary);
                }
                employee_setsalary(pElement, atof(salary));
                break;
            }
            default:
            {
                printf("\nOpcion incorrecta\n");
                break;
            }
            }
        }
        else
        {
            printf("\n\nSelecciono un ID Inexistente\n\n");
        }
    }
    else
    {
        printf("La lista esta vacia");
    }
    return rtn;
}

///------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------
/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int     rtn retorna -1 si es Error y 1 si es correcto
 *
 */

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int rtn=-1, id=-1, indexIs=-1, choice=-1, removeOk=-1;

    if (pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        id=getValidInt("\nIngrese el Id del registro a borrar","\nIngreso un Id inexistente ", 1, 10000);
        indexIs=controller_findEmployee(pArrayListEmployee, id);

        if (indexIs!=-1)
        {
            controller_ListsSingleEmployee(pArrayListEmployee, indexIs);
            choice=getValidInt("\nEsta seguro que desea borrar? \t\t 1-Si    2-No\n\n? ","Ingreso una opcion incorrecta", 1, 2);
            switch (choice)
            {
            case 1:
            {
                removeOk=ll_remove( pArrayListEmployee, indexIs);
                if (removeOk==0)
                {
                    printf("\n\n\n\nSe ha borrado un archivo correctamente\n\n\n\n");
                }
                else
                {
                    printf("\n\n\n\nNo se ha borrado ningun archivo\n\n\n\n");
                }
                break;
            }
            case 2:
            {
                printf("\n\n\n\nNo se ha borrado ningun archivo\n\n\n\n");
                break;
            }
            default:
            {
                break;
            }
            }
        }
        else
        {
            printf("\n\nNO existe el ID\n\n");
        }

    }
    return rtn;
}

///------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------
/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int  rtn retorna -1 si es Error y 1 si es correcto
 *
 */

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
  ///  Employee *pEmpleado=employee_new();
    int rtn = 1, i=-1;
  ///s  int auxId, auxHsWorked;
   /// char auxName[50];
///    float auxSalary;
    system("cls");
    tags();
    for (i=0; i < ll_len(pArrayListEmployee); i++)
    {
        controller_ListsSingleEmployee (pArrayListEmployee, i);
    }
    printf("\n");
    return rtn;
}

///------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------
/** \brief Listar un empleado
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \param id int es el valor de id que debe ser impreso
* \return int  rtn retorna -1 si es Error y 1 si es correcto
 *
 */

void controller_ListsSingleEmployee(LinkedList* pArrayListEmployee, int id)
{
    Employee *pEmpleado;
    int auxId, auxHsWorked;
    char auxName[50];
    float auxSalary;
    ///  system("cls");   /// tags();
    pEmpleado = ll_get(pArrayListEmployee, id);
    employee_getId(pEmpleado, &auxId);
    employee_getname(pEmpleado, auxName);
    employee_gethoursWorked(pEmpleado, &auxHsWorked);
    employee_getsalary(pEmpleado, &auxSalary);
    printf("%3d %13s %12d %19.2f\n",auxId,auxName,auxHsWorked,auxSalary);
}

///------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------
/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int  rtn retorna -1 si es Error y 1 si es correcto
 *
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int rtn = -1;
    int option, order=0;

    printf("\n\nPor que campo desea ordenar?\n\n");
    printf("1-Id\n");
    printf("2-Nombre\n");
    printf("3-Horas trabajadas\n");
    printf("4-Salario\n");
    scanf("%d", &option);

    printf("\n\nDesea hacerlo en forma: 1-Ascendente    2-Descendente");
    scanf("%d", &order);

    switch (order)
    {
    case 1:
    {
        order=0;
        break;
    }
    case 2:
    {
        order=1;
        break;
    }
    default:
    {
        break;
    }
    }

    switch(option)
    {
    case 1:
        ll_sort(pArrayListEmployee, employeeSortById, order);
        printf("Ordenamiento por id realizado!\n");
        break;
    case 2:
        ll_sort(pArrayListEmployee, employeeSortByName, order);
        printf("Ordenamiento por nombre realizado!\n");
        break;
    case 3:
        ll_sort(pArrayListEmployee, employeeSortByHours, order);
        printf("Ordenamiento por horas trabajadas realizado!\n");
        break;
    case 4:
        ll_sort(pArrayListEmployee, employeeSortBySalary, order);
        printf("Ordenamiento por salario realizado!\n");
        break;
    default:
        printf("Opcion incorrecta\n");
        break;
    }
    return rtn;
}

///------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*    Puntero al path donde debe guardarse el archivo
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int  rtn retorna -1 si es Error y 1 si es correcto
 *
 */

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int rtn = -1;
    int auxId, auxHsWorked;
    char auxName[50];
    float auxSalary;
    Employee* this;
    FILE* csvFile = fopen(path, "w");

    if(csvFile==NULL)
    {
        printf("Error al guardar\n");
        return rtn;
    }
    fprintf(csvFile, "id,nombre,horasTrabajadas,sueldo\n"); ///IMPRIME ENCABEZADO
    if(pArrayListEmployee!=NULL)
    {
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            this = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(this, &auxId);
            employee_getname(this, auxName);
            employee_gethoursWorked(this, &auxHsWorked);
            employee_getsalary(this, &auxSalary);

            fprintf(csvFile, "%d,%s,%d,%f\n", auxId, auxName, auxHsWorked, auxSalary);
        }
        printf("\n\n\n%d Empleados guardados en modo texto OK!\n", ll_len(pArrayListEmployee));
        rtn = 1;
    }
    fclose(csvFile);
    return rtn;
}

///------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*    Puntero al path donde debe guardarse el archivo
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int  rtn retorna -1 si es Error y 1 si es correcto
 *
 */

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int rtn = -1;
    int len = ll_len(pArrayListEmployee);
    Employee* this;
    FILE* list = fopen(path, "wb");

    if(list==NULL)
    {
        printf("Error para guardar. No se pudo abrir archivo\n");
        return rtn;
    }
    if(pArrayListEmployee!=NULL)
    {
        for(int i=0; i<len; i++)
        {
            this = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(this,sizeof(Employee),1,list);
        }
        printf("\n\nArchivo guardado conteniendo %d empleados \n", ll_len(pArrayListEmployee));
        rtn = 1;
    }
    fclose(list);
    return rtn;
}

///------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------
/** \brief busca un empleado usando el ID
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \param id int es el valor que se usa para buscar un empleado en concreto
* \return int  rtn retorna -1 si es Error y 1 si es correcto
 *
 */

int controller_findEmployee(LinkedList* pArrayListEmployee, int id) ///-1 NO LO ENCONTRO
{
    Employee* pEmployee;
    int i, rtn = -1;
    int auxId=0;
    for (i=0; i < ll_len(pArrayListEmployee); i++)
    {
        pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
        employee_getId(pEmployee, &auxId);
        if (id == auxId)
        {
            rtn = i;
            break;
        }
    }
    return rtn;
}

///---------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------
/** \brief Generates a unique ID identifier for each Employee added
*
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
* \return ID is the number of ID an employee will have
*
*/

int generates_Next_Id_Employee (LinkedList* pArrayListEmployee)
{
    int id=-1;
    id=controller_find_Biggest_ID(pArrayListEmployee);
    if (id!=-1)
    {
        id ++;
    }
    return id;
}

///------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------
/** \brief Searches for the biggest ID used to create a new one, with the next number
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int MaxID    numero máximo de ID utilizado en la lista, esto no contempla los posibles ID´s utilizados y luego borrado, puesto que los sobreescribe.
 *
 */

int controller_find_Biggest_ID(LinkedList* pArrayListEmployee) ///-1 NO LO ENCONTRO
{
    Employee* pEmployee;
    int i, maxID=-1, auxId=0;

    if (pArrayListEmployee!=NULL)
    {

        for (i=0; i < ll_len(pArrayListEmployee); i++)
        {
            pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            employee_getId(pEmployee, &auxId);
            if (maxID < auxId)
            {
                maxID = auxId;

            }
            else if(maxID == auxId)
            {
                printf (" has caido en un vortex espacio temporal, no debería haber dos ID con igual valor, huye!!");
            }
        }
    }
    return maxID;
}

///----------------------------------------------------------------------------------
///----------------------------------------------------------------------------------

int FilteredList (void* pElement)
{
    int rtn=-1;
    Employee *pEmployee=NULL;
    float auxSalary=0;
    if (pElement!=NULL)
    {
        pEmployee=(Employee*) pElement;
        employee_getsalary(pEmployee, &auxSalary);
        if(auxSalary<1000)      ///ESTA ES LA CONDICION A CUMPLIR PARA SER GUARDADO EN LA NUEVA LISTA /// LOS QUE LA CUMPLEN SON PARTE DE LA NUEVA LISTA
        {
            rtn=0;
        }
    }
    return rtn;
}

///------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------
///REDUCE LA LISTA SEGUN UN CRITERIO DETERMINADO


int reducedList (void* pElement)
{
    int rtn=-1;
    Employee *pEmployee=NULL;
    float auxSalary=0;
    if (pElement!=NULL)
    {
        pEmployee=(Employee*) pElement;
        employee_getsalary(pEmployee, &auxSalary);
        if(auxSalary<1000)      ///ESTA ES LA CONDICION A CUMPLIR PARA SER GUARDADO EN LA NUEVA LISTA ///BORRA AQUELLO QUE CUMPLA ESTA CONDICION///
        {
            rtn=0;
        }
    }
    return rtn;
}


int reduceList(LinkedList* this)
{
    int ret=-1;

    if(!ll_reduce(this, reducedList))
        {
         ret=0;
        }
    return ret;
}

///------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------
///CALCULAN MAXIMOS
int maximoHoras(LinkedList* this)
{
    int contador=0;
    contador=ll_maximo(this, parametroMaximo);
    return contador;
}

int parametroMaximo(void* p)
{
    int ret=-1;
    int bufferCant;
    Employee* pLista;
    pLista=(Employee*)p;

    if(pLista!=NULL)
    {
       employee_gethoursWorked(pLista, &bufferCant);
        ret=bufferCant;
    }
    return ret;
}

///------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------
///CALCULAN MINIMOS
int minimoHoras(LinkedList* this)
{
    int contador=0;
    contador=ll_minimo(this, parametroMinimo);
    return contador;
}

int parametroMinimo(void* p)
{
    int ret=-1;
    int bufferCant;
    Employee* pLista;
    pLista=(Employee*)p;

    if(pLista!=NULL)
    {
       employee_gethoursWorked(pLista, &bufferCant);
        ret=bufferCant;
    }
    return ret;
}

///------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------
///SUMADOR INT

int sumadorDeEnteros(LinkedList* this)
{
    int contador=0;
    contador=ll_sumador(this, sumaEnteros)+contador;
    return contador;
}

int sumaEnteros(void* p)
{
    int bufferCant;
    int ret=0;
    Employee* pLista;
    pLista=(Employee*)p;

    if(pLista!=NULL)
    {
        employee_gethoursWorked(pLista, &bufferCant);
        ret=bufferCant;
    }
    return ret;
}

///------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------
///SUMADOR FLOAT

float sumadorDeFloat(LinkedList* this)
{
    float contador=0;
    contador=ll_sumadorFloat(this, sumaFloat);///+contador;
    printf("suma en foo sumador de float: %.2f", contador);
    return contador;
}

float sumaFloat(void* p)
{
    float bufferCant;
    float ret=0;
    Employee* pLista;
    pLista=(Employee*)p;

    if(pLista!=NULL)
    {
        employee_getsalary(pLista, &bufferCant);
        ret=bufferCant;
    }
    return ret;
}

///---------------------------------------------------------------------------------
///---------------------------------------------------------------------------------
///PROMEDIO DE SUELDOS USANDO SUMADOR FLOAT
float promedioSueldos(LinkedList* this)
{
    int lenList=ll_len(this);
    float cantidadTotal=0;
    float cantidadPromedio=0;
    cantidadTotal=ll_sumadorFloat(this, sueldoPromedio);
    cantidadPromedio= cantidadTotal/lenList;
    //printf("TOTAL %.2f", (float)cantidadPromedio);
    return cantidadPromedio;
}

float sueldoPromedio(void* p)
{
    float bufferSueldo;
    Employee* pLista;
    pLista=(Employee*)p;

    if(pLista!=NULL)
    {
       employee_getsalary(pLista, &bufferSueldo);
        //printf("suma %.2f\n", bufferSueldo);
    }
    return bufferSueldo;
}

///---------------------------------------------------------------------------------
///---------------------------------------------------------------------------------

int foo_Contador (void* pElement)
{
    int rtn=-1;
    float bufferSueldo;
    Employee* pLista;
    pLista=(Employee*)pElement;

    if(pLista!=NULL)
    {
        employee_getsalary(pLista, &bufferSueldo);
        ///printf("bufferSueldo:%.2f", bufferSueldo);system("pause");
        if (bufferSueldo<1000)      ///CONDICION PARA QUE SE SUME AL CONTADOR
       {
           rtn=0;
       }
    }
return rtn;
}
