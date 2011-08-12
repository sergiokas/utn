/*
 * stack.c
 *
 *  Created on: Aug 12, 2011
 *      Author: sergio
 */

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

// Push an item into the stack
void stack_push (struct stack_node ** list, void * data)
{
	struct stack_node * node;
	node = (struct stack_node *) malloc(sizeof(struct stack_node));
	node->data = data;
	node->next = *list;
	*list = node;
}

// Pop an item from the stack, return pointer to the data
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
