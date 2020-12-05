#include <stdio.h>
#include <ctype.h>
#include <getopt.h>
#include <stdlib.h>

int show_lines, show_words, show_bytes;
struct wc_values data;

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
	    fprintf(stderr,"error opening file\n");
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
void
print_values(const char*filename)
{
  if(show_bytes && show_lines && show_words)
    printf("%i %i %i",
           data.lines,
           data.words,
           data.bytes);
  else
    {
      if(!show_lines)
        printf("%i ",data.lines);
      if(!show_words)
        printf("%i ",data.words);
      if(!show_bytes)
        printf("%i ",data.bytes);
    }
  printf(" %s\n",filename);
}
int
main(int argc, char *argv[])
{
  int c;

  show_lines = show_words = show_bytes = 1;
  /* Process arguments */

  while((c = getopt(argc,argv,"lwcm")) > 0)
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
        case 'm':
          show_bytes = 0;
	  break;

        }
    }

  if(optind == argc)
    {
      data = wc(stdin);
      print_values("stdin");
    }
  else for(int i = optind; i<argc; i++)
         {
           if(argv[i][0] == '-' && argv[i][1] == '\0')
             data = wc(stdin);
           else
	     data = wc(fopen(argv[i],"r"));
           print_values(argv[i]);
         }
  return 0;
}
