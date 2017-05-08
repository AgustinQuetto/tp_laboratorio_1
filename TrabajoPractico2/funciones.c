#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define SIZE 20

/* GENERAL
@param "persona" hace referencia a la 'estructura EPersona'.
@param "longitud" es la longitud del vector.
*/

//Inicializa los estados en 0.

void inicializarEstados(EPersona persona[], int longitud) {
    int i;
    for(i=0; i<longitud; i++) {
        persona[i].estado=0;

    }
}


//Validacion de unicamente caracteres enteroericos.
int validarNumero(char entero[]) {
    int i;
    for(i=0; i<strlen(entero); i++) {
        if(!(isdigit(entero[i]))) {
            printf("Debe ingresar solo numeros enteros.\n");
            return 0;
        }
    }
    return 1;
}

//Validacion de unicamente caracteres alfabéticos.
int validarCadena(char caracter[]) {
    int i;
    for(i=0; i<strlen(caracter); i++) {
        if(isdigit(caracter[i]) || ispunct(caracter[i])) {
            printf("Debe ingresar solo caracteres alfabeticos.\n");
            return 0;
        }
    }
    return 1;
}

//Agrega personas al vector siempre y cuando el 'estado' de la fila sea 0.
void agregarNuevaPersona(EPersona persona[], int longitud) {
    int i;
    char aux[20];
    char auxDNI[20];
    char auxnombre[20];
    int auxInt;
    int correctDNI;
    int flag=0;
    for(i=0; i<longitud; i++) {


        if(persona[i].estado==0) {
            do {
                printf("\nIngrese nombre: ");
                fflush(stdin);
                gets(auxnombre);

            } while(validarCadena(auxnombre)==0);

            do {

                printf("Ingrese edad: ");
                fflush(stdin);
                gets(aux);
            } while(validarNumero(aux)==0);

            do {
                printf("Ingrese DNI: ");
                fflush(stdin);
                gets(auxDNI);
            } while(validarNumero(auxDNI)==0);


            auxInt=atoi(aux);
            correctDNI=atoi(auxDNI);

            persona[i].edad=auxInt;
            persona[i].dni=correctDNI;
            strcpy(persona[i].nombre, auxnombre);
            persona[i].estado=1;



            flag=1;
            printf("%s registrado con exito.\n", persona[i].nombre);
            system("pause");
            break;
        }

    }

    if(!flag) {

        printf("ERROR: no hay espacio suficiente.");
    }
}

//Cambiar el estado en 0 para no mostrarlo y poder sobreescribirlo.
void borrarPersona(EPersona persona[], int longitud) {
    int i;
    int flag=0;
    long aux;

    printf("Ingrese DNI: ");
    scanf("%d", &aux);
    for(i=0; i<longitud; i++) {
        if(aux == persona[i].dni) {
            persona[i].estado=0;
            flag=1;
            printf("%s eliminado con exito.\n", persona[i].nombre);
            system("pause");
            break;
        }
    }
    if(!flag) {
        printf("ERROR: no hay personas disponibles para eliminar.\n");
    }
}

//Muestra y ordena la informacion cargada de todo el vector en estado 1.
void ordenarListar(EPersona persona[], int longitud) {

    int flag=0;
    EPersona aux;
    int i,j;
    for(i=0; i<longitud-1; i++)
    {
        for(j=i; j<longitud; j++)
        {

            if(strcmp(persona[i].nombre,persona[j].nombre)>0)
            {

                aux=persona[i];
                persona[i]=persona[j];
                persona[j]=aux;
            }
        }
    }


    for(i=0; i<longitud; i++) {
        if(persona[i].estado==1) {

            printf("\nNombre: %s", persona[i].nombre);
            printf("\nEdad: %d", persona[i].edad);
            printf("\nDNI: %d\n", persona[i].dni);
            flag=1;

        }
    }
    if(!flag) {

        printf("ERROR: no se encuentran personas cargadas al sistema.");

    }
    system("pause");
    system("cls");
}

//Imprime en consola un grafico con la longitudidad de personas en los rangos determinados.
void graficar(EPersona persona[], int longitud) {
    int flag=0;
    int i;
    int menor18=0;
    int entre19y35=0;
    int mayor35=0;
    int conteoTotal;
    for(i=0; i<longitud; i++)
    {
        if(persona[i].estado==1)
        {
            if(persona[i].edad<18) {
                menor18++;
            }
            else {
                if(persona[i].edad>=18 && persona[i].edad<=35) {
                    entre19y35++;
                }
                if(persona[i].edad>35) {
                    mayor35++;
                }
            }
        }
    }

    conteoTotal=menor18+entre19y35+mayor35;
    for(i=conteoTotal; i>0; i--) {
        if(menor18 == i) {
            printf("*");
            menor18--;
        }

        printf("\t");

        if(entre19y35 == i)
        {
            printf("*");
            entre19y35--;
        }
        printf("\t");

        if(mayor35==i)
        {
            printf("*");
            mayor35 --;
        }

        printf("\n");
        flag=1;
    }

    if(!flag) {

        printf("ERROR: no existen personas para intentar mostrar el grafico.\n");
    }
    printf("-----------------\n");
    printf("<=18\t19-35\t>=35\n");
    system("pause");
    system("cls");

}
