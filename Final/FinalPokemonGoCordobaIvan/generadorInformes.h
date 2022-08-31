#include "pokemon.h"

#ifndef GENERADORINFORMES_H_INCLUDED
#define GENERADORINFORMES_H_INCLUDED



#endif // GENERADORINFORMES_H_INCLUDED

/** \brief Imprime un pokemon para no repetir codigo
 *
 * \param auxPokemon ePokemon*  Recibe el elemento a imprimir
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int imprimirPokemon(ePokemon* auxPokemon);

/** \brief Imprime la lista entera de pokemones
 *
 * \param this LinkedList*  Recibe la lista
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int imprimirPokemones(LinkedList* this);

/** \brief Imprime un pokemon solo en formato de tabla
 *
 * \param auxPokemon ePokemon*  Recibe el elemento a imprimir
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int imprimirPokemonSolo(ePokemon* auxPokemon);
