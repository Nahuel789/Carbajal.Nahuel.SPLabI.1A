#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "bicicletas.h"
#include "utn.h"
/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this=(LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->pFirstNode=NULL;
        this->size=0;

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

    if(this != NULL)
    {
        returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode=NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <ll_len(this))
    {
        pNode=this->pFirstNode;

        while(nodeIndex > 0)
        {
            pNode=pNode->pNextNode;
            nodeIndex--;
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
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *+
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNodo=NULL;
    if(this != NULL && nodeIndex >= 0 && nodeIndex <=ll_len(this))
    {
        newNodo=(Node*)malloc(sizeof(Node));

        if(newNodo != NULL)
        {
            newNodo->pElement=pElement;
            newNodo->pNextNode=NULL;
            if(nodeIndex == 0)
            {
                newNodo->pNextNode=this->pFirstNode;
                this->pFirstNode=newNodo;
            }
            else
            {
                newNodo->pNextNode=getNode(this,nodeIndex);
                (getNode(this,nodeIndex-1))->pNextNode=newNodo;
            }
            this->size=this->size + 1;
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

    if(this != NULL)
    {
        if(ll_len(this) != -1)
        {
            if(!addNode(this,ll_len(this),pElement))
            {
                returnAux=0;
            }

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
/*
Retorna un puntero al elemento que se encuentra en el índice especificado. Verificando que el puntero this sea distinto
de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación falla la función retorna (NULL)
 y si tiene éxito retorna el elemento.
 */
void* ll_get(LinkedList* this, int index)
{
    Node* pNode = NULL;
    void* pVoid=NULL;

    if(this != NULL && index >=0 && index< ll_len(this))
    {
        pNode=getNode(this,index);
        if(pNode != NULL)
        {
            pVoid=pNode->pElement;
        }
    }

    return pVoid;
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


/*

Inserta un elemento en el LinkedList, en el índice
especificado. Verificando que el puntero this sea
distinto de NULL y que index sea positivo e inferior
 al tamaño del array. Si la verificación falla la
 función retorna (-1) y si tiene éxito (0).

*/
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux =-1;
    Node* pNode=NULL;
    if(this != NULL && index >=0 && index < ll_len(this))
    {
        pNode=getNode(this,index);

        if(pNode!=NULL)
        {
            pNode->pElement=pElement;
            returnAux=0;
        }
    }
    return returnAux;
}
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


    if(this != NULL && index >= 0 && index <ll_len(this) && ll_len(this) > 0)
    {

        if(index == 0 )
        {
            pNode=getNode(this,index);
            if(pNode != NULL)
            {
                this->pFirstNode=pNode->pNextNode;
                free(pNode);
                pNode=NULL;
            }
        }
        else
        {
            pNode=getNode(this,index-1); //LLAMO AL ANTERIOR
            Node* pNodeEliminar=pNode->pNextNode; //ASIGNO EL NODO A ELIMINAR EN UN NUEVO NODO
            pNode->pNextNode=pNodeEliminar->pNextNode;//HAGO QUE APUNTE EL 1 AL 3 USANDO 2 NODOS
            free(pNodeEliminar);
            pNodeEliminar=NULL; //LIBERO
        }
        this->size--;
        returnAux=0;
    }
    return returnAux;
}
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
    if(this != NULL)
    {


        while(ll_len(this) > 0)
        {
            ll_remove(this,0);
            returnAux=0;
        }

        /*for(int i=ll_len(this)-1;i>=0;i--)
        {
                ll_remove(this,i);
                returnAux=0;
        }
        */
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

    if(this != NULL)
    {
        if(!ll_clear(this))
        {

            free(this);
            this=NULL;
            returnAux=0;
        }
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
    Node* pNode=NULL;

    if(this != NULL)
    {
        for(int i=0; i<ll_len(this); i++)
        {
            pNode=getNode(this,i);
            if(pNode != NULL && pNode->pElement == pElement)
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

    if(this != NULL)
    {
        returnAux=0;

        if(ll_len(this)==0)
        {
            returnAux=1;
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
int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this,index,pElement);
}
/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    returnAux=ll_get(this,index);
    ll_remove(this,index);
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
    int returnAux=-1;

    if(this != NULL)
    {
        returnAux=1;

        if(ll_indexOf(this,pElement) == -1)
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
    int returnAux = -1;
    if(this != NULL && this2 != NULL)
    {
        returnAux=1;

        for(int i=0; i<ll_len(this2); i++)
        {
            if(!ll_contains(this,ll_get(this2,i)))
            {
                returnAux=0;
                break;
            }
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

    if(this != NULL && from >=0 && from<=ll_len(this) && to>from && to<=ll_len(this))
    {
        cloneArray=ll_newLinkedList();

        for(; from<to; from++)
        {
            ll_add(cloneArray,ll_get(this,from));
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
    return ll_subList(this,0,ll_len(this));
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

    void* pJ=NULL;
    void* pI=NULL;

    if(this != NULL && pFunc != NULL && (order == 1 ||order == 0 ))
    {
        for(int i=0; i<ll_len(this)-1; i++)
        {
            for(int j=i+1; j<ll_len(this); j++)
            {
                pI=ll_get(this,i);
                pJ=ll_get(this,j);

                if((pFunc(pI,pJ) >0 && order == 1 )||(pFunc(pI,pJ)<0 && order == 0 ))
                {
                    ll_set(this,i,pJ);
                    ll_set(this,j,pI);
                    returnAux=0;
                }
            }
        }
    }
    return returnAux;
}
/** \brief Filtra los elementos de la lista
 *
 * \param lista a filtrar
 * \param funcion que sabe filtrar el elemento devuelve 1 si el elemento devuelto en la lista nueva o 0 si no
 * \return Retorna un nuevo linkedList cargado con los elementos que cumplen con la funcion
 *
 */

LinkedList* ll_filter(LinkedList* this,int(*pFunc)(void*))
{
    void* param=NULL;
    LinkedList* listaNew=NULL;
    if(this != NULL && pFunc != NULL )
    {
        listaNew=ll_newLinkedList();
        if(listaNew != NULL)
        {

            int tam=ll_len(this);
            for(int i=0; i<tam; i++)
            {
                param=ll_get(this,i);
                if(param != NULL)
                {
                    if(pFunc(param) == 1)
                    {
                        ll_add(listaNew,param);
                    }
                }
            }
        }
    }
    return listaNew;
}
LinkedList* ll_map(LinkedList* lista,void*(*pFunc)(void*))
{
    void* pElement=NULL;
    int tam=ll_len(lista);
    if(lista != NULL && pFunc != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            pElement=ll_get(lista,i);
            pElement=pFunc(pElement);
        }
    }
    return ll_clone(lista);
}
















