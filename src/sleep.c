#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int
main(int argc, char *argv[])
{
  if(argc == 1)
    {
      printf("missing opperand\n");
    }

  sleep(atoi(argv[1]));
  
  return 0;
}
