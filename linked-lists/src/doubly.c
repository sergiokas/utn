/*
 * doubly.c
 *
 *  Created on: Aug 12, 2011
 *      Author: sergio
 */

#include "doubly.h"
#include <stdlib.h>
#include <stdio.h>

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

void doubly_swap (struct doubly_node * a, struct doubly_node * b)
{
	void * aux;
	aux = a->data;
	a->data = b->data;
	b->data = aux;
}

void doubly_insert_before( struct doubly_node * l, void * data) {
	struct doubly_node * node;

	if( l != NULL )
	{
		node = (struct doubly_node *) malloc(sizeof(struct doubly_node));
		node->data = data;
		node->next = l;
		node->prev = l->prev;
		if( l->prev != NULL )
		{
			l->prev->next = node;
		}
		l->prev = node;
	}
}

void doubly_insert_after( struct doubly_node * l, void * data) {
	struct doubly_node * node;

	if( l != NULL )
	{
		node = (struct doubly_node *) malloc(sizeof(struct doubly_node));
		node->data = data;
		node->prev = l;
		node->next = l->next;
		if( l->next != NULL )
		{
			l->next->prev = node;
		}
		l->next = node;
	}
}

void doubly_destroy (struct doubly_node ** L )
{
    struct doubly_node *aux;

    while( *L != NULL ) {
        aux = *L;
        *L = (*L)->next;
        free(aux->data);
        free(aux);
    }
}

