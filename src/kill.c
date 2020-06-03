#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int
main(int argc, char *argv[])
{
  int sig = 0;
  pid_t pid;

  if(argc == 2)
    {
      sig = 15;
      pid = atoi(argv[1]);
    }
  else if(argc == 3)
    {
      sig = abs(atoi(argv[1]));
      pid = abs(atoi(argv[2]));
      printf("Here 2\n");


    }
  else
    {
      printf("Specify who to kill\n %i",argc);
    }
  kill(pid,sig);
}
