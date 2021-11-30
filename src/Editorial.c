
#include "Controller.h"


eEditorial* ConstructorEditorialPorDefecto ()
{
	eEditorial* pEditorial = NULL;

	pEditorial = (eEditorial*) malloc (sizeof(eEditorial));

	if (pEditorial != NULL)
	{
		SetAllEditorial(pEditorial, 0, "\0");
	}

	return pEditorial;
}

eEditorial* ConstructorEditorialConParametros (char* idEditorial, char* nombre)
{
	eEditorial* pUnaEditorial = NULL;

	pUnaEditorial = ConstructorEditorialPorDefecto();

	if(pUnaEditorial != NULL && idEditorial != NULL && nombre != NULL)
	{
		SetAllEditorial(pUnaEditorial, atoi(idEditorial), nombre);
	}

	return pUnaEditorial;
}


int SetIdEditorial(eEditorial* editorial, int idEditorial)
{
	int estado;
	estado = -1;

	if(editorial != NULL && idEditorial > 0)
	{
		editorial->idEditorial = idEditorial;
		estado = 0;
	}

	return estado;
}

int SetNombreEditorial(eEditorial* editorial, char* nombre)
{
	int estado;
	estado = -1;

	if (editorial != NULL && nombre != NULL)
	{
		strcpy(editorial->nombre, nombre);
		estado = 0;
	}

	return estado;
}

int GetIdEditorial (eEditorial* editorial, int* idEditorial)
{
	int estado;
	estado = -1;


	if (editorial != NULL && idEditorial != NULL)
	{
		*idEditorial = editorial->idEditorial;
		estado = 0;
	}

	return estado;
}

int GetNombreEditorial (eEditorial* editorial, char* nombre)
{
	int estado;
	estado = -1;

	if (editorial != NULL && nombre != NULL)
	{
		strcpy(nombre, editorial->nombre);
		estado = 0;
	}

	return estado;
}

int SetAllEditorial (eEditorial* editorial, int idEditorial, char* nombre)
{
	int estado;
	estado = -1;

	if(	editorial != NULL && nombre != NULL &&
		SetIdEditorial(editorial, idEditorial) == 0 &&
		SetNombreEditorial(editorial, nombre) == 0)
	{
		estado = 0;
	}

	return estado;
}

int GetAllEditorial (eEditorial* editorial, int* idEditorial, char* nombre)
{
	int estado;
	estado = -1;

	if (editorial != NULL && nombre != NULL &&
		GetIdEditorial(editorial, idEditorial) == 0 &&
		GetNombreEditorial(editorial, nombre) == 0 )
	{
		estado = 0;
	}

	return estado;
}


