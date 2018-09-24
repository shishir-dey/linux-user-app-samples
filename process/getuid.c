#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
	fprintf(stdout, "PID %d: UID = %d\n", getpid(), getuid());
	fprintf(stdout, "PID %d: GID = %d\n", getpid(), getgid());
	return 0;
}
