#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "miBiblioteca.h"

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

    printf("  _______________________________________________________     \n"
           "||                  ***MENU PRINCIPAL***                 ||\n"
           "||_______________________________________________________||\n"
           "|| 1) Cargar archivo pokemones                           ||\n"
           "|| 2) Eliminar Pokemon                                   ||\n"
           "|| 3) Imprimir Pokemones                                 ||\n"
           "|| 4) Filtrar de tipo Agua variocolor                    ||\n"
           "|| 5) Mapear ataque cargado                              ||\n"
           "|| 6) Batalla pokemon                                    ||\n"
           "|| 10) Salir                                             ||\n"
           "||_______________________________________________________||"
          );


    printf("\n\nIngrese opci%cn: ", 162);
    scanf("%d", &auxOpcion);

    while((auxOpcion < 1 || auxOpcion > 9) && auxOpcion != 10)
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
        printf("Ingrese la ruta del archivo con extension (.bin o .csv): ");
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

int subMenuModif(int* opcion)
{
    int todoOk = 0;

    if(opcion != NULL)
    {
        printf("Que desea modificar?\n1. Nombre\n2. Tipo\n3. Tamanio\n4. Ataque cargado\n5. Valor ataque\n6. Es variocolor \n7. Salir\n");
        pedirYValidarInt(opcion, "Ingrese un numero: ", "Error, ingrese un numero del 1 al 7: ", 1, 7);
        todoOk = 1;
    }

    return todoOk;
}
