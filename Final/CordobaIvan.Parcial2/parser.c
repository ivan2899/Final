#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "movies.h"
#include "miBiblioteca.h"

int parser_FromText(FILE* pFile, LinkedList* pArrayList)
{
    int todoOk = 0;
    char encabezados[4][20];
    eMovie* auxMovies;
    int cant;
    char conf;

    if(ll_len(pArrayList) > 0)
    {
        confirma("Se van a sobreescribir los pasajeros en memoria, desea cargarlo de todas formas?", &conf);
    }

    if(ll_len(pArrayList) == 0 || conf == 's')
    {
        ll_clear(pArrayList);
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", encabezados[0], encabezados[1], encabezados[2], encabezados[3]);
        while(!feof(pFile))
        {
            auxMovies = movie_new();
            if(auxMovies != NULL)
            {
                cant = fscanf(pFile, " %d, %[^,], %[^,],%f \n", &auxMovies->id, auxMovies->titulo, auxMovies->genero, &auxMovies->rating);
                if(cant <1)
                {
                    return todoOk;
                }
                ll_add(pArrayList, auxMovies);
            }
            todoOk = 1;
        }
    }

    return todoOk;
}


int parser_FromBinary(FILE* pFile, LinkedList* pArrayList)
{
    int todoOk = 0;
    char encabezados[80];
    eMovie* auxMovies;
    int cant;
    char conf;

    if(ll_len(pArrayList) > 0)
    {
        confirma("Se van a sobreescribir los pasajeros en memoria, desea cargarlo de todas formas?", &conf);
    }

    if(ll_len(pArrayList) == 0 || conf == 's')
    {
        fread(encabezados, sizeof(char), 80, pFile);
        while(!feof(pFile))
        {
            auxMovies = movie_new();
            if(auxMovies != NULL)
            {
                cant = fread(auxMovies, sizeof(eMovie), 1, pFile);
                if(cant <1)
                {
                    return todoOk;
                }
                ll_add(pArrayList, auxMovies);
                todoOk = 1;
            }
        }
    }

    return todoOk;
}
