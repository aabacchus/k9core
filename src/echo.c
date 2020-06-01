#include <stdio.h>

int
main(int argc, char *argv[])
{
  ++argv;
  while(*argv) {
    (void)fputs(*argv, stdout);   // Print argv
    if(*++argv) putchar(' ');     // If multiple things in argv, print a space between them.
  }
  putchar('\n');
  return 0;
}
