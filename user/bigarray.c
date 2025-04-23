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
  int pid;
  int num_killed;
  int statuses[64];
  int res = 0;

  int bigarray[BIGARRAY_LEN];
  for (i = 0; i < BIGARRAY_LEN; i++){
    bigarray[i] = i;
  }

  pid = forkn(4, pids);
  if (pid == -1){
    exit(1, "error");
  }
  
  if(pid == 0){
    res = waitall(&num_killed, statuses);
    if(res == -1){
      exit(1, "");
    }
  }

  exit(0, "");
}