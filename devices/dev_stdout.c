#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
	int fd = open("/dev/stdout", O_WRONLY);
	if (fd == -1) {
		return 1;
	}
	char *text = "Hello, world!\n";
	write(fd, text, 14 * sizeof(char));
	int c = close(fd);
	if (c == -1) {
		perror("close");
	}
	return 0;
}
