#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <errno.h>
#include <sys/stat.h>

int
fill_with_zeroes(const char *filename)
{
  int fd = open(filename,O_RDWR);
  if(fd == -1)
    {
      printf("Error reading file: %i = %s\n",errno,strerror(errno));
      return 1;
    }
  struct stat stat_struct; /* What name should i use? */
  stat(filename,&stat_struct);
  long int bytes_to_write = stat_struct.st_size;
  int bytes_read = 0;
  char *buf = NULL;
  buf = malloc(bytes_to_write);
  while((bytes_read = read(fd,buf,bytes_to_write)) > 0)
    write(fd,"\0",bytes_to_write + 4096);
  free(buf);
  return 0;
}

int
main(int argc, char *argv[])
{
  int c = getopt(argc, argv, "u"); /* TODO: add -f */
  
  fill_with_zeroes(argv[1]);
  if(c == 'u')
    remove(argv[1]);
}
