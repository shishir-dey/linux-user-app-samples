#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int status;
	if (argc != 3) {
		fprintf(stderr, "Usage: ./symlink <file/dir> <link file/dir>\n");
		return 1;
	}
	if ((status = symlink(argv[1], argv[2])) < 0) {
		perror("symlink");
	}
	return 0;
}
