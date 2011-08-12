/*
 * data.c
 *
 *  Created on: Aug 12, 2011
 *      Author: sergio
 */

#include "data.h"
#include "random.h"
#include <stdio.h>
#include <stdlib.h>

// Generate a new dataset
data_t * get_data() {
	data_t * d;
	d = (data_t *) malloc(sizeof(data_t));
	d->r1 = random_between(DATA_R_MIN, DATA_R_MAX);
	d->r2 = random_between(DATA_R_MIN, DATA_R_MAX);
	// d->r3 = random_between(DATA_R_MIN, DATA_R_MAX);
	return d;
}

// Compare two datasets
int compare_data(data_t * a, data_t * b) {
	return ( 100*(a->r1 - b->r1) + (a->r2 - b->r2) );
	// return ( 10000*(a->r1 - b->r1) + 100*(a->r2 - b->r2) + (a->r3 - b->r3) );
}

// Print dataset
void print_data(data_t * d) {
	printf("%d\t%d\n", d->r1, d->r2);
	// printf("%d\t%d\t%d\n", d->r1, d->r2, d->r3);
}
