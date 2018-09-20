#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

int main(void) {
	int fd;
	if ((fd = open("abc.txt", O_WRONLY)) < 0) {
		printf("Error number %d\n", errno);
		perror("open");
		exit(1);
	}
	close(fd);
	return 0;
}
