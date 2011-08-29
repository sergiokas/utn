#include <time.h>
#include <stdlib.h>

void random_init(void) {
	srandom(time(NULL));
}

int random_between( int a, int b ) {
	return a + random() % (b);
}
