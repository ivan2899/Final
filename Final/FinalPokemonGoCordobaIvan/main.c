#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "LinkedList.h"
#include "controller.h"
#include "miBiblioteca.h"
#include "generadorInformes.h"

int main()
{
    char confSal;
    LinkedList* mochilaPokemon = ll_newLinkedList();
    int id = 152;

    do
    {
        system("cls");
        switch(opcion())
        {
        case 1:
            if(Cordoba_Datos_controllerCarga(mochilaPokemon))
            {
                printf("Se cargo correctamente");
            }
            else
            {
                printf("No se pudo abrir el archivo");
            }
            break;
        case 2:
            bajaPokemon(mochilaPokemon, id);
            break;
        case 3:
            imprimirPokemones(mochilaPokemon);
            break;
        case 4:
            Cordoba_Filtros_controllerFiltroTipoAgua(mochilaPokemon);
            break;
        case 5:
            Cordoba_Ataque_mapearAtaqueCargado(mochilaPokemon);
            break;
        case 6:
            Cordoba_Batalla_controllerBatallaPokemon(mochilaPokemon);
            break;
        case 7:
            altaPokemon(mochilaPokemon, &id);
            break;
        case 8:
            if(Cordoba_Datos_controllerGuardado(mochilaPokemon))
            {
                printf("Se guardo correctamente");
            }
            else
            {
                printf("No se pudo guardar el archivo");
            }
            break;
        case 9:
            editarPokemon(mochilaPokemon, &id);
            break;
        case 10:
            Cordoba_Salida_controllerSalida(mochilaPokemon, &confSal);
            break;
        }

        if(confSal != 's')
        {
            printf("\n\n");
            system("pause");
        }

    }
    while(confSal != 's');

    return 0;
}


