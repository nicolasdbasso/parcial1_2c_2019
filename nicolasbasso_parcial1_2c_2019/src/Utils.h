#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

int Utils_getString(char *msg, char *msgError, int min, int max,int *reintentos, char *resultado);
int Utils_getNumero(int *input, char message[], char eMessage[], int lowLimit,
		int hiLimit);
int Utils_getCuit(char *msg, char *msgError, int reintentos, char *input);
int Utils_esCuitValido(char *stringRecibido);

