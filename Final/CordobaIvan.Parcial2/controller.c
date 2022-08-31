#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "controller.h"
#include "miBiblioteca.h"
#include "parser.h"
#include "movies.h"

int controller_carga(LinkedList* this)
{
    int todoOk = 0;
    int num;
    char path[50];
    char conf;

    if(this != NULL)
    {
        pedirYValidarInt(&num, "Ingreso a cargar el archivo en modo\n1. Binario\n2. Texto\n", "Error, reingrese un numero\n1. Binario\n2. Texto\n", 1, 2);
        conf = 's';
        if(num == 2)
        {
        confirma("La ruta por defecto es \"movies.csv\", desea cambiarla?", &conf);
        strcpy(path, "movies.csv");
        }

        if(conf == 's')
        {
            pedirPath(path);
        }

        if(path != NULL && num >= 1 && num <= 2)
        {
            if(num == 1)
            {
                FILE* f = fopen(path, "rb");
                if(f != NULL)
                {
                    parser_FromBinary(f, this);
                    todoOk = 1;
                }
                fclose(f);
            }
            else
            {
                FILE* f = fopen(path, "r");

                if(f != NULL)
                {
                    parser_FromText(f, this);
                    todoOk = 1;
                }
                fclose(f);
            }

        }
    }

    return todoOk;
}

int controller_salida(LinkedList* this, char* confSalida)
{
    int todoOk = 0;
    char auxConfSalida;

    if(this != NULL && confSalida != NULL)
    {
        confirmaSalida(&auxConfSalida);

        if(auxConfSalida == 's')
        {
            ll_deleteLinkedList(this);
        }
        *confSalida = auxConfSalida;
    }
    return todoOk;
}

int controller_listar(LinkedList* this)
{
    int todoOk = 0;
    eMovie* auxMovie = NULL;

    if(this != NULL)
    {
        printf("|  ID |                      TITULO                      |                      GENERO                      |   RATING             \n");
        printf("-------------------------------------------------------------------------------------------------------------------\n");
        for(int i=0; i<ll_len(this); i++)
        {
            auxMovie = (eMovie*) ll_get(this, i);
            mostrarPelicula(auxMovie);
        }
        todoOk = 1;
    }
    return todoOk;
}

int controller_rating(LinkedList* this)
{
    int todoOk = 0;

   if(this != NULL)
    {
            this = ll_map(this, asignarRating);
            todoOk = 1;
    }

    return todoOk;
}

int controller_genero(LinkedList* this)
{
    int todoOk = 0;

    if(this != NULL)
    {
        this = ll_map(this, asignarGenero);
        todoOk = 1;
    }
    return todoOk;
}

int controller_guardado(LinkedList* this)
{
    int todoOk = 0;
    eMovie* auxMovie;
    int cant;
    char conf;
    char path[50];

    pedirPath(path);

    if(path != NULL && this != NULL)
    {
        FILE* file = fopen(path, "r");

        if(file != NULL)
        {
            printf("Precauci%cn!, ya existe un archivo con ese nombre y se va a sobrescribir\n", 162);
            confirma("Desea guardarlo con el mismo nombre, de todas formas? ", &conf);
        }
        fclose(file);

        if(file == NULL || conf == 's')
        {
            file = fopen(path, "w");
            fprintf(file, "Id,titulo,genero,rating\n");
            for(int i=0; i<ll_len(this); i++)
            {
                auxMovie = ll_get(this, i);
                if(auxMovie != NULL)
                {
                    cant = fprintf(file, "%d, %s, %s, %f\n", auxMovie->id, auxMovie->titulo, auxMovie->genero, auxMovie->rating);
                    todoOk = 1;
                }
                if(cant <1)
                {
                    return todoOk;
                }
            }
            fclose(file);
        }
    }

    return todoOk;
}

int controller_filtrar_genero(LinkedList* this)
{
    int todoOk;
    int resultado;
    LinkedList* aux = NULL;

    if(this != NULL)
    {
        printf("Que genero quiere filtrar?");
        pedirYValidarInt(&resultado, "\n1. Drama\n2. Comedia\n3. Accion\n4. Terror\n", "Error, num del 1 al 4,\n1. Drama\n2. Comedia\n3. Accion\n4. Terror\n", 1, 4);
        switch(resultado)
        {
        case 1:
            printf("Se filtrara por genero Drama\n");
            aux = ll_filter(this, filtrarGeneroDrama);
            break;
        case 2:
            printf("Se filtrara por genero Comedia\n");
            aux = ll_filter(this, filtrarGeneroComedia);
            break;
        case 3:
            printf("Se filtrara por genero Accion\n");
            aux = ll_filter(this, filtrarGeneroAccion);
            break;
        case 4:
            printf("Se filtrara por genero Terror\n");
            aux = ll_filter(this, filtrarGeneroTerror);
            break;
        }
        controller_listar(aux);
        todoOk = 1;
    }
    return todoOk;
}

int controller_ordenar(LinkedList* this)
{
    int todoOk = 0;

    if(this != NULL)
    {
    ll_sort(this, ordenarGenero, 1);
    ll_sort(this, ordenarRating, 1);
    }

    controller_listar(this);

    return todoOk;
}
