/*
 * singly.h
 *
 *  Created on: Aug 12, 2011
 *      Author: sergio
 */

#ifndef SINGLY_H_
#define SINGLY_H_

struct singly_node {
	void * data;
	struct singly_node * next;
};

void singly_insert( struct singly_node **, void *);
void singly_delete( struct singly_node **, struct singly_node *);

#endif /* SINGLY_H_ */
