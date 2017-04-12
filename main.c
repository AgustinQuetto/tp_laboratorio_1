#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

//DECLARACION DE VARIABLES
float valor1, valor2, resultado;
int opcion;
char seguir = 's';

int main()
{
    printf("Ingrese X: ");
    scanf("%g", &valor1);
    printf("Valor de X asignado: %g", valor1);
    printf("\n\nIngrese Y: ");
    scanf("%g", &valor2);
    printf("Valor de Y asignado: %g \n\n", valor2);

    do{
        printf("Operaciones disponibles:\n");
        printf("1- Reingresar X\n");
        printf("2- Reingresar Y\n");
        printf("3- Calcular la suma (X+Y)\n");
        printf("4- Calcular la resta (X-Y)\n");
        printf("5- Calcular la division (X/Y)\n");
        printf("6- Calcular la multiplicacion (X*Y)\n");
        printf("7- Calcular el factorial (X!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        printf("-> Ingrese el numero de operacion que desee realizar: ");
        scanf("%i",&opcion);

        switch(opcion)
        {
            case 1:
                valor1 = reingresarX(valor1);
                printf("# Nuevo valor asignado para X: %g\n\n", valor1);
                break;
            case 2:
                valor2 = reingresarY(valor2);
                printf("# Nuevo valor asignado para Y: %g\n\n", valor2);
                break;
            case 3:
                resultado = sumarXY(valor1,valor2);
                printf("# Suma de ambos terminos: %g\n\n", resultado);
                break;
            case 4:
                resultado = restarXY(valor1,valor2);
                printf("# Resta de ambos terminos: %g\n\n", resultado);
                break;
            case 5:
                resultado = divisionXY(valor1,valor2);
                printf("# Division de ambos terminos: %g\n\n", resultado);
                break;
            case 6:
                resultado = multiplicarXY(valor1,valor2);
                printf("# Multiplicacion de ambos terminos: %g\n", resultado);
                break;
            case 7:
                factorialXY(valor1, valor2);
                break;
            case 8:
                resultado = sumarXY(valor1,valor2); //SUMAR
                    printf("\n# Suma de ambos terminos: %g\n", resultado);
                resultado = restarXY(valor1,valor2); //RESTAR
                    printf("# Resta de ambos terminos: %g\n", resultado);
                resultado = divisionXY(valor1,valor2); //DIVIDIR
                    printf("# Division de ambos terminos: %g\n", resultado);
                resultado = multiplicarXY(valor1,valor2); //MULTIPLICAR
                    printf("# Multiplicacion de ambos terminos: %g\n", resultado);
                factorialXY(valor1, valor2); //FACTORIALES
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }while(seguir == 's');


    return 0;
}
