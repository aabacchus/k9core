#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	if(argc == 1) {
		fprintf(stderr, "usage: sleep time\n");
		return 1;
	}
	if(usleep(atof(argv[1]) * 1000000) == -1) {
		fprintf(stderr, "sleep: %s\n", strerror(errno));
		return 1;
	}

	return 0;
}
