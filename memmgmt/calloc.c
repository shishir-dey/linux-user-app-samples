#include <stdio.h>
#include <stdlib.h>

void print_data(int *memloc, int N) {
	printf("[");
	for (int i = 0; i < N; i++) {
		printf("%d ", memloc[i]);
	}
	printf("]\n");
}

int main(void) {
	int *data = (int *)calloc(10, sizeof(int));

	/* Print the data in allocated space */
	print_data(data, 10);

	/* Put values in the allocated space */
	for (int i = 0; i < 10; i++) {
		data[i] = (i + 1) << 1;
	}

	/* Print data again */
	print_data(data, 10);

	free(data);
	return 0;
}
