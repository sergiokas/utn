#include <stdio.h>
#include "data.h"
#include "doubly.h"
#include "random.h"

// Crop some list elements
void crop_list( struct doubly_node ** L );
// Sort the list
void sort_list( struct doubly_node * );
// Print list
void print_list( struct doubly_node * );

int main(int argc, char * argv[], char *arge[]) {

	int i;
	// Main list
	struct doubly_node *L = NULL;

	// Generate datasets
	random_init();
	for(i=0; i<10; i++)
		doubly_insert(&L, get_data());

	// Print the list
	printf("Original List\n");
	print_list(L);

	// Print the list with some deleted data
	crop_list(&L);
	printf("\nCropped List\n");
	print_list(L);

	// Print the sorted list
	sort_list(L);
	printf("\nSorted List\n");
	print_list(L);

	return 0;
}

// Crop some list elements
void crop_list( struct doubly_node ** L ) {
	struct doubly_node * aux;
	aux = *L;
	while( aux )
	{
		// A very hardcoded condition
		if( ((data_t *) aux->data)->r1 < 50 ) {
			doubly_delete( L, aux );
		}
		aux = aux->next;
	}
}

// Sort list with data criteria
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

// Print entire list
void print_list( struct doubly_node *list ) {
	while( list ) {
		print_data((data_t *) list->data);
		list = list->next;
	}
}
