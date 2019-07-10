#ifndef ePelicula_H_INCLUDED
#define ePelicula_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int anio;
    char genero[128];
} ePelicula;

/** \brief crea un nuevo dominio con parametros vacios
 *
 * \return ePelicula* retorna el puntero al dominio
 *
 */
ePelicula* ePelicula_new();
/** \brief crea un nuevo dominio con parametros
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param anioStr char*
 * \return ePelicula* retorna el puntero al dominio
 *
 */
ePelicula* ePelicula_newParametros(char* idStr,char* nombreStr,char* anioStr);
/** \brief guarda el id en la estructura
 *
 * \param this ePelicula*
 * \param id int
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int ePelicula_setId(ePelicula* this,int id);
/** \brief obtiene el id de la estructura
 *
 * \param this ePelicula*
 * \param id int*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int ePelicula_getId(ePelicula* this,int* id);

/** \brief guarda el dominio en la estructura
 *
 * \param this ePelicula*
 * \param nombre char*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int ePelicula_setNombre(ePelicula* this,char* nombre);
/** \brief obtiene el dominio de la estructura
 *
 * \param this ePelicula*
 * \param nombre char*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int ePelicula_getNombre(ePelicula* this,char* nombre);

/** \brief guarda el tipo en la estructura
 *
 * \param this ePelicula*
 * \param  int
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int ePelicula_setGenero(ePelicula* this,char* genero);
/** \brief obtiene el genero de la estructura
 *
 * \param this ePelicula*
 * \param  int*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int ePelicula_getGenero(ePelicula* this,char* genero);

/** \brief guarda el anio en la estructura
 *
 * \param this ePelicula*
 * \param sueldo int
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int ePelicula_setAnio(ePelicula* this,int anio);
/** \brief obtiene el anio de la estructura
 *
 * \param this ePelicula*
 * \param sueldo int*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int ePelicula_getAnio(ePelicula* this,int* anio);
/** \brief mapea los elementos recibidos como parametros
 *
 * \param persona void*
 * \return int 1 si todo ok -1 si hubo error
 *
 */
/*int eDominio_mapearTipo(void* pElement);*/

/** \brief funcion criterio para con la condicion para filtrar
 *
 * \param persona void*
 * \return int 1 si todo ok -1 si hubo error
 *
 */
/*int eDominio_filtrarMoto(void* pElement);*/

/** \brief funcion criterio para con la condicion para filtrar
 *
 * \param persona void*
 * \return int 1 si todo ok -1 si hubo error
 *
 */
//int eDominio_filtrarAuto(void* pElement);

#endif // eDominio_H_INCLUDED
