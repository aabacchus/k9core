#include <stdio.h>

void
wc(FILE *file)
{
  char c;
  int newlines, spaces, bytes = 0;
  newlines = spaces = bytes = 0;
  while((c = fgetc(file)) > 0)
    {
      bytes++;
      if(c == '\n')
        newlines++;
      if(c == ' ')
        spaces++;
    }
  printf("%i %i %i\n",newlines,spaces,bytes);
  fclose(file);
}

int
main(int argc, char *argv[])
{
  if (argc == 1)
    wc(stdin);
  else
    {
      for(int i = 1; i<argc;i++)
	{
	  wc(fopen(argv[i],"r"));
	}
      
    }
  return 0;
}
