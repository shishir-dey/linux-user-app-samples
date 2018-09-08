#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* REGULAR INCLUDES */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *data = (int *)malloc(100 * sizeof(int));
	for (int i = 0; i < 100; i++) {
		data[i] = -1;
	}
	fprintf(stdout, "-->reset\n");
	for (int i = 0; i < 100; i++) {
		fprintf(stdout, "%d", data[i]);
		if ((i + 1) % 10 == 0) {
			fprintf(stdout, "\n");
		}
	}
	int fd = open("/dev/zero", O_RDONLY);
	if (fd == -1) {
		fprintf(stderr, "Unable to open device: zero\n");
	}
	fprintf(stdout, "--Read from /dev/zero\n");
	int r = read(fd, data, 100 * sizeof(int));
	if (r == -1) {
		fprintf(stderr, "Unable to read from device\n");
	}
	if (close(fd) == -1) {
		perror("close");
	}
	for (int i = 0; i < 100; i++) {
		fprintf(stdout, "%d", data[i]);
		if ((i + 1) % 10 == 0) {
			fprintf(stdout, "\n");
		}
	}
	free(data);
	return 0;
}
