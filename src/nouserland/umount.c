#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <sys/mount.h>

int
main(int argc, char *argv[])
{
	int c = getopt(argc, argv, "f");
	int options = 0; /* No options by default */
	int destination = 1;
	if(c == 'f') {
		options = MNT_FORCE;
		destination++;
	}
	if(argc == 1) {
		printf("usage: umount mountpoint\n");
		return 1;
	}
	int fd = umount2(argv[destination], options);
	if(fd == -1) {
		fprintf(
			stderr, "umount: %s: %s\n", argv[destination], strerror(errno));
		return 1;
	}
	return 0;
}
