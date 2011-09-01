/*
 * data.h
 *
 *  Created on: Aug 12, 2011
 *      Author: sergio
 */

#ifndef DATA_H_
#define DATA_H_

/** Minimo para rango de numeros aleatorios **/
#define DATA_R_MIN 0
/** Maximo para rango de numeros aleatorios **/
#define DATA_R_MAX 100

/**
 * Estructura de datos. Solamente dos enteros aleatorios, como ejemplo.
 */
typedef struct data_s {
	unsigned int r1;
	unsigned int r2;
} data_t;

/** Genera un nuevo data set */
data_t * get_data ();
/** Compara dos data sets para ordenamiento */
int		 compare_data ( data_t *, data_t * );
/** Imprime un data set **/
void 	 print_data ( data_t * );

#endif /* data.h */
