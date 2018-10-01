#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv) {
	int status;
	struct stat *dat = (struct stat *)malloc(sizeof(struct stat));
	struct stat *datcp;
	if (argc != 2) {
		fprintf(stderr, "Usage: ./stat file.txt\n");
		return 1;
	}
	if ((status = stat(argv[1], dat)) < 0) {
		perror("stat");
	}
	printf("ID of device containing file: %ld\n", dat->st_dev);
	printf("Inode number: %ld\n", dat->st_ino);
	printf("File type and mode: %d\n", dat->st_mode);
	printf("Number of hard links: %ld\n", dat->st_nlink);
	printf("User ID of owner: %d\n", dat->st_uid);
	printf("Group ID of owner: %d\n", dat->st_gid);
	printf("Device ID**: %ld\n", dat->st_rdev);
	printf("Total size: %ld\n", dat->st_size);
	printf("Block size for file system I/O: %ld\n", dat->st_blksize);
	printf("Number of 512B blocks allocated: %ld\n", dat->st_blocks);
	printf("** only for special files\n");
	free(datcp);
	return 0;
}
