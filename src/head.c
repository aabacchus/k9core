#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int
head(int fd, int lines)
{
	int a;
	ssize_t r;
	int c = 0;

	while((r = read(fd, &a, 1)) > 0) {
		if(r == -1) {
			fprintf(stderr, "head: %s\n", strerror(errno));
			return 1;
		}
		if((char)a == '\n')
			++c;

		putchar(a);
		if(c == lines)
			break;
	}
	return 0;
}

int
main(int argc, char *argv[])
{
	int lines = 10;
	int return_value = 0;
	int c, fd;
	c = getopt(argc, argv, "n:");
	switch(c) {
		case 'n':
			lines = atoi(optarg);
			if(lines == 0) {
				fprintf(stderr, "head: invalid number '%s'\n", optarg);
				return 1;
			}
			break;
		case ':':
		case '?':
			fprintf(stderr, "usage: head [-n N] file\n");
			return 1;
	}

	if(optind == argc)
		fd = 0;
	else {
		fd = open(argv[optind], O_RDONLY);
		if(fd == -1) {
			fprintf(stderr, "head: %s: %s\n", argv[optind], strerror(errno));
			return 1;
		}
	}
	return_value = head(fd, lines);
	close(fd);
	return return_value;
}
