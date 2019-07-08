#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"




/** \brief Reserves space for 1 Employee
 *
 * \param void
 * \return Employee's
 *
 */

Employee *employee_new()
{
    return (Employee*)calloc(1, sizeof(Employee));
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
/** \brief Sets all parameters for 1 Employee
 *
 * \param char* id  id del empleado
 * \param char* name    nombre del empleado
 * \param char* hoursWorked horas trabajadas del empleado
 * \param char* salary salario del empleado
 * \return Employee's retorna la direcci�n de memoria del empleado cargado
 *
 */
Employee* employee_newParametros(char* id,char* name,char* hoursWorked,char* salary)
{
    int auxId, auxHoursWorked;
    float auxSalary;
    Employee* this = employee_new();
    if(this != NULL)
    {
        auxId = atoi(id);
        employee_setId(this, auxId);

        employee_setname(this, name);

        auxHoursWorked= atoi(hoursWorked);
        employee_sethoursWorked(this, auxHoursWorked);

        auxSalary = atof(salary);
        employee_setsalary(this,auxSalary);
    }
    return this;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
/** \brief Sets id parameter for 1 Employee
 *
 * \param int* id  id del empleado
  * \param Employee* this linked List de empleados
  * \return rtn int valor de control 0 es Error  1 es correcto
 *
 */
int employee_setId(Employee* this, int id)
{
    int rtn = 0;
    if (id >= 0 && id <10000 && this != NULL)
    {
        this->id = id;
        rtn = 1;
    }
    return rtn;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
/** \brief Gets id parameter for 1 Employee
 *
 * \param int* id  id del empleado
  * \param Employee* this linked List de empleados
  * \return rtn int valor de control 0 es Error  1 es correcto
 *
 */

int employee_getId(Employee* this, int* id)
{
    int rtn = 0;
    if (id != NULL && this != NULL)
    {
        *id = this->id;
        rtn = 1;
    }
    return rtn;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
/** \brief Sets name parameter for 1 Employee
 *
 * \param char* name  nombre del empleado
  * \param Employee* this linked List de empleados
  * \return rtn int valor de control 0 es Error  1 es correcto
 *
 */

int employee_setname(Employee* this,char* name)
{
    int rtn = 0;
    if (strlen(name) > 0 && this != NULL)
    {
        strncpy(this->name, name, 50);
        rtn = 1;
    }
    return rtn;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
/** \brief Gets name parameter for 1 Employee
 *
 * \param char* name  nombre del empleado
  * \param Employee* this linked List de empleados
  * \return rtn int valor de control 0 es Error  1 es correcto
 *
 */

int employee_getname(Employee* this,char* name)
{
    int rtn = 0;
    if (strlen(this->name) > 0 && this != NULL)
    {
        strncpy(name, this->name, 50) ;
        rtn = 1;
    }
    return rtn;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
/** \brief Sets hoursWorked parameter for 1 Employee
 *
 * \param int* hoursWorked horas trabajadas del empleado
  * \param Employee* this linked List de empleados
  * \return rtn int valor de control 0 es Error  1 es correcto
 *
 */

int employee_sethoursWorked(Employee* this, int hoursWorked)
{
    int rtn = 0;
    if(this != NULL)
    {
        if (hoursWorked>= 0 && hoursWorked<500)
        {
            this->hoursWorked= hoursWorked;
            rtn = 1;
        }
        else
        {
            printf("\n\ningreso un dato erroneo\n\n");
        }
    }
    return rtn;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
/** \brief Gets hoursWorked parameter for 1 Employee
 *
 * \param int* hoursWorked  nombre del empleado
  * \param Employee* this linked List de empleados
  * \return rtn int valor de control 0 es Error  1 es correcto
 *
 */

int employee_gethoursWorked(Employee* this,int* hoursWorked)
{
    int rtn = 0;
    if (hoursWorked!= NULL && this != NULL)
    {
        *hoursWorked = this->hoursWorked;
        rtn = 1;
    }
    return rtn;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
/** \brief Sets salary parameter for 1 Employee
 *
 * \param char* salary salario del empleado
  * \param Employee* this linked List de empleados
  * \return rtn int valor de control 0 es Error  1 es correcto
 *
 */

int employee_setsalary(Employee* this, float salary)
{
    int rtn = 0;
    if (salary> 0  && this != NULL)
    {
        this->salary = salary;
        rtn = 1;
    }
    return rtn;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
/** \brief Gets salary parameter for 1 Employee
 *
 * \param int* salary  salario del empleado
 * \param Employee* this linked List de empleados
 * \return rtn int valor de control 0 es Error  1 es correcto
 *
 */

int employee_getsalary(Employee* this,float *salary)
{
    int rtn = 0;
    if (salary!= NULL && this != NULL)
    {
        *salary = this->salary;
        rtn = 1;
    }
    return rtn;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
/** \brief function to retrieve input data from user
 *
 * \param char* id Puntero al dato ID
 * \return rtn int valor de control 0 es Error  1 es correcto
 *
 */

int enterId (char *id)
{
    int rtn=1, r=0;
    getString("Ingrese el Id: ", id);
    r=esNumerico(id);

    if (r==0)
    {
        printf("\n\nID incorrecto\n\n");
        rtn=0;
    }
    ///printf("\n FOO ENTERID ID:%s\n", id);

    return rtn;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
/** \brief function to retrieve input data from user
 *
 * \param char* name Puntero al dato nombre
 * \return rtn int valor de control 0 es Error  1 es correcto
 *
 */

int enterName (char *name)
{
    int rtn=1, r=0;

    getString("Ingrese el nombre: ", name);
    r=esSoloLetras(name);

    if (r==0)
    {
        printf("\n\nNombre incorrecto\n\n");
        rtn=0;
    }
    else
    {
        changeCase(name);
    }

    return rtn;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
/** \brief function to retrieve input data from user
 *
 * \param char* hoursWorked Puntero al dato horas trabajadas
 * \return rtn int valor de control 0 es Error  1 es correcto
 *
 */

int enterHoursWorked (char *hoursWorked)
{
    int rtn=1, auxHours=-1;
    auxHours=getValidInt("Ingrese las horas trabajadas: ","ingreso un dato erroneo", 1, 500);
    if (auxHours<0 || auxHours>=500)
    {
        printf("\n\nCampo horas incorrecto\n\n");
        rtn=0;
    }
    else
    {
        itoa(auxHours, hoursWorked, 10);
    }
    return rtn;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
/** \brief function to retrieve input data from user
 *
 * \param char*  salary Puntero al dato salario
 * \return rtn int valor de control 0 es Error  1 es correcto
 *
 */

int enterSalary(char *salary)
{
    int rtn=1, r=0;
    getString("Ingrese el salario: ",salary);
    r=esNumericoFlotante (salary);
    if (r==0)
    {
        printf("\n\nsalario incorrecto\n\n");
        rtn=0;
    }
    ///printf("\nFOO ENTERSALARY salary:%s\n", salary);
    return rtn;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
/** \brief function to sort by ID
 *
 * \param void* empleadoA   Puntero que contiene uno de los empleados a ordenar
 * \param void* empleadoB   Puntero que contiene el segundo de los empleados a ordenar
 * \return rtn int valor de control 0 es ambos empleados son iguales / 1 empleadoA es menor que empleadoB / -1 empleadoA es mayor que empleadoB
 *
 */

int employeeSortById(void* empleadoA, void* empleadoB)
{
    int rtn= 0;
    int empA;
    int empB;

    employee_getId(empleadoA, &empA);
    employee_getId(empleadoB, &empB);

    if(empleadoA !=NULL && empleadoB !=NULL)
    {
        if(empA<empB)
        {
            rtn= 1 ;
        }
        else if(empA>empB)
        {
            rtn= -1 ;
        }
    }
    return rtn;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
/** \brief function to sort by name
 *
 * \param void* empleadoA   Puntero que contiene uno de los empleados a ordenar
 * \param void* empleadoB   Puntero que contiene el segundo de los empleados a ordenar
 * \return rtn int valor de control 0 es ambos empleados son iguales / 1 empleadoA es menor que empleadoB / -1 empleadoA es mayor que empleadoB
 *
 */

int employeeSortByName(void* empleadoA, void* empleadoB)
{
    int rtn= 0;
    char empA[51];
    char empB[51];

    employee_getname(empleadoA, empA);
    employee_getname(empleadoB, empB);

    if(empleadoA !=NULL && empleadoB !=NULL)
    {
      rtn= strcmp(empB, empA);
    }

    return rtn;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
/** \brief function to sort by hoursWorked
 *
 * \param void* empleadoA   Puntero que contiene uno de los empleados a ordenar
 * \param void* empleadoB   Puntero que contiene el segundo de los empleados a ordenar
 * \return rtn int valor de control 0 es ambos empleados son iguales / 1 empleadoA es menor que empleadoB / -1 empleadoA es mayor que empleadoB
 *
 */

int employeeSortByHours(void* empleadoA, void* empleadoB)
{
    int rtn= 0;
    int empA;
    int empB;

    if(empleadoA !=NULL && empleadoB !=NULL)
    {
     employee_gethoursWorked(empleadoA, &empA);
     employee_gethoursWorked(empleadoB, &empB);

        if(empA<empB)
        {
            rtn= 1 ;
        }
        else if(empA>empB)
        {
            rtn= -1 ;
        }
        else if(empA==empB)
        {
            rtn= 0;
        }
    }
    return rtn;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
/** \brief function to sort by Salary
 *
 * \param void* empleadoA   Puntero que contiene uno de los empleados a ordenar
 * \param void* empleadoB   Puntero que contiene el segundo de los empleados a ordenar
 * \return rtn int valor de control 0 es ambos empleados son iguales / 1 empleadoA es menor que empleadoB / -1 empleadoA es mayor que empleadoB
 *
 */

int employeeSortBySalary(void* empleadoA, void* empleadoB)
{
    int rtn= -1;
    float empA;
    float empB;

    if(empleadoA !=NULL && empleadoB !=NULL)
    {
        employee_getsalary(empleadoA, &empA);
        employee_getsalary(empleadoB, &empB);

        if(empA<empB)
        {
            rtn= 1 ;
        }
        else if(empA>empB)
        {
            rtn= -1 ;
        }
        else if(empA==empB)
        {
            rtn= 0;
        }
    }
    return rtn;
}

///----------------------------------------------------------------------------------
///----------------------------------------------------------------------------------

int foo_Compara_Letras (void* pElement)
{
    int rtn=-1, prueba=-1;
    char auxName[51];
    char valor[10]="Juli";
    Employee *empleado=NULL;
    empleado=(Employee*)pElement;

    if(empleado!=NULL)
    {
    employee_getname(empleado, auxName);
    prueba=strcmp(auxName, valor);

    ///printf("\naux name: %s\t", auxName);
    ///printf("prueba: %d\t", prueba);
    if (prueba==0)
    {
        rtn=0;
    }
    }
   /// printf("letras rtn;%d", rtn);
    return rtn;
}
///----------------------------------------------------------------------------------
///----------------------------------------------------------------------------------
/** \brief borra el empleado
 *
 * \param la lista
 * \return -1 si dio erro y 0 si se pudo borra el empleado
 *
 */

int emp_Delete(Employee* this)
{
    int ret = -1;
    if(this != NULL)
    {
        free(this);
        ret = 0;
    }
    return ret;
}
///-----------------------------------------------------------------------------
///-----------------------------------------------------------------------------


