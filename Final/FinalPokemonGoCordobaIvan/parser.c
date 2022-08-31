#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "pokemon.h"
#include "miBiblioteca.h"

int parser_FromText(FILE* pFile, LinkedList* pArrayList)
{
    int todoOk = 0;
    ePokemon* auxPokemon;
    int cant;
    char conf;

    if(ll_len(pArrayList) > 0)
    {
        confirma("Se van a sobreescribir los pokemones en mochila, desea cargarlo de todas formas?", &conf);
    }

    if(ll_len(pArrayList) == 0 || conf == 's')
    {
        ll_clear(pArrayList);
        while(!feof(pFile))
        {
            auxPokemon = pokemon_new();
            if(auxPokemon != NULL)
            {
                cant = fscanf(pFile, " %d, %[^,], %[^,], %[^,], %[^,], %d, %d \n", &auxPokemon->numero, auxPokemon->nombre, auxPokemon->tipo, auxPokemon->tamanio, auxPokemon->ataqueCargado, &auxPokemon->valorAtaque, &auxPokemon->esVariocolor);
                fscanf(pFile,"  ");
                if(cant <1)
                {
                    return todoOk;
                }
                ll_add(pArrayList, auxPokemon);
            }
            todoOk = 1;
        }
    }

    return todoOk;
}


int parser_FromBinary(FILE* pFile, LinkedList* pArrayList)
{
    int todoOk = 0;
    ePokemon* auxPokemon;
    int cant;
    char conf;

    if(ll_len(pArrayList) > 0)
    {
        confirma("Se van a sobreescribir los pokemones en mochila, desea cargarlo de todas formas?", &conf);
    }

    if(ll_len(pArrayList) == 0 || conf == 's')
    {
        while(!feof(pFile))
        {
            auxPokemon = pokemon_new();
            if(auxPokemon != NULL)
            {
                cant = fread(auxPokemon, sizeof(ePokemon), 1, pFile);
                if(cant <1)
                {
                    return todoOk;
                }
                ll_add(pArrayList, auxPokemon);
                todoOk = 1;
            }
        }
    }

    return todoOk;
}
