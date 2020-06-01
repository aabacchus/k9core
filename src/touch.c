#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

int
main(int argc, char *argv[])
{
  if(argc <=1)
    {
      fprintf(stderr,"Give a file\n");
      return 1;
    }

  int fd = open(argv[1],O_RDWR|O_CREAT);

  if(fd == -1)
    {
      fprintf(stderr,"Error creating file\n");
      return 1;
    }
  chmod(argv[1],420); /* 644 in decimal */
  return 0;
}
