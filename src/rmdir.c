#include <unistd.h>
#include <stdio.h>
#include <err.h>

int
main(int argc, char *argv[]) {
  int errors = 0;
  for(int i = 1; i<argc;i++)
    {
      int fd = rmdir(argv[i]); /* Is it actually a file descriptor? */
      if(fd == -1)
        {
	  warn("Error removing dir %s\n",argv[i]);
	  errors++;
	}
    }
  if(errors>0)
    {
      warn("%i error(s) found\n",errors);
    }
  return 0;
}
