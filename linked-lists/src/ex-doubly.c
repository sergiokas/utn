#include <stdio.h>
#include "data.h"
#include "doubly.h"
#include "random.h"

// Elimina algunos elementos de la lista
void crop_list( struct doubly_node ** );

// Ordena la lista
void sort_list( struct doubly_node * );

// Imprime la lista
void print_list( struct doubly_node * );

int main(int argc, char * argv[], char *arge[]) {

	int i;
	// Lista principal
	struct doubly_node *L = NULL;

	// Genera sets de datos
	random_init();
	for(i=0; i<10; i++)
		doubly_insert(&L, get_data());

	// Imprime la lista original
	printf("Lista original\n");
	print_list(L);

	// Imprime la lista con algunos datos removidos
	crop_list(&L);
	printf("\nLista recortada\n");
	print_list(L);

	// Imprime la lista ordenada
	sort_list(L);
	printf("\nLista ordenada\n");
	print_list(L);

	// Imprime la lista con algunos datos ordenados
	doubly_insert_after( L->next, get_data());
	doubly_insert_before( L->next, get_data());
	printf("\nLista con elementos adicionales\n");
	print_list(L);

	return 0;
}

void crop_list( struct doubly_node ** L ) {
	struct doubly_node * aux;
	aux = *L;
	while( aux )
	{
		// Condici—n MUY hardcodeada
		if( ((data_t *) aux->data)->r1 < 50 ) {
			doubly_delete( L, aux );
		}
		aux = aux->next;
	}
}

void sort_list( struct doubly_node * list ) {
	struct doubly_node *i, *j;

	for( i=list; i->next != NULL; i=i->next)
	{
		for (j=i->next; j != NULL; j=j->next )
		{
			if( compare_data((data_t *) i->data, (data_t *) j->data ) > 0)
			{
				doubly_swap(i, j);
			}
		}
	}

}

void print_list( struct doubly_node *list ) {
	while( list ) {
		print_data((data_t *) list->data);
		list = list->next;
	}
}
