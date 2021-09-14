#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
cat(int fd, const char *filename)
{
	int c;
	char buf[8192];
	if(filename[0] == '-' && filename[1] != 'u')
		fd = 0;

	if(fd != 0)
		fd = open(filename, O_RDONLY);

	if(fd == -1) {
		fprintf(stderr, "cat: %s: %s\n", filename, strerror(errno));
		return 1;
	}

	while((c = read(fd, buf, sizeof(buf))) > 0) {
		if(c == -1) {
			fprintf(stderr, "cat: %s: %s\n", filename, strerror(errno));
			return 1;
		}
		if(write(1, buf, c) == -1) {
			fprintf(stderr, "cat: %s: %s\n", filename, strerror(errno));
			return 1;
		}
	}
	close(fd);
	return 0;
}
int
main(int argc, char *argv[])
{
	int return_value = 0;
	getopt(argc, argv, "u");
	if(argc == optind)
		return_value = cat(0, "-");
	for(int i = optind; i < argc; i++)
		return_value = cat(1, argv[i]);

	return return_value;
}
