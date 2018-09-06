#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* REGULAR INCLUDES */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
	fprintf(stderr, "Usage: ./read filename.txt\n");
		return 1;
	}
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		fprintf(stderr, "Unable to open file %s\n", argv[1]);
		return 1;
	}
	char *read_data = (char *)malloc(20 * sizeof(char));
	char *read_data2 = read_data;
	ssize_t r = read(fd, read_data, 20 * sizeof(char));
	if (r == -1) {
		fprintf(stderr, "Unable to read file %s\n", argv[1]);
		return 1;
	}
	while (*read_data) {
		fprintf(stdout, "%c", *read_data);
		read_data++;
	}
	int c = close(fd);
	if (c == -1) {
		perror("Unable to close stream \n");
		return 1;
	}
	free(read_data2);
	return 0;
}
