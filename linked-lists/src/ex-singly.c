#include <stdio.h>
#include "data.h"
#include "singly.h"
#include "random.h"

/** Elimina algunos datos de la lista */
void crop_list( struct singly_node ** );
/** Imprime la lista */
void print_list( const char *, struct singly_node * );
/** Ordena la lista */
void sort_list( struct singly_node * );

/** Ejemplo de lista simplemente enlazada **/
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
	print_list("Lista original", L);

	// Imprime la lista ordenada
	crop_list(&L);
	print_list("Lista Recortada", L);

	// Imprime la lista ordenada
	sort_list(L);
	print_list("Lista Ordenada", L);

	// Libera la memoria
	singly_destroy(&L);

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

void crop_list( struct singly_node ** L)
{
	struct singly_node *aux;
	aux = *L;
	while( aux )
	{
		// Una pregunta muy hardcodeada
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
