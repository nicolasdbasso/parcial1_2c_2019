#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#define TEXT_SIZE 51

typedef struct {
	int id;
	char nombre[TEXT_SIZE];
	int cuit;
	char direccion[TEXT_SIZE];
	char localidad[TEXT_SIZE];
	int isEmpty;
} Cliente;

void iniciarClientes(Cliente clientes[], int tam);
int altaCliente(Cliente *clientes, int len, int *countID);
int buscarClienteLibre(Cliente clientes[], int tam, int *position);
int modificarCliente(Cliente clientes[], int len);
int buscarCliente(Cliente clientes[], int len, int idSearch, int *position);
int bajaCliente(Cliente* clientes, int len);
