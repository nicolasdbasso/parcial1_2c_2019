#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "Utils.h"

int Utils_getString(char *msg, char *msgError, int min, int max,
		int *reintentos, char *resultado) {
	int retorno = -1;
	char bufferStr[max + 10];

	if (msg != NULL && msgError != NULL
			&& min <= max&& reintentos>=0 && resultado!=NULL) {
		do {
			printf("%s", msg);
			fgets(bufferStr, sizeof(bufferStr), stdin);
			bufferStr[strlen(bufferStr) - 1] = '\0';

			if (strlen(bufferStr) >= min && strlen(bufferStr) < max) {
				strncpy(resultado, bufferStr, max);
				retorno = 0;
				break;
			}
			printf("%s 1", msgError);
			(*reintentos)--;
		} while ((*reintentos) >= 0);
	}
	return retorno;
}

int Utils_getNumero(int *input, char message[], char eMessage[], int lowLimit,
		int hiLimit) {
	int flag = -1;
	int entero;

	do {
		printf("%s\n", message);
		scanf("%d", &entero);

		if ((entero >= lowLimit) && (entero <= hiLimit)) {
			flag = 0;
			printf("El numero fue cargado con exito\n\n");
			*input = entero;
		} else {
			printf("%s\n", eMessage);
		}
	} while (flag == -1);

	return flag;
}

int Utils_getCuit(char *msg, char *msgError, int reintentos, char *input) {
	int maxSize = 14; //con guiones 13 elementos
	int minSize = 11;  // sin puntos
	int retorno = -1;
	char bufferStr[maxSize];

	if (msg != NULL && msgError != NULL
			&& minSize < maxSize&& reintentos>=0 && input!=NULL) {
		do {
			if (!Utils_getString(msg, msgError, minSize, maxSize, &reintentos,
					bufferStr)) //==0 sin errores !0
					{
				if (Utils_esCuitValido(bufferStr) == 1) {
					strncpy(input, bufferStr, maxSize);
					retorno = 0;
					break;
				} else {
					printf("%s 2", msgError);
					reintentos--;
				}
			}
		} while (reintentos >= 0);
	}
	return retorno;
}

int Utils_esCuitValido(char *stringRecibido) {
	int retorno = 1; // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
	int i;
	int j;
	char buffer[14];
	strncpy(buffer, stringRecibido, 14);

	for (i = 0; buffer[i] != '\0'; i++) {
		if ((buffer[i] < '0' || buffer[i] > '9') && (buffer[i] != '-')) // chequeo que solo sean numeros o -
				{
			retorno = 0;
			break;
		}

		if (buffer[i] == '-')  //elimino los -
				{
			for (j = i; buffer[j] != '\0'; j++) {
				strncpy(&buffer[j], &buffer[j + 1], 1);
			}
		}
	}

	int digitos[10] = { 2, 3, 4, 5, 6, 7, 2, 3, 4, 5 };
	int acumulado = 0;
	int verificador;

	for (i = 0; i < strlen(buffer - 1); i++) {
		acumulado += buffer[i] * digitos[i];
	}

	verificador = 11 - (acumulado % 11);
	if (verificador == 11) {
		verificador = 0;
	}

	if (buffer[11] != verificador) {
		retorno = 0;
	}

	return retorno;
}

