#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>

int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
     float bufferFloat;
    int retorno = -1;

    if( pResultado !=NULL && mensaje!= NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0 )
    {
        do
        {
        printf("%s", mensaje);
        scanf("%f", &bufferFloat);
        if(bufferFloat >= minimo && bufferFloat <= maximo)
        {
            *pResultado=bufferFloat;
             retorno=0;
             break;
        }
        else
        {
            printf("%s", mensajeError);
            reintentos--;
        }





        }while(reintentos>=0);


    }



    return retorno;




}

int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos)
{
    char bufferChar;
    int retorno = -1;

    if( pResultado !=NULL && mensaje!= NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0 )
    {
        do
        {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%c", &bufferChar);
        if(bufferChar >= minimo && bufferChar <= maximo)
        {
            *pResultado=bufferChar;
             retorno=0;
             break;
        }
        else
        {
            printf("%s", mensajeError);
            reintentos--;
        }





        }while(reintentos>=0);


    }



    return retorno;




}


static int myGets(char* cadena, int longitud)
{


   fflush(stdin);
   fgets(cadena,longitud,stdin);
   cadena[strlen(cadena)-1]='\0';

    return 0;
}


static int esNumerica(char* cadena)
{
    int retorno = 1;

    int i=0;

    if(cadena[0] == '-')
    {

        i  = 1;


    }

    for( ; cadena[i] != '\0'; i++)
    {


        if(cadena[i] > '9' || cadena[i] < '0')
        {

            retorno = 0;
            break;

        }




    }

    return retorno;
}

static int getInt(int* pResultado)
{
    int retorno = -1;
    char buffer[4096];

    if(myGets(buffer,sizeof(buffer))== 0 && esNumerica(buffer))
    {

        retorno = 0 ;
        *pResultado= atoi(buffer);



    }



    return retorno;


}



int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int bufferInt;
    int retorno = -1;



    if( pResultado !=NULL && mensaje!= NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0 )
    {
        do
        {
        printf("%s", mensaje);

        if(getInt(&bufferInt)== 0 && bufferInt >= minimo && bufferInt <= maximo)
        {
            *pResultado=bufferInt;
             retorno=0;
             break;
        }
        else
        {
            printf("%s", mensajeError);
            reintentos--;
        }





        }while(reintentos>=0);


    }



    return retorno;

}

int esNumerico(char str[])
{
    int i=0;

    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return 0 ;
        }

        i++;

    }

    return 1 ;

}


/** \brief
 *
 * \param Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene ' 'y letras, y 0 si no lo es
 *
 */

int esSoloLetras(char str[])
{
    int i=0;

    int retorno = 1;

    while(str[i] != '\0')
    {

        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {

            retorno=0 ;

        }

        i++;


    }

    return retorno;


}

int esAlfaNumerico(char str[])
{

    int i=0;

    while(str[i] != '\0')
    {
        if((str[i] != ' ') &&(str[i] != '.') && (str[i] < 'a' || str[i] > 'z')&&(str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
        {
            return 0;
        }

        i++;
    }
    return 1;

}

int esTelefono(char str[])
{

    int i=0;

    int contadorGuiones =0;

    while(str[i] != '\0')
    {


        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
        {
             return 0;
        }



        if(str[i] == '-')
        {
         contadorGuiones++;
        }



        i++;





    }

    if(contadorGuiones == 1)
    {
      return 1 ;


    }






    return 0;


}

int utn_getCadena(char *pAux, int len, int intentos, char* mensaje, char* mensajeError)
{
	int retorno = -1;
    char auxString[len];

    if(pAux != NULL && mensaje != NULL && mensajeError != NULL && len > 0 && intentos >= 0){
        do{
        	printf("%s", mensaje);

            if((getCadena(auxString, len)) == 0)
            {
                fflush(stdin);
                strncpy(pAux, auxString, len);
                retorno = 0; //exito
                break;
            }else
            {
            	printf("%s", mensajeError);
            }
            intentos--;

        }while(intentos>=0);
    }

    return retorno;
}

int getCadena(char* pAux, int len)
{
    char auxString[4096];

    int retorno= -1;

    if (pAux != NULL && len > 0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);

        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= len)
        {
            strncpy(pAux, auxString, len);
            retorno=0; //exito
        }
    }

    return retorno;
}
