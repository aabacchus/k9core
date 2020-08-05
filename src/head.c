#include <stdio.h>
#include <stdlib.h>

int
head(FILE *file, int lines)
{
  int a;
  int c = 0;
  while((a = fgetc(file)) != EOF)
    {
      if(a == '\n')
        {
          ++c;
        }
      putchar(a);
      if(c == lines)
        return lines;
    }
  return lines;

}

int
main(int argc, char *argv[])
{
  int lines = 10;
  if(argc == 1)
    head(stdin,lines);
  if(argc == 2)
    head(fopen(argv[1],"r"),lines);
  if(argc == 3)
    {
      lines = abs(atoi(argv[1]));
      head(fopen(argv[2],"r"),lines);
    }
  return 0;
}
