#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
  char a = 'y';

  if(argv[1] != NULL)
    {
      strcpy(&a,argv[1]);
    }
  while(1)
    {
      putchar(a);
      putchar('\n');
    }
  return 0;
}
