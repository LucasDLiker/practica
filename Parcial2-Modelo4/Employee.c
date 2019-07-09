#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

eEmpleado *employee_new()
{
    eEmpleado* employeeReturn;
    employeeReturn = (eEmpleado*) malloc(sizeof(eEmpleado));
    return employeeReturn;
}

eEmpleado* employee_newParametros(char* idStr, char* nombreStr, char* empleoStr, char* edadStr, char* horasTrabajadasStr)
{
    eEmpleado* employeeReturn;
    employeeReturn = employee_new();

    if(employeeReturn!=NULL)
    {
        employee_setId(employeeReturn, atoi((idStr)));
        employee_setNombre(employeeReturn, nombreStr);
        employee_setEmpleo(employeeReturn, empleoStr);
        employee_setEdad(employeeReturn, atoi(edadStr));
        employee_setHorasTrabajadas(employeeReturn, atoi(horasTrabajadasStr));;
    }

    return employeeReturn;
}


int employee_setNombre(eEmpleado* this, char* nombre)
{
    int retorno = FALSE;

    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = TRUE;
    }

    return retorno;
}

int employee_setId(eEmpleado* this, int id)
{
    int retorno = FALSE;

    if(this!=NULL && id>0)
    {
        this->id=id;
        retorno = TRUE;
    }

    return retorno;
}

int employee_setHorasTrabajadas(eEmpleado* this, int horasTrabajadas)
{
    int retorno = FALSE;

    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno = TRUE;
    }

    return retorno;
}

int employee_setEmpleo(eEmpleado* this, char* empleo)
{
    int retorno = FALSE;

    if(this!=NULL)
    {
        strcpy(this->empleo,empleo);
        retorno = TRUE;
    }

    return retorno;
}

int employee_setEdad(eEmpleado* this, int edad)
{
    int retorno = FALSE;

    if(this!=NULL && edad>0)
    {
        this->edad=edad;
        retorno = TRUE;
    }

    return retorno;
}

int employee_setSueldo(eEmpleado* this,int sueldo)
{
    int retorno = FALSE;

    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        retorno = TRUE;
    }

    return retorno;
}

int employee_getId(eEmpleado* this,int* id)
{
    int retorno = FALSE;

    if(this!=NULL && id>0)
    {
        *id = this->id;
        retorno = TRUE;
    }

    return retorno;
}


int employee_getNombre(eEmpleado* this,char* nombre)
{
    int retorno = FALSE;

    if(this!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = TRUE;
    }

    return retorno;
}

int employee_getHorasTrabajadas(eEmpleado* this,int* horasTrabajadas)
{
    int retorno = FALSE;

    if(this!=NULL && horasTrabajadas>0)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = TRUE;
    }

    return retorno;
}

int employee_getEdad(eEmpleado* this,int* edad)
{
    int retorno = FALSE;

    if(this!=NULL && edad>0)
    {
        *edad = this->edad;
        retorno = TRUE;
    }

    return retorno;
}

int employee_getEmpleo(eEmpleado* this,char* empleo)
{
    int retorno = FALSE;
    if(this!=NULL)
    {
        strcpy(empleo,this->empleo);
        retorno = TRUE;
    }

    return retorno;
}

int employee_getSueldo(eEmpleado* this,int* sueldo)
{
    int retorno;
    if(this!=NULL && sueldo>0)
    {
        *sueldo = this->sueldo;
        retorno = TRUE;
    }

    return retorno;
}

void employee_calcularSueldo(void* auxEmployee)
{
    eEmpleado* employee;
    int auxHoras;

    if(auxEmployee!=NULL)
    {
        employee = (eEmpleado*)auxEmployee;
        employee_getHorasTrabajadas(employee,&auxHoras);

        if(auxHoras>=0)
        {
            employee_setSueldo(employee,auxHoras*300);
        }

    }
}

int employee_empleadosProgramadores (void* auxEmployee)
{
    eEmpleado* employee;
    int auxEdad;
    char auxEmpleo[50];
    int retorno = FALSE;

    if(auxEmployee!=NULL)
    {
        employee = (eEmpleado*)auxEmployee;
        employee_getEmpleo(employee,auxEmpleo);
        employee_getEdad(employee,&auxEdad);


        if(auxEdad>=20 && strcmp(auxEmpleo,"programador")==0)
        {
            retorno= TRUE;
        }
    }
    return retorno;
}
//
//int employee_empleadosPlatudos (void* auxEmployee)
//{
//    eEmpleado* employee;
//    int auxSueldo;
//    int retorno = FALSE;
//
//
//    employee = (eEmpleado*)auxEmployee;
//    auxSueldo = employee->sueldo;
//
//    if(auxSueldo>35000)
//    {
//        retorno= TRUE;
//    }
//
//    return retorno;
//}
//
//int employee_empleadosExplotados (void* auxEmployee)
//{
//    eEmpleado* employee;
//    int auxHoras;
//    int retorno = FALSE;
//
//    employee = (eEmpleado*)auxEmployee;
//    auxHoras = employee->horasTrabajadas;
//
//    if(auxHoras>=0 && auxHoras<=240)
//    {
//        if(auxHoras > 200)
//        {
//            retorno = TRUE;
//        }
//
//
//    }
//    return retorno;
//}
//
//int employee_empleadosConIdBajo (void* auxEmployee)
//{
//    eEmpleado* employee;
//    int auxId;
//    int retorno = FALSE;
//
//    employee = (eEmpleado*)auxEmployee;
//    auxId = employee->id;
//
//    if(auxId>=0 && auxId<=150)
//    {
//        retorno = TRUE;
//    }
//    return retorno;
//}


//int sortEmployeeById(void* auxEmployeeUno, void* auxEmployeeDos){
//    int retorno = FALSE;
//    if(((Employee*)auxEmployeeUno)->id > ((Employee*)auxEmployeeDos)->id)
//    {
//        retorno = TRUE;
//    }
//    return retorno;
//}
//
int sortEmployeeByName(void* auxEmployeeUno, void* auxEmployeeDos)
{
    int retorno = FALSE;
    if(strcmp(((eEmpleado*)auxEmployeeUno)->nombre, ((eEmpleado*)auxEmployeeDos)->nombre) > 0)
    {
        retorno = TRUE;
    }

    return retorno;
}
//
//int sortEmployeeByHorasTrabajadas(void* auxEmployeeUno, void* auxEmployeeDos){
//    int retorno = FALSE;
//    if(((Employee*)auxEmployeeUno)->horasTrabajadas > ((Employee*)auxEmployeeDos)->horasTrabajadas)
//    {
//        retorno = TRUE;
//    }
//    return retorno;
//}
//
//int sortEmployeeBySueldo(void* auxEmployeeUno, void* auxEmployeeDos){
//    int retorno = FALSE;
//    if(((Employee*)auxEmployeeUno)->sueldo > ((Employee*)auxEmployeeDos)->sueldo)
//    {
//        retorno = TRUE;
//    }
//    return retorno;
//}



