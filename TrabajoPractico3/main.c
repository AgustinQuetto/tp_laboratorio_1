#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include "functions.c"

int main()
{
    char saveAndExit, seguir='s';
    int countMovies=0, opcion, i;
    int* pointerCount=&countMovies;

    EMovie* moviesList;

    moviesList=(EMovie*)malloc(sizeof(EMovie)*50);
        if(moviesList==NULL)
        {
            printf("\nNo hay espacio en memoria.\n");
            exit(0);
        }

    //inicializa en 0
    for(i=0; i<countMovies; i++)
    {
        moviesList->duracion=0;
        moviesList->puntaje=0;
    }

    //carga los datos previamente guardados
    if(uploadFromMovies(moviesList,pointerCount))
    {
        printf("No se pudo abrir la base de datos.");
        exit(1);
    }

    while(seguir=='s')
    {
        printf("Peliculas cargadas en la base de datos: %d\n",countMovies);
        printf("1. Agregar pelicula\n");
        printf("2. Borrar pelicula\n");
        printf("3. Modificar pelicula\n");
        printf("4. Exportar a binario y generar pagina\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            if(countMovies%100==0)
            {
                countMovies++;
                EMovie* auxMovies;
                auxMovies=(EMovie*)realloc(moviesList,100*sizeof(EMovie));
                if(auxMovies!=NULL)
                {
                    moviesList=auxMovies;
                    agregarPelicula(moviesList,countMovies,pointerCount);
                }
                else
                {
                    exit(1);
                }
            }
            else
            {
                countMovies++;
                agregarPelicula(moviesList,countMovies,pointerCount);
            }
            break;
        case 2:
            if(borrarPelicula(moviesList,countMovies,pointerCount))
            {
                countMovies--;
            }
            break;
        case 3:
            modifyMovie(moviesList,countMovies);
            break;
        case 4:
            generarPagina(moviesList,countMovies);
            if(saveToFile(moviesList,countMovies,pointerCount))
            {
                printf("\nEl archivo no pudo ser abierto. Error.\n");
            }
            else
            {
                printf("\nSe guardo la informacion con exito.\n");
            }
            break;
        case 5:
            printf("Guardar cambios (S/n): ");
            fflush(stdin);
            scanf("%c", &saveAndExit);
            if(saveAndExit == 's')
            {
                if(saveToFile(moviesList,countMovies,pointerCount))
                {
                    printf("\nEl archivo no pudo ser abierto. Error.\n");
                }
                else
                {
                    printf("\nSe guardo la informacion con exito. Ya puede salir.\n");
                }
            }
            seguir = 'n';
            break;
        default:
            printf("Opcion invalida.\n");
            break;
        }
        system("pause");
        system("cls");
    }

    return 0;
}
