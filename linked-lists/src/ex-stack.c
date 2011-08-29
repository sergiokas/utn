#include <stdio.h>
#include "data.h"
#include "random.h"
#include "stack.h"

int main(int argc, char * argv[], char *arge[])
{
	int i;
	// Main list
	struct stack_node *S = NULL;
	data_t * data;

	// Generate datasets and push them to the stack
	random_init();
	printf("Pushing...\n");
	for(i=0; i<10; i++)
	{
		data = get_data();
		stack_push(&S, data);
		print_data(data);
	}

	// Pop elements from the stack
	printf("\nPopping...\n");
	while( (data=stack_pop(&S)) != NULL )
	{
		print_data( data );
	}

	// Destroy the list and free memory
	stack_destroy(&S);

	return 0;
}
