#include <stdio.h>
#include "data.h"
#include "singly.h"
#include "random.h"

/** Imprime la lista */
void print_list( const char *, struct singly_node * );

/** Ejemplo de nodos compartidos por dos listas distintas */
int main(int argc, char * argv[], char *arge[])
{
	int i;

	// Lista principal
	struct singly_node *list = NULL, *even = NULL, *aux = NULL;

	// Generar sets de datos
	random_init();
	for(i=0; i<10; i++)
		singly_insert(&list, get_data());

	// Imprime la lista
	print_list("Lista Original", list);
	
	// Crea una lista con los elementos pares.
	aux = list;
	while( aux != NULL ) {
		if(!(( (data_t *)aux->data)->r1 % 2)) {
			singly_insert(&even, aux->data);
		}
		aux = aux->next;
	}

	// Imprime lista de pares
    print_list("Lista de Pares", even);

	// Cambia el 2do elemento de la lista de los pares
	aux = even;
	while( aux != NULL ) {
		((data_t *) aux->data)->r2 = 0;
		aux = aux->next;
	}

	// Imprime las listas nuevamente
	print_list("Lista Modificada", list);
	print_list("Lista de Pares", even);

	// OJO! si quiero destruir las listas,
	// no puedo liberar los mismos datos dos veces.
	singly_unlink(&even);
	singly_destroy(&list);
	
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
