#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	fd_set rfds;
	struct timeval tv;

	/* Watch stdin */
	FD_ZERO(&rfds);
	FD_SET(0, &rfds);

	/* Config - wait 5 seconds for stdin */
	tv.tv_sec = 5;

	int r;
	if ((r = select(1, &rfds, NULL, NULL, &tv)) < 0) {
		perror("select");
	}
	else {
		printf("No data within 5 seconds\n");
	}
	exit(0);
}
