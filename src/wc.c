#include <stdio.h>

int
main(void)
{
  char c;
  int newlines = 0, spaces = 0, bytes = 0;
  
  while((c = getchar()) != EOF)
    {
      bytes++;
      if(c == '\n')
        newlines++;
      if(c == ' ')
        spaces++;
    }

  printf("%i %i %i\n",newlines,spaces,bytes);
  return 0;
}
