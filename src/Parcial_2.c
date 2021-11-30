
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
				MsjController1(Controller1_CargarEditorialesModoTexto(listaEditoriales, &flagCarga2));
			break;

			case 3:
				Controller4_OrdenarPorAutor(listaLibros);
			break;

			case 4:
				Controller2_ImprimirListadoLibros(listaLibros, listaEditoriales);
			break;

			case 5:
				Controller3_listadoFiltrado(listaLibros, listaEditoriales);
			break;

			case 6:
				Controller5_listaMapeada(listaLibros);
			break;
		}
	}while(opcion!=7);











	return 0;
}



