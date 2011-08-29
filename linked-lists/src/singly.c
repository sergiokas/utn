/*
 * singly.c
 *
 *  Created on: Aug 12, 2011
 *      Author: sergio
 */

#include "singly.h"
#include <stdlib.h>
#include <stdio.h>

void singly_insert( struct singly_node ** list, void * data ) {
	struct singly_node * aux;
	struct singly_node * node;

	node = (struct singly_node *) malloc(sizeof(struct singly_node));
	node->data = data;
	node->next = NULL;

	if (*list == NULL)
	{
		// Create the list with the first item.
		*list = node;
	}
	else
	{
		// Append item to the list
		aux = *list;
		while( aux->next != NULL ) {
			aux = aux->next;
		}
		aux->next = node;
	}
}

void singly_delete( struct singly_node ** list, struct singly_node * node ) {
	
	struct singly_node * aux;

	if( *list == node )
	{
		*list = node->next;
	}
	else
	{
		aux = *list;
		while( aux->next != node )
		{
			aux = aux->next;
		}
		aux->next = aux->next->next;
	}

	free( node->data );
	free( node );
}

void singly_swap (struct singly_node * a, struct singly_node * b)
{
	void * aux;
	aux = a->data;
	a->data = b->data;
	b->data = aux;
}

void singly_destroy (struct singly_node ** L ) 
{
	struct singly_node *aux;

	while( *L != NULL ) {
		aux = *L;
		*L = (*L)->next;
		free(aux->data);
		free(aux);
	}
}

void singly_unlink( struct singly_node ** L )
{
	struct singly_node * aux;

	while( *L != NULL ) {
		aux = *L;
		*L = (*L)->next;
		free(aux);
	}	
}

