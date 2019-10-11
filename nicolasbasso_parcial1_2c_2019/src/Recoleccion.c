#include "Recoleccion.h"

#include <stdio.h>

#include "Cliente.h"
#include "Utils.h"


void iniciarRecolecciones(Recoleccion recolecciones[], int tam) {
	int i;
	for (i = 0; i < tam; i++) {
		recolecciones[i].isEmpty = 0;
	}
}
int buscarRecoleccionLibre(Recoleccion recolecciones[], int tam, int *posicion) {
	int i;
	int retorno = -1;
	for (i = 0; i < tam; i++) {
		if (recolecciones[i].isEmpty == 0) {
			retorno = 0;
			*posicion = i;
			break;
		}
	}
	return retorno;
}

int altaRecolecciones(Recoleccion *recolecciones, int len, int *countID, int clienteID) {
	int retorno = -1;
	int kgAProcesar;
	int posicion;
	if (recolecciones != NULL && len > 0 && countID != NULL) {
		if (buscarRecoleccionLibre(recolecciones, len, &posicion) == -1) {
			printf("\nNo hay lugares vacios");
		} else {
			(*countID)++;
			recolecciones[posicion].id = *countID;
			recolecciones[posicion].clienteId = clienteID;
			recolecciones[posicion].isEmpty = 1;
			recolecciones[posicion].hdpe = 0;
			recolecciones[posicion].ldpe = 0;
			recolecciones[posicion].pp = 0;
			recolecciones[posicion].estado = 0;
			Utils_getNumero(&kgAProcesar,"\nKg a procesar: ","\nError",1,100);
			recolecciones[posicion].cantKgTotales = kgAProcesar;
			printf(
					"\n ID: %i\n ClienteID asociado: %i\n KG a procesar: %i",
					recolecciones[posicion].id, clienteID,recolecciones[posicion].cantKgTotales);
			retorno = 0;
		}
	}
	return retorno;
}

int imprimirRecolecciones(Recoleccion *recolecciones, int length) {

	int retorno = -1;
	int i;
	if (recolecciones != NULL && length >= 0) {
		for (i = 0; i < length; i++) {
			if (recolecciones[i].isEmpty == 0)
				continue;
			else
				printf(
						"\n ID Pedido: %d\n ID Cliente asociado: %d",
						recolecciones[i].id, recolecciones[i].clienteId);
		}
	}
	return retorno;
}

int buscarRecoleccion(Recoleccion recolecciones[], int len, int idSearch, int *position)
{
	int retorno = -1;
	int i;
	if (recolecciones != NULL && len >= 0) {
		for (i = 0; i < len; i++) {
			if (recolecciones[i].isEmpty == 1)
				continue;
			else if (recolecciones[i].id == idSearch)
					{
				retorno = 0;
				*position = i;
				break;
			}
		}
	}
	return retorno;
}


int agregarKgObtenidosRecoleccion(Recoleccion recolecciones[], int len) {
	int reintentos;
	int retorno = -1;
	int position;
	int id;                                      //cambiar si no se busca por ID
	int opcion;
	if (recolecciones != NULL && len > 0) {
		Utils_getNumero(&id,"\nID a modificar: ", "\nError", 1, 100);
		if (buscarRecoleccion(recolecciones, len, id, &position) == -1)
				{
			printf("\nNo existe este ID");
		} else {
			do {
				recolecciones[position].estado= 1;
				printf("AGREGAR LOS KG OBTENIDOS:");
				Utils_getNumero(&recolecciones[position].hdpe,"\nKg obtenidos de HDPE: ","\nError",1,100);
				Utils_getNumero(&recolecciones[position].ldpe,"\nKg obtenidos de LDPE: ","\nError",1,100);
				Utils_getNumero(&recolecciones[position].pp,"\nKg obtenidos de PP: ","\nError",1,100);
			} while (opcion != 3);
			retorno = 0;
		}
	}
	return retorno;

}




