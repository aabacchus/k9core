#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{

	if(argc == 1) {
		printf("usage: ln [-s] destination link\n");
		return 1;
	}
	int opts, fd, fflag;
	while((opts = getopt(argc, argv, "sf")) != -1) {
		if(opts == 'f')
			fflag = 1;
		switch(opts) {
			case 's':
				if(fflag == 1 && (access(argv[3], F_OK) != 1)) {
					if(remove(argv[3]) == -1)
						rmdir(argv[3]);
				}
				int symstat = symlink(argv[2], argv[3]);
				if(symstat == -1) {
					fprintf(stderr, "ln: %s: %s", argv[3], strerror(errno));
					return 1;
				}
				break;
			case '?':
				printf("-%c: Argument not found", optopt);
				break;
			default:
				fd = link(argv[1], argv[2]);
				if(fd == -1) {
					fprintf(stderr, "ln: %s: %s\n", argv[2], strerror(errno));
					return 1;
				}
				return 0;
		}
	}
}
