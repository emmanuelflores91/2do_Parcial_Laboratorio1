
#include "Controller.h"


int ShowMenu (int* opcion )
{
	int estado;
	estado = -1;

	printf("\n...........................................................\n");
	printf(" 1. Cargar datos libros desde un archivo .csv.\n"
			" 2. Cargar datos editoriales desde un archivo .csv.\n"
			" 3. Ordenar.\n"
			" 4. Mostrar listado de libros.\n"
			" 5. Listado de libros de la editorial MINOTAURO.\n"
			" 6. Generar el archivo de salida “mapeado.csv” luego de aplicar la función map.\n"
			" 7. Salir");
	printf("\n............................................................\n");

	if(PedirEnteroEnRango(opcion, "\n Ingrese opcion deseada: ", "\n Datos erroneos.", 1, 7, 2)== 0)
	{
		estado = 0;
	}



	return estado;
}

void MsjMenu (int estado)
{
	if (estado == -1)
	{
		printf("\n No se pudo acceder.");
	}
}

void MsjController1 (int estado)
{
	switch(estado)
	{
		case -4:
			printf("\n Error. La lista ya está cargada.");

		break;

		case -3:
			printf("\n Error en el nombre del archivo.");

		break;

		case -2:
			printf("\n Error al intentar abrir el archivo.");

		break;

		case -1:
			printf("\n Error en la carga de datos.");

		break;

		case 0:
			printf("\n Se cargaron exitosamente los datos.");

		break;
	}
}
