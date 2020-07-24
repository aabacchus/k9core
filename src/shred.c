#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <errno.h>

int
count_bytes(const char *filename)
{
  int fd = open(filename,O_RDWR);
  if(fd == -1)
    {
      printf("Error reading file: %i = %s\n",errno,strerror(errno));
      return 1;
    }
  int bytes_read = 0;
  char *buf = NULL;
  int bytes = 0;
  buf = malloc(1);
  while ((bytes_read = read(fd,buf,1)) > 0)
    bytes++;
  return bytes;
}

int
fill_with_zeroes(const char *filename)
{
  int fd = open(filename,O_RDWR);
  if(fd == -1)
    {
      printf("Error reading file: %i = %s\n",errno,strerror(errno));
      return 1;
    }
  int bytes_to_write = count_bytes(filename);
  int bytes_read = 0;
  char *buf = NULL;
  int bytes = 0;
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
