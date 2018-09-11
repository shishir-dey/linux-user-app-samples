#include <stdio.h>

int main(void) {
	FILE *fp;
	fp = fopen("test.txt", "w");
	fprintf(fp, "This string is written by the program.");
	fclose(fp);
	return 0;
}
