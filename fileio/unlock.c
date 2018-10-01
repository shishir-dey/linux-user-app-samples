#include <stdio.h>
#include <sys/file.h>

int main(int argc, char **argv) {
	int fd, lock_status;
	if (argc != 2) {
		fprintf(stderr, "Usage: ./unlock <filename>\n");
		return 1;
	}
	if ((fd = open(argv[1], O_RDWR)) < 0) {
		perror("open");
	}
	lock_status = flock(fd, LOCK_UN);
	if (lock_status < 0) {
		fprintf(stderr, "Unable to unlock file %s\n", argv[1]);
	}
	return 0;
}
