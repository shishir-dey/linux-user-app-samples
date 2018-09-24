#include <stdio.h>
#include <stdlib.h>

void f(int arc, void *arv) {
	printf("%s(): arc = %d, arv = %s\n", __FUNCTION__, arc, (char *)arv);
}

int main(void) {
	void (*fp)(int, void *) = f;
	char *s = "abc";
	on_exit(fp, (void *)s);
	return 0;
}
