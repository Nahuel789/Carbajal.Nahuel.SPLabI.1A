#include "LinkedList.h"

#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED

typedef struct
{
    int id_bike;
    char nombre[50];
    char tipo[50];
    int tiempo;
}eBicicleta;

#endif // BICICLETAS_H_INCLUDED

/** \brief Parsea los datos de un archivo a una lista
 *
 * \param lista donde guardara los datos
 * \return 0 si esta ok ,-1 si hay un error
 *
 */

int parser_BikeFromText(LinkedList* pList);

/** \brief Crea una nueva bicicleta con parametros
 *
 * \param id como string
 * \param nombre como string
* \param tipo como string
 * \param  tiempo como string
 * \return retorna una bicicleta
 *
 */

eBicicleta* bike_newParametros(char* idStr,char* nombreStr,char* tipoStr,char* tiempoStr);
/** \brief Crea una bicicleta sin parametros
 *
 * \param
 * \param
 * \return una bicicleta
 *
 */

eBicicleta* bike_new();
/** \brief Elimina una bicicleta
 *
 * \param bicicleta a eliminar
 *
 */

void bike_delete(eBicicleta* this);
/** \brief Setea el tiempo en una bici
 *
 * \param this una bicicleta
 * \param int tiempo
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */

int bike_setTiempo(eBicicleta*this,int tiempo);
/** \brief Setea el Tipo en una bici
 *
 * \param this una bicicleta
 * \param char* tipo nuevo tipo
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */
int bike_setTipo(eBicicleta* this,char* tipo);
/** \brief Setea el nombre en una bici
 *
 * \param this una bicicleta
 * \param char* nombre
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */
int bike_setNombre(eBicicleta* this,char* nombre);
/** \brief Setea el id en una bici
 *
 * \param this una bicicleta
 * \param int id
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */
int bike_setId(eBicicleta* this,int id);
/** \brief Obtiene el tiempo en una bici
 *
 * \param this una bicicleta
 * \param int*  puntero donde guardara el tiempo
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */
int bike_getTiempo(eBicicleta* unaBicicleta,int* tiempo);
/** \brief Obtiene el tipo en una bici
 *
 * \param this una bicicleta
 * \param char* tipo puntero donde guardara el tipo
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */
int bike_getTipo(eBicicleta* unaBicicleta,char* tipo);
/** \brief Obtiene el nombre en una bici
 *
 * \param this una bicicleta
 * \param char* nombre puntero donde guardara el tiempo
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */
int bike_getNombre(eBicicleta* unaBicicleta,char* nombre);
/** \brief Obtiene el id en una bici
 *
 * \param this una bicicleta
 * \param int*  id puntero donde guardara el tiempo
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */
int bike_getId(eBicicleta* unaBicicleta,int* id);

/** \brief Muestra todas las bicicletas de una lista
 *
 * \param this puntero lista
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */

int bike_list(LinkedList* this);
/** \brief Genera un nummero random
 *
 * \param void* a donde guardara el random
 * \return el puntero modificado
 *
 */

void* datosRandom(void* a);
/** \brief Guarda el archivo como texto
 *
 * \param path nombre del archivo a guardar
 * \param lista de donde conseguira los datos
 * \return 0 si esta todo ok,-1 si hay un error
 *
 */
int saveAsText(char* path, LinkedList* lista);
/** \brief Filtra por tipo BMX
 *
 * \param a puntero void a filtrar
 * \return 1 si esta todo ok,  0 si hay error
 *
 */

int filterTipoBMX(void* a);
/** \brief Filtra por tipo MTB
 *
 * \param a puntero void a filtrar
 * \return 1 si esta todo ok,  0 si hay error
 *
 */
int filterTipoMTB(void* a);
/** \brief Filtra por tipo PLAYERA
 *
 * \param a puntero void a filtrar
 * \return 1 si esta todo ok,  0 si hay error
 *
 */
int filterTipoPlAYERA(void* a);
/** \brief Filtra por tipo paseo
 *
 * \param a puntero void a filtrar
 * \return 1 si esta todo ok,  0 si hay error
 *
 */
int filterTipoPASEO(void* a);
/** \brief Compara dos punteros
 *
 * \param a primer puntero a comparar
 * \param b segundo puntero a comparar
 * \return 1 si el primero es mayor al segundo ,-1 si el 2do es mayor al primero
  en el caso que sean iguales retorna 0 y compara por tiempo,
   si el primer tiempo es mayor que el 2do retorna 1
 *
 */
int sortByTipoyTiempo(void* a,void* b);
