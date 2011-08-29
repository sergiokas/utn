#include <stdio.h>
#include "data.h"
#include "singly.h"
#include "random.h"

// Elimina algunos datos de la lista
void crop_list( struct singly_node ** );
// Imprime la lista
void print_list( const char *, struct singly_node * );
// Ordena la lista
void sort_list( struct singly_node * );

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

	getchar(); // Pause

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
