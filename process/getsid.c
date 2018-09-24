#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	fprintf(stdout, "PID %d: Session ID = %d\n", getpid(), getsid(getpid()));
	return 0;
}
