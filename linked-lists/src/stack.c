/*
 * stack.c
 *
 *  Created on: Aug 12, 2011
 *      Author: sergio
 */

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void stack_push (struct stack_node ** list, void * data)
{
	struct stack_node * node;
	node = (struct stack_node *) malloc(sizeof(struct stack_node));
	node->data = data;
	node->next = *list;
	*list = node;
}

void * stack_pop (struct stack_node ** list)
{
	void * data = NULL;
	struct stack_node * node = NULL;

	node = *list;
	if(node != NULL)
	{
		data = node->data;
		*list = node->next;
	}

	free(node);
	return data;
}

void stack_destroy( struct stack_node ** list ) 
{
	void * data;

	while( *list != NULL) {
		data = stack_pop( list );
		free(data);
	}
}
