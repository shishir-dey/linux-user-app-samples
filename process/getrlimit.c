#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(void) {
	struct rlimit *rlim = (struct rlimit *)malloc(sizeof(struct rlimit));
	int status;
	if ((status = getrlimit(RLIMIT_DATA, rlim)) < 0) {
		fprintf(stderr, "Unable to getrlimit\n");
		return 1;
	}
	printf("RLIMIT_DATA\n");
	printf("Soft limit: %ld\n", rlim->rlim_cur);
	printf("Hard limit: %ld\n", rlim->rlim_max);
	free(rlim);
	return 0;
}
