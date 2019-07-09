/*---------------------ENTEROS----------------*/

int getInt(char* mensaje);
int esNumerico(char* str);
int getStringNumeros(char* mensaje,char* input);
int getValidInt(char* requestMessage,char* errorMessage, int lowLimit, int hiLimit);

/*-----------------------FLOTANTES--------------------*/

float getFloat(char* mensaje);
int esNumericoFlotante(char* str);
int getStringNumerosFlotantes(char* mensaje,char* input);
int getValidFloat(char* requestMessage,char* errorMessage, int lowLimit, int hiLimit);

/*----------------------STRING-----------------------*/

char getChar(char* mensaje);
void getString(char* mensaje ,char* input);
int esSoloLetras(char* str);
int esAlfaNumerico(char* str);
int getStringLetras(char* mensaje,char* input);
void getValidString(char* requestMessage,char* errorMessage, char* input);
void validarMayusculas (char* buffer, char* nombre);
