
#include "Controller.h"
//#include "Parser.h"
//#include <stdio.h>

int ParserLibros (FILE* pFile, LinkedList* listaLibros)
{
	int estado;
	char id[12];
	char titulo[128];
	char autor[128];
	char precio[12];
	char idEditorial[12];

	eLibro* pLibro = NULL;

	estado = -1;

	fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^\n]\n",id, titulo, autor, precio, idEditorial);


	while (!feof(pFile))
	{
		fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^\n]\n",id, titulo, autor, precio, idEditorial);

		pLibro = ConstructorLibroConParametros(id, titulo, autor, precio, idEditorial);

		if (pLibro != NULL && ComprobarSiEsEntero(id) &&
			ComprobarSiEsNombre(autor) &&
			ComprobarSiEsFlotante(precio))
		{

			if(ll_add(listaLibros, pLibro)== 0)
			{
				estado = 0;
			}
			else
			{
				BorrarLibro(pLibro);
			}
		}
	}

	return estado;

}

int ParserEditoriales (FILE* pFile, LinkedList* listaEditoriales)
{
	int estado;
	char idEditorial[12];
	char nombre[128];


	eEditorial* pEditorial = NULL;

	estado = -1;

	fscanf(pFile,"%[^,], %[^\n]\n",idEditorial, nombre);

	while (!feof(pFile))
	{
		fscanf(pFile,"%[^,], %[^\n]\n",idEditorial, nombre);

		pEditorial = ConstructorEditorialConParametros(idEditorial, nombre);

		if (pEditorial != NULL && ComprobarSiEsEntero(idEditorial) &&
			ComprobarSiEsNombre(nombre))
		{

			if(ll_add(listaEditoriales, pEditorial)== 0)
			{
				estado = 0;
			}
			else
			{
				BorrarUnaEditorial(pEditorial);
			}
		}
	}

	return estado;

}
