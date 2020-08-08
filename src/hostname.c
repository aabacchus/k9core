#include <unistd.h>
#include <stdio.h>

int
main(void)
{
  char buf[64];
  gethostname(buf,64);
  puts(buf);
  return 0;
}
