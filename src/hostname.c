#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
main(void)
{
	char buf[64];
	if(gethostname(buf, 64) == -1) {
		fprintf(stderr, "hostname: %s\n", strerror(errno));
		return 1;
	}
	puts(buf);
	return 0;
}
