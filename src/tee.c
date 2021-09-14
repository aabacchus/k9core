#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
tee(int fd)
{
	char buf[8192];
	int read_bytes = 0;
	while((read_bytes = read(0, buf, 8192)) > 0) {
		if(read_bytes == -1) {
			fprintf(stderr, "tee: %s\n", strerror(errno));
			return 1;
		}
		if(write(fd, buf, read_bytes) == -1) {
			fprintf(stderr, "tee: %s\n", strerror(errno));
			return 1;
		}
		if(fd != 1)
			if(write(1, buf, read_bytes) == -1) {
				fprintf(stderr, "tee: %s\n", strerror(errno));
				return 1;
			}
	}
	return 0;
}

int
main(int argc, char *argv[])
{
	int c;
	int append = 0;
	int ignore_signt = 0;
	int fd;
	int return_value = 0;
	int FLAGS = O_WRONLY | O_CREAT; /* yeah, it will overwrite the thing if it
							   * can't read what's in the file, thanks
							   * POSIX! */
	while((c = getopt(argc, argv, "ai")) != -1) {
		switch(c) {
			case 'a':
				append = 1;
				break;
			case 'i':
				ignore_signt = 1;
				break;
		}
	}
	if(argc == optind || argv[optind][0] == '-') {
		fd = 1;
	} else {
		if(append)
			FLAGS = O_RDWR | O_APPEND; /* Remember what I said? */
		fd = open(argv[optind], FLAGS, 0644);
		if(fd == -1) {
			fprintf(stderr, "tee: %s: %s\n", argv[optind], strerror(errno));
			return 1;
		}
	}
	if(ignore_signt)
		signal(SIGINT, SIG_IGN);

	return_value = tee(fd);
	close(fd);
	return return_value;
}
