#include <stdlib.h>
#include "defs.h"
#include "camino.h"

// Determina si el siguiente paso en una dirección es posible
int camino(paso_t *s, char dir) {
	unsigned int p;
	p = rand()%(TOTAL_P);

	if(p<SALIDA_P)
		return SALIDA;
	else if (p<CERRADO_P)
		return CERRADO;
	else
		return ABIERTO;
}
