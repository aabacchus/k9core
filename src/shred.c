#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int
fill_with_zeroes(const char *filename)
{
	int fd = open(filename, O_WRONLY);
	if(fd == -1) {
		fprintf(stderr, "shred: %s: %s\n", filename, strerror(errno));
		return 1;
	}
	struct stat stat_struct; /* What name should i use? */
	if(stat(filename, &stat_struct) == -1) {
		fprintf(stderr, "shred: %s: %s\n", filename, strerror(errno));
		return 1;
	}
	long int bytes_to_write = stat_struct.st_size;
	char *buf = NULL;

	buf = malloc(bytes_to_write);
	for(int i = 0; i < bytes_to_write; i++)
		if(write(fd, "\0\0\0\0\0", bytes_to_write + 2048) == -1) {
			fprintf(stderr, "shred: %s: %s\n", filename, strerror(errno));
			return 1;
		}
	free(buf);
	return 0;
}

int
main(int argc, char *argv[])
{
	int c = getopt(argc, argv, "u"); /* TODO: add -f */

	if(fill_with_zeroes(argv[1]) != 0) {
		return 1;
	}
	if(c == 'u')
		if(remove(argv[1]) == -1) {
			fprintf(stderr, "shred: %s: %s\n", argv[1], strerror(errno));
			return 1;
		}
	return 0;
}
