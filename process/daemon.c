#include <stdio.h>
#include <unistd.h>

int main(void) {
	int d = daemon(1, 1);
	if (d == -1) {
		fprintf(stderr, "Unable to run as a system daemon.\n");
	}
	fprintf(stdout, "PID %d: Daemon execution started.\n", getpid());
	for (;;) {}
	return 0;
}
