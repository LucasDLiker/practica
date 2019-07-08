#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"     ///BORRAR LUEGO
#include "employee.h" ///BORRAR LUEGO




static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if (this!=NULL)
    {
        returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o
 (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;

    if(this != NULL && nodeIndex>=0 && nodeIndex<ll_len(this))
    {
        // LinkedList auxList = *this;
        // pNode = auxList.pFirstNode;
        pNode=this->pFirstNode;
        for(int i = 0; i<nodeIndex; i++)
        {
            pNode = pNode->pNextNode;
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{

    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int i=0;
    Node* pNode= malloc(sizeof(Node));

    if((this !=NULL) && (nodeIndex>=0) && (nodeIndex<=ll_len(this)))
    {
        //Node* pNode= malloc(sizeof(Node));
        LinkedList auxList = *this;
        if(pNode != NULL)
        {
            pNode->pElement = pElement;
            if(ll_len(this)==0)
            {
                pNode->pNextNode = NULL;
                this->pFirstNode = pNode;
            }
            else  ///ll_len(this)!=0
            {
                if(nodeIndex == 0)
                {
                    pNode->pNextNode = this->pFirstNode;
                    this->pFirstNode = pNode;
                }
                else
                {
                    for(i=0; i+1<nodeIndex; i++)
                    {
                        auxList.pFirstNode = auxList.pFirstNode->pNextNode;
                    }
///COMO FUNCIONA ESTO DE LLAMAR USANDO PUNTO Y FLECHA???
                    pNode->pNextNode = auxList.pFirstNode->pNextNode;
                    auxList.pFirstNode->pNextNode = pNode;
                }
            }
            this->size++;
            returnAux=0;
        }
    }
    return returnAux;

}



/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if (this!=NULL)
    {
        if(addNode(this, ll_len(this), pElement) != -1)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int nodeIndex)
{
    void* returnAux = NULL;
    Node *pNode=malloc(sizeof(Node));
    if((this !=NULL) && (nodeIndex>=0) && (nodeIndex<=ll_len(this)))
    {
        pNode=getNode(this, nodeIndex);
        if(pNode!=NULL)
        {
            returnAux = pNode->pElement;
        }
    }
    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node *pNode=malloc(sizeof(Node));
    if((this !=NULL) && (nodeIndex>=0) && (nodeIndex<=ll_len(this)))
    {
        pNode=getNode(this, nodeIndex);
        if(pNode!=NULL)
        {
            pNode->pElement=pElement;
            returnAux=0;
        }
    }
    return returnAux;
}

///------------------------------------------------------------------------------------
/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode=NULL;
    Node* pNodeAux=NULL;

    if(this!=NULL && index>=0 && index<(this->size))
    {
        if(index == 0)
        {
            pNode = getNode(this, index);
            this->pFirstNode = pNode->pNextNode;
            free(pNode);
        }
        else if(index == (ll_len(this)))
        {
            free(pNode);
        }
        else
        {
            pNodeAux = getNode(this,(index-1));
            pNode = getNode(this,index);
            pNodeAux->pNextNode = pNode->pNextNode;
            free(pNode);

        }
        this->size--;
        returnAux=0;
    }
    return returnAux;
}

///------------------------------------------------------------------------------------
/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */

int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        for(int i= ll_len(this); i>=0; i--)
        {
            ll_remove(this, i);
        }
        returnAux=0;
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node *pNode=malloc(sizeof (Node));

    if (this!=NULL)
    {
        for (int i=0; i<ll_len(this); i++)
        {
            pNode=getNode(this, i);
            if (pNode->pElement==pElement)
            {
                returnAux=i;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if (this!=NULL)
    {
        if (this->size>0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;

    if((this!=NULL) && (nodeIndex>=0) && (nodeIndex<=ll_len(this)))
    {
        if(addNode(this, nodeIndex, pElement) ==0 )
        {
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int nodeIndex)
{
    Node *pNode=malloc(sizeof(Node));
    void* returnAux = NULL;

    if((this!=NULL) && (nodeIndex>=0) && (nodeIndex<=ll_len(this)))
    {
        pNode=ll_get(this, nodeIndex);            //  printf("\npNode:%p\n", pNode);
        if (pNode!=NULL && ll_remove(this, nodeIndex)==0)
        {
            returnAux=pNode;                  //  printf("\npNode:%p\n", pNode);
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/



int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1, flag=0;
    Node *pNode;

    if (this!=NULL)
    {
        for (int i=0; i<ll_len(this); i++)
        {
            pNode=getNode(this, i);
            if (pNode->pElement==pElement)
            {
                returnAux=1;
                flag=1;
                break;
            }
        }
        if (flag==0)
        {
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1, flagContains=0;

    Node *nodeThis2=malloc(sizeof(Node));

    if (this!=NULL && this2!=NULL)
    {
        for (int i=0; i<ll_len(this2); i++)
        {
            nodeThis2=ll_get(this2,i);
            if ((ll_contains(this, nodeThis2))==1)
            {
                flagContains++;
            }
        }
        if (flagContains== ll_len(this2))
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }

    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElemAux;

    if(this!=NULL)
    {
        if((from>=0) && (from<ll_len(this)) && (to>from) && (to<=ll_len(this)))
        {
            cloneArray = ll_newLinkedList();
            for(int i = from; i < to ; i++)
            {
                pElemAux = ll_get(this, i);
                ll_add(cloneArray, pElemAux);
            }
        }
    }
    return cloneArray;
}


/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this!=NULL)
    {
        cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void* pElemAux;

    if(this!=NULL && pFunc!=NULL && (order == 0 || order == 1) )
    {
        for(int i=0; i<((ll_len(this))-1); i++)
        {
            for(int j=i+1; j<(ll_len(this)); j++)
            {
                if(order == 0 && pFunc(ll_get(this, i), ll_get(this, j))<0)
                {
                    pElemAux = ll_get(this,i);
                    ll_set(this, i, ll_get(this,j));
                    ll_set(this, j, pElemAux);
                }
                else if(order == 1 && pFunc(ll_get(this, i), ll_get(this, j))>0)
                {
                    pElemAux = ll_get(this,i);
                    ll_set(this, i, ll_get(this,j));
                    ll_set(this, j, pElemAux);
                }
            }
        }
        returnAux=0;
    }
    return returnAux;
}

///----------------------------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------------------------
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* listFilter=NULL;
    void* pBufferElement=NULL;
    if((this!=NULL)&&(pFunc!=NULL))
    {
        listFilter=ll_newLinkedList();
        if(listFilter!=NULL)
        {
            for(int i=0; i<ll_len(this); i++)
            {
                pBufferElement=ll_get(this, i);
                if(!pFunc(pBufferElement))
                {
                    ll_add(listFilter, pBufferElement);
                }
            }
        }
    }
    ///controller_ListEmployee(listFilter);    ///ESTO SE PUEDE QUITAR
    return listFilter;
}

///--------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------

int ll_reduce(LinkedList* this, int (*pFunc)(void*))
{
    int ret=-1;
    int contador=0;
    void* pBufferElement=NULL;
    if((this!=NULL)&&(pFunc!=NULL))
    {
        for(int i=0; i<ll_len(this); i++)
        {
            pBufferElement=ll_get(this, i);
            if(!pFunc(pBufferElement))
            {
                if(!ll_remove(this,i))
                {
                   i--;
                   contador++;
                }
            }
        }//FOR
        printf("Elementos eliminados %d\n", contador);
        ret=0;
    }
    return ret;
}

///------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------

/** \brief
 *
 * \param
 * \param
 * \return -1 si no pudo modificar la lista, 0 si pudo modificar y 1 si hubo al menos uno que no pudo modificar;
 *
 */

int ll_counter(LinkedList* this, int (*pFunc)(void*))
{
///     int ret=-1;
     void* pBufferElement=NULL;
     int contadorDeElementos=0;

     if((this!=NULL)&&(pFunc!=NULL))
     {
          for(int i=0; i<ll_len(this); i++)
          {
              pBufferElement=ll_get(this,i);
              if(!pFunc(pBufferElement))
              {
                  contadorDeElementos++;
   ///               ret=0;
              }
              else  ///Si hubo al menos uno q no pudo modificar
              {
      ///            ret=1;
              }
          }//FOR
     }
     return contadorDeElementos;
}

///--------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------

int ll_sumador(LinkedList* this, int (*pFunc)(void*))
{
    int sumador=0;
    int contador=0;
    void* pBufferElement=NULL;

    if((this!=NULL)&&(pFunc!=NULL))
    {
        for(int i=0; i<ll_len(this); i++)
        {
            pBufferElement=ll_get(this,i);
            contador=pFunc(pBufferElement);
            sumador=sumador+contador;
        }//FOR
    }
    return sumador;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
float ll_sumadorFloat(LinkedList* this,float (*pFunc)(void*))//NO ANDA
{
    float sumador=0;
    float sumaParcial=0;
    void* pBufferElement=NULL;

    if((this!=NULL)&&(pFunc!=NULL))
    {
        for(int i=0; i<ll_len(this); i++)
        {
            pBufferElement=ll_get(this,i);
            sumaParcial=pFunc(pBufferElement);
            sumador=sumador+sumaParcial;
            ///printf("\n\nsuma %.2f\t", sumador);
            ///printf("\tsumaParcial %.2f\n", sumaParcial);
        }
    }
    ///printf("\n\nsumador al salir %.2f\n", sumador);
    return sumador;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
int ll_maximo(LinkedList* this, int (*pFunc)(void*))
{
    int bufferCantidad;
    int cantidadMaxima=0;
    void* pBufferElement=NULL;

    if((this!=NULL)&&(pFunc!=NULL))
    {
        for(int i=0; i<ll_len(this); i++)
        {
            pBufferElement=ll_get(this,i);
            bufferCantidad=pFunc(pBufferElement);
            if(cantidadMaxima<bufferCantidad)
            {
                cantidadMaxima=bufferCantidad;
            }
        }//FOR
    }
    return cantidadMaxima;
}

///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
int ll_minimo(LinkedList* this, int (*pFunc)(void*))
{
    int bufferCantidad;
    int cantMinima;
    void* pBufferElement=NULL;

    if((this!=NULL)&&(pFunc!=NULL))
    {
        for(int i=0; i<ll_len(this); i++)
        {
            pBufferElement=ll_get(this,i);
            bufferCantidad=pFunc(pBufferElement);
            if(cantMinima>bufferCantidad)
            {
                cantMinima=bufferCantidad;
            }
        }//FOR
    }
    return cantMinima;
}
///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------
int ll_Name_Compare (LinkedList *this, int (*pFunc)(void*))
{
    int rtn=-1, i;
    void *pBufferElement=NULL;
    int contadorDeElementos=0;
    int FlagError=0;

    if ((this!=NULL)&& (pFunc!=NULL))
    {
        ///printf("\n\nID      Nombre     Hs Trabajadas    Sueldo\n\n");
        for (i=0; i<ll_len(this); i++)
        {
            ///printf("\ni: %d", i);
            pBufferElement=ll_get(this, i);
            if (!pFunc(pBufferElement))
            {
                 contadorDeElementos++;
                 printf("\n\n\n");
                 tags();
                 controller_ListsSingleEmployee(this, i);
                continue;
                rtn=0;
            }
            if (pFunc(pBufferElement)==-1)      ///SI LA FOO FALLA
            {
              ///  printf("\nNo se pudo modificar el elemento nro %d\n", contadorDeElementos);
                FlagError=1;
                continue;
            }
        }///CLOSES FOR
        if (FlagError==1)
        {
            rtn=1;
        }
    }
    printf("\n\nse encontraron %d coincidencia/s\n", contadorDeElementos);
    ///printf("NOMBRES rtn;%d", rtn);
    return rtn;
}


///-------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------

/*
int ll_map(LinkedList* this, int (*pFunc)(void*))
{

     int ret=0;
     void* pBufferElement=NULL;
     int contadorDeElementos=0;

     if((this!=NULL)&&(pFunc!=NULL))
     {
          for(int i=0; i<ll_len(this); i++)
          {
              pBufferElement=ll_get(this,i);
              contadorDeElementos++;
              if(!pFunc(pBufferElement))
              {
                  continue;
                  ret=1;
              }
              if(pFunc(pBufferElement)==-1)//SI LA FUNCION FALLA
              {
                printf("No se pudo modifical el elemento n%d \n", contadorDeElementos);
                continue;
              }
          }//FOR
     }
     return ret;
}
*/
