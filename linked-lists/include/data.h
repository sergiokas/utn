/*
 * data.h
 *
 *  Created on: Aug 12, 2011
 *      Author: sergio
 */

#ifndef DATA_H_
#define DATA_H_

#define DATA_R_MIN 0
#define DATA_R_MAX 100

typedef struct data_s {
	unsigned int r1;
	unsigned int r2;
	// unsigned int r3;
} data_t;

// Prototypes
data_t * get_data ();							// Generate a new dataset
int		 compare_data ( data_t *, data_t * );  	// Compare two datasets
void 	 print_data ( data_t * );				// Print dataset

#endif /* data.h */
