#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* REGULAR INCLUDES */
#include <stdio.h>

int main(void) {
	int fd = open("offset.txt", O_RDONLY | O_WRONLY);
	if (fd == -1) {
		fprintf(stderr, "Unable to create file\n");
		return 1;
	}
	lseek(fd, (off_t) 0, SEEK_END);
	int w = write(fd, "This text should be added to last.", 34);
	if (close(fd) == -1) {
		perror("close");
	}
	return 0;
}
