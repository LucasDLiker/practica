#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
    1. Cargar los datos de lxs empleadxs desde el archivo data.csv (modo texto).
    2. Cargar los datos de lxs empleadxs desde el archivo data.bin (modo binario).
    3. Alta de empleadx
    4. Modificar datos de empleado
    5. Baja de empleadx
    6. Listar empleadxs
    7. Ordenar empleadxs
    8. Guardar los datos de lxs empleadxs en el archivo data.csv (modo texto).
    9. Guardar los datos de lxs empleadxs en el archivo data.bin (modo binario).
    10. Filtrar empleadxs y guardar lista filtrada (modo texto)
    11. Mapear empleadxs y guardar sueldo
    12. Salir
*****************************************************/


int main()
{
    char seguir = 'y';
    int flagFile = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    char archivoTxt[20] = "data.csv";
    char archivoBin[20] = "data.bin";

    do{
        switch(controller_menu())
        {
            case 1:
                //printf("Que archivo desea cargar? Ingrese el nombre junto con '.csv': ");
                //gets(archivoTxt);
                if(controller_loadFromText(archivoTxt, listaEmpleados) == 1){
                    flagFile = 1;                                               //bandera para realizar resto
                }
                break;
            case 2:
                //printf("Que archivo desea cargar? Ingrese el nombre junto con '.bin': ");
                //gets(archivoBin);
                if(controller_loadFromBinary(archivoBin, listaEmpleados) == 1){
                    flagFile = 1;                                                   //bandera para realizar resto
                }
                break;
            case 3:
                if(controller_addEmployee(listaEmpleados) == 0){
                    flagFile = 1;                                               //bandera para realizar resto
                }
                break;
            case 4:
                if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_editEmployee(listaEmpleados);
                }
                break;
            case 5:
                 if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_removeEmployee(listaEmpleados);
                }
                break;
            case 6:
                if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_ListEmployee(listaEmpleados);
                }
                break;
            case 7:
                 if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_sortEmployee(listaEmpleados);
                }
                break;
            case 8:
                 if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_saveAsText("data.csv",listaEmpleados);
                }
                break;
            case 9:
                 if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_saveAsBinary("data.bin",listaEmpleados);
                }
                break;
            case 10:
                if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_filterEmployee(listaEmpleados);
                }
                break;
            case 11:
                if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_mapEmployee(listaEmpleados);
                }
                break;
            case 12:
                seguir = 'n';
                printf("\nSaliendo... \n");
                break;
            default:
                printf("Opcion invalida, reintente. \n");
                break;
        }
      system("pause");
    }while(seguir != 'n');
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
