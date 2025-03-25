#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  printf("%d\n", memsize());
  void* buffer = malloc(20000);
  printf("%d\n", memsize());
  free(buffer);
  printf("%d\n", memsize());
  exit(0);
}