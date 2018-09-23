#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	pid_t pid = fork();
	if (pid > 0) {
		fprintf(stdout, "PID %d: Started\n", getpid());
		fprintf(stdout, "PID %d: Created child process %d\n", getpid(), pid);
		fprintf(stdout, "PID %d: Ended\n", getpid());
	}
	else if ((pid == 0)) {
		fprintf(stdout, "PID %d: Started\n", getpid());
		fprintf(stdout, "PID %d: This is the child process\n", getpid());
		fprintf(stdout, "PID %d: Ended\n", getpid());
	}
	else {
		perror("fork");
	}
	return 0;
}
