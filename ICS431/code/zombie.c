#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid;
  pid = fork();
  printf("PID: %d\n", pid);

  if (pid < 0) {
    fprintf(stderr, "Fork failed.\n");
    exit(1);
  } else if (pid == 0) {
    printf("This is the child process.\n");
    sleep(5);
    printf("Child process exiting.\n");
    exit(0);
  } else {
    printf("This is the parent process.\n");
    sleep(10);
    waitpid(pid, NULL, 0); // wait for child process to exit
    printf("Parent process exiting.\n");
    exit(0);
  }

  return 0;
}
