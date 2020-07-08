#include <stdio.h>
#include <sys/mount.h>
#include <errno.h>
#include <getopt.h>

int
main(int argc, char *argv[])
{
  int c = getopt(argc, argv, "f");
  int options = 0; /* No options by default */
  int destination = 1;
  if(c == 'f')
    {
    options = MNT_FORCE;
    destination++;
    }
  if(argc == 1)
    {
      printf("give a directory\n");
      return 1;
    }
  int fd = umount2(argv[destination],options);
  if(fd == -1)
    {
      printf("error umounting: %i\n",errno);
    }
}
