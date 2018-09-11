#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 4) {
		fprintf(stderr, "Usage: ./cp file.txt file2.txt N\n");
		return 1;
	}
	int N = atoi(argv[3]);
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		fprintf(stderr, "Unable to open file %s\n", argv[1]);
		return 0;
	}
	int fd2 = creat(argv[2], S_IRWXU | S_IRGRP | S_IROTH);
	if (fd2 == -1) {
		fprintf(stderr, "Unable to create file %s\n", argv[2]);
		return 1;
	}
	char *data = (char *)malloc(N * sizeof(char));
	int rd = read(fd, data, N);
	if (rd == -1) {
		fprintf(stderr, "Unable to read from file %s\n", argv[1]);
		return 1;
	}
	int wr = write(fd2, data, N);
	if (wr == -1) {
		fprintf(stderr, "Unable to write to file %s\n", argv[2]);
		return 1;
	}
	fprintf(stdout, "Writing %d characters to file...Done\n", N);
	fprintf(stdout, "Exiting program.\n");
	free(data);
	close(fd);
	close(fd2);
	return 0;
}
