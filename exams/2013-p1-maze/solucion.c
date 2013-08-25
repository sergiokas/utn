#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "defs.h"
#include "camino.h"
#include "solucion.h"

// Soluciona la mazmorra
int solucion(void) {
	int i;
	paso_t * L = NULL; 
	paso_t * p = NULL;

	// Agrego paso inicial, ingresando al laberinto hacia el norte
	p = nodo();
	cerrar(p, 'S');
	avanzar(&L,p);

	// Ciclo hasta salir del laberinto
	do {
		usleep(PAUSA);
		if(L==NULL) {
			printf("Volvimos a la entrada, el laberinto no tiene salida!\n");
			exit(1);
		}
		if(L->N == ABIERTO) {
			i=intentar(&L,'N');
		}
		else if (L->S == ABIERTO) {
			i=intentar(&L,'S');	
		}
		else if (L->O == ABIERTO) {
			i=intentar(&L, 'O');
		}
		else if (L->E == ABIERTO) {
			i=intentar(&L, 'E');
		}
		else {
			printf("No se puede avanzar, retrocediendo un paso...\n");
			retroceder(&L);
		}
	} while (i!=SALIDA);
	return 0;
}

// Intenta moverse en una direccion
int intentar(paso_t ** S, char D) {
	int c;

	c = camino(*S, D);
	// Encontramos la salida
	if(c == SALIDA) {
		printf("Encontramos la salida!\n");
	}
	// El camino esta cerrado
	else if (c == CERRADO) {
		cerrar(*S, D);	// Si no se puede seguir, cerramos
		printf("Intento hacia %c, camino cerrado.\n", D);
	}
	// Se puede continuar
	else {
		cerrar(*S, D);
		avanzar(S, nodo());
		cerrar(*S, opuesto(D));
		printf("Avanzando hacia %c...\n", D);
	}

	return c;
}


// Crea un nodo nuevo
paso_t * nodo(void) {
	paso_t * p;
	p = (paso_t *) malloc(sizeof(paso_t));
	p->N = p->S = p->O = p->E = ABIERTO;
	p->next = NULL;
	return p;
}

// Cierra una direccion dada para el paso
void cerrar(paso_t * p, char D) {
	switch(D) {
		case 'N':
			p->N = CERRADO;
			break;
		case 'S':
			p->S = CERRADO;
			break;
		case 'O':
			p->O = CERRADO;
			break;
		case 'E':
			p->E = CERRADO;
			break;
		default:
			break;
	}
}

// Retorna el punto cardinal opuesto al dado
char opuesto(char D) {
	if(D=='N') return 'S';
	if(D=='S') return 'N';
	if(D=='O') return 'E';
	if(D=='E') return 'O';
	return '\0';
}

// Agrego un paso a la lista (stack)
int avanzar(paso_t ** S, paso_t * p) {
	if (*S == NULL) {
		*S = p; // Lista vacía
	}
	else {
		p->next = *S; // Agrego el elemento al comienzo
		*S = p;
	}
	return 0;
}

// Retrocede un paso en la lista
void retroceder(paso_t ** S) {
	if(*S != NULL) {
		paso_t * aux;
		aux = *S;
		*S = aux->next;
		free(aux);
	}
}

