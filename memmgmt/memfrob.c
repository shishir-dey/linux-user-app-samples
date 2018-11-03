#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

void print_data(void *p, int N) {
	char *p2 = (char *)p;
	for (int i = 0; i < N; i++) {
		printf("0x%x ", p2[i]);
	}
	printf("\n");
}

int main(void) {
	char arr[5] = {0xaa, 0xbb, 0xcc, 0xdd, 0xee};
	printf("Original data = \n");
	print_data(arr, 5);

	/* Encrypt this data */
	memfrob(arr, 5 * sizeof(char));
	printf("After encryption = \n");
	print_data(arr, 5);
	return 0;
}
