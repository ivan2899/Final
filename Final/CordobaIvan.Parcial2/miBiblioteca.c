#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "miBiblioteca.h"
#include "movies.h"

int confirmaSalida(char* eleccion)
{
    int todoOk = 0;
    char auxSalida;

    if(eleccion)
    {
        system("cls");
        printf(" ______________________________________ \n");
        printf("|   Ha ingresado a la opcion SALIR     |\n");
        printf("|______________________________________|\n\n");
        printf("Esta seguro que desea salir?\n");
        printf("Ingrese una letra, \"s\" para si \"n\" para no: ");
        fflush(stdin);
        scanf("%c", &auxSalida);
        auxSalida = tolower(auxSalida);

        while(auxSalida != 's' && auxSalida != 'n')
        {
            printf("Reingrese una letra, \"s\" (si) o \"n\" (no): ");
            fflush(stdin);
            scanf("%c", &auxSalida);
            auxSalida = tolower(auxSalida);
        }

        *eleccion = auxSalida;
        todoOk = 1;
    }
    return todoOk;
}

int opcion()
{
    int auxOpcion;

    printf("                                                            \n"
           "                   ***MENU PRINCIPAL***        \n"
           "                                                                  \n"
           "1) Cargar datos                                                             \n"
           "2) Listar peliculas                                                             \n"
           "3) Asignar rating                                                             \n"
           "4) Asignar genero                                                             \n"
           "5) Filtrar por genero                                                             \n"
           "6) Ordenar peliculas                                                             \n"
           "7) Guardar peliculas                                                             \n"
           "8) Salir                                                           \n"
          );


    printf("\nIngrese opci%cn: ", 162);
    scanf("%d", &auxOpcion);

    while(auxOpcion < 1 || auxOpcion > 8)
    {
        fflush(stdin);      //Limpio el buff de entrada para que en el caso de que arriba ingresen una letra no se rompa el programa
        printf("Se ingreso una opci%cn erronea, ingrese la opcion nuevamente: ", 162);
        scanf("%d", &auxOpcion);
    }
    return auxOpcion;
}

int pedirPath(char* pPath)
{
    int todoOk = 0;

    if(pPath != NULL)
    {
        printf("Ingrese la ruta del archivo: ");
        fflush(stdin);
        gets(pPath);
        while(!(validarGets(50, pPath)))
        {
            printf("Reingrese el nuevo nombre del archivo siendo menor a 50 caracteres: ");
            gets(pPath);
        }
        todoOk = 1;
    }

    return todoOk;
}

int validarGets(int tam, char auxCad[100])
{
    int validacion = 0;
    if(tam > 0 && auxCad)
    {
        if(strlen(auxCad) < tam)
        {
            validacion = 1;
        }
    }
    return validacion;
}

int confirma(char cadena[100], char* letra)
{
    int todoOk = 0;
    char auxLetra;

    if(letra != NULL)
    {
        printf("%s", cadena);
        printf("\n\n Ingrese S (si) o N (no): ");
        fflush(stdin);
        scanf("%c", &auxLetra);
        auxLetra = tolower(auxLetra);

        printf("\n");
        while((auxLetra != 's') && (auxLetra != 'n'))
        {
            printf("Se introdujo una letra erronea, reingrese por favor \"S\" (si) o \"N\" (no): ");
            fflush(stdin);
            scanf("%c", &auxLetra);
            auxLetra = tolower(auxLetra);
        }

        *letra = auxLetra;
        todoOk = 1;
    }

    return todoOk;
}

int pedirYValidarInt(int* resultado, char mensaje[50], char mensajeError[50], int minimo, int maximo)
{
    int todoOk = 0;
    char auxCad[50];
    int auxInt;


    if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        printf("\n%s", mensaje);
        fflush(stdin);
        gets(auxCad);
        while(!(validarGets(50, auxCad)))
        {
            printf("Error, reingrese un numero menor a 50 cifras");
            fflush(stdin);
            gets(auxCad);
        }
        auxInt = atoi(auxCad);

        while(auxInt < minimo || auxInt > maximo)
        {
            printf ("\n%s",mensajeError);
            fflush(stdin);
            gets(auxCad);
            while(!(validarGets(50, auxCad)))
            {
                printf("Error, reingrese un numero menor a 50 cifras");
                gets(auxCad);
            }
            auxInt = atoi(auxCad);
        }

        *resultado = auxInt;
        todoOk = 1;
    }
    return todoOk;
}

int pedirYValidarFloat(float* resultado, char mensaje[50], char mensajeError[50], float minimo, float maximo)
{
    int todoOk = 0;
    char auxCad[50];
    float auxFloat;


    if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        printf("\n%s", mensaje);
        gets(auxCad);
        while(!(validarGets(50, auxCad)))
        {
            printf("Error, reingrese un numero menor a 50 cifras");
            fflush(stdin);
            gets(auxCad);
        }
        auxFloat = atof(auxCad);

        while(auxFloat < minimo || auxFloat > maximo)
        {
            printf ("\n%s",mensajeError);
            fflush(stdin);
            gets(auxCad);
            while(!(validarGets(50, auxCad)))
            {
                printf("Error, reingrese un numero menor a 50 cifras");
                gets(auxCad);
            }
            auxFloat = atof(auxCad);
        }

        *resultado = auxFloat;
        todoOk = 1;
    }
    return todoOk;
}

int pedirYValidarChar(char* resultado, char mensaje[50], char mensajeError[50], char minimo, char maximo)
{
    int todoOk = 0;
    char buffer;

    if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        printf("\n%s", mensaje);
        fflush(stdin);
        scanf("%c", &buffer);

        if(buffer >= minimo && buffer <= maximo)
        {
            *resultado = buffer;
            todoOk = 1;
        }
        else
        {
            do
            {
                printf("\n%s", mensajeError);
                fflush(stdin);
                scanf("%c", &buffer);

                if(buffer >= minimo && buffer <= maximo)
                {
                    *resultado = buffer;
                    todoOk = 1;
                    break;
                }
            }
            while(1);
        }
    }
    return todoOk;
}

int pedirYValidarString(int maximo, char* cadena,  char mensaje[50], char mensajeError[50], int minimo)
{
    int todoOk = 0;
    char auxCad[maximo];

    if(cadena != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        printf("\n%s", mensaje);
        fflush(stdin);
        gets(auxCad);
        while(!validarGets(maximo, auxCad))
        {
            printf("Error, reingrese un texto menor a %d car%ccteres: ", maximo-1, 160);
            gets(auxCad);
        }

        if(strlen(auxCad) >= minimo && strlen(auxCad) < maximo)
        {
            strcpy(cadena, auxCad);
            todoOk = 1;
        }
        else
        {
            do
            {
                printf("\n%s", mensajeError);
                gets(auxCad);
                while(!validarGets(maximo, auxCad))
                {
                    printf("Error, reingrese un texto menor a %d y menor a %d car%ccteres", maximo-1, minimo, 160);
                    fflush(stdin);
                    gets(auxCad);
                }
                if(strlen(auxCad) >= minimo && strlen(auxCad) < maximo)
                {
                    strcpy(cadena, auxCad);
                    todoOk = 1;
                    break;
                }
            }
            while(1);
        }

    }


    return todoOk;
}

int mostrarPelicula(eMovie* auxMovie)
{
    int todoOk = 0;
    if(auxMovie != NULL)
    {
        printf("|%5d|%50s|%50s|%5.1f\n", auxMovie->id, auxMovie->titulo, auxMovie->genero, auxMovie->rating);
        todoOk = 1;
    }
    return todoOk;
}

void* asignarRating(void* a)
{
    int min = 10;
    int max = 100;
    float resultado;
    eMovie* movie = NULL;
    if(a != NULL)
    {
        movie = (eMovie*) a;
        if(movie->rating == 0)
        {
            resultado = (float) (rand() % (max - min + 1) + min) / 10;
            movie->rating = resultado;
        }
    }
    return a;
}

void* asignarGenero(void* a)
{
    int min = 1;
    int max = 4;
    int resultado;

    eMovie* movie = NULL;

    if(a != NULL)
    {
        movie = (eMovie*)a;
        if(stricmp(movie->genero, "sin genero") == 0)
        {
            resultado = (rand() % (max - min +1)) + min;

            switch(resultado)
            {
            case 1:
                strcpy(movie->genero, "Drama");
                break;
            case 2:
                strcpy(movie->genero, "Comedia");
                break;
            case 3:
                strcpy(movie->genero, "Accion");
                break;
            case 4:
                strcpy(movie->genero, "Terror");
                break;
            }
        }
    }
    return a;
}

int filtrarGeneroDrama(void* a)
{
    int rta = 0;
    eMovie* pAux = NULL;

    if(a != NULL)
    {
        pAux = (eMovie*) a;
        if(stricmp(pAux->genero, "Drama") == 0)
        {
            rta = 1;
        }
    }
    return rta;
}

int filtrarGeneroComedia(void* a)
{
    int rta = 0;
    eMovie* pAux = NULL;

    if(a != NULL)
    {
        pAux = (eMovie*) a;
        if(stricmp(pAux->genero, "Comedia") == 0)
        {
            rta = 1;
        }
    }
    return rta;
}

int filtrarGeneroAccion(void* a)
{
    int rta = 0;
    eMovie* pAux = NULL;

    if(a != NULL)
    {
        pAux = (eMovie*) a;
        if(stricmp(pAux->genero, "Accion") == 0)
        {
            rta = 1;
        }
    }
    return rta;
}

int filtrarGeneroTerror(void* a)
{
    int rta = 0;
    eMovie* pAux = NULL;

    if(a != NULL)
    {
        pAux = (eMovie*) a;
        if(stricmp(pAux->genero, "Terror") == 0)
        {
            rta = 1;
        }
    }
    return rta;
}

int ordenarGenero(void* type1, void* type2)
{
    int todoOk = 0;
    eMovie* auxMovie1;
    eMovie* auxMovie2;

    if(type1 != NULL && type2 != NULL)
    {
        auxMovie1 = (eMovie*) type1;
        auxMovie2 = (eMovie*) type2;

            todoOk = stricmp(auxMovie1->genero, auxMovie2->genero);
    }

    return todoOk;
}

int ordenarRating(void* type1, void* type2)
{
    int todoOk = 0;
    eMovie* auxMovie1;
    eMovie* auxMovie2;

    if(type1 != NULL && type2 != NULL)
    {
        auxMovie1 = (eMovie*) type1;
        auxMovie2 = (eMovie*) type2;

        if((stricmp(auxMovie1->genero, auxMovie2->genero) == 0) && (auxMovie1->rating < auxMovie2->rating))
        {
            todoOk = 1;
        }
    }

    return todoOk;
}

