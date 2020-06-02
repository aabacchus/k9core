#include <stdio.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
  
  if(argc == 1)
    {
      printf("Usage: ln oldfile newfile\n");
      return 1;
    }
  int opts;
  int fd;
  /* I am aware that this doesn't conform to style, but it's the only option that actually works */
  while((opts = getopt(argc, argv, "s:")) != -1)
    {
      switch(opts)
        {
	case 's': 
	  symlink(argv[2],argv[3]);
	  break;
	case '?':
	  printf("-%c: Argument not found", optopt);
	  break;
	default:
	  fd = link(argv[1],argv[2]);
	  if(fd == -1)
	    {
	      fprintf(stderr,"Error creating link\n");
	      return 1;
	    }
	  return 0;
        }
    }
}
