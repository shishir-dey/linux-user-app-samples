#include <stdio.h>
#include <stdlib.h>

#define BUFFER_LEN 8

int main(int argc, char *argv[]) {
	size_t r;
	if (argc != 3) {
		fprintf(stderr, "Usage: ./copy file.txt file2.txt\n");
		return 1;
	}
	FILE *fp;
	FILE *fp2;
	fp = fopen(argv[1], "r");
	fp2 = fopen(argv[2], "w");
	char *data = (char *)malloc(BUFFER_LEN * sizeof(char));
	while ((r = fread(data, BUFFER_LEN * sizeof(char), 1, fp)) > 0) {
		fwrite(data, BUFFER_LEN * sizeof(char), 1, fp2);
	}
	fclose(fp);
	fclose(fp2);
	free(data);
	return 0;
}
