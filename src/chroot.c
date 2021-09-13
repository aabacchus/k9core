#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* UNTESTED */

int
main(int argc, char *argv[])
{
	if(argc != 2) {
		fprintf(stderr, "usage: chroot newroot\n");
		return 1;
	}
	if(chroot(argv[1]) == -1) {
		fprintf(stderr, "chroot: %s: %s\n", argv[1], strerror(errno));
		return 1;
	}
}
