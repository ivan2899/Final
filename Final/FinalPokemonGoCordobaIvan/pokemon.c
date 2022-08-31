#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "pokemon.h"
#include "miBiblioteca.h"
#include "generadorInformes.h"

ePokemon* pokemon_new()
{
    ePokemon* newPokemon = (ePokemon*) calloc(1, sizeof(ePokemon));
    return newPokemon;
}

int bajaPokemon(LinkedList* lista, int id)
{
    int todoOk = 0;
    int auxId;
    int indice;
    char conf;
    ePokemon* auxPokemon;


    if(lista != NULL && id > 0)
    {
        imprimirPokemones(lista);
        pedirYValidarInt(&auxId, "Ingrese el numero de un pokemon: ", "Error, reingrese el numero de un pokemon valido: ", 1, id);

        if((ll_buscarId(lista, auxId, &indice)))
        {
            auxPokemon = (ePokemon*) ll_get(lista, indice);
            printf("Ingres%c el id %d: \n", 162, auxId);
            imprimirPokemonSolo(auxPokemon);

            confirma("Esta seguro que desea eliminarlo?", &conf);

            if(conf == 's')
            {
                ll_remove(lista, indice);
                printf("Se elimin%c el pokem%cn correctamente",162,162);
                todoOk = 1;
            }
            else
            {
                printf("Se cancel%c la baja del pokemon", 162);
            }
        }
        else
        {
            printf("No se encontr%c el id ingresado", 162);
        }
    }
    return todoOk;
}

void* ataqueCargado(void* a)
{
    float resultado;
    ePokemon* auxPokemon = NULL;

    if(a != NULL)
    {
        auxPokemon = (ePokemon*) a;
        if(( stricmp(auxPokemon->tipo, "Fire") == 0) || ( stricmp(auxPokemon->tipo, "Ground") == 0 ) || ( stricmp(auxPokemon->tipo, "Grass") == 0))
        {
            resultado = auxPokemon->valorAtaque;
            resultado *= 1.1;

            auxPokemon->valorAtaque = resultado;
        }
    }
    return a;
}

int batallaPokemon(void* a)
{
    int cumpleCaracteristicas = 0;
    ePokemon* auxPokemon = NULL;

    if(a != NULL)
    {
        auxPokemon = (ePokemon*) a;
        if( ( (stricmp(auxPokemon->tipo, "Fire") == 0) && (stricmp(auxPokemon->tamanio, "XL") == 0) && (stricmp(auxPokemon->ataqueCargado, "Lanzallamas") == 0) && (auxPokemon->valorAtaque > 80) )  ||
                ( (stricmp(auxPokemon->tipo, "Water") == 0) && (stricmp(auxPokemon->tamanio, "L") == 0) && (stricmp(auxPokemon->ataqueCargado, "Hidrobomba") == 0) && (auxPokemon->valorAtaque > 80)) )
        {
            cumpleCaracteristicas = 1;
        }
    }
    return cumpleCaracteristicas;
}

int Pokemon_setNum(ePokemon* this,int num)
{
    int todoOk = 0;
    if(this != NULL && num >= 1)
    {
        this->numero = num;
        todoOk = 1;
    }
    return todoOk;
}

int Pokemon_setNombre(ePokemon* this,char* nombre)
{
    int todoOk = 0;
    if(this != NULL && nombre != NULL && strlen(nombre) <= 30 && strlen(nombre) >= 2)
    {
        strcpy(this->nombre, nombre);
        strlwr(this->nombre);
        (this->nombre)[0] = toupper((this->nombre)[0]);

        todoOk = 1;
    }
    return todoOk;
}

int Pokemon_setTipo(ePokemon* this,char* tipo)
{
    int todoOk = 0;
    if(this != NULL && tipo != NULL && strlen(tipo) <= 30 && strlen(tipo) >= 2)
    {
        strcpy(this->tipo, tipo);
        strlwr(this->tipo);
        (this->tipo)[0] = toupper((this->tipo)[0]);

        todoOk = 1;
    }
    return todoOk;
}

int Pokemon_setTamanio(ePokemon* this,char* tamanio)
{
    int todoOk = 0;
    if(this != NULL && tamanio != NULL && strlen(tamanio) <= 4 && strlen(tamanio) >= 1)
    {
        strcpy(this->tamanio, tamanio);
        strupr(this->tamanio);

        todoOk = 1;
    }
    return todoOk;
}

int Pokemon_setAtaqueCargado(ePokemon* this,char* ataqueCargado)
{
    int todoOk = 0;
    if(this != NULL && ataqueCargado != NULL && strlen(ataqueCargado) <= 30 && strlen(ataqueCargado) >= 1)
    {
        strcpy(this->ataqueCargado, ataqueCargado);
        strlwr(this->ataqueCargado);
        (this->ataqueCargado)[0] = toupper((this->ataqueCargado)[0]);
        todoOk = 1;
    }
    return todoOk;
}

int Pokemon_setValorAtaque(ePokemon* this,int valorAtaque)
{
    int todoOk = 0;
    if(this != NULL && valorAtaque >= 1 && valorAtaque <=500)
    {
        this->valorAtaque = valorAtaque;
        todoOk = 1;
    }
    return todoOk;
}

int Pokemon_setEsVariocolor(ePokemon* this,int esVariocolor)
{
    int todoOk = 0;
    if(this != NULL && esVariocolor >= 1 && esVariocolor <=2)
    {
        this->esVariocolor = esVariocolor;
        todoOk = 1;
    }
    return todoOk;
}

void pokemon_delete(ePokemon* this)
{
    free(this);
}

ePokemon* pokemon_newParametros(int num,char* nombreStr, char* tipoStr, char* tamanioStr, char* ataqueCargadoStr, int valorAtaque, int esVariocolor)
{
    ePokemon* newPokemon = pokemon_new();

    if(newPokemon != NULL)
    {
        if(!(   Pokemon_setNum(newPokemon, num) &&
                Pokemon_setNombre(newPokemon, nombreStr) &&
                Pokemon_setTipo(newPokemon, tipoStr) &&
                Pokemon_setTamanio(newPokemon, tamanioStr) &&
                Pokemon_setAtaqueCargado(newPokemon, ataqueCargadoStr) &&
                Pokemon_setValorAtaque(newPokemon, valorAtaque) &&
                Pokemon_setEsVariocolor(newPokemon, esVariocolor)))
        {

            pokemon_delete(newPokemon);
            newPokemon = NULL;
        }
    }
    return newPokemon;
}

int altaPokemon(LinkedList* lista, int* pNum)
{
    int todoOk = 0;
    char auxNombre[30];
    char auxTipo[30];
    char auxTamanio[4];
    char auxAtaqueCargado[30];
    int auxValorAtaque;
    int auxEsVariocolor;
    ePokemon* newPokemon = NULL;

    if(lista != NULL && pNum != NULL)
    {
        if(
            (pedirYValidarString(30, auxNombre, "Ingrese el nombre del pokemon: ", "Error, ingrese un nombre menor a 30 caracteres: ", 2)) &&
            (pedirYValidarString(30, auxTipo, "Ingrese el tipo del pokemon: ", "Error, ingrese un tipo menor a 30 caracteres: ", 2)) &&
            (pedirYValidarString(30, auxTamanio, "Ingrese el tamanio del pokemon: ", "Error, ingrese un tamanio menor a 30 caracteres: ", 1)) &&
            (pedirYValidarString(30, auxAtaqueCargado, "Ingrese el ataque cargado del pokemon: ", "Error, ingrese un ataque cargado menor a 30 caracteres: ", 2)) &&
            (pedirYValidarInt(&auxValorAtaque, "Ingrese el valor del ataque: ", "Error ingrese un valor entre 0 y 500: ", 0, 500)) &&
            (pedirYValidarInt(&auxEsVariocolor, "Ingrese si es variocolor: ", "Error ingrese un valor entre 0 y 2: ", 0, 2)))
        {
            newPokemon = pokemon_newParametros(*pNum, auxNombre, auxTipo, auxTamanio, auxAtaqueCargado, auxValorAtaque, auxEsVariocolor);
            ll_add(lista, newPokemon);
            todoOk = 1;
            *pNum = *pNum + 1;
        }
    }

    return todoOk;
}

int filtrarTipoWater(void* a)
{
    int rta = 0;
    ePokemon* pAux = NULL;

    if(a != NULL)
    {
        pAux = (ePokemon*) a;

        if(stricmp(pAux->tipo, "Water") == 0)
        {
            rta = 1;
        }
    }
    return rta;
}

int filtrarPokemonApto(void* a)
{
    int rta = 0;
    ePokemon* auxPokemon = NULL;

    if(a != NULL)
    {
        auxPokemon = (ePokemon*) a;

        if( ( (stricmp(auxPokemon->tipo, "Fire") == 0) && (stricmp(auxPokemon->tamanio, "XL") == 0) && (stricmp(auxPokemon->ataqueCargado, "Lanzallamas") == 0) && (auxPokemon->valorAtaque > 80)  )||
                ( (stricmp(auxPokemon->tipo, "Water") == 0) && (stricmp(auxPokemon->tamanio, "L") == 0) && (stricmp(auxPokemon->ataqueCargado, "Hidrobomba") == 0) && (auxPokemon->valorAtaque > 80)))
        {
            rta = 1;
        }
    }
    return rta;
}

int editarPokemon(LinkedList* lista, int* pId)
{
    int todoOk = 0;
    int auxId;
    int indice;
    int opcion;
    char conf;
    char auxNombre[30];
    char auxTipo[30];
    char auxTamanio[4];
    char auxAtaqueCargado[30];
    int auxValorAtaque;
    int auxEsVariocolor;
    ePokemon* auxPokemon;

    if(lista != NULL && pId != NULL)
    {
        imprimirPokemones(lista);

        pedirYValidarInt(&auxId, "Ingrese el numero de un pokemon: ", "Error, reingrese el numero de un pokemon valido: ", 1, *pId);

        if((ll_buscarId(lista, auxId, &indice)))
        {
            auxPokemon = (ePokemon*) ll_get(lista, indice);
            printf("Ingres%c el id %d: \n", 162, auxId);
            imprimirPokemonSolo(auxPokemon);

            confirma("Esta seguro que desea modificarlo?", &conf);

            if(conf == 's')
            {
                subMenuModif(&opcion);
                switch(opcion)
                {
                case 1:
                    printf("Ha ingresado a modificar el nombre\n\n");
                    if(pedirYValidarString(30, auxNombre, "Ingrese el nuevo nombre: ", "Error, reingrese el nombre menor a 29 caracteres: ", 2))
                    {
                        strcpy(auxPokemon->nombre, auxNombre);
                    }
                    break;
                case 2:
                    printf("Ha ingresado a modificar el tipo\n\n");
                    if(pedirYValidarString(30, auxTipo, "Ingrese el nuevo tipo: ", "Error, reingrese el tipo menor a 29 caracteres: ", 1))
                    {
                        strcpy(auxPokemon->tipo, auxTipo);
                    }
                    break;
                case 3:
                    printf("Ha ingresado a modificar el Tamanio\n\n");
                    if(pedirYValidarString(4, auxTamanio, "Ingrese el tamanio del pokemon: ", "Error, reingrese el tamanio menor a 3 caracteres: ", 1))
                    {
                        strcpy(auxPokemon->tamanio, auxTamanio);
                    }
                    break;
                case 4:
                    printf("Ha ingresado a modificar el ataque cargado\n\n");
                    if(pedirYValidarString(30, auxAtaqueCargado, "Ingrese el nuevo ataque cargado: ", "Error, reingrese el ataque cargado menor a 20 caracteres: ", 1))
                    {
                        strcpy(auxPokemon->ataqueCargado, auxAtaqueCargado);
                    }
                    break;
                case 5:
                    printf("Ha ingresado a modificar el valor de ataque\n\n");
                    if(pedirYValidarInt(&auxValorAtaque, "Ingrese el nuevo valor de ataque", "Error, ingrese un valor de ataque mayor o igual a 0 y menor a 500", 0, 500))
                    {
                        auxPokemon->valorAtaque = auxValorAtaque;
                    }
                    break;
                case 6:
                    printf("Ha ingresado a modificar si es variocolor \n\n");
                    if(pedirYValidarInt(&auxEsVariocolor, "Ingrese el nuevo valor", "Error, ingrese un valor mayor o igual a 0 y menor a 3", 0, 3))
                    {
                        auxPokemon->esVariocolor = auxEsVariocolor;
                    }
                    break;
                default:
                    printf("Se ha cancelado la modificaci%cn", 162);
                    break;
                }
            }
            else
            {
                printf("Se cancel%c la modificacion del pokemon", 162);
            }
        }
        else
        {
            printf("No se encontr%c el numero ingresado", 162);
        }
    }

    return todoOk;
}
