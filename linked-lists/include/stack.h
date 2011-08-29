/*
 * stack.h
 *
 *  Created on: Aug 12, 2011
 *      Author: sergio
 */

#ifndef STACK_H_
#define STACK_H_

struct stack_node {
	void * data;
	struct stack_node * next;
};

// Push a data item to the stack
void stack_push (struct stack_node **, void *);

// Pop a data item from the stack, return a pointer to it.
void * stack_pop (struct stack_node **);

// Delete a complete list
void stack_destroy( struct stack_node **);

#endif /* STACK_H_ */
