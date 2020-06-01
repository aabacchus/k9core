#include <stdio.h>
#include <sys/stat.h>

int
main(int argc, char *argv[])
{
  if (argc == 1)
    {
      fprintf(stderr,"specify path(s) to make\n");
      return 1;
    }
  for(int i = 1; i<argc;i++)
    {
      int fd = mkdir(argv[i],420);
      if(fd == -1)
	{
	  fprintf(stderr,"Error creating dir %s\n",argv[i]);
	  return 1;
	}
    }
  return 0;
}
