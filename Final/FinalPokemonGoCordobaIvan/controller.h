#include "LinkedList.h"

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

/** \brief  Menu de salida
 *
 * \param this LinkedList*  Recibe puntero a linked list
 * \param confSalida char*  Recibe puntero en donde se almacena la opcion elegida
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Cordoba_Salida_controllerSalida(LinkedList* this, char* confSalida);

/** \brief Carga los datos desde un archivo
 *
 * \param this LinkedList*  Recibe puntero a la lista de datos
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Cordoba_Datos_controllerCarga(LinkedList* this);

/** \brief Filtra la lista y deja unicamente los de tipo agua
 *
 * \param this LinkedList*  Recibe puntero a la lista de datos
 * \return int      Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Cordoba_Filtros_controllerFiltroTipoAgua(LinkedList* this);

/** \brief Incrementa un 10% del ataque dependiendo del tipo de pokemon
 *
 * \param this LinkedList*  Recibe puntero a la lista de datos
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Cordoba_Ataque_mapearAtaqueCargado(LinkedList* this);

/** \brief Realiza una batalla pokemon, si hay 3 pokemones o mas que cumplen las caracteristicas, da por ganada la batalla
 *
 * \param this LinkedList*  Recibe puntero a la lista de datos
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Cordoba_Batalla_controllerBatallaPokemon(LinkedList* this);


/** \brief Realiza el guardado de datos, en binario o en modo texto
 *
 * \param this LinkedList*  Recibe puntero a la lista de datos
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int Cordoba_Datos_controllerGuardado(LinkedList* this);
