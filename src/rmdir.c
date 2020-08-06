#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
int
main(int argc, char *argv[]) {
  int errors = 0;
  for(int i = 1; i<argc;i++)
    {
      int fd = rmdir(argv[i]); /* Is it actually a file descriptor? */
      if(fd == -1)
        {
	  fprintf(stderr,"Error removing dir %s: %i = %s\n",argv[i],
		  errno,strerror(errno));
	  errors++;
	}
    }
  return 0;
}
