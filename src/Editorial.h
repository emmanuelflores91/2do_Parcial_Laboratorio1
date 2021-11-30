
#ifndef EDITORIAL_H_
#define EDITORIAL_H_

typedef struct
{
	int idEditorial;
	char nombre[128];

}eEditorial;

/// @brief constructor por defecto de una editorial
///
/// @return = puntero a una editorial por defecto
eEditorial* ConstructorEditorialPorDefecto ();

/// @brief constructor parametrizado de una editorial
///
/// @param idEditorial
/// @param nombre = nombre de la editorial
/// @return = puntero a una editorial
eEditorial* ConstructorEditorialConParametros (char* idEditorial, char* nombre);

/// @brief asigna el ID a una editorial
///
/// @param editorial
/// @param idEditorial
/// @return -1 en caso de error, 0 en caso de éxito.
int SetIdEditorial(eEditorial* editorial, int idEditorial);

/// @brief asigna el nombre a una editorial
///
/// @param editorial
/// @param nombre
/// @return -1 en caso de error, 0 en caso de éxito.
int SetNombreEditorial(eEditorial* editorial, char* nombre);

/// @brief obtiene el ID de una editorial
///
/// @param editorial
/// @param idEditorial
/// @return -1 en caso de error, 0 en caso de éxito.
int GetIdEditorial (eEditorial* editorial, int* idEditorial);

/// @brief obtiene el nombre de una editorial
///
/// @param editorial
/// @param nombre
/// @return -1 en caso de error, 0 en caso de éxito.
int GetNombreEditorial (eEditorial* editorial, char* nombre);


/// @brief asigna todos los datos de una editorial
///
/// @param editorial
/// @param idEditorial
/// @param nombre
/// @return -1 en caso de error, 0 en caso de éxito.
int SetAllEditorial (eEditorial* editorial, int idEditorial, char* nombre);


/// @brief obtiene todos los datos de una editorial
///
/// @param editorial
/// @param idEditorial
/// @param nombre
/// @return -1 en caso de error, 0 en caso de éxito.
int GetAllEditorial (eEditorial* editorial, int* idEditorial, char* nombre);

/// @brief libera el espacio en memoria reservado para una editorial
///
/// @param editorial
void BorrarEditorial (eEditorial* editorial);






#endif /* EDITORIAL_H_ */
