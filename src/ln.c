#include <stdio.h>
#include <unistd.h>

/* TODO -s flag */

int
main(int argc, char *argv[])
{
  if(argc == 1)
    {
      printf("Usage: ln oldfile newfile\n");
      return 1;
    }
  int fd = link(argv[1],argv[2]);
  if(fd == -1)
    {
      fprintf(stderr,"Error creating link\n");
      return 1;
    }
  return 0;
}
