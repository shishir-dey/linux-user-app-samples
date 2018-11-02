#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	printf("sizeof(int) = %ld bytes (%ld bits)\n", sizeof(int), 8 * sizeof(int));
	int c = 0b11111111;
	int *p_data = (int *)malloc(100 * sizeof(int));
	memset((void *)p_data, c, 50 * sizeof(int));

	for (int i = 0; i < 100;) {
		printf("0x%x ", p_data[i]);
		if ((++i) % 10 == 0) {
			printf("\n");
		}
	}

	free(p_data);
	return 0;
}
