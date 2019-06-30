#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------

int lettersOnly (char auxiliarInput[])
{
    int isalpha_result;              /// HOLDS RESULT OF ISALPHA FUNCTION
    int txt_length;               ///HOLDS LENGTH OF TEXT ARRAY
    int lettersOnly=1;     ///if=0 INVALID VALUE // IF=1 VALID VALUE

    txt_length=strlen (auxiliarInput);

    for (int i=0; i<txt_length-1; i++)
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

///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------
/** \brief validates that input char contains only numbers
 *
 * \param auxiliarInput[] char input user received from main
 * \return numbersOnlyChar int validation result
 *
 */

int numbersOnly (char auxiliarInput[])
{
    int isdigit_result;              /// HOLDS RESULT OF ISALPHA FUNCTION
    int array_length;               ///HOLDS LENGTH OF TEXT ARRAY
    int numbersOnlyChar=1;     ///if=0 INVALID VALUE // IF=1 VALID VALUE

    array_length=strlen (auxiliarInput);
    for (int i=0; i<array_length-1; i++)
    {
        isdigit_result=isdigit(auxiliarInput[i]);

        if (auxiliarInput[i]==46)
        {
            /// Condition used to prevent if(isdigit_result==0)
            /// transform numbersOnlyChar=0 because of a dot
        }

        else if (isdigit_result==0)
        {
            numbersOnlyChar=0;
            break;
        }
    }
    return numbersOnlyChar;         ///if=0 INVALID VALUE // IF=1 VALID VALUE
}

///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------
/** \brief changes case to Name Lastname
 *
 * \param auxiliarInput[] char input user received from main
 * \return VOID function
 *
 */

void changeCase (char auxiliarInput[])
{
    int length;
    length=strlen (auxiliarInput);
    auxiliarInput=strlwr(auxiliarInput);
    for (int i=0; i<length; i++)
    {
        if (auxiliarInput[i]==32)
        {
            auxiliarInput[i+1]=auxiliarInput[i+1]-32;
        }
    }
    auxiliarInput[0]=auxiliarInput[0]-32;

}

///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------

int isAlphaNumeric(char auxiliarInput [])
{
    int txt_length;                        ///HOLDS LENGTH OF TEXT ARRAY
    int lettersAndNumbersOnly=1;                    ///if=0 INVALID VALUE // IF=1 VALID VALUE
    txt_length=strlen (auxiliarInput);
    printf("txt_length: %d\n", txt_length);
    printf("auxiliarInput: %s\n",auxiliarInput);
    for (int i=0; i<txt_length-1; i++)
    {
        if ((auxiliarInput[i]>47 && auxiliarInput[i]<58)||(auxiliarInput[i]>64 && auxiliarInput[i]<91)||(auxiliarInput[i]>96 && auxiliarInput[i]<123)||auxiliarInput[i]==32)
        {
            lettersAndNumbersOnly=1;
        }
        else
        {
            lettersAndNumbersOnly=0;
            break;
        }
    }
    auxiliarInput[txt_length-1]= 00;              ///This instruction is due to the fact of fgets adding an enter char at the end of the array
    return lettersAndNumbersOnly;
}

///-----------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------
/** \brief Valida los tres enteros ingresados como fecha.
 *
 * \param day
 * \param month
 * \param year
 * \return Retorna 1 si es valida o 0 si no lo es.
 *
 */

 ///USAR FOO DE VALID DATE DE SELENE

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
