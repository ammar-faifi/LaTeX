#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

int main() {
  char command[MAX_COMMAND_LENGTH];
  char *arguments[MAX_ARGUMENTS];
  pid_t pid;
  int status;
  printf("Enter commands (type 'exit' to quit): \n");
  while (1) {
    printf("201855360> ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    // Remove newline character
    command[strlen(command) - 1] = '\0';
    if (strcmp(command, "exit") == 0) {
      printf("Exiting shell program...\n");
      break;
    }
    // Parse command-line arguments
    char *token;
    int i = 0;
    token = strtok(command, " ");
    while (token != NULL) {
      arguments[i++] = token;
      token = strtok(NULL, " ");
    }
    arguments[i] = NULL; // Set last element to NULL for execvp
    pid = fork();
    if (pid == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      // Child process
      if (execvp(arguments[0], arguments) == -1) {
        perror("execvp");
        exit(EXIT_FAILURE);
      }
    } else {
      // Parent process
      if (waitpid(pid, &status, 0) == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
      }
      printf("Terminated: ");
      if (WIFEXITED(status)) {
        printf("Normally\n");
        printf("Exit status: %d\n", WEXITSTATUS(status));
      } else if (WIFSIGNALED(status)) {
        printf("Due to signal\n");
        printf("Signal number: %d\n", WTERMSIG(status));
      }
    }
  }
  return 0;
}
