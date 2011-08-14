/*
 * doubly.h
 *
 *  Created on: Aug 12, 2011
 *      Author: sergio
 */

#ifndef DOUBLY_H_
#define DOUBLY_H_

// Nodo para una lista doblemente enlazada
struct doubly_node {
	void * data;
	struct doubly_node * prev;
	struct doubly_node * next;
};

// Inserta un nodo en la lista
void doubly_insert (struct doubly_node **, void *);

// Elimina un nodo de la lsita
void doubly_delete (struct doubly_node **, struct doubly_node *);

// Intercambia los datos de dos nodos de una lista
void doubly_swap (struct doubly_node *, struct doubly_node *);

// Inserta un nuevo nodo antes del nodo especificado
void doubly_insert_before( struct doubly_node *, void *);

// Inserta un nuevo nodo después del nodo especificado
void doubly_insert_after( struct doubly_node *, void *);

#endif /* DOUBLY_H_ */
