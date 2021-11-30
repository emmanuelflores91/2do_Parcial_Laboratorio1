
#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>

/// @brief Lee los datos de los libros desde el archivo indicado en modo texto.
///
/// @param pFile
/// @param listaLibros
/// @return -1 en caso de error, 0 en caso de éxito
int ParserLibros (FILE* pFile, LinkedList* listaLibros);


/// @brief Lee los datos de las editoriales desde el archivo indicado en modo texto.
///
/// @param pFile
/// @param listaEditoriales
/// @return -1 en caso de error, 0 en caso de éxito
int ParserEditoriales (FILE* pFile, LinkedList* listaEditoriales);



#endif /* PARSER_H_ */
