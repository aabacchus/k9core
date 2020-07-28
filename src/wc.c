#include <stdio.h>
#include <ctype.h>
#include <getopt.h>
#include <stdlib.h>

struct wc_values
{
  int lines;
  int bytes;
  int words;
};

struct wc_values
wc(FILE *file)
{
  if(file == NULL)
    {
      fprintf(stderr,"error\n");
      exit(1);
    }
  struct wc_values foobar;
  char c;
  int newlines, spaces, bytes = 0;
  newlines = spaces = bytes = 0;
  while((c = fgetc(file)) > 0)
    {
      bytes++;
      if(c == '\n')
        newlines++;
      if(isspace(c))
        spaces++;
    }
  foobar.bytes = bytes;
  foobar.lines = newlines;
  foobar.words = spaces;

  // printf("%i %i %i\n",newlines,spaces,bytes);
  fclose(file);
  return foobar;
}

int
main(int argc, char *argv[])
{
  int c = getopt(argc, argv, "clw");
  struct wc_values data;
  if (argc == 1)
    data = wc(stdin);
  else
    {
      for(int i = optind; i<argc;i++)
        {
          data = wc(fopen(argv[i],"r"));
          switch(c)
            {
            case 'c':
              printf("%i\n",data.bytes);
              break;
            case 'l':
              printf("%i\n",data.lines);
              break;
            case 'w':
              printf("%i\n",data.words);
              break;
            default:
              printf("%i %i %i\n",data.lines,data.words,data.bytes);
            }
        }

    }
  return 0;
}
