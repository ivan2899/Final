#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "LinkedList.h"
#include "controller.h"
#include "miBiblioteca.h"

int main()
{
    char confSal;
    LinkedList* lista = ll_newLinkedList();

    do
    {
        system("cls");
        switch(opcion())
        {
        case 1:
            if(controller_carga(lista))
            {
                printf("Se cargo correctamente");
            }
            else
            {
                printf("No se pudo abrir el archivo");
            }
            break;
        case 2:
            controller_listar(lista);
            break;
        case 3:
            if(controller_rating(lista))
            {
                printf("Se le asigno el rating correctamente");
            }
            else
            {
                printf("Se produjo un fallo al asignar el rating");
            }
            break;
        case 4:
            if(controller_genero(lista))
            {
                printf("Se le asigno genero correctamente");
            }
            else
            {
                printf("No se pudo asignar genero");
            }
            break;
        case 5:
            controller_filtrar_genero(lista);
            break;
        case 6:
            controller_ordenar(lista);
            break;
        case 7:
            if(controller_guardado(lista))
            {
                printf("Se guardo correctamente");
            }
            else
            {
                printf("Ocurrio un problema al guardar");
            }
            break;
        case 8:
            controller_salida(lista, &confSal);
            break;
        }

        printf("\n\n");
        system("pause");
    }while(confSal != 's');



    return 0;
}
