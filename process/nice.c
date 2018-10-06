#include <stdio.h>
#include <unistd.h>

int main(void) {
	printf("Setting priority to +19 (low priority, very nice)\n");
	nice(19);
	for (int i = 0; i < 20; i++) {
		printf("[PID %d]: i = %d\n", getpid(), i);
		usleep(100000);
	}
	return 0;
}
