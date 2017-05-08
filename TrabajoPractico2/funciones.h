#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 20

typedef struct{
	char nombre[50];
	int edad;
	long dni;
	int estado;
}EPersona;

void inicializarEstados(EPersona var[], int tam);
void AgregarNuevaPersona(EPersona var[], int tam);
void ordenarListar(EPersona var[], int tam);
void borrarPersona(EPersona var[], int tam);
int validarNumero(char num[]);
int validarCadena(char auxchar[]);
void graficar(EPersona var[], int tam);
