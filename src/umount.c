#include <stdio.h>
#include <sys/mount.h>
#include <errno.h>

int
main(int argc, char *argv[])
{
  if(argc == 1)
    {
      printf("give a directory\n");
      return 1;
    }
  int fd = umount(argv[1]);
  if(fd == -1)
    {
      printf("error umounting: %i\n",errno);
    }
}
