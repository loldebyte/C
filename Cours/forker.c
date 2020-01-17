#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
  int pid = fork();
  if (pid == 0)
    execv("./hello.c", NULL);
  else {
    printf("fatha process : my pid is %d and this, is my son : %d\n", getpid(), pid);
  }
  waitpid(pid, NULL,0);
}