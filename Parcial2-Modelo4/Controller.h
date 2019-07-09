#define FALSE 0
#define TRUE 1

int controller_loadEmpleados(char* path, LinkedList* pArrayListEmpleados);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_guardarTexto(char* path, LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

int controller_ListEmployeeConSueldo(LinkedList* pArrayListEmployee);




