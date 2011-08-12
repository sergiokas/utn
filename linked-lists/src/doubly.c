/*
 * doubly.c
 *
 *  Created on: Aug 12, 2011
 *      Author: sergio
 */

#include "doubly.h"
#include <stdlib.h>
#include <stdio.h>

// Insert an element on the list
void doubly_insert (struct doubly_node ** list, void * data)
{
	struct doubly_node * aux;
	struct doubly_node * node;

	node = (struct doubly_node *) malloc(sizeof(struct doubly_node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;

	if( *list == NULL )
	{
		// Insert first element in an empty list.
		*list = node;
	}
	else
	{
		// Add at the end of the list
		aux = *list;
		while( aux->next != NULL )
		{
			aux = aux->next;
		}
		aux->next = node;
		node->prev = aux;
	}
}

// Delete an element from the list
void doubly_delete (struct doubly_node ** list, struct doubly_node * node)
{
	struct doubly_node * prev = NULL;
	struct doubly_node * next = NULL;

	prev = node->prev;
	next = node->next;

	// Bypass to the previous element
	if(next)
		next->prev = node->prev;

	// Bypass to the next element
	if(prev)
		prev->next = node->next;

	// If it's the first element, move the list pointer
	if( *list == node )
		*list = node->next;

	free(node->data);
	free(node);
}

// Swap two list elements.
void doubly_swap (struct doubly_node * a, struct doubly_node * b)
{
	void * aux;
	aux = a->data;
	a->data = b->data;
	b->data = aux;
}
