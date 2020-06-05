#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int
main(int argc, char *argv[])
{
  mode_t mode = atoi(argv[1]);
  for(int i = 2; i<argc;i++)
    {
      int fd = chmod(argv[i],mode);
      if(fd == -1)
        {
          printf("Error setting %i on %s\n",mode,argv[i]);
        }
    }

  return 0;
}
