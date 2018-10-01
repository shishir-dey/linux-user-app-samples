#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	int audiorec_fd, stdout_fd;
	int dat;
	if ((audiorec_fd = open("/dev/snd/pcmC0D0c", O_RDONLY)) < 0) {
		perror("open");
	}
	stdout_fd = open("/dev/stdout", O_WRONLY);

	write(stdout_fd, "Recorded audio data\n", 20 * sizeof(char));
	while (1) {
		read(audiorec_fd, &dat, sizeof(int));
		write(stdout_fd, &dat, sizeof(int));
	}
	write(stdout_fd, "\n", sizeof(char));
	return 0;
}
