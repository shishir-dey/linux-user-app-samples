#include <stdio.h>
#include <stdlib.h>

void f(void) {
	printf("%s running...\n", __FUNCTION__);
}

int main(void) {
	void (*pf)(void) = f;
	atexit(pf);
	return 0;
}
