#include "movies.h"

#ifndef MIBIBLIOTECA_H_INCLUDED
#define MIBIBLIOTECA_H_INCLUDED


#endif // MIBIBLIOTECA_H_INCLUDED

/** \brief Menu de confirmacion de salida
 *
 * \param eleccion char*	Recibe un puntero a donde se guarde la opcion elegida
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int confirmaSalida(char* eleccion);

/** \brief Menu para elegir la opcion de abm o guardar o cargar
 *
 * \return int	Retorna la opcion
 *
 */
int opcion();

/** \brief Le pide la ruta al usuario
 *
 * \param pPath char*	Recibe el puntero de un vector a donde se va a guardar la ruta
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int pedirPath(char* pPath);

/** \brief Valida que el vector no se desborde
 *
 * \param tam int	Recibe el tamaño del vector
 * \param auxCad[100] char	Recibe el tamaño del texto de 100 caracteres como maximo
 * \return int	Retorna (1)Si salio todo bien, (0)Si se desbordo
 *
 */
int validarGets(int tam, char auxCad[100]);

/** \brief Menu de confirmacion de salida
 *
 * \param cadena char*	Recibe un texto que le muestre al usuario que tiene que elegir
 * \param cadena char*	Recibe un puntero a donde se guarde la opcion elegida
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int confirma(char* cadena, char* letra);

/** \brief Pide y valida un Int con parametros recibidos
 *
 * \param resultado int* puntero a donde se va a guardar el resultado
 * \param mensaje[50] char	Mensaje que le pida al usuario el numero
 * \param mensajeError[50] char	Mesaje de error, si el usuario ingreso mal el numero
 * \param minimo int	Numero minimo a validar
 * \param maximo int	Numero maximo a validar
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int pedirYValidarInt(int* resultado, char mensaje[50], char mensajeError[50], int minimo, int maximo);

/** \brief Pide y valida un Float con parametros recibidos
 *
 * \param resultado float* puntero a donde se va a guardar el resultado
 * \param mensaje[50] char	Mensaje que le pida al usuario el numero
 * \param mensajeError[50] char	Mesaje de error, si el usuario ingreso mal el numero
 * \param minimo float	Numero minimo a validar
 * \param maximo float	Numero maximo a validar
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int pedirYValidarFloat(float* resultado, char mensaje[50], char mensajeError[50], float minimo, float maximo);

/** \brief Pide y valida un Char con parametros recibidos
 *
 * \param resultado char*	puntero a donde se va a guardar la letra
 * \param mensaje[50] char	Mensaje que le pida al usuario el caracter
 * \param mensajeError[50] char	Mesaje de error, si el usuario ingreso mal el caracter
 * \param minimo char	caracter minimo a validar
 * \param maximo char	caracter maximo a validar
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int pedirYValidarChar(char* resultado, char mensaje[50], char mensajeError[50], char minimo, char maximo);

/** \brief Pide y valida un string con parametros recibidos
 *
 * \param maximo int	valor del maximo texto que puede recibir
 * \param cadena char*	puntero a donde se va a guardar el texto
 * \param mensaje[50] char	Mensaje que le pida al usuario el texto
 * \param mensajeError[50] char	Mesaje de error, si el usuario ingreso mal el texto
 * \param minimo char	largo de texto minimo a validar
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int pedirYValidarString(int maximo, char* cadena,  char mensaje[50], char mensajeError[50], int minimo);

/** \brief Muestra una pelicula
 *
 * \param auxMovie eMovie* recibe el elemento
 * \return int  Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int mostrarPelicula(eMovie* auxMovie);

/** \brief Asigna un ratin de 0.1 a 10
 *
 * \param a void*   recibe el elemento
 * \return void*    Devuelve el puntero al elemento, modificado
 *
 */
void* asignarRating(void* a);

/** \brief Asigna un genero, con un numero random de 0 a 4
 *
 * \param a void*   recibe el elemento
 * \return void*    Devuelve el puntero al elemento, modificado
 *
 */
void* asignarGenero(void* a);

/** \brief Filtra el genero Drama
 *
 * \param a void*   Puntero al elemento
 * \return int  Devuelve 1 si es de genero "Drama", 0 si no es de ese genero
 *
 */
int filtrarGeneroDrama(void* a);

/** \brief Filtra el genero comedia
 *
 * \param a void*   Puntero al elemento
 * \return int  Devuelve 1 si es de genero "Comedia", 0 si no es de ese genero
 *
 */
int filtrarGeneroComedia(void* a);

/** \brief Filtra el genero Accion
 *
 * \param a void*   Puntero al elemento
 * \return int  Devuelve 1 si es de genero "Accion", 0 si no es de ese genero
 *
 */
int filtrarGeneroAccion(void* a);

/** \brief Filtra el genero Terror
 *
 * \param a void*   Puntero al elemento
 * \return int  Devuelve 1 si es de genero "Terror", 0 si no es de ese genero
 *
 */
int filtrarGeneroTerror(void* a);

/** \brief Ordena por genero entre dos elementos
 *
 * \param type1 void*   Recibe un elemento
 * \param type2 void*   Recibe el otro elemento
 * \return int
 *
 */
int ordenarGenero(void* type1, void* type2);


/** \brief  Ordena por rating entre dos elementos
 *
 * \param type1 void*   Recibe un elemento
 * \param type2 void*   Recibe el otro elemento
 * \return int
 *
 */
int ordenarRating(void* type1, void* type2);
