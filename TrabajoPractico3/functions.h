#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[150];
    int puntaje;
    char linkImagen[250];
}EMovie;


/** \brief Print movies data.
 *
 * \param moviesList EMovie*
 *
 */
void showInfo(EMovie *moviesList);


/** \brief Print movies data.
 *
 * \param moviesList EMovie*
 *
 */
void validateString(char valid[], int);


/** \brief Print movies data.
 *
 * \param moviesList EMovie*
 * \return 1 if true, 0 if false
 */
int validateMinMax(int ,int ,int );


/** \brief Take space from dynamic memory.
 *
 * \param moviesList EMovie*
 * \return int 1 if I can find space in the dynamic memory.
 *
 */
int getSpace(EMovie *moviesList,int);


/** \brief Load from the binary file of the movies in dynamic memory
 *
 * \param moviesList EMovie*
 * \return int Returns 1 if the file could not be read or created | 0 if possible.
 *
 */
int uploadFromMovies(EMovie *moviesList,int*);


/** \brief Add a movie to memory.
 *
 * \param moviesList EMovie*
 * \return void
 *
 */
void agregarPelicula(EMovie *moviesList,int,int*);


/** \brief Modify data from memory to .dat file
 *
 * \param moviesList EMovie*
 * \return void
 *
 */
 void modifyMovie(EMovie *moviesList,int);


/** \brief Delete a specific movie from memory.
 *
 * \param moviesList EMovie*
 * \return 1 if delete a movie || 0 if not possible
 *
 */
int borrarPelicula(EMovie *moviesList,int,int*);


/** \brief Create a HTML document from memory data.
 *
 * \param moviesList EMovie*
 * \return void
 *
 */
void generarPagina(EMovie* moviesList, int);


/** \brief Save array to .dat file
 *
 * \param moviesList EMovie*
 * \return void
 *
 */
int saveToFile(EMovie* moviesList,int,int*);

#endif // FUNCIONES_H_INCLUDED
