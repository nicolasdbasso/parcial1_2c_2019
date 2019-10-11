#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"
#include "Utils.h"
#define TEXT_SIZE 51

void iniciarClientes(Cliente clientes[], int tam) {
	int i;
	for (i = 0; i < tam; i++) {
		clientes[i].isEmpty = 0;
	}
}

int altaCliente(Cliente *clientes, int len, int *countID) {
	int retorno = -1;
	int position;
	if (clientes != NULL && len > 0 && countID != NULL) {
		if (buscarClienteLibre(clientes, len, &position) == -1) {
			printf("\nNo hay lugares vacios");
		} else {
			(*countID)++;
			clientes[position].id = *countID;
			clientes[position].isEmpty = 1;
			Utils_getCuit("Ingrese el CUIT de la empresa\n: ", "\nError", 1,
					clientes[position].cuit);
			Utils_getString("Ingrese la direccion de la empresa\n: ", "\nError",
					1, TEXT_SIZE, 1, clientes[position].direccion);
			Utils_getString("Ingrese la localidad de la empresa\n: ", "\nError",
					1, TEXT_SIZE, 1, clientes[position].localidad);
			printf(
					"\n ID: %d\n Nombre de la empresa: %s\n CUIT: %d\n Direccion: %s\n Localidad: %s",
					clientes[position].id, clientes[position].nombre,
					clientes[position].cuit, clientes[position].direccion,
					clientes[position].localidad);
			retorno = 0;
		}
	}
	return retorno;
}

int buscarClienteLibre(Cliente clientes[], int tam, int *position) {
	int i;
	int retorno = -1;
	for (i = 0; i < tam; i++) {
		if (clientes[i].isEmpty == 0) {
			retorno = 0;
			*position = i;
			break;
		}
	}
	return retorno;
}

int modificarCliente(Cliente clientes[], int len) {
	int reintentos;
	int retorno = -1;
	int position;
	int id;                                      //cambiar si no se busca por ID
	int opcion;
	if (clientes != NULL && len > 0) {
		Utils_getNumero(&id,"\nID a modificar: ", "\nError", 1, 100);
		if (buscarCliente(clientes, len, id, &position) == -1)
				{
			printf("\nNo existe este ID");
		} else {
			do {
				Utils_getNumero(&opcion,"\nSolo puedes modificar la direccion(1) y localidad(2) (1, 2 o 3 para salir)", "\nError", 1, 100);
				switch (opcion) {
				case '1':
					Utils_getString("\nIngrese la nueva direccion: ", "\nError", 1, TEXT_SIZE, reintentos, &clientes[position].direccion);
					break;
				case '2':
					Utils_getString("\nIngrese la nueva localidad: ", "\nError", 1, TEXT_SIZE, reintentos, &clientes[position].localidad);
					break;
				default:
					printf("\nOpcion no valida");
				}
			} while (opcion != 3);
			retorno = 0;
		}
	}
	return retorno;

}

int imprimirClientes(Cliente *clientes, int length) {

	int retorno = -1;
	int i;
	if (clientes != NULL && length >= 0) {
		for (i = 0; i < length; i++) {
			if (clientes[i].isEmpty == 0)
				continue;
			else
				printf(
						"\n ID: %d\n Nombre de la empresa: %s\n CUIT: %d\n Direccion: %s\n Localidad: %s",
						clientes[i].id, clientes[i].nombre,
						clientes[i].cuit, clientes[i].direccion,
						clientes[i].localidad);
		}
		retorno = 0;
	}
	return retorno;
}

int buscarCliente(Cliente clientes[], int len, int idSearch, int *position)
{
	int retorno = -1;
	int i;
	if (clientes != NULL && len >= 0) {
		for (i = 0; i < len; i++) {
			if (clientes[i].isEmpty == 1)
				continue;
			else if (clientes[i].id == idSearch)
					{
				retorno = 0;
				*position = i;
				break;
			}
		}
	}
	return retorno;
}


int bajaCliente(Cliente* clientes, int len)
{
    int retorno=-1;
    int position;
    int id;
    int respuesta;
    if(clientes!=NULL && len>0)
    {
        Utils_getNumero(&id,"\nID a dar de baja: ","\nError",1,100);
        if(buscarCliente(clientes,len,id,&position)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
            	clientes[position].id=0;
            	clientes[position].cuit=0;
            	strcpy(clientes[position].nombre,"");
            	strcpy(clientes[position].direccion,"");
            	strcpy(clientes[position].localidad,"");
            	clientes[position].isEmpty=0;
                retorno=0;
        	}
    return retorno;
}
