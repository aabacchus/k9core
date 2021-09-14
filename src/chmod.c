#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int
main(int argc, char *argv[])
{
	mode_t mode = atoi(argv[1]);
	for(int i = 2; i < argc; i++) {
		int fd = chmod(argv[i], mode);
		if(fd == -1) {
			fprintf(stderr, "chmod: %s: %s", argv[i], strerror(errno));
			return 1;
		}
	}

	return 0;
}
