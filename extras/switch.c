#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: ./switch n\n");
		return 1;
	}
	switch (atoi(argv[1])) {
		case 90 ... 100: printf("A\n"); break;
		case 80 ... 89: printf("B\n"); break;
		case 70 ... 79: printf("C\n"); break;
		default: printf("No match\n");
	}
	return 0;
}
