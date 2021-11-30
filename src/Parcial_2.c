
#include "Controller.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int flagCarga = 0;
	int flagCarga2 = 0;
	LinkedList* listaLibros = ll_newLinkedList();
	LinkedList* listaEditoriales = ll_newLinkedList();

	do
	{
		MsjMenu(ShowMenu(&opcion));

		switch (opcion)
		{
			case 1:
				MsjController1(Controller1_CargarLibrosModoTexto(listaLibros, &flagCarga));
			break;

			case 2:
				MsjController1(Controller2_CargarEditorialesModoTexto(listaEditoriales, &flagCarga2));
			break;

			case 3:
				Controller3_OrdenarPorAutor(listaLibros);
			break;

			case 4:
				Controller4_ImprimirListadoLibros(listaLibros, listaEditoriales);
			break;

			case 5:
				Controller6_listadoFiltrado(listaLibros, listaEditoriales);
			break;

			case 6:
				Controller7_listaMapeada(listaLibros);
			break;
		}
	}while(opcion!=7);


	BorrarTodasLasEditorialYsuLista(listaEditoriales);

	BorrarTodosLosLibrosYsuLista(listaLibros);



	return 0;
}



