#include <stdio.h>

int
move(const char *src, const char *dst)
{
  FILE *source = fopen(src,"r");
  FILE *destination = fopen(dst,"w");
  if(destination == NULL)
    {
      printf("Error opening destination file\n");
      return 1;
    }
  if(source == NULL)
    {
      printf("Error opening source file\n");
      return 1;
    }

  char c;

  while((c = fgetc(source)) > 0)
    {
      int value = fputc(c,destination);
      if(value == -1)
        {
          printf("Error\n");
          return 1;
        }
    }
  remove(src);
  return 0;
}

int
main(int argc, char *argv[])
{
  if (argc == 1)
    {
      fprintf(stderr,"usage: mv source destination\n");
      return 1;
    }
  else
    move(argv[1],argv[2]);

}
