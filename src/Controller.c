
#include "Controller.h"

int Controller1_CargarLibrosModoTexto (LinkedList* listaLibros, int* flagCarga)
{
	int estado;
	char nombreArchivo[51];

	FILE* pFile;

	estado =-4;

	if(*flagCarga == 0)
	{
		estado =-3;

		if(PedirCadena("\n Ingrese nombre del archivo (Max. 50 caracteres): ",
					   "\n Datos erroneos.", nombreArchivo, sizeof(nombreArchivo),2)== 0)
		{
			pFile = fopen(nombreArchivo,"r");

			estado = -2;

			if (pFile != NULL)
			{
				estado = -1;

				if(ParserLibros(pFile, listaLibros)== 0)
				{
					estado = 0;
					*flagCarga = 1;
				}
			}

			fclose(pFile);
		}
	}
	return estado;
}

int Controller2_CargarEditorialesModoTexto (LinkedList* listaEditoriales, int* flagCarga)
{
	int estado;
	char nombreArchivo[51];

	FILE* pFile;

	estado =-4;

	if(*flagCarga == 0)
	{
		estado =-3;

		if(PedirCadena("\n Ingrese nombre del archivo (Max. 50 caracteres): ",
					   "\n Datos erroneos.", nombreArchivo, sizeof(nombreArchivo),2)== 0)
		{
			pFile = fopen(nombreArchivo,"r");

			estado = -2;

			if (pFile != NULL)
			{
				estado = -1;

				if(ParserEditoriales(pFile, listaEditoriales)== 0)
				{
					estado = 0;
					*flagCarga = 1;
				}
			}

			fclose(pFile);
		}
	}
	return estado;
}

int Controller4_ImprimirListadoLibros (LinkedList* listaLibros, LinkedList* listaEditoriales)
{
	int estado;
	estado = -1;
	int lenLibros;
	int lenEditoriales;
	int	idEditorialLibro;
	int idEditorial;

	eLibro* pLibro = NULL;
	eEditorial* pEditorial = NULL;

	if (listaLibros != NULL && listaEditoriales != NULL)
	{
		lenLibros = ll_len(listaLibros);
		lenEditoriales = ll_len(listaEditoriales);


		for(int i = 0; i< lenLibros; i++)
		{

			pLibro = (eLibro*) ll_get(listaLibros, i);

			if (pLibro != NULL)
			{

				for(int j = 0; j < lenEditoriales; j++)
				{
					pEditorial = (eEditorial*) ll_get(listaEditoriales, j);


					if (pEditorial != NULL &&
						GetIdEditorialLibro(pLibro, &idEditorialLibro) == 0 &&
						GetIdEditorial(pEditorial, &idEditorial) == 0 &&
						idEditorialLibro == idEditorial)
					{
						ImprimirUnLibro(pLibro, pEditorial);

					}
				}

				estado = 0;
			}
		}
	}

	return estado;
}

void Controller6_listadoFiltrado (LinkedList* listaLibros, LinkedList* listaEditoriales)
{
	LinkedList* listaFiltrada = NULL;


	listaFiltrada = ll_filter(listaLibros,ComprobarSiEsEditorialMinotauro);

	GuardarModoTexto(listaFiltrada, "filtrado.csv");

}
void Controller3_OrdenarPorAutor (LinkedList* listaLibros)
{
	ll_sort(listaLibros, CompararNombreAutor, 1);
}

int Controller7_listaMapeada (LinkedList* listaLibros)
{
	int estado = 0;


	ll_map(listaLibros, AsignarDescuentos);

	estado = GuardarModoTexto(listaLibros, "mapeado.csv");


	return estado;

}

int GuardarModoTexto (LinkedList* lista, char* ruta)
{
	int estado;
	estado = -1;

	FILE* pFile;
	int len;
	int idLibro;
	char titulo[128];
	char autor [128];
	float precio;
	int idEditorial;
	eLibro* pLibro = NULL;

	if ( lista != NULL && ruta != NULL)
	{
		pFile = fopen(ruta,"w");

		if (pFile!= NULL)
		{
			len = ll_len(lista);
			fprintf(pFile, "id,Titulo,Autor,precio,idEditorial\n");

			for (int i = 0; i< len; i++)
			{
				pLibro = (eLibro*) ll_get(lista, i);

				if(	pLibro != NULL &&
					GetAllLibro(pLibro, &idLibro, titulo, autor, &precio, &idEditorial) == 0)
				{
					fprintf(pFile, "%d,%s,%s,%.2f,%d\n", idLibro, titulo, autor, precio, idEditorial);
					estado = 0;
				}
			}

			fclose(pFile);
		}
	}

	return estado;
}

void BorrarTodosLosLibrosYsuLista (LinkedList* listalibros)
{
	eLibro* unlibro = NULL;

	if(listalibros != NULL)
	{
		for(int i = 0; i< ll_len(listalibros); i++)
		{
			unlibro = ll_get(listalibros, i);

			if (unlibro != NULL)
			{
				BorrarLibro(unlibro);
			}
		}

		ll_deleteLinkedList(listalibros);
	}

}

void BorrarTodasLasEditorialYsuLista (LinkedList* listaEditoriales)
{
	eEditorial* unaEditorial = NULL;

	if(listaEditoriales != NULL)
	{
		for(int i = 0; i< ll_len(listaEditoriales); i++)
		{
			unaEditorial = ll_get(listaEditoriales, i);

			if (unaEditorial != NULL)
			{
				BorrarUnaEditorial(unaEditorial);
			}
		}

		ll_deleteLinkedList(listaEditoriales);
	}

}




