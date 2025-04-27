#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#define BIGARRAY_LEN 65536

int
main(int argc, char *argv[])
{
  int i;
  int num_forks = 4;
  int pids[num_forks];
  int pid;
  int num_killed;
  int statuses[64];
  int res = 0;
  int total_sum = 0;
  int start = 0;
  int end = 0;
  int sum = 0;


  pid = forkn(num_forks, pids);
  if (pid == -1){
    exit(1, "error");
  }
  if(pid == 0){
    res = waitall(&num_killed, statuses);
    if(res == -1){
      exit(1, "");
    }
  }
  else {
    start = (pid - 1) * (BIGARRAY_LEN / num_forks);
    end = start + (BIGARRAY_LEN / num_forks);
    sum = 0;

    for (i = start; i < end; i++) {
      sum += i;
    }

    printf("Partial sum from process %d: %d\n", pid, sum);
    exit(sum, "");
  }

  if (pid == 0) {
    for (i = 0; i < num_forks; i++) {
      total_sum += statuses[i];
    }
    printf("Killed %d processes\n", num_killed);
    printf("\nTotal sum: %d\n", total_sum);
  }


  exit(0, "");
}