#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{

	for(int i = 1; i < argc; i++) {
		if(rmdir(argv[i]) == -1) {
			fprintf(stderr, "rmdir: %s: %s\n", argv[i], strerror(errno));
			return 1;
		}
	}
	return 0;
}
