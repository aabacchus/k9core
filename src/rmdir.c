#include <unistd.h>
#include <stdio.h>

int
main(int argc, char *argv[]) {
  for(int i = 1; i<argc;i++)
    {
      int fd = rmdir(argv[i]); /* Is it actually a file descriptor? */
      if(fd == -1)
        {
          fprintf(stderr,"Error removing dir %s\n",argv[i]);
        }
    }
  return 0;
}
