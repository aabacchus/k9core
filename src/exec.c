#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	if(argc == 1) {
		fprintf(stderr, "usage: exec command [args]\n");
		return 1;
	}
	char *const argv2[1] = { argv[2] };
	if(execv(argv[1], argv2) == -1) {
		fprintf(stderr, "exec: %s: %s\n", argv[1], strerror(errno));
		return 1;
	}
	return 0;
}
