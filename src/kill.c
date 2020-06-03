#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int
main(int argc, char *argv[])
{
  int sig = 0;
  pid_t pid;
  switch(argc)
    {
    case 2:
      sig = 15;
      pid = atoi(argv[1]);
      break;
    case 3:
      sig = abs(atoi(argv[1]));
      pid = abs(atoi(argv[2]));
      puts("Here 2");
      break;
    default:
      fprintf(stderr, "Specify who to kill\n");
      return 1;
    }
  kill(pid,sig);
  return 0;
}
