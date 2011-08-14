#include <stdio.h>
#include "data.h"
#include "singly.h"
#include "random.h"

// Elimina algunos datos de la lista
void crop_list( struct singly_node ** );
// Imprime la lista
void print_list( struct singly_node * );
// Ordena la lista
void sort_list( struct singly_node * );

int main(int argc, char * argv[], char *arge[])
{

	int i;

	// Lista principal
	struct singly_node *L = NULL;

	// Generar sets de datos
	random_init();
	for(i=0; i<10; i++)
		singly_insert(&L, get_data());

	// Imprime la lista
	printf("Lista original\n");
	print_list(L);

	// Imprime la lista ordenada
	crop_list(&L);
	printf("\nLista Recortada\n");
	print_list(L);

	// Imprime la lista ordenada
	sort_list(L);
	printf("\nLista Ordenada\n");
	print_list(L);

	return 0;
}

void print_list( struct singly_node *list )
{
	while( list ) {
		print_data((data_t *) list->data);
		list = list->next;
	}
}

void crop_list( struct singly_node ** L)
{
	struct singly_node *aux;
	aux = *L;
	while( aux )
	{
		// Una condici—n muy hardcodeada
		if( ((data_t *) aux->data)->r1 < 50 ) {
			singly_delete(L, aux);
		}
		aux = aux->next;
	}
}

void sort_list( struct singly_node * list )
{
	struct singly_node *i, *j;

	for( i=list; i->next != NULL; i=i->next)
	{
		for (j=i->next; j != NULL; j=j->next )
		{
			if( compare_data((data_t *) i->data, (data_t *) j->data ) > 0)
			{
				singly_swap(i, j);
			}
		}
	}
}
