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

data_t * get_data() {
	data_t * d;
	d = (data_t *) malloc(sizeof(data_t));
	d->r1 = random_between(DATA_R_MIN, DATA_R_MAX);
	d->r2 = random_between(DATA_R_MIN, DATA_R_MAX);
	return d;
}

int compare_data(data_t * a, data_t * b) {
	return ( 100*(a->r1 - b->r1) + (a->r2 - b->r2) );
}

void print_data(data_t * d) {
	printf("%d\t%d\n", d->r1, d->r2);
}
