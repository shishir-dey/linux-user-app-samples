#include <stdio.h>

void *retchar(void *data) {
	return (char *)data;
}

int main(void) {
	char *s = "My String\n";

	void *(*retchar_p[2])(void *) = {retchar, retchar};
	for (int i = 0; i < 2; i++) {
		printf("%s\n", (char *)(*retchar_p[i])(s));
	}
	return 0;
}
