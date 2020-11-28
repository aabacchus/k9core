#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <getopt.h>
#include <errno.h>
#include <string.h>

int
cat(int fd, const char *filename)
{
  int c;
  char buf[8192];
  if (filename[0] == '-' && filename[1] != 'u')
    fd = 0;
  
  if(fd != 0)
    fd = open(filename, O_RDONLY);

  if (fd == -1)
    fprintf(stderr,"error opening %s: %s\n",filename,strerror(errno));


  while((c = read(fd,buf,sizeof(buf))) > 0)
    write(1,buf,c);
  close(fd);
  return 0;
}
int
main(int argc, char *argv[])
{
  int c = getopt(argc,argv,"u");
  if (argc == optind)
    cat(0,"-");
  for(int i = optind; i<argc;i++)
    cat(1,argv[i]);

  return 0;
}
