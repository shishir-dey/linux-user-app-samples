#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_LEN 2

int main(int argc, char *argv[]) {
	int r;
	int stdout_fd = open("/dev/stdout", O_WRONLY);
	if (argc != 3) {
		write(stdout_fd, "Usage: ./copy file.txt file2.txt\n", 33 * sizeof(char));
	}
	int read_fd = open(argv[1], O_RDONLY);
	int write_fd = creat(argv[2], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	char *data = (char *)malloc(BUFFER_LEN * sizeof(char));
	while ((r = read(read_fd, data, BUFFER_LEN * sizeof(char))) > 0) {
		write(write_fd, data, BUFFER_LEN * sizeof(char));
	}
	close(stdout_fd);
	close(read_fd);
	close(write_fd);
	free(data);
	return 0;
}
