#include <string.h>
#include <stdio.h>

int main(void) {
	int a = 0b1111;
	int b = 0b0011;
	int status;

	status = memcmp(&a, &b, 4);

	if (status == 0) {
		printf("Same bytes\n");
	}
	else if (status < 0) {
		printf()
	return 0;
}
