#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char *data = (char *)malloc(10 * sizeof(char));
	memset((void *)data, 0xA, 10 * sizeof(char));

	/* Print the data */
	for (int i = 0; i < 10; i++) {
		printf("0x%x\n", data[i]);
	}

	free(data);
	return 0;
}
