#include <stdio.h>

int main(void) {
	printf("Inline assembly\n");
	__asm__("RET");
}
