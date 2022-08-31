#include "LinkedList.h"

#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED

typedef struct
{
    int numero;
    char nombre[30];
    char tipo[30];
    char tamanio[4];
    char ataqueCargado[30];
    int valorAtaque;
    int esVariocolor;
}ePokemon;

#endif // POKEMON_H_INCLUDED

/** \brief Crea un nuevo elemento pokemon
 *
 * \return ePokemon*    Retorna la referencia a ese nuevo elemento
 *
 */
ePokemon* pokemon_new();


/** \brief Crea un nuevo elemento pokemon con los parametros recibidos
 *
 * \param num int   Recibe el numero de pokemon y lo carga en el nuevo elemento
 * \param nombreStr char*   Recibe el nombre del pokemon y lo carga en el nuevo elemento
 * \param tipoStr char* Recibe el tipo de pokemon y lo carga en el nuevo elemento
 * \param tamanioStr char*  Recibe el tamanio del pokemon y lo carga en el nuevo elemento
 * \param ataqueCargadoStr char*    Recibe el ataque cargado del pokemon y lo carga en el nuevo elemento
 * \param valorAtaque int   Recibe el valor de ataque del pokemon y lo carga en el nuevo elemento
 * \param esVariocolor int  Recibe el numero de si es variocolor y lo carga en el nuevo elemento
 * \return ePokemon*    Retorna la referencia a ese nuevo elemento
 *
 */
ePokemon* pokemon_newParametros(int num,char* nombreStr, char* tipoStr, char* tamanioStr, char* ataqueCargadoStr, int valorAtaque, int esVariocolor);

/** \brief Incrementa en un 10% el ataque de determinados pokemones
 *
 * \param a void*   Recibe el elemento a modificar
 * \return void*    Retorna el elemento modificado
 *
 */
void* ataqueCargado(void* a);

/** \brief Realiza la battalla pokemon
 *
 * \param a void*   Recibe el elemento a verificar
 * \return int  Retorna 1 si el elemento coincide con los filtros especificados
 *
 */
int batallaPokemon(void* a);

/** \brief Borra el elemento pokemon
 *
 * \param this ePokemon*    Recibe el elemento a borrar
 * \return void
 *
 */
void pokemon_delete(ePokemon* this);


/** \brief Realiza el alta de un nuevo pokemon
 *
 * \param lista LinkedList* Recibe la lista con los datos
 * \param pNum int* Recibe el numero de pokemon
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int altaPokemon(LinkedList* lista, int* pNum);

/** \brief Realiza la baja de un pokemon
 *
 * \param lista LinkedList* Recibe la lista con los datos
 * \param id int    Recibe el id del elemento que debe eliminar
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int bajaPokemon(LinkedList* lista, int id);

/** \brief Realiza la modificacion de un pokemon
 *
 * \param lista LinkedList* Recibe la lista con los datos
 * \param pId int*  Recibe el id del elemento que debe modificar
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int editarPokemon(LinkedList* lista, int* pId);

/** \brief Filtra el elemento recibido para saber si es de tipo water
 *
 * \param a void*   Recibe el elemento a filtrar
 * \return int  Retorna (1)Si se filtro bien, (0)Si algo salio mal
 *
 */
int filtrarTipoWater(void* a);

/** \brief Filtra el elemento recibido para que pueda ganar la batalla
 *
 * \param a void*   Recibe el elemento a filtrar
 * \return int  Retorna (1)Si se filtro bien, (0)Si algo salio mal
 *
 */
int filtrarPokemonApto(void* a);

// SETTERS
int Pokemon_setNum(ePokemon* this,int num);
int Pokemon_setNombre(ePokemon* this,char* nombre);
int Pokemon_setTipo(ePokemon* this,char* tipo);
int Pokemon_setTamanio(ePokemon* this,char* tamanio);
int Pokemon_setAtaqueCargado(ePokemon* this,char* ataqueCargado);
int Pokemon_setValorAtaque(ePokemon* this,int valorAtaque);
int Pokemon_setEsVariocolor(ePokemon* this,int esVariocolor);

