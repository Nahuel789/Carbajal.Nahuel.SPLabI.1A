#include "menu.h"
#include "utn.h"
#include <stdio.h>
int menu()
{
    int opcion;

    printf("1)Cargar archivo\n");
    printf("2)Imprimir lista\n");
    printf("3)Asignar tiempos\n");
    printf("4)Filtrar por tipo\n");
    printf("5)Mostrar posiciones\n");
    printf("6)Guardar posiciones\n");
    printf("7)Salir\n");

    utn_getNumero(&opcion,"Ingrese la opcion que desee: \n","Error.Reingrese: \n",1,7,100);


    return opcion;
}
