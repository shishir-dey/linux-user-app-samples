#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv) {
	int status;
	if ((status = system("/bin/ls")) < 0) {
		perror("system");
	}
	return 0;
}
