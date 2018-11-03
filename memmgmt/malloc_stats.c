#include <stdio.h>
#include <malloc.h>

int main(void) {

	/* Allocate memory using malloc() */
	int *p_i = (int *)malloc(sizeof(int));

	/* Print the stats */
	malloc_stats();

	/* Free up the allocated memory */
	free(p_i);
	return 0;
}
