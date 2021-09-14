#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	if(argc != 2) {
		fprintf(stderr, "usage: unlink file\n");
		return 1;
	}

	int fd = unlink(argv[1]);
	if(fd == -1) {
		fprintf(stderr, "unlink: %s: %s\n", argv[1], strerror(errno));
		return 1;
	}
	return 0;
}
