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

void stack_push (struct stack_node **, void *);
void * stack_pop (struct stack_node **);

#endif /* STACK_H_ */
