#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int
main(int argc, char *argv[])
{
	int c = getopt(argc, argv, "p");
	if(argc == 1) {
		fprintf(stderr, "usage [-p] dir...\n");
		return 1;
	}
	/*
	if(c == 'p')
	  {
	    const char tok[2] = "/";
	    char *token;
	    token = strtok(argv[2],tok);
	    char *directories = argv[2];
	    printf("%s\n",directories);
	    while(token != NULL)
		 {
		mkdir(token,511);
		token = strtok(NULL,"/");
		printf("%s",token);
		strcat(directories,"/");
		printf("%s",directories);
		 }
	    return 0;
	  }
	*/
	for(int i = 1; i < argc; i++) {

		int fd = mkdir(argv[i], 420);
		if(fd == -1) {
			fprintf(stderr, "mkdir: %s: %s\n", argv[i], strerror(errno));
			return 1;
		}
	}
	return 0;
}
