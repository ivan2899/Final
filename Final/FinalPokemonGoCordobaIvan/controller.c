#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "miBiblioteca.h"
#include "controller.h"
#include "parser.h"
#include "pokemon.h"
#include "generadorInformes.h"

int Cordoba_Salida_controllerSalida(LinkedList* this, char* confSalida)
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

int Cordoba_Datos_controllerCarga(LinkedList* this)
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
            confirma("La ruta por defecto es \"Data_Pokemones.csv\", desea cambiarla?", &conf);
            strcpy(path, "Data_Pokemones.csv");
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

int Cordoba_Filtros_controllerFiltroTipoAgua(LinkedList* this)
{
    int todoOk;
    LinkedList* aux = NULL;

    if(this != NULL)
    {
        printf("Se filtrara por tipo Water\n");
        aux = ll_filter(this, filtrarTipoWater);
        imprimirPokemones(aux);
        todoOk = 1;
    }
    return todoOk;
}

int Cordoba_Ataque_mapearAtaqueCargado(LinkedList* this)
{
    int todoOk = 0;
    char conf;

    if(this != NULL)
    {
        this = ll_map(this, ataqueCargado);
        todoOk = 1;
    }

    printf("Enhorabuena!!, debido a que el tiempo despejado favorece a tus pokemones "
           "tenemos una buena noticia, \nTODOS TUS POKEMONES DE TIPO \"FIRE\", \"GROUND\" y \"GRASS\" \n\n"
           "--HAN RECIBIDO UN 10 DE AUMENTO EN EL ATAQUE!!!!-- \n ");
    confirma("Desea ver el nuevo listado de pokemones?", &conf);

    if(conf == 's')
    {
        imprimirPokemones(this);
    }

    return todoOk;
}

int Cordoba_Batalla_controllerBatallaPokemon(LinkedList* this)
{
    int todoOk = 0;
    int pokemonsApto;
    LinkedList* aux = NULL;
    char conf;

    if(this != NULL)
    {
        printf("Nos hemos encontrado con el jefe del team Rocket, Giovanni.\n"
               "El malvado jugara su batalla final con Lugia, pokemon de tipo Psiquico.\n"
               "Necesitaremos al menos 3 pokemones que cumplan las caracteristicas para poder derrotarlo\n\n");
        pokemonsApto = ll_count(this, batallaPokemon);
        todoOk = 1;
    }

    if(pokemonsApto == 1)
    {
        printf("Hay un unico pokemon que cumple con las caracteristicas para poder ganar\n");
    }
    else if( pokemonsApto == 0)
    {
        printf("No hay ningun pokemon que cumpla las caracteristicas para poder ganar la batalla");
    }
    else
    {
        printf("Los pokemones que cumplen con las caracteristicas para poder ganar son: %d\n", pokemonsApto);
    }

    if(pokemonsApto >= 3)
    {
        printf("Hemos GANADO la batalla!!!\n");
    }
    else
    {
        printf("Han derrotado a nuestros pokemones :( \n");
    }

    confirma("Desea ver los pokemones que cumplen con las caracteristicas?", &conf);

    if(conf == 's')
    {
        aux = ll_filter(this, filtrarPokemonApto);
        imprimirPokemones(aux);
    }

    return todoOk;
}

int Cordoba_Datos_controllerGuardado(LinkedList* this)
{
    int todoOk = 0;
    ePokemon* auxPokemon;
    int cant;
    char conf;
    char path[50];
    int opcion;

    printf("Ha ingresado a guardar el archivo");
    pedirYValidarInt(&opcion, "\n1. Modo texto\n2. Modo binario\n Ingrese opcion: ", "Error, reingrese\n1. Modo texto\n2. Modo binario: ", 1,2);
    pedirPath(path);

    if(path != NULL && this != NULL && (opcion >= 1 || opcion <=2))
    {
        if(opcion == 1)
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
                for(int i=0; i<ll_len(this); i++)
                {
                    auxPokemon = ll_get(this, i);
                    if(auxPokemon != NULL)
                    {
                        cant = fprintf(file, "%d, %s, %s, %s, %s, %d, %d\n\n", auxPokemon->numero, auxPokemon->nombre, auxPokemon->tipo, auxPokemon->tamanio, auxPokemon->ataqueCargado, auxPokemon->valorAtaque, auxPokemon->esVariocolor);
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
        else
        {
            FILE* pFile = fopen(path, "rb");

            if(pFile != NULL)
            {
                printf("Precauci%cn!, ya existe un archivo con ese nombre y se va a sobrescribir\n", 162);
                confirma("Desea guardarlo con el mismo nombre, de todas formas? ", &conf);
            }
            fclose(pFile);

            if(pFile == NULL || conf == 's')
            {
                pFile = fopen(path, "wb");
                for(int i=0; i<ll_len(this); i++)
                {
                    auxPokemon = ll_get(this, i);
                    if(auxPokemon != NULL)
                    {
                        cant = fwrite(auxPokemon, sizeof(ePokemon), 1, pFile);
                        todoOk = 1;
                    }
                    if(cant <1)
                    {
                        return todoOk;
                    }
                }
                fclose(pFile);
            }
        }
    }

    return todoOk;
}
