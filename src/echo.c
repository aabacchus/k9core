#include <string.h>
#include <stdio.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
  while(*argv) {
    (void)fputs(*argv, stdout);   // Print argv
    if(*++argv) putchar(' ');     // If multiple things in argv, print a space between them.
  }
  putchar('\n');
  return 0;
}
