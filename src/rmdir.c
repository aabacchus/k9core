#include <unistd.h>

int
main(int argc, char *argv[]) {
  while(*argv) {
    rmdir(*argv);
    *argv++;
  }
}
