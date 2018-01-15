#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  int statval = 0, exstat = 0;
  pid_t pid; 
  for(int i = 0; i<2; i++){
    if(fork() == 0){
        printf("child %d\n", i);
        sleep(1);
        printf("done %d\n",i);
        exit(1);
    }
  }
  while (pid = waitpid(-1, &statval, 0)) {
   if (errno == ECHILD) {
      break;
   } else {
   	exstat += WEXITSTATUS(statval);
   }
  }
  printf("%d\n",exstat);
  return 0;
}