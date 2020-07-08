#include <stdio.h>
#include <sys/mount.h>
#include <unistd.h>
#include <errno.h>

/* Do NOT use this unironically for now, this only supports ext4, and
 * you cannot specify another filesystem unless you change the source
 * code. */

int
main(int argc, char *argv[]) {
  if(argc < 2)
    {
      printf("./mount source destination\n");
      return 1;
    }
  
  if(getuid() != 0)
    {
      fprintf(stderr,"Only root can run this\n");
      return 1;
    }
  int fd = mount(argv[1],argv[2],"ext4",0,NULL);
  if(fd == -1)
    {
      fprintf(stderr,"error mounting: %i\n",errno);
    }
}
