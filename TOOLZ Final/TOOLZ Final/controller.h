#ifndef controller_H_INCLUDED
#define controller_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_findEmployee(LinkedList* pArrayListEmployee, int id);
void controller_ListsSingleEmployee(LinkedList* pArrayListEmployee, int id);
int generates_Next_Id_Employee (LinkedList* pArrayListEmployee);
int controller_find_Biggest_ID(LinkedList* pArrayListEmployee);
int FilteredList (void* pElement);
int reduceList(LinkedList* this);
int reduceForSalary(void* p);

int minimoHoras(LinkedList* this);
int maximoHoras(LinkedList* this);
///---------------------------------------------------------------
int parametroMaximo(void* p);
int parametroMinimo(void* p);
///---------------------------------------------------------------

int sumaEnteros(void* p);

float sumaFloat(void* p);

int sumadorDeEnteros(LinkedList* this);
int sumaEnteros(void* p);

float sumadorDeFloat(LinkedList* this);
float sumaFloat(void* p);

float promedioSueldos(LinkedList* this);
float sueldoPromedio(void* p);

int emp_reduceForSalary(void* p);

int reducedList (void* pElement);

int foo_Contador (void* pElement);
#endif

