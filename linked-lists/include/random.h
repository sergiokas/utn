/*
 * random.h
 *
 *  Created on: Aug 12, 2011
 *      Author: sergio
 */

#ifndef RANDOM_H_
#define RANDOM_H_

/**
 * Asigna semilla al generador de numeros aleatorios
 */
void random_init();

/**
 * Genera un numero aleatorio entre el rango especificado
 */
int random_between(int, int);

#endif /* random.h */
