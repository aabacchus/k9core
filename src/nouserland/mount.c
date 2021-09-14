#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <sys/mount.h>
#include <unistd.h>

/* Do NOT use this unironically for now, this only supports ext4, and
 * you cannot specify another filesystem unless you change the source
 * code. */

/* Update: now this supports filetype with -t flag. But I still don't
 * recommend it to mounting something that it's not extx
 */

int
main(int argc, char *argv[])
{
	int c = getopt(argc, argv, "t:");
	if(argc < 2) {
		printf("usage: mount source destination\n");
		return 1;
	}

	if(getuid() != 0) {
		fprintf(stderr, "mount: must be root\n");
		return 1;
	}
	char filesystem[10] = "ext4";
	int source = 1;
	int destination = 2;
	if(c == 't') {
		strcpy(filesystem, optarg);
		source++;
		destination++;
	}
	int fd = mount(argv[source], argv[destination], filesystem, 0, NULL);
	if(fd == -1) {
		fprintf(stderr, "mount: %s\n", strerror(errno));
		return 1;
	}
	return 0;
}
