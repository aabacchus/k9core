#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	if(argc != 2) {
		fprintf(stderr, "usage: touch file\n");
		return 1;
	}

	int fd = creat(argv[1], 0644);

	if(fd == -1) {
		fprintf(stderr, "touch: %s: %s\n", argv[1], strerror(errno));
		return 1;
	}
	close(fd);
	return 0;
}
