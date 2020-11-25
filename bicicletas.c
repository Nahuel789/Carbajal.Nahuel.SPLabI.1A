#include "bicicletas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int parser_BikeFromText( LinkedList* pList)
{
    char id[100];
    char nombre[100];
    char tipo[100];
    char tiempo[100];
    int retorno=-1;
    eBicicleta* pBicicleta;
    FILE* pFile;
    char path[100];


    if(!utn_getCadena(path,sizeof(path),4,"Ingrese el nombre del archivo(incluir .csv):\n","Error.Reingrese: "))
    {
        pFile=fopen(path,"r");
        if(pFile!=NULL && pList !=NULL)
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,tipo,tiempo);
            do
            {
                if((fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,tipo,tiempo))== 4)
                {
                    pBicicleta=bike_newParametros(id,nombre,tipo,tiempo);

                    if(pBicicleta != NULL)
                    {
                        ll_add(pList,pBicicleta);
                        retorno=0;
                    }
                }
                else
                    break;

            }
            while(!feof(pFile));
        }
        else
        {
            printf("No existe el archivo\n");
            exit(EXIT_FAILURE);
        }
    }

    return retorno;
}
eBicicleta* bike_new()
{
    eBicicleta* pBicicleta=NULL;
    pBicicleta=(eBicicleta*)malloc(sizeof(eBicicleta));
    if(pBicicleta != NULL)
    {
        pBicicleta->id_bike=0;
        strcpy(pBicicleta->nombre,"");
        strcpy(pBicicleta->tipo,"");
        pBicicleta->tiempo='0';
    }
    return pBicicleta;
}
eBicicleta* bike_newParametros(char* idStr,char* nombreStr,char* tipoStr,char* tiempoStr)
{
    eBicicleta* this=NULL;

    this=bike_new();

    if(idStr!= NULL && nombreStr!=NULL && tipoStr!=NULL && tiempoStr!=NULL)
    {
        if(!(!bike_setId(this,atoi(idStr)) && !bike_setNombre(this,nombreStr) && !bike_setTipo(this,(tipoStr)) && !bike_setTiempo(this,atoi(tiempoStr))))
        {
            bike_delete(this); //ELIMINA EL PUNTERO AUXILIAR
        }
    }
    return this;
}
int bike_getId(eBicicleta* unaBicicleta,int* id)
{
    int retorno=-1;

    if(unaBicicleta != NULL && id != NULL)
    {

        *id=unaBicicleta->id_bike;
        retorno=0;
    }

    return retorno;
}
int bike_getNombre(eBicicleta* unaBicicleta,char* nombre)
{
    int retorno=-1;

    if(unaBicicleta != NULL && nombre != NULL)
    {
        strcpy(nombre,unaBicicleta->nombre);
        retorno=0;
    }
    return retorno;
}
int bike_getTipo(eBicicleta* unaBicicleta,char* tipo)
{
    int retorno=-1;
    if(unaBicicleta != NULL && tipo != NULL)
    {
        strcpy(tipo,unaBicicleta->tipo);
        retorno=0;
    }
    return retorno;
}
int bike_getTiempo(eBicicleta* unaBicicleta,int* tiempo)
{
    int retorno=-1;
    if(unaBicicleta != NULL && tiempo != NULL)
    {
        *tiempo=unaBicicleta->tiempo;
        retorno=0;
    }
    return retorno;

}
int bike_setId(eBicicleta* this,int id)
{
    int retorno=-1;
    {
        if(this != NULL && id >=0 )
        {
            this->id_bike=id;
            retorno=0; //EXITO
        }
    }
    return retorno;
}
int bike_setNombre(eBicicleta* this,char* nombre)
{
    int retorno=-1;
    {
        if(this != NULL && nombre != NULL )
        {
            strcpy(this->nombre,nombre);
            retorno=0; //EXITO
        }
    }
    return retorno;
}
int bike_setTipo(eBicicleta* this,char* tipo)
{
    int retorno=-1;
    {
        if(this != NULL && tipo >=0 )
        {
            strcpy(this->tipo,tipo);
            retorno=0; //EXITO
        }
    }
    return retorno;


}
int bike_setTiempo(eBicicleta*this,int tiempo)
{
    int retorno=-1;
    {
        if(this != NULL && tiempo >=0 )
        {
            this->tiempo=tiempo;
            retorno=0; //EXITO
        }
    }
    return retorno;

}
void bike_delete(eBicicleta* this) //ELIMINA UNA BICICLETA
{
    free(this);
    this=NULL;
}
int bike_list(LinkedList* lista) //LISTA EMPLEADOS ACTIVOS
{
    int retorno=-1;
    eBicicleta* pBicicleta=NULL;
    int auxId;
    char nombre[50];
    char tipo[50];
    int tiempo;
    int flag=0;

    if(lista != NULL && ll_len(lista) > 0  )
    {

        printf(".............................................................................................................\n");
        printf(".............................................LISTA DE BICIS..................................................\n");
        printf(".............................................................................................................\n\n");
        printf("ID                     NOMBRE                                    TIPO                        TIEMPO                        \n\n");
        for(int i=0; i<ll_len(lista); i++)
        {
            pBicicleta=(eBicicleta*)ll_get(lista,i);

            if(pBicicleta != NULL)
            {
                if(!bike_getId(pBicicleta,&auxId))
                {
                    if(!bike_getNombre(pBicicleta,nombre))
                    {
                        if(!bike_getTipo(pBicicleta,tipo))
                        {
                            if(!bike_getTiempo(pBicicleta,&tiempo))
                            {


                                printf("%2d              %15s                      %15s                         %d\n",auxId,nombre,tipo,tiempo);
                                flag=1;
                                pBicicleta=NULL;
                                retorno=0;//EXITO

                            }
                        }
                    }
                }
            }
        }
    }
    if(!flag)
    {
        printf("No hay bicicletas que listar\n");
    }
    return retorno;
}

void* datosRandom(void* a)
{
    int random;
    eBicicleta* unaBicicleta=NULL;

    if(a!= NULL)
    {
        unaBicicleta=(eBicicleta*)a;
        random=rand()%(71)+50;
        bike_setTiempo(unaBicicleta,random);

    }
    return unaBicicleta;
}

int saveAsText(char* path, LinkedList* lista)
{
    int retorno=-1;
    FILE* pFile;
    int tam;
    int auxId;
    char nombre[50];
    char tipo[50];
    int tiempo;
    eBicicleta* pBicicleta=NULL;
    tam=ll_len(lista);

    if(path != NULL && lista != NULL)
    {
        pFile=fopen(path,"w"); //ABRE EL ARCHIVO EN EL QUE VA A GUARDAR LA INFORMACION

        if(pFile != NULL)
        {
            fprintf(pFile,"Id,Nombre,Tipo,Tiempo\n");

            for(int i=0; i<tam; i++)
            {
                pBicicleta=(eBicicleta*)ll_get(lista,i);

                if(pBicicleta != NULL)
                {
                    if(!bike_getId(pBicicleta,&auxId) && !bike_getNombre(pBicicleta,nombre) && !bike_getTipo(pBicicleta,tipo) && !bike_getTiempo(pBicicleta,&tiempo))
                    {
                        fprintf(pFile,"%d,%s,%s,%d\n",auxId,nombre,tipo,tiempo);
                        retorno=0; //EXITO
                    }
                }
            }
            fclose(pFile); //CIERRE DE ARCHIVO
        }

    }

    return retorno;
}

int filterTipoBMX(void* a)
{
    int retorno=0;
    if(a!=NULL)
    {
        eBicicleta* pBicicleta=(eBicicleta*)a;
        if(strcmp(pBicicleta->tipo,"BMX") == 0)
        {
            retorno=1;//EXITO
        }
    }
    return retorno;
}

int filterTipoMTB(void* a)
{
    int retorno=0;
    if(a!=NULL)
    {
        eBicicleta* pBicicleta=(eBicicleta*)a;
        if(strcmp(pBicicleta->tipo,"MTB") == 0)
        {
            retorno=1;//EXITO
        }
    }
    return retorno;
}
int filterTipoPlAYERA(void* a)
{
    int retorno=0;
    if(a!=NULL)
    {
        eBicicleta* pBicicleta=(eBicicleta*)a;
        if(strcmp(pBicicleta->tipo,"PLAYERA") == 0)
        {
            retorno=1;//EXITO
        }
    }
    return retorno;
}
int filterTipoPASEO(void* a)
{
    int retorno=0;
    if(a!=NULL)
    {
        eBicicleta* pBicicleta=(eBicicleta*)a;
        if(strcmp(pBicicleta->tipo,"PASEO") == 0)
        {
            retorno=1;//EXITO
        }
    }
    return retorno;
}

int sortByTipoyTiempo(void* a,void* b)
{
    int retorno=0;

    if(a != NULL && b != NULL)
    {

        eBicicleta* pA=(eBicicleta*)a;
        eBicicleta* pB=(eBicicleta*)b;

        if(strcmp(pA->tipo,pB->tipo) == 0)
        {
            if(pA->tiempo > pB->tiempo)
            {
                retorno=1;
            }

        }
        else if(strcmp(pA->tipo,pB->tipo) > 0)
        {
            retorno=1;
        }
        else
        {
            retorno=-1;
        }
    }

    return retorno;

}

int sortByTiempo(void* a,void* b)
{
    int retorno=0;

    if(a != NULL && b != NULL)
    {

        eBicicleta* pA=(eBicicleta*)a;
        eBicicleta* pB=(eBicicleta*)b;

        if( pA->tiempo == pB->tiempo)
        {
            retorno=0;
        }
        else if(pA->tiempo > pB->tiempo)
        {
            retorno=1;
        }
        else
        {
            retorno=-1;
        }
    }

    return retorno;

}



