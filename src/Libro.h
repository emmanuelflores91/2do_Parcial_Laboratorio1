
#ifndef LIBRO_H_
#define LIBRO_H_
#include <stdio.h>
#include "Editorial.h"

typedef struct
{
	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int idEditorial;

}eLibro;

/// @brief constructor por defecto de un libro
///
/// @return = puntero al libro por defecto
eLibro* ConstructorLibroPorDefecto ();


/// @brief constructor parametrizado de un libro
///
/// @param id
/// @param titulo
/// @param autor
/// @param precio
/// @param idEditorial
/// @return = puntero a un libro
eLibro* ConstructorLibroConParametros (char* id, char* titulo, char* autor, char* precio, char* idEditorial);

/// @brief asigna el ID a un libro
///
/// @param libro
/// @param id
/// @return -1 en casor de error, 0 en caso de éxito
int SetIdLibro(eLibro* libro, int id);

/// @brief asigna el Título a un libro
///
/// @param libro
/// @param titulo
/// @return -1 en casor de error, 0 en caso de éxito
int SetTituloLibro(eLibro* libro, char* titulo);

/// @brief asigna el autor a un libro
///
/// @param libro
/// @param autor
/// @return -1 en casor de error, 0 en caso de éxito
int SetAutorLibro(eLibro* libro, char* autor);


/// @brief asigna el precio a un libro
///
/// @param libro
/// @param precio
/// @return -1 en casor de error, 0 en caso de éxito
int SetPrecioLibro(eLibro* libro, float precio);


/// @brief asigna el ID de editorial a un libro
///
/// @param libro
/// @param idEditorial
/// @return -1 en casor de error, 0 en caso de éxito
int SetIdEditorialLibro(eLibro* libro, int idEditorial);


/// @brief asigna todos los valores a un libro
///
/// @param libro
/// @param id
/// @param titulo
/// @param autor
/// @param precio
/// @param idEditorial
/// @return /// @return -1 en casor de error, 0 en caso de éxito
int SetAllLibro (eLibro* libro, int id, char* titulo, char* autor, float precio, int idEditorial);


/// @brief obtiene el ID de un libro
///
/// @param libro
/// @param id
/// @return -1 en casor de error, 0 en caso de éxito
int GetIdLibro (eLibro* libro, int* id);


/// @brief obtiene el título de un libro
///
/// @param libro
/// @param titulo
/// @return -1 en casor de error, 0 en caso de éxito
int GetTituloLibro (eLibro* libro, char* titulo);


/// @brief obtiene el autor de un libro
///
/// @param libro
/// @param autor
/// @return -1 en casor de error, 0 en caso de éxito
int GetAutorLibro (eLibro* libro, char* autor);


/// @brief obtiene el precio de un libro
///
/// @param libro
/// @param precio
/// @return -1 en casor de error, 0 en caso de éxito
int GetPrecioLibro (eLibro* libro, float* precio);


/// @brief obtiene el ID de editorial de un libro
///
/// @param libro
/// @param idEditorial
/// @return -1 en casor de error, 0 en caso de éxito
int GetIdEditorialLibro (eLibro* libro, int* idEditorial);

/// @brief obtiene todos los datos de un libro
///
/// @param libro
/// @param id
/// @param titulo
/// @param autor
/// @param precio
/// @param idEditorial
/// @return -1 en casor de error, 0 en caso de éxito
int GetAllLibro (eLibro* libro, int* id, char* titulo, char* autor, float* precio, int* idEditorial);


/// @brief libera el espacio en memoria reservado para un libro
///
/// @param libro
void BorrarLibro (eLibro* libro);

/// @brief imprime los datos de un libro
///
/// @param libro
/// /// @param editorial
/// @return -1 en caso de error, 0 en caso de éxito
int ImprimirUnLibro (eLibro* libro, eEditorial* editorial);


int ComprobarSiEsEditorialMinotauro (void* element);

int CompararNombreAutor (void* libro1, void* libro2);

int AsignarDescuentos (void* element);





#endif /* LIBRO_H_ */
