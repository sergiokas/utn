#include <stdio.h>

int variable_array(int n);

int main(void) {
	printf("Variable-lenght Array: %d\n", variable_array(20));
	return 0;
}

int variable_array(int n) {
	float val[n];
	float result = 0;
	for(int i=0; i<n; i++) {
		result += val[n];
	}
	return result;
}
