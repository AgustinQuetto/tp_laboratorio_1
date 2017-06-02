#ifndef FUNCTIONS_C_INCLUDED
#define FUNCTIONS_C_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include "functions.h"

//show info
void showInfo(EMovie *moviesList)
{
    printf("Titulo: %s\nGenero: %s\nDuracion: %d mins\nDescripcion: %s\nPuntaje: %d\nEnlace de la imagen: %s\n", moviesList->titulo, moviesList->genero, moviesList->duracion, moviesList->descripcion, moviesList->puntaje, moviesList->linkImagen);
}

//validates the number of characters in the string to not exceed
void validateString(char valid[], int max)
{
    int large=strlen(valid);

    while(max<large)
    {
        printf("Se ha excedido el limite de caracteres.\nReingrese: ");
        gets(valid);
        large=strlen(valid);
    }
}

//validates integer ranges
int validateMinMax(int num,int min,int max)
{
    int checkNum=num;

    while(checkNum>max || checkNum<min)
    {
        printf("Entero no valido. Reingrese: ");
        scanf("%d", &checkNum);
    }
    return checkNum;
}

//get space from memory
int getSpace(EMovie *moviesList,int countMovies)
{
    int index=-1, i;

    for(i=0; i<countMovies; i++)
        if((moviesList+i)->duracion==0)
        {
            index=i;
            break;
        }
    return index;
}

//upload data to memory from file like database
int uploadFromMovies(EMovie *moviesList, int* pointerCount)
{
    int flag = 0;
    FILE *file;

    file=fopen("moviesData.dat", "rb");
    if(file==NULL)
    {
        file= fopen("moviesData.dat", "wb");
        if(file==NULL)
        {
            return 1;
        }
        flag=1;
    }
    if(flag==0)
    {
        fread(pointerCount,sizeof(int),1,file);
        while(!feof(file))
        {
            fread(moviesList,sizeof(EMovie),*pointerCount,file);
        }
    }
    fclose(file);
    return 0;
}

//add a movie in memory
void agregarPelicula(EMovie *moviesList,int countMovies,int* pointerCount)
{
    int ubicacion, disponible=0, i, duracion, puntaje, largeTitulo;
    char auxTitulo[50], auxGenero[50], auxDescripcion[150], linkImagen[250];

    ubicacion=countMovies-1;
    printf("\nNUEVA PELICULA\nTitulo: ");
    fflush(stdin);
    gets(auxTitulo);
    validateString(auxTitulo,50);
    largeTitulo=strlen(auxTitulo);
    for(i=0; i<largeTitulo; i++)
    {
        auxTitulo[i]=toupper(auxTitulo[i]); //Format title
    }

    for(i=0; i<countMovies; i++)
    {
        if(strcmp(auxTitulo,(moviesList+i)->titulo)==0 && (moviesList+i)->duracion!=0)
        {
            disponible=1;
            break;
        }
    }

    if(!disponible)
    {
        strcpy((moviesList+ubicacion)->titulo,auxTitulo);
        printf("Genero: ");
        fflush(stdin);
        gets(auxGenero);
        validateString(auxGenero,50);
        strcpy((moviesList+ubicacion)->genero,auxGenero);
        printf("Duracion (minutos): ");
        scanf("%d",&duracion);
        duracion=validateMinMax(duracion,0,400);
        (moviesList+ubicacion)->duracion=duracion;
        printf("Descripcion: ");
        fflush(stdin);
        gets(auxDescripcion);
        validateString(auxDescripcion,50);
        strcpy((moviesList+ubicacion)->descripcion,auxDescripcion);
        printf("Puntaje (1 a 10): ");
        scanf("%d",&puntaje);
        puntaje=validateMinMax(puntaje,1,10);
        (moviesList+ubicacion)->puntaje=puntaje;
        printf("Enlace de la imagen: ");
        fflush(stdin);
        gets(linkImagen);
        validateString(linkImagen,250);
        strcpy((moviesList+ubicacion)->linkImagen,linkImagen);
    }
    else
    {
        printf("ERROR: el titulo ingresado ya existe.\n");
        *pointerCount-=1;
    }
}

//modify the movie in memory
void modifyMovie(EMovie *moviesList,int countMovies)
{
    int flag=0, opcion, ubicacion, i, duracion, puntaje, largeTitulo, disponible=0;
    char auxTitulo[50], auxGenero[50], linkImagen[250], auxDescripcion[150];
    printf("\nMODIFICACION DE PELICULA\nTitulo de la pelicula a modificar: ");
    fflush(stdin);
    gets(auxTitulo);
    validateString(auxTitulo,50);
    largeTitulo=strlen(auxTitulo);
    for(i=0; i<largeTitulo; i++)
    {
        auxTitulo[i]=auxTitulo[i];
    }
    for(i=0; i<countMovies; i++)
    {
        if(stricmp(auxTitulo,(moviesList+i)->titulo)==0 && (moviesList+i)->duracion!=0)
        {
            printf("\nModificando: %s\n", auxTitulo);

            showInfo((moviesList + i));
            ubicacion=i;
            printf("\nSe ha encontrado la pelicula. Indique que propiedad desea modificar.\n");
            printf("1. Titulo\n");
            printf("2. Genero\n");
            printf("3. Duracion\n");
            printf("4. Descripcion\n");
            printf("5. Puntaje\n");
            printf("6. Link a imagen\n");
            printf("7. Cancelar\n");
            fflush(stdin);
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                printf("\nMODIFICACION\n");
                printf("Ingrese el titulo: ");
                fflush(stdin);
                gets(auxTitulo);
                validateString(auxTitulo,50);
                largeTitulo=strlen(auxTitulo);
                for(i=0; i<largeTitulo; i++)
                {
                    auxTitulo[i]=toupper(auxTitulo[i]);
                }
                /*Buscamos si el titulo ya existe*/
                for(i=0; i<countMovies; i++)
                {
                    if(strcmp(auxTitulo,(moviesList+i)->titulo)==0 && (moviesList+i)->duracion!=0)
                    {
                        disponible=1;
                        break;
                    }
                }
                if(!disponible)//entra si disponible==0
                {
                    strcpy((moviesList+ubicacion)->titulo,auxTitulo);
                    printf("Titulo modificado.\n");
                }
                else
                {
                    printf("El titulo ingresado ya existe.\n");
                }
                break;
            case 2:
                printf("Nuevo genero: ");
                fflush(stdin);
                gets(auxGenero);
                validateString(auxGenero,50);
                strcpy((moviesList+ubicacion)->genero,auxGenero);
                printf("\nGenero modificado.\n");
                break;
            case 3:
                printf("Duracion (minutos): ");
                scanf("%d",&duracion);
                duracion=validateMinMax(duracion,0,400);
                (moviesList+ubicacion)->duracion=duracion;
                printf("\nDuracion modificada.\n");
                break;
            case 4:
                printf("Descripcion: ");
                fflush(stdin);
                gets(auxDescripcion);
                validateString(auxDescripcion,250);
                strcpy((moviesList+ubicacion)->descripcion,auxDescripcion);
                printf("\nPDescripcion modificada.\n");
                break;
            case 5:
                printf("Puntaje: ");
                scanf("%d",&puntaje);
                puntaje=validateMinMax(puntaje,1,10);
                (moviesList+ubicacion)->puntaje=puntaje;
                printf("\nPuntaje modificado\n");
                break;
            case 6:
                printf("Enlace de la imagen: ");
                fflush(stdin);
                gets(linkImagen);
                validateString(linkImagen,250);
                strcpy((moviesList+ubicacion)->linkImagen,linkImagen);
                printf("\nEnlace de la imagen modificado.\n");
                break;
            case 7:
                break;
            default:
                printf("ERROR: Opcion invalida.\n");
                break;
            }

            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("No se encontro la pelicula en la base de datos.\n");
    }
}

//delete the movie in memory
int borrarPelicula(EMovie *moviesList,int countMovies,int* pointerCount)
{
    int flag=0,i, largeTitulo;
    char opcion, titulo[50];

    printf("\nIngrese la pelicula a eliminar: ");
    fflush(stdin);
    gets(titulo);
    validateString(titulo,50);
    largeTitulo=strlen(titulo);
    for(i=0; i<largeTitulo; i++)
    {
        titulo[i]=toupper(titulo[i]);
    }
    for(i=0; i<countMovies; i++)
    {
        if(strcmp(titulo,(moviesList+i)->titulo)==0 && (moviesList+i)->duracion!=0)
        {
            printf("\nPelicula a eliminar:\n");

            showInfo((moviesList + i));

            printf("\nPelicula encontrada. Confirme la eliminacion (S/n): ");
            fflush(stdin);
            scanf("%c", &opcion);
            if(opcion=='s' || opcion=='S')
            {
                (moviesList+i)->duracion=0;
                printf("\n%s eliminada.\n", titulo);
                return 1;
            }
            else
            {
                printf("\n%s no ha sido eliminada.\n", titulo);
                return 0;
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("%s no esta registrada.\n", titulo);
        return 0;
    }
}

//save data as file
int saveToFile(EMovie* moviesList,int countMovies,int* pointerCount)
{

    FILE *file;
    file=fopen("moviesData.dat","wb");
    if(file == NULL)
    {
        return 1;
    }
    fwrite(pointerCount,sizeof(int),1,file);

    fwrite(moviesList,sizeof(EMovie),countMovies,file);

    fclose(file);

    return 0;
}

//create a file .html and save the data to database
void generarPagina(EMovie* moviesList, int countMovies)
{
    int i;
    FILE *file;
    file=fopen("index.html","w");
    if(file == NULL)
    {
        printf("El archivo no pudo ser creado.");
        exit(1);
    }
        fprintf(file,"<!DOCTYPE html>");
        fprintf(file,"<html lang='en'>");
        fprintf(file,"<head>");
            fprintf(file,"<title>Listado de peliculas</title>");
            fprintf(file,"<meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'>");
            fprintf(file,"<meta name='viewport' content='width=device-width, initial-scale=1'>");
            fprintf(file,"<link href='css/bootstrap.min.css' rel='stylesheet'>");
            fprintf(file,"<link href='css/custom.css' rel='stylesheet'>");
        fprintf(file,"</head>");
        fprintf(file,"<body>");
            fprintf(file,"<div class='container'>");
            fprintf(file,"<div class='row'>");
            for(i=0; i<countMovies; i++)
            {
                if((moviesList+i)->duracion!=0)
                {
                    fprintf(file,"<article class='col-md-4 article-intro'>");
                    fprintf(file,"<a href='#'>");
                    fprintf(file,"<img class='img-responsive img-rounded' src='%s' alt='%s'></a>\n",(moviesList+i)->linkImagen,(moviesList+i)->titulo);
                    fprintf(file,"<h3 style='color:#2196f3'>%s</h3>\n",(moviesList+i)->titulo);
                    fprintf(file,"<ul><li>Genero: %s</li>\n<li>Puntaje: %d</li>\n<li>Duracion: %d mins</li></ul>\n",(moviesList+i)->genero,(moviesList+i)->puntaje,(moviesList+i)->duracion);
                    fprintf(file,"<p>%s</p></article>",(moviesList+i)->descripcion);
                }
            }
        fprintf(file,"</div></div>");
            fprintf(file,"<script src='js/jquery-1.11.3.min.js'></script>");
            fprintf(file,"<script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'>");
            fprintf(file,"</script><script src='js/holder.min.js'></script>");
        fprintf(file,"</body>");
        fprintf(file,"</html>");
    fclose(file);
}

#endif // FUNCTIONS_C_INCLUDED
