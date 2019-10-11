#include "Recoleccion.h"
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>



void procesaReciduos(Recoleccion recolecciones[],int tamanio){
	imprimirRecolecciones(recolecciones, tamanio);
	agregarKgObtenidosRecoleccion(recolecciones, tamanio);
}
