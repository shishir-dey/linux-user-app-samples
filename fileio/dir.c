#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
	struct dirent *dat = (struct dirent *)malloc(sizeof(struct dirent));
	struct dirent *datcp = dat;
	if (argc != 2) {
		fprintf(stderr, "Usage: ./dir <directory>\n");
		return 1;
	}
	DIR *fd = opendir(argv[1]);
	if (fd == NULL) {
		perror("open");
	}
	dat = readdir(fd);
	printf("Inode Number: %ld\n", dat->d_ino);
	printf("Length of this record: %d\n", dat->d_reclen);
	printf("Type of file: %d\n", dat->d_type);
	closedir(fd);
	free(datcp);
	return 0;
}
