#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>


///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
float getFloat(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
/**
 * \brief Genera un n�mero aleatorio
 * \param desde N�mero aleatorio m�nimo
 * \param hasta N�mero aleatorio m�ximo
 * \param iniciar Indica si se trata del primer n�mero solicitado 1 indica que si
 * \return retorna el n�mero aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
/**
 * \brief Verifica si el valor recibido es num�rico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
/**
 * \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */

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
///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
/**
 * \brief Verifica si el valor recibido contiene solo letras y n�meros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y n�meros, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
/**
 * \brief Verifica si el valor recibido contiene solo n�meros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}
///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}
///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
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

///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El n�mero ingresado por el usuario
 *
 */
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

///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El flotante ingresado por el usuario
 *
 */

float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    float auxFloat;
    while(1)
    {
        if (!getStringNumerosFlotantes(requestMessage, auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxFloat = atof(auxStr);
        if(auxFloat < lowLimit || auxFloat > hiLimit)
        {
            printf ("El numero debe ser mayor o igual a %d y menor o igual a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxFloat;

    }


}
///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */

void cleanStdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargar� el texto ingresado
 * \return -
 *
 */

void getValidString(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }

}

///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------

/** \brief Quita el salto de linea que toma la funcion fgets
 *
 * \param char *cadena
 * \return sin return
 *
 */

void removeLineFeed(char *text)
{
    if (text[strlen(text)-1]=='\n')
    {
        text[strlen(text)-1]='\0';
    }
}

///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------

float numbersOnlyFloat (char auxiliarInput[])
{
    int isdigit_result;              /// HOLDS RESULT OF ISDIGIT FUNCTION
    int array_length;               ///HOLDS LENGTH OF TEXT ARRAY
    int numbersOnlyChar=1;     ///if=0 INVALID VALUE // IF=1 VALID VALUE
    int i=0;

    array_length=strlen (auxiliarInput);
    for ( i=0; i<array_length-1; i++)
    {
        printf("\nvalor: %c", auxiliarInput[i] );

        isdigit_result=isdigit(auxiliarInput[i]);
        if (isdigit_result==0)
        {
            if (auxiliarInput[i]=='.')
            {printf("engancho punto");
                numbersOnlyChar=0;
                break;
            }
        printf("es numero");
        }
    }
    return numbersOnlyChar;         ///if=0 INVALID VALUE // IF=1 VALID VALUE
}

///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
/** \brief validates that input char contains only letters
 *
 * \param auxiliarInput[] char input user received from main
 * \return lettersOnly int validation result
 *
 */

int lettersOnly (char auxiliarInput[])
{
    int  i=0;
    int isalpha_result;              /// HOLDS RESULT OF ISALPHA FUNCTION
    int txt_length;               ///HOLDS LENGTH OF TEXT ARRAY
    int lettersOnly=1;     ///if=0 INVALID VALUE // IF=1 VALID VALUE

    txt_length=strlen (auxiliarInput);

    for (i=0; i<txt_length-1; i++)
    {
        isalpha_result=isalpha(auxiliarInput[i]);

        if (auxiliarInput[i]==32)
        {
            /// Condition used to prevent if(isalpha_result==0)
            /// to transform lettersOnly=0 because of an empty space
        }
        else if (isalpha_result==0)
        {
            lettersOnly=0;
            break;
        }
        auxiliarInput[txt_length-1]= 00;              ///This instruction is due to the fact of fgets adding an enter char at the end of the array
    }
    return lettersOnly;
}
///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
/** \brief changes case to Name Lastname
 *
 * \param auxiliarInput[] char input user received from main
 * \return VOID function
 *
 */

void changeCase (char auxiliarInput[])
{
    int  i=0;
    int length;
    length=strlen (auxiliarInput);
    auxiliarInput=strlwr(auxiliarInput);
    for (i=0; i<length; i++)
       {
           if (auxiliarInput[i]==32)
           {
               auxiliarInput[i+1]=auxiliarInput[i+1]-32;
           }
       }
       auxiliarInput[0]=auxiliarInput[0]-32;
 }
///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------
void tags (void)
{
    printf(" ID        Nombre      Hs Trabajadas       Salario\n");
}

///--------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------

void mainMenu (void)
{
 system("cls");
        printf("\t\t\t\tMENU PRINCIPAL\tJulian Avramides 1C 2019\n\n\n");

        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
        printf("S. Salir\n\n");
        printf("Que es lo que desea hacer? ");
}

