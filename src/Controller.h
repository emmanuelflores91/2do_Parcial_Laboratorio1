
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"
#include "Libro.h"
#include "Editorial.h"
#include "Mensajes.h"
#include "Parser.h"
#include "myFunctions.h"

/// @brief carga los datos de los libros en modo texto desde el archivo libros.csv
///
/// @param listaLibros
/// @param flagCarga = para verificar si la lista ya fue cargada
/// @return -1 en caso de error, 0 en caso de éxito
int Controller1_CargarLibrosModoTexto (LinkedList* listaLibros, int* flagCarga);


int Controller2_CargarEditorialesModoTexto (LinkedList* listaEditoriales, int* flagCarga);

/// @brief imprime los datos de todos los libros de la lista
///
/// @param listaLibros
/// @return -1 en caso de error, 0 en caso de éxito
int Controller4_ImprimirListadoLibros (LinkedList* listaLibros, LinkedList* listaEditoriales);

void Controller6_listadoFiltrado (LinkedList* listaLibros, LinkedList* listaEditoriales);

void Controller3_OrdenarPorAutor (LinkedList* listaLibros);

int Controller7_listaMapeada (LinkedList* listaLibros);

int GuardarModoTexto (LinkedList* lista, char* ruta);

void BorrarTodosLosLibrosYsuLista (LinkedList* listalibros);

void BorrarTodasLasEditorialYsuLista (LinkedList* listaEditoriales);








#endif /* CONTROLLER_H_ */
