#include <stdio.h>
#include <stdlib.h>

#include "Cliente.h"
#include "Informes.h"
#include "Recoleccion.h"
#include "Utils.h"

#define TAMANIO_CLIENTES 100
#define TAMANIO_PEDIDOS 1000

int menu();

int main(void) {
	char continuar = 's';
	int idSeleccionado;
	int posicion;
	Cliente clientes[TAMANIO_CLIENTES];
	iniciarClientes(clientes, TAMANIO_CLIENTES);
	Recoleccion recolecciones[TAMANIO_PEDIDOS];
	iniciarRecolecciones(recolecciones, TAMANIO_PEDIDOS);
	int countIDClientes = 0;
	int countIDRecolecciones = 0;

	do {

		switch (menu()) {
		case 1:
			printf("\nAlta cliente\n\n");
			if (altaCliente(clientes, TAMANIO_CLIENTES, countIDClientes) == 0)
				printf("\nSe ha efectuado el alta del cliente.\n\n");
			else
				printf("\nNo se efectuo el alta del cliente.\n\n");
			break;
		case 2:
			printf("\nModificar datos de cliente\n\n");
			imprimirClientes(clientes, TAMANIO_CLIENTES);
			if(modificarCliente (clientes, TAMANIO_CLIENTES)==0)
				printf("\nSe ha efectuado la modificacion del cliente.\n\n");
			else
				printf("\nNo se efectuo la modificacion del cliente.\n\n");
			break;
		case 3:
			printf("\nBaja de cliente\n\n");
			imprimirClientes(clientes, TAMANIO_CLIENTES);
			if (bajaCliente(clientes,TAMANIO_CLIENTES)==0)
				printf("\nSe ha efectuado la baja del cliente.\n\n");
			else
				printf("\No se efectuo la baja del cliente.\n\n");
			break;
		case 4:
			printf("\nCrear pedido de recoleccion\n\n");
			imprimirClientes(clientes, TAMANIO_CLIENTES);
			Utils_getNumero(&idSeleccionado,"\nID seleccionado: ", "\nError", 1,100);
			if (buscarCliente(clientes, TAMANIO_CLIENTES, idSeleccionado, &posicion) == -1) {
				printf("\nNo existe este ID");
			} else {
				if (altaRecolecciones(recolecciones, TAMANIO_PEDIDOS, countIDRecolecciones, idSeleccionado) == 0)
					printf("\nSe ha efectuado el alta del pedido de recoleccion.\n\n");
				else
					printf("\nNo se efectuo el alta del pedido de recoleccion.\n\n");
			}
			break;
		case 5:
			printf("\nProcesar residuos\n\n");
			procesaReciduos(recolecciones, TAMANIO_CLIENTES);
			break;
		case 6:
			printf("\nImprimir pedidos pendientes\n\n");
			break;
		case 7:
			printf("\nImprimir imprimir pedidos procesados\n\n");
			break;
		case 8:
			printf("\nSalir\n\n");
			break;
		}
		printf("\nDesea continuar 's': ");
		scanf("%c", &continuar);
	} while (continuar == 's');

	return 0;
}

int menu() {
	int opcion;
	system("cls");
	printf("\nBIENVENIDO\n");
	printf("\n1--Alta cliente\n");
	printf("2--Modificar datos de cliente\n");
	printf("3--Baja de cliente\n");
	printf("4--Crear pedido de recoleccion\n");
	printf("5--Procesar residuos:\n");
	printf("5- Imprimir clientes:\n");
	printf("6--Imprimir pedidos pendientes:\n");
	printf("7--Imprimir imprimir pedidos procesados:\n");
	printf("8--SALIR\n\n");
	printf("\n Ingrese opcion: ");
	scanf("%d", &opcion);
	return opcion;
}
