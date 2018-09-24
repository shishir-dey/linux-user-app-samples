#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
	int status;
	pid_t pid = fork();
	if (pid > 0) {
		printf("PID %d: Child created successfully\n", getpid());
	}
	if (pid == 0) {
		printf("PID %d: I am the child process\n", getpid());
	}
	wait(&status);

	if (pid > 0 && WIFEXITED(status)) {
		printf("PID %d: Child terminated successfully\n", getpid());
	}
	return 0;
}
