#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "singly.h"
#include "doubly.h"
#include "random.h"

// Imprime la lista
void print_list( const char *, struct singly_node * );

int main(int argc, char * argv[], char *arge[])
{
	int i;

	struct singly_node *S = NULL, *saux = NULL;	// Lista principal
	struct doubly_node *D = NULL, *daux = NULL;	// Otra lista
	float  * f;

	// Generar sets de datos
	random_init();
	for(i=0; i<10; i++)
		singly_insert(&S, get_data());

	// Imprime la lista
	print_list("Lista original", S);
	
	// Genera otra lista a partir de la primera
	saux = S;
	while( saux != NULL ) {
		f = (float *) malloc(sizeof(float));
		*f = (float)((data_t *) saux->data)->r1 / ((data_t *) saux->data)->r2;
		doubly_insert(&D, f);
		saux = saux->next;
	}

	// Imprime lista de divisiones
	printf("\nLista de Divisiones\n");
	saux = S;
	daux = D;
	while( daux != NULL && saux != NULL) {
		printf( "%d / %d\t= %0.3f\n",
			(int) ((data_t *)saux->data)->r1,
			(int) ((data_t *)saux->data)->r2,
			(double) *((float *) daux->data) 
		);
		saux = saux->next;
		daux = daux->next;
	}

	singly_destroy(&S);
	doubly_destroy(&D);

	return 0;
}

void print_list( const char * title, struct singly_node *list )
{
	printf("\n%s\n", title);
	while( list ) {
		print_data((data_t *) list->data);
		list = list->next;
	}
}

