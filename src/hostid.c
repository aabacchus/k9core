#include <unistd.h>
#include <stdio.h>

int
main(void)
{
  long id = gethostid();
  printf("%lx\n",id);

  return 0;
}
