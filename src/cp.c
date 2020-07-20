#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int
copy(const char *src, const char *dst)
{
  int source = open(src,O_RDONLY);
  int destination = creat(dst,0644);

  if(destination == -1)
    {
      printf("Error opening destination file\n");
      return 1;
    }
  if(source == -1)
    {
      printf("Error opening source file\n");
      return 1;
    }
  int lines;
  char buf[8912];
  while((lines = read(source,buf,sizeof(buf))) > 0)
    write(destination,buf,lines);
  return 0;
}

int
main(int argc, char *argv[])
{
  if (argc == 1)
    {
      fprintf(stderr,"usage: cp source destination\n");
      return 1;
    }
  else
    copy(argv[1],argv[2]);

}
