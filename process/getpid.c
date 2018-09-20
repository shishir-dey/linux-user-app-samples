#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
	printf("My PID(getpid) = %lu\n", getpid());
	printf("My PPID(bash) = %lu\n", getppid());

	for (;;) {}

	return 0;
}
