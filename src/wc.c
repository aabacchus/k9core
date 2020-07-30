#include <stdio.h>
#include <ctype.h>
#include <getopt.h>
#include <stdlib.h>

/* TODO: fix stdin */

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

  fclose(file);
  return foobar;
}

int
main(int argc, char *argv[])
{
  int c;
  int show_lines, show_words, show_bytes;
  show_lines = show_words = show_bytes = 1;
  struct wc_values data;
  /* Process arguments */

  while((c = getopt(argc,argv,"lwc")) > 0)
    {
      switch(c)
        {
        case 'l':
          show_lines = 0;
          break;
        case 'w':
          show_words = 0;
          break;
        case 'c':
          show_bytes = 0;
          break;
        }
    }
  for(int i = optind; i<argc;i++)
    {
      if(argc > 1)
        {
          if(argc > i)
            data = wc(fopen(argv[i],"r"));
          else
            data = wc(stdin);
          if(show_lines && show_words && show_bytes)
            printf("%i %i %i",data.lines, data.words, data.bytes);
          else
            {
	      if(!show_lines)
		printf("%i ",data.lines);
	      if(!show_words)
		printf("%i ",data.words);
	      if(!show_bytes)
		printf("%i ",data.bytes);
	    }
        }
      printf("\n");
    }

  return 0;
}
