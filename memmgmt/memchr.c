#include <stdio.h>
#include <string.h>

int main(void) {
	char ar[5] = {'a', 'e', 'i', 'o', 'u'};
	for (int i = 0; i < 5; i++) {
		printf("%p: %c\n", &ar[i], ar[i]);
	}
	char *ch = (char *)memchr((void *)ar, (int)'e', 5 * sizeof(char));
	if (ch != NULL) {
		printf("%c found at %p\n", *ch, ch);
	}
	return 0;
}
