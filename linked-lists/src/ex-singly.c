#include <stdio.h>
#include "data.h"
#include "singly.h"
#include "random.h"

void print_list( struct singly_node * );

int main(int argc, char * argv[], char *arge[]) {

	int i;

	// Main list
	struct singly_node *L = NULL;
	struct singly_node *aux;

	// Generate datasets
	random_init();
	for(i=0; i<10; i++)
	{
		singly_insert(&L, get_data());
	}

	// Print the list
	printf("Original List\n");
	print_list(L);

	// Delete some data
	aux = L;
	while( aux )
	{
		// A very hardcoded condition
		if( ((data_t *) aux->data)->r1 < 50 ) {
			singly_delete( &L, aux );
		}
		aux = aux->next;
	}

	// Print the list again
	printf("\nCropped List\n");
	print_list(L);
	
	return 0;
}

void print_list( struct singly_node *list ) {
	while( list ) {
		print_data((data_t *) list->data);
		list = list->next;
	}
}

