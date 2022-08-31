#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "pokemon.h"
#include "miBiblioteca.h"


int imprimirPokemon(ePokemon* auxPokemon)
{
    int todoOk = 0;
    if(auxPokemon != NULL)
    {
        printf("||------|------------------------------|------------------------------|---------|------------------------------|-------------|-----------||\n");
        printf("||%6d|%30s|%30s|    %5s|%30s|        %5d|         %2d|| \n", auxPokemon->numero, auxPokemon->nombre, auxPokemon->tipo, auxPokemon->tamanio, auxPokemon->ataqueCargado, auxPokemon->valorAtaque, auxPokemon->esVariocolor);
        todoOk = 1;
    }
    return todoOk;
}

int imprimirPokemones(LinkedList* this)
{
    int todoOk = 0;
    ePokemon* auxPokemon = NULL;

    if(this != NULL)
    {
        printf("  _______________________________________________________________________________________________________________________________________ \n");
        printf("||  NUM |             NOMBRE           |               TIPO           | TAMANIO |       ATAQUE CARGADO         |  V. ATAQUE  | VARIOCOLOR||\n");

        for(int i=0; i<ll_len(this); i++)
        {
            auxPokemon = (ePokemon*) ll_get(this, i);
            imprimirPokemon(auxPokemon);
        }
        printf("||_______________________________________________________________________________________________________________________________________||\n");

        todoOk = 1;
    }
    return todoOk;
}

int imprimirPokemonSolo(ePokemon* auxPokemon)
{
    int todoOk = 0;

    if(auxPokemon)
    {
        printf("  _______________________________________________________________________________________________________________________________________ \n");
        printf("||  NUM |             NOMBRE           |               TIPO           | TAMANIO |       ATAQUE CARGADO         |  V. ATAQUE  | VARIOCOLOR||\n");
        printf("||------|------------------------------|------------------------------|---------|------------------------------|-------------|-----------||\n");
        printf("||%6d|%30s|%30s|    %5s|%30s|        %5d|         %2d|| \n", auxPokemon->numero, auxPokemon->nombre, auxPokemon->tipo, auxPokemon->tamanio, auxPokemon->ataqueCargado, auxPokemon->valorAtaque, auxPokemon->esVariocolor);
        printf("||_______________________________________________________________________________________________________________________________________||\n");

        todoOk = 1;
    }
    return todoOk;
}
