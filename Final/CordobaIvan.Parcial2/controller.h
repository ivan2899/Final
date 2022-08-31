#include "LinkedList.h"

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

/** \brief Carga los datos de un archivo
 *
 * \param this LinkedList* Recibe puntero a linked list
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int controller_carga(LinkedList* this);

/** \brief  Menu de salida
 *
 * \param this LinkedList*  Recibe puntero a linked list
 * \param confSalida char*  Recibe puntero en donde se almacena la opcion elegida
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int controller_salida(LinkedList* this, char* confSalida);

/** \brief Lista todos los elementos del linked list
 *
 * \param this LinkedList*  Recibe puntero a linked list
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int controller_listar(LinkedList* this);

/** \brief Asigna el rating aleatorio de 0.1 a 10
 *
 * \param this LinkedList*  Recibe puntero a linked list
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int controller_rating(LinkedList* this);

/** \brief Asigna el genero
 *
 * \param this LinkedList*  Recibe puntero a linked list
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int controller_genero(LinkedList* this);

/** \brief Guarda el linked list en un archivo
 *
 * \param this LinkedList*  Recibe puntero a linked list
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int controller_guardado(LinkedList* this);

/** \brief Filtra dependiendo del genero elegido
 *
 * \param this LinkedList*  Recibe puntero a linked list
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int controller_filtrar_genero(LinkedList* this);

/** \brief Ordena por genero
 *
 * \param this LinkedList*  Recibe puntero a linked list
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int controller_ordenar(LinkedList* this);
