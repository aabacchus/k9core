#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int
cat(int fd,const char *filename)
{
  
  char c;
  char buf[8192];
  if(fd != 0)
    fd = open(filename, O_RDONLY);
  if ( fd == -1)
    {
      fprintf(stderr,"Error opening file\n");
      return 1;
    }
  while((c = read(fd,buf,sizeof(buf)) > 0))
    printf("%s",buf);
  return 0;
}
int
main(int argc, char *argv[])
{
  if(argc == 1)
    cat(0,NULL);
  else for(int i = 1; i<argc;i++)
         {
           cat(1,argv[i]);
         }

  return 0;
}
