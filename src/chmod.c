#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	mode_t mode = atoi(argv[1]);
	for(int i = 2; i<argc;i++)
	{
		int fd = chmod(argv[i],mode);
		mu		if(fd == -1)
			fprintf(stderr,"Error setting %i on %s\n %i = %s",
				   mode,
				   argv[i],
				   errno,
				   strerror(errno));
	}

	return 0;
}
