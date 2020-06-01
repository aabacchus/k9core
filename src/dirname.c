#include <stdio.h>
#include <libgen.h>

int
main(int argc, char *argv[]) {
  char *dir;
  if((dir = dirname(argv[1])) == NULL) {
    fprintf(stderr, "%s", argv[0]);
    return 1;
  }
  puts(dir);
  return 0;
}
