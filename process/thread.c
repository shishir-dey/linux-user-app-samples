#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void *__task(void *__param) {
	for (int i = 0; i < 10; i++) {
		if (*(int *)__param == 5) {
			printf("[PID %d Thread t1]: running...\n", getpid());
			sleep(2);
		}
		else {
			printf("[PID %d Thread t2]: running...\n", getpid());
			sleep(2);
		}
	}
	return __param;
}

int main(void) {
	int status;
	pthread_t t1, t2;
	int data_1 = 5, data_2 = 6;
	if ((status = pthread_create(&t1, NULL, __task, (void *) &data_1)) < 0) {
		printf("Unable to create thread t1\n");
	}
	if ((status = pthread_create(&t2, NULL, __task, (void *) &data_2)) < 0) {
		printf("Unable to create thread t1\n");
	}
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
