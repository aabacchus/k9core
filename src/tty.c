#include <unistd.h>
#include <stdio.h>

int
main(void)
{
  printf("%s\n",ttyname(1));
  return 0;
}
