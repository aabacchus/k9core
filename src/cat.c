#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int
cat(int fd, char *string)
{
  char buf[256];
  long lines;

  while((lines=read(fd, buf, (long)sizeof(buf)))>0)
    {
      if(write(1,buf,lines)!=lines)
        {
	  fprintf(stderr,"Error copying. %s",string);
	  return 1;
        }
      if (lines < 0)
	{
	  fprintf(stderr,"Error reading %s",string);
	  return 1;
	}
    }
  return 0;
}

int
main(int argc, char *argv[])
{
  int fd, i;

  if(argc == 1)
    {
      cat(0,"<stdin>");
    }
  else for(i=1;i<argc; i++)
	 {
	   fd = open(argv[i],O_RDONLY);
	   if(fd<0)
	     fprintf(stderr,"Cannot open %s",argv[i]);
	   else
	     {
	       cat(fd,argv[i]);
	       close(fd);
	     }
	 }
  return 0;
}
