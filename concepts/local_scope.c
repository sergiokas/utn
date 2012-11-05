/** Try out if a local scope variable still retains its value */
#include <stdio.h>

#define VALUE 5

int * local(void);

int main (void) {
	printf("Local variable value for the invoked function is: %d\n", *local());
	return 0;
}

int * local(void) {
	int a = VALUE, *p;
	return p = &a;
}
