#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int
main(int argc, char *argv[])
{
	int c;
	int human_readable = 0;
	struct stat file_data;

	while((c = getopt(argc, argv, "h")) != -1) {
		switch(c) {
			case 'h':
				human_readable = 1;
				break;
		}
	}
	if(argc == optind) {
		printf("usage: du [-h] file...\n");
		return 1;
	}
	for(int i = optind; i < argc; i++) {
		if(stat(argv[i], &file_data) == -1) {
			fprintf(stderr, "du: %s: %s\n", argv[i], strerror(errno));
			continue;
		}
		if(human_readable)
			printf("%liK\t %s", file_data.st_size / 1024, argv[i]);
		else
			printf("%li\t %s", file_data.st_size, argv[i]);
		puts("");
	}
	return 0;
}
