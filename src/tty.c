#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
main(void)
{
	char *tty = ttyname(1);
	if(tty == NULL) {
		fprintf(stderr, "tty: %s\n", strerror(errno));
		return 1;
	}
	printf("%s\n", tty);
	return 0;
}
