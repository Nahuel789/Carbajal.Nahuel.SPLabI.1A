#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "bicicletas.h"
#include "menu.h"
#include <time.h>
#include "utn.h"

int main()
{

    srand (time(NULL)); // esta linea va al inicio de main

    char seguir='s';
    int flag=0;

    LinkedList* listaBicicletas=ll_newLinkedList();
    LinkedList* listaFILTRADA=NULL;
    LinkedList* listaRandom=NULL;
    do
    {
        system("cls");

        switch(menu())
        {
        case 1://CARGA ARCHIVO
            system("cls");
            if(!parser_BikeFromText(listaBicicletas))
            {
                printf("PARSER REALIZADO CON EXITO\n");
                flag=1;
            }
            system("pause");

            break;
        case 2://IMPRIMIR LISTA

            system("cls");

            if(flag)
            {
                if(!bike_list(listaBicicletas))
                {
                    printf("LISTADO CON EXITO\n");
                }
            }
            else
            {
                printf("Primero cargar el archivo\n");
            }
            system("pause");
            break;
        case 3://ASIGNAR ESTADISTICAS
            system("cls");
            if(flag)
            {
                listaRandom=ll_map(listaBicicletas,datosRandom);
                if(listaRandom != NULL)
                {
                    printf("LISTA RANDOM CREADA CON EXITO\n");
                    if(!saveAsText("listaRandom.csv",listaRandom))
                    {
                        printf("Guardada lista random con exito\n");
                    }
                    bike_list(listaRandom);
                }

            }
            else
            {
                printf("Primero cargar el archivo\n");
            }

            system("pause");
            break;
        case 4://FILTRAR POR BICICLETAS
            system("cls");
            if(flag)
            {
                int opcion;
                utn_getNumero(&opcion,"FILTRAR POR:\n1)BMX\n2)MTB\n3)PASEO\n4)PLAYERA\n","Error",1,4,1);
                switch(opcion)
                {
                case 1:
                    listaFILTRADA=ll_filter(listaRandom,filterTipoBMX);
                    if(listaFILTRADA !=NULL)
                    {
                        bike_list(listaFILTRADA);
                    }
                    break;

                case 2:

                    listaFILTRADA=ll_filter(listaRandom,filterTipoMTB);
                    if(listaFILTRADA !=NULL)
                    {
                        bike_list(listaFILTRADA);
                    }
                    break;
                case 3:
                    listaFILTRADA=ll_filter(listaRandom,filterTipoPASEO);
                    if(listaFILTRADA !=NULL)
                    {
                        bike_list(listaFILTRADA);
                    }
                    break;
                case 4:

                    listaFILTRADA=ll_filter(listaRandom,filterTipoPlAYERA);
                    if(listaFILTRADA !=NULL)
                    {
                        bike_list(listaFILTRADA);
                    }
                    break;

                }
            }
            else
            {
                printf("Primero cargar el archivo\n");
            }
            system("pause");
            break;
        case 5://MOSTRAR POSICIONES ORDENADAS POR TIPO Y POR TIEMPO ASCENDENTE
            system("cls");
            if(flag)
            {
                if(!ll_sort(listaBicicletas,sortByTipoyTiempo,1))
                {
                    bike_list(listaBicicletas);
                }
            }else
            {
                printf("Primero cargar el archivo\n");
            }
            system("pause");
            break;
        case 6://GUARDAR POSICIONES ORDENADAS
            system("cls");
            if(flag)
            {
                if(!saveAsText("listaOrdenada.csv",listaBicicletas))
                {
                    printf("GUARDADA CON EXITO\n");
                }

            }else
            {
                printf("Primero cargar el archivo\n");
            }
            system("pause");
            break;

        case 7://SALIR
            seguir='n';
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
    }
    while(seguir=='s');

    ll_deleteLinkedList(listaBicicletas); //ELIMINO LAS LISTAS PARA QUE NO QUEDEN EN MEMORIA
    ll_deleteLinkedList(listaFILTRADA);
    ll_deleteLinkedList(listaRandom);
    return 0;
}


