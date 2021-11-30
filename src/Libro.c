
#include "Controller.h"


eLibro* ConstructorLibroPorDefecto ()
{
	eLibro* pLibro = NULL;

	pLibro = (eLibro*) malloc (sizeof(eLibro));

	if (pLibro != NULL)
	{
		SetAllLibro(pLibro, 0, "\0", "\0", 0, 0);
	}

	return pLibro;
}

eLibro* ConstructorLibroConParametros (char* id, char* titulo, char* autor, char* precio, char* idEditorial)
{
	eLibro* pUnLibro = NULL;

	pUnLibro = ConstructorLibroPorDefecto();

	if(pUnLibro != NULL && id != NULL && titulo != NULL && autor != NULL && precio != NULL && idEditorial != NULL)
	{
		SetAllLibro(pUnLibro, atoi(id), titulo, autor, atof(precio), atoi(idEditorial));
	}

	return pUnLibro;
}

int SetIdLibro(eLibro* libro, int id)
{
	int estado;
	estado = -1;

	if(libro != NULL && id > 0)
	{
		libro->id = id;
		estado = 0;
	}

	return estado;
}

int SetTituloLibro(eLibro* libro, char* titulo)
{
	int estado;
	estado = -1;

	if (libro != NULL && titulo != NULL)
	{
		strcpy(libro->titulo, titulo);
		estado = 0;
	}

	return estado;
}

int SetAutorLibro(eLibro* libro, char* autor)
{
	int estado;
	estado = -1;

	if (libro != NULL && autor != NULL)
	{
		strcpy(libro->autor, autor);
		estado = 0;
	}

	return estado;
}

int SetPrecioLibro(eLibro* libro, float precio)
{
	int estado;
	estado = -1;

	if(libro != NULL && precio > 0)
	{
		libro->precio = precio;
		estado = 0;
	}

	return estado;
}

int SetIdEditorialLibro(eLibro* libro, int idEditorial)
{
	int estado;
	estado = -1;

	if(libro != NULL && idEditorial > 0)
	{
		libro->idEditorial = idEditorial;
		estado = 0;
	}

	return estado;
}

int SetAllLibro (eLibro* libro, int id, char* titulo, char* autor, float precio, int idEditorial)
{
	int estado;
	estado = -1;

	if(	libro != NULL &&
		SetIdLibro(libro, id) == 0 &&
		SetTituloLibro(libro, titulo) == 0 &&
		SetAutorLibro(libro, autor) == 0 &&
		SetPrecioLibro(libro, precio) == 0 &&
		SetIdEditorialLibro(libro, idEditorial) == 0)
	{
		estado = 0;
	}

	return estado;
}

int GetIdLibro (eLibro* libro, int* id)
{
	int estado;
	estado = -1;

	if (libro != NULL && id != NULL)
	{
		*id = libro->id;
		estado = 0;
	}

	return estado;
}

int GetTituloLibro (eLibro* libro, char* titulo)
{
	int estado;
	estado = -1;

	if (libro != NULL && titulo != NULL)
	{
		strcpy(titulo, libro->titulo);
		estado = 0;
	}

	return estado;
}

int GetAutorLibro (eLibro* libro, char* autor)
{
	int estado;
	estado = -1;

	if (libro != NULL && autor != NULL)
	{
		strcpy(autor, libro->autor);
		estado = 0;
	}

	return estado;
}

int GetPrecioLibro (eLibro* libro, float* precio)
{
	int estado;
	estado = -1;

	if (libro != NULL && precio != NULL)
	{
		*precio = libro->precio;
		estado = 0;
	}

	return estado;
}

int GetIdEditorialLibro (eLibro* libro, int* idEditorial)
{
	int estado;
	estado = -1;

	if (libro != NULL && idEditorial != NULL)
	{
		*idEditorial = libro->idEditorial;
		estado = 0;
	}

	return estado;
}

int GetAllLibro (eLibro* libro, int* id, char* titulo, char* autor, float* precio, int* idEditorial)
{
	int estado;
	estado = -1;

	if (libro != NULL &&
		GetIdLibro(libro, id) == 0 &&
		GetTituloLibro(libro, titulo) == 0 &&
		GetAutorLibro(libro, autor) == 0 &&
		GetPrecioLibro(libro, precio) == 0 &&
		GetIdEditorialLibro(libro, idEditorial) == 0)
	{
		estado = 0;
	}

	return estado;
}

void BorrarLibro (eLibro* libro)
{
	if (libro != NULL)
	{
		free(libro);
	}

}

int ImprimirUnLibro (eLibro* libro, eEditorial* editorial)
{
	int estado;
	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int idEditorial;
	int editorialID;
	char nombreEditorial[128];

	estado = -1;

	if (libro != NULL && editorial != NULL &&
		GetAllLibro(libro, &id, titulo, autor, &precio, &idEditorial) == 0 &&
		GetAllEditorial(editorial, &editorialID, nombreEditorial) == 0)
	{
		printf("\n %-8d %-38s %-30s $ %-12.2f %-20s", id, titulo, autor, precio, nombreEditorial);
		estado = 0;
	}

	return estado;

}

int ComprobarSiEsEditorialMinotauro (void* element)
{
	int estado;
	int idEditorial;
	estado = 0;

	eLibro* libro = NULL;

	if (element != NULL)
	{
		libro = (eLibro*) element;

		if( GetIdEditorialLibro(libro, &idEditorial) == 0 &&
			idEditorial == 4)
		{
			estado = 1;
		}
	}
	return estado;
}

int CompararNombreAutor (void* libro1, void* libro2)
{
	int estado;
	char autorA[128];
	char autorB[128];
	estado = 0;

	eLibro* libroA = NULL;
	eLibro* libroB = NULL;

	if (libro1 != NULL && libro1 != NULL)
	{
		libroA = (eLibro*) libro1;
		libroB = (eLibro*) libro2;

		if (GetAutorLibro(libroA, autorA) == 0 &&
			GetAutorLibro(libroB, autorB) == 0)
		{
			estado = stricmp(autorA,autorB);
		}
	}
	return estado;
}


int AsignarDescuentos (void* element)
{
	int estado;
	int idEditorial;
	float precioLibro;
	float precioConDescuento;
	estado = -1;

	eLibro* libro = NULL;

	if (element != NULL)
	{
		libro = (eLibro*) element;

		if(	GetIdEditorialLibro(libro, &idEditorial) == 0 &&
			GetPrecioLibro(libro, &precioLibro) == 0)
		{

			if(idEditorial == 1 && precioLibro >= 300)
			{
				precioConDescuento = precioLibro*0.8;

				SetPrecioLibro(libro, precioConDescuento);
			}
			else if(idEditorial == 2 && precioLibro <= 1500)
			{
				precioConDescuento = precioLibro*0.9;

				SetPrecioLibro(libro, precioConDescuento);
			}

			estado = 0;
		}

	}

	return estado;
}






