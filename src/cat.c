#include <stdio.h>


int
cat(FILE *file)
{

  char c;
  if (file == NULL)
    {
      fprintf(stderr,"Error opening file\n");
      return 1;
    }
  while((c = fgetc(file)) > 0)
    putchar(c);
  return 0;
}
int
main(int argc, char *argv[])
{
  if(argc == 1)
    cat(stdin);
  else {
    for(int i = 1; i<argc;i++)
	 {
	   cat(fopen(argv[i],"r"));
	 }
  }
  return 0;
}
