#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	printf("sizeof(int) = %ld bytes (%ld bits)\n", sizeof(int), 8 * sizeof(int));
	
	int arr[] = {1, 2, 3, 4, 5};
	int *p_data = (int *)malloc(5 * sizeof(int));

	memcpy(p_data, arr, 5 * sizeof(int));

	printf("Original data = ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\nCopied Data = ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", p_data[i]);
	}
	printf("\n");

	free(p_data);
	return 0;
}
