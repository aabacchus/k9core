#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int
main(int argc, char *argv[])
{
  if(argc == 1)
    {
      fprintf(stderr,"What do I unlink?\n");
      return 1;
    }
  int fd = unlink(argv[1]);
  if(fd == -1)
    {
      printf("Error unlinking: %i = %s\n",errno,strerror(errno));
    }
  return 0;

}
