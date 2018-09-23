#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	fprintf(stdout, "pid = %d\n", getpid());
	fprintf(stdout, "ppid = %d\n", getppid());
	
	for (;;) {
		/* Delay */
	}

	return 0;
}
