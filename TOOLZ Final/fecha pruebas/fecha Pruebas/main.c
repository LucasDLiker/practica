#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"




typedef struct
{
    int day;
    int month;
    int year;
} eDate;


void fooInexistente (void);
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
int isValidDate(int day, int month, int year);
int getStringNumeros(char mensaje[],char input[]);
void getString(char mensaje[],char input[]);
int esNumerico(char str[]);
int parser_DateFromText(FILE* pFile, LinkedList* pArrayListEmployee);
eDate *Fecha_new(void);
eDate* date_newParametros(char* day,char* month,char* year);

int Date_setDay(eDate* this, int day);
int Date_getday(eDate* this, int* day);

int Date_setMonth(eDate* this, int month);
int Date_getMonth(eDate* this, int* month);

int Date_setYear(eDate* this, int year);
int Date_getYear(eDate* this, int* year);

void foo_Prints_Single_Date (eDate *fecha);

int controller_loadFromText(char* path, LinkedList* pArrayList);
int controller_saveAsText(char* path, LinkedList* pArrayList);

void controller_ListsSingleEmployee(LinkedList* pArrayListEmployee, int id);
int controller_ListEmployee(LinkedList* pArrayListEmployee);

int organizaFecha (char *fecha);

int main()
{
///eDate *Fecha=(eDate*)Fecha_new();
    LinkedList *fechasDeArchivo=ll_newLinkedList();
    controller_loadFromText("fechas.csv",fechasDeArchivo);
    printf("\n\nPrint en Main\n\n");
    controller_ListEmployee(fechasDeArchivo);
///controller_saveAsText("fechas.csv",fechasDeArchivo);

    return 0;
}

///-------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param FILE* pFile Puntero al archivo con el que se trabajará
 * \param pArrayListEmployee LinkedList* pArrayListEmployee Puntero al LinkedList de empleados
 * \return int i -1 es Puntero a File Nulo  i es la cantidad de elementos parseados desde el archivo
 *
 */
int parser_DateFromText(FILE* pFile, LinkedList* pArrayList)
{
    eDate* auxDate = Fecha_new();
    int r, i = 0;
    int pruebadia, pruebames, pruebaanio;
    char auxDay[50],auxMonth[50],auxYear[50];
    char auxiliarDate[50];
    if(pFile == NULL)
    {
        return -1;
    }
    ///  r = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",auxDay,auxMonth,auxYear);  ///PASADA PARA LEER TITULOS
    while(!feof(pFile))
    {
   ///     r = fscanf(pFile,"%[^\n]\n",auxiliarDate); ///ESTA OK
        r = fscanf(pFile,"%[^/],%[^/],%[^\n]\n",auxDay, auxMonth, auxYear);
        if(r==1)
        {
           ///  printf("\n\nauxiliarDate: %s\n\n", auxiliarDate);
             printf("\n\nauxDay: %s\n\n", auxDay);
             printf("\n\nauxMonth: %s\n\n", auxMonth);

            if (!organizaFecha(auxiliarDate))
            {
              ///  printf("\n\nACAAAAAAAAAAAAAAAAAAAAAAAAAA\n\n");
///                system("pause");

///                 auxDay=atoi(&auxiliarDate[0]);
   ///             auxMonth=atoi(&auxiliarDate[3]);
      ///          auxYear=atoi(&auxiliarDate[6]);

///-------------------------------------------------------------------------------
///-------------------------------------------------------------------------------
///-------------------------------------------------------------------------------
///--------------SOLUCION A FECHA---------------------------------------------------
///-------------------------------------------------------------------------------
/// SI SE PUEDE CAMBIAR NEW PARAMETROS PARA RECIBIR ENTEROS EN LUGAR DE CHAR, SE PUEDE USAR SSCANF
///***************************************************************************************************
///***************************************************************************************************
///***************************************************************************************************
///***************************************************************************************************

///                sscanf(auxiliarDate, "%d/%d/%d", &pruebadia, &pruebames, &pruebaanio);
///                printf("\npruebadia:%d", pruebadia);
///                printf("\npruebames:%d", pruebames);
                ///printf("\npruebaanio:%d", pruebaanio);
///system("pause");

                auxDate  = date_newParametros(auxDay,auxMonth,auxYear);
                printf("\nFoo ParserDate\n");
                controller_ListEmployee(pArrayList);
                ll_add(pArrayList, auxDate);
                i++;
            }
            else
            {
                printf("La fecha leida es incorrecta");
                break;
            }
        }
        printf("\n\n%d empleados cargados en modo texto OK!\n", i);
    }
        return i;
}
///-------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------
    /** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
     *
     * \param path char*    Puntero al path donde debe buscarse el archivo
     * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
     * \return int rtn retorna 0 si es Error y 1 si es correcto
     *
     */

    int controller_loadFromText(char* path, LinkedList* pArrayList)
    {
        FILE* fp = fopen(path, "r");
        int rtn= 0;
        if(fp != NULL)
        {
            parser_DateFromText(fp, pArrayList);
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
///-------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------

    void fooInexistente (void)
    {
        int day, month, year, ValidDate;
        do
        {
            fflush(stdin);
            day=getValidInt("Ingrese el dia del estreno: ","ERROR", 1, 31);
            fflush(stdin);
            month=getValidInt("Ingrese el mes del estreno: ","ERROR", 1, 12);
            fflush(stdin);
            year=getValidInt("Ingrese el anio del estreno: ","ERROR", 1895, 2020);
            ValidDate=isValidDate(day, month, year);
        }
        while (ValidDate!=0);
        ///     peliculas[indexIs].fechaDeEstreno.day=day;
        ///     peliculas[indexIs].fechaDeEstreno.month=month;
        ///     peliculas[indexIs].fechaDeEstreno.year=year;
    }


///-------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------
    int isValidDate(int day, int month, int year)
    {
        int rtn = -1;
        if (year>=1895 && year <=2019)
        {


            if ( month >= 1 && month <= 12 )
            {
                switch (month)
                {
                case  1 :
                case  3 :
                case  5 :
                case  7 :
                case  8 :
                case 10 :
                case 12 :
                    if (day >= 1 && day <= 31)
                    {
                        rtn = 0;
                        break;
                    }
                case  4 :
                case  6 :
                case  9 :
                case 11 :
                    if ( day >= 1 && day <= 30 )
                    {
                        rtn = 0;
                        break;
                    }
                case  2 :
                    if ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) )
                    {
                        if ( day >= 1 && day <= 29 )
                        {
                            rtn = 0;
                        }
                    }
                    else if ( day >= 1 && day <= 28 )
                    {
                        rtn = 0;
                    }
                }
            }
        }
        return rtn;
    }
///----------------------------------------------------------------------
///----------------------------------------------------------------------

    int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
    {
        char auxStr[256];
        int auxInt;
        while(1)
        {
            if (!getStringNumeros(requestMessage,auxStr))
            {
                printf ("%s\n",errorMessage);
                continue;
            }
            auxInt = atoi(auxStr);
            if(auxInt < lowLimit || auxInt > hiLimit)
            {
                printf ("El numero debe ser mayor o igual a %d y menor o igual a %d\n",lowLimit,hiLimit);
                continue;
            }
            return auxInt;
        }
    }

///-------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------
    int getStringNumeros(char mensaje[],char input[])
    {
        char aux[256];
        getString(mensaje,aux);
        if(esNumerico(aux))
        {
            strcpy(input,aux);
            return 1;
        }
        return 0;
    }

///-------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------

    void getString(char mensaje[],char input[])
    {
        printf("%s",mensaje);
        scanf ("%s", input);
    }

    /**
     * \brief Solicita un texto al usuario y lo devuelve
     * \param mensaje Es el mensaje a ser mostrado
     * \param input Array donde se cargará el texto ingresado
     * \return 1 si el texto contiene solo letras
     */
///-------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------
    int esNumerico(char str[])
    {
        int i=0;
        while(str[i] != '\0')
        {
            if(str[i] < '0' || str[i] > '9')
                return 0;
            i++;
        }
        return 1;
    }

///----------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------
    eDate *Fecha_new(void)
    {
        return (eDate*)calloc(1, sizeof(eDate));
    }
///-----------------------------------------------
///-----------------------------------------------
    eDate* date_newParametros(char* day,char* month,char* year)
    {
        int auxDay,auxMonth,auxYear;
        eDate* this = Fecha_new();
        if(this != NULL)
        {
            auxDay = atoi(day);
            Date_setDay(this, auxDay);

            auxMonth= atoi(month);
            Date_setMonth(this, auxMonth);

            auxYear= atoi(year);
            Date_setYear(this, auxYear);
        }
        return this;
    }
///---------------------------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------------------------
    int Date_setDay(eDate* this, int day)
    {
        int rtn = 0;
        if (day > 0 && day <=31 && this != NULL)
        {
            this->day = day;
            rtn = 1;
        }
        return rtn;
    }

    /** \brief Gets id parameter for 1 Employee
     *
     * \param int* id  id del empleado
      * \param Employee* this linked List de empleados
      * \return rtn int valor de control 0 es Error  1 es correcto
     *
     */

    int Date_getday(eDate* this, int* day)
    {
        int rtn = 0;
        if (day != NULL && this != NULL)
        {
            *day = this->day;
            rtn = 1;
        }
        return rtn;
    }


///---------------------------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------------------------
    int Date_setMonth(eDate* this, int month)
    {
        int rtn = 0;
        if (month> 0 && month<=12 && this != NULL)
        {
            this->month= month;
            rtn = 1;
        }
        return rtn;
    }

    /** \brief Gets id parameter for 1 Employee
     *
     * \param int* id  id del empleado
      * \param Employee* this linked List de empleados
      * \return rtn int valor de control 0 es Error  1 es correcto
     *
     */

    int Date_getMonth(eDate* this, int* month)
    {
        int rtn = 0;
        if (month!= NULL && this != NULL)
        {
            *month = this->month;
            rtn = 1;
        }
        return rtn;
    }

///---------------------------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------------------------
    int Date_setYear(eDate* this, int year)
    {
        int rtn = 0;
        if (year> 0 && year<=12 && this != NULL)
        {
            this->year= year;
            rtn = 1;
        }
        return rtn;
    }
///---------------------------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------------------------

    /** \brief Gets id parameter for 1 Employee
     *
     * \param int* id  id del empleado
      * \param Employee* this linked List de empleados
      * \return rtn int valor de control 0 es Error  1 es correcto
     *
     */

    int Date_getYear(eDate* this, int* year)
    {
        int rtn = 0;
        if (year!= NULL && this != NULL)
        {
            *year = this->year;
            rtn = 1;
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
        int rtn = 1, i=-1;
        /// system("cls");
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
        eDate *pFecha;
        int day, month, year;
        ///  system("cls");   /// tags();
        pFecha = ll_get(pArrayListEmployee, id);

        Date_getday(pFecha, &day);
        Date_getMonth(pFecha, &month);
        Date_getYear(pFecha, &year);

        printf("%d/%d/%d\n",day,month,year);
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

    int controller_saveAsText(char* path, LinkedList* pArrayList)
    {
        int rtn = -1;
        int day, month, year;
        eDate* this;
        FILE* csvFile = fopen(path, "w");

        if(csvFile==NULL)
        {
            printf("Error al guardar\n");
            return rtn;
        }
        ///   fprintf(csvFile, "id,nombre,horasTrabajadas,sueldo\n"); ///IMPRIME ENCABEZADO
        if(pArrayList!=NULL)
        {
            for(int i=0; i<ll_len(pArrayList); i++)
            {
                this = (eDate*)ll_get(pArrayList, i);

                Date_getday(this, &day);
                Date_getMonth(this, &month);
                Date_getYear(this, &year);


                printf("%d/%d/%d\n", day, month, year);
                system("pause");
                fprintf(csvFile, "%d/%d/%d\n", day, month, year);
            }
            printf("\n\n\n%d Empleados guardados en modo texto OK!\n", ll_len(pArrayList));
            rtn = 1;
        }
        fclose(csvFile);
        return rtn;
    }

///------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------
    int organizaFecha (char *fecha)
    {
        int day=0, month=0, year=0, isDateOK=-1;
        printf("organizaFecha");
        day=atoi(&fecha[0]);
        month=atoi(&fecha[3]);
        year=atoi(&fecha[6]);
        isDateOK=isValidDate(day, month, year);
        return isDateOK;
    }
