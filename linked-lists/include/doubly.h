/*
 * doubly.h
 *
 *  Created on: Aug 12, 2011
 *      Author: sergio
 */

#ifndef DOUBLY_H_
#define DOUBLY_H_

struct doubly_node {
	void * data;
	struct doubly_node * prev;
	struct doubly_node * next;
};

void doubly_insert (struct doubly_node **, void *);
void doubly_delete (struct doubly_node **, struct doubly_node *);
void doubly_swap (struct doubly_node *, struct doubly_node *);

#endif /* DOUBLY_H_ */
