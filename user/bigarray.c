#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#define BIGARRAY_LEN 65536

int
main(int argc, char *argv[])
{
  int i;
  int num_forks = 4;
  int* pids[4];
  int res;

  int bigarray[BIGARRAY_LEN];
  for (i = 0; i < BIGARRAY_LEN; i++){
    bigarray[i] = i;
  }

  res = forkn(4, pids);
  if (res == -1){
    exit(1, "error");
  }
  
  exit(0, "");
}