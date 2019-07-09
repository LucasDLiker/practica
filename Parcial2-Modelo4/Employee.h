#ifndef Employee_H_INCLUDED
#define Employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    char empleo[128];
    int edad;
    int horasTrabajadas;
    int sueldo;
}eEmpleado;

eEmpleado* employee_new();
eEmpleado* employee_newParametros(char* idStr, char* nombreStr, char* empleoStr, char* edadStr, char* horasTrabajadasStr);
void employee_delete(eEmpleado* this);

int employee_setId(eEmpleado* this,int id);
int employee_getId(eEmpleado* this,int* id);

int employee_setNombre(eEmpleado* this,char* nombre);
int employee_getNombre(eEmpleado* this,char* nombre);

int employee_setHorasTrabajadas(eEmpleado* this,int horasTrabajadas);
int employee_getHorasTrabajadas(eEmpleado* this,int* horasTrabajadas);

int employee_setEmpleo(eEmpleado* this,char* empleo);
int employee_getEmpleo(eEmpleado* this,char* empleo);

int employee_setEdad(eEmpleado* this, int edad);
int employee_getEdad(eEmpleado* this,int* edad);

int employee_setSueldo(eEmpleado* this,int sueldo);
int employee_getSueldo(eEmpleado* this,int* sueldo);

void employee_calcularSueldo(void* auxemployee);
int employee_empleadosProgramadores (void* auxEmployee);
int employee_empleadosExplotados (void* auxemployee);
int employee_empleadosConIdBajo (void* auxemployee);

int sortEmployeeById(void* auxEmployeeUno, void* auxEmployeeDos);
int sortEmployeeByName(void* auxEmployeeUno, void* auxEmployeeDos);
int sortEmployeeByHorasTrabajadas(void* auxEmployeeUno, void* auxEmployeeDos);
int sortEmployeeBySueldo(void* auxEmployeeUno, void* auxEmployeeDos);

#endif // Employee_H_INCLUDED
