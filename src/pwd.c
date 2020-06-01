#include <unistd.h>
#include <stdio.h>

int
main()
{
  puts(getcwd(NULL, 0));
  return 1;
}
