#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define SIZE 20

int main()
{
   EPersona persona[SIZE];
   int opc;
   inicializarEstados(persona,SIZE);
    do{
        printf("\n-Sistema de gestion de usuarios-");
        printf("\n1- Agregar Persona");
        printf("\n2- Borrar  Persona");
        printf("\n3- Mostrar Persona");
        printf("\n4- Imprimir Graficos de edades");
        printf("\n5- salir\n");
        printf("\nIngrese su opcion: ");
        scanf("%d", &opc);
                //VALIDO LA OPCION INGRESADA
                while(opc<1 || opc>5){
                    printf("ERROR: su opcion ingresada es invalida.\n");
                            printf("\nIngrese su opcion: ");
                            scanf("%d", &opc);
                }

        switch(opc){
            case 1:
                agregarNuevaPersona(persona, SIZE);
                break;
            case 2:
                borrarPersona(persona,SIZE);
                    break;
            case 3:
                ordenarListar(persona, SIZE);
                break;
            case 4:
                graficar(persona, SIZE);
                break;
            case 5:

            system("pause");
            break;
        }
        system("cls");
        }while(opc!=5);
        /*Si la opcion es distinta a 5, salgo del bucle.
        Anteriormente fue validada para estar dentro de 1 y 4 que serían opciones correctas.*/


    return 0;
}

