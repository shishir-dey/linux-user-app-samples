#include <stdio.h>

int main(void) {
	FILE *stream;
	int fd = open("test2.txt", O_WRONLY);
	if (fd == -1) {
		fprintf(stderr, "Unable to open file test2.txt\n");
	}
	stream = fdopen(fd, "w");
	close(fd);
	return 0;
}
