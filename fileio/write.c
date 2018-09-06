#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* REGULAR INCLUDES */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 4) {
		fprintf(stderr, "Usage: ./write filename.txt hello N\n");
		return 1;
	}
	int fd = creat(argv[1], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1) {
		fprintf(stderr, "Unable to create file %s\n", argv[1]);
		return 1;
	}
	write(fd, argv[2], atoi(argv[3]));
	int c = close(fd);
	if (c == -1) {
		fprintf(stderr, "Unable to close stream\n");
		return 0;
	}
	return 0;
}
