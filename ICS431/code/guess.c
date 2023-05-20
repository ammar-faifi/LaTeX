#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <unistd.h>

#define SIZE 1 // size of the shared memory segment
#define MAX_GUESSES 5

int main() {
  int shmid;
  char *shmptr, guess;
  key_t key = IPC_PRIVATE;
  pid_t pid;
  int guessCount = 0;

  // Create the shared memory segment,
  // read and write permissions for user, group, and others.
  if ((shmid = shmget(key, SIZE, IPC_CREAT | 0666)) < 0) {
    perror("shmget");
    exit(1);
  }

  // Attach the shared memory segment to our data space
  if ((shmptr = shmat(shmid, NULL, 0)) == (char *)-1) {
    perror("shmat");
    exit(1);
  }

  // Fork a child process
  pid = fork();
  if (pid < 0) {
    fprintf(stderr, "Fork Failed");
    return 1;
  } else if (pid > 0) { // Parent Process (Server)
    // Put a random letter in shared memory
    srand(time(0));
    *shmptr = 'A' + (rand() % 26);

    // Wait for the client to finish guessing
    wait(NULL);

    // Show the correct answer if client hasn't guessed correctly
    printf("The correct letter was %c\n", *shmptr);
  } else { // Child Process (Client)
    do {
      printf("Enter a letter to guess: ");
      scanf(" %c",
            &guess); // A space before %c is required to skip any leftover '\n'

      if (guess > *shmptr)
        printf("Your guess is too high.\n");
      else if (guess < *shmptr)
        printf("Your guess is too low.\n");
      else {
        printf("Congrats! You guessed the letter.\n");
        exit(0);
      }

      guessCount++;
    } while (guessCount < MAX_GUESSES);
  }

  // Detach from the shared memory segment
  if (shmdt(shmptr) == -1) {
    perror("shmdt");
    exit(1);
  }

  // Delete the shared memory segment
  if (shmctl(shmid, IPC_RMID, NULL) == -1) {
    perror("shmctl");
    exit(1);
  }

  return 0;
}
