/*
 * singly.h
 *
 *  Created on: Aug 12, 2011
 *      Author: sergio
 */

#ifndef SINGLY_H_
#define SINGLY_H_

// Nodo para una lista simplemente enlazada
struct singly_node {
	void * data;
	struct singly_node * next;
};

// Inserta un nodo en la lista
void singly_insert( struct singly_node **, void *);

// Elimina un nodo de la lista
void singly_delete( struct singly_node **, struct singly_node *);

// Intercambia los datos dos nodos de una lista
void singly_swap (struct singly_node *, struct singly_node *);

#endif /* SINGLY_H_ */
