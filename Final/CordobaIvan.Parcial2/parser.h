#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#endif // PARSER_H_INCLUDED

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*	Recibe la ruta del archivo a parsear
 * \param pArrayListPassenger LinkedList*	Recibe el puntero al linked list
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int parser_FromText(FILE* pFile , LinkedList* pArrayList);

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * \param path char*	Recibe la ruta del archivo a parsear
 * \param pArrayListPassenger LinkedList*	Recibe el puntero al linked list
 * \return int	Retorna (1)Si salio todo bien, (0)Si algo salio mal
 *
 */
int parser_FromBinary(FILE* pFile , LinkedList* pArrayList);
