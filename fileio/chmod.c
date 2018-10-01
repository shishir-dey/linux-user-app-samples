#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
	int mod;
	if (argc != 2) {
		fprintf(stderr, "Usage: ./chmod file.txt\n");
		return 1;
	}
	if ((mod = chmod(argv[1], S_IRWXU | S_IRWXG | S_IRWXO)) < 0) {
		perror("chown");
	}
	return 0;
}
