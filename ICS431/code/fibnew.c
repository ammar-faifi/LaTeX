#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SEQUENCE 100
#define NUM_THREADS 2

int fib_sequence[MAX_SEQUENCE];
int last_idx = -1; // initialize last index to -1

pthread_mutex_t mutex;

void *fibonacci(void *arg) {
  int n = *((int *)arg);
  fib_sequence[0] = 0;
  fib_sequence[1] = 1;

  for (int i = 2; i < n; i++) {
    pthread_mutex_lock(&mutex);
    fib_sequence[i] = fib_sequence[i - 1] + fib_sequence[i - 2];
    last_idx = i; // update last index to i
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  pthread_t threads[NUM_THREADS];

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <Number of fib elements>\n", argv[0]);
    exit(-1);
  }
  int n = atoi(argv[1]);

  pthread_mutex_init(&mutex, NULL);

  int rc = pthread_create(&threads[0], NULL, fibonacci, (void *)&n);
  if (rc) {
    printf("ERROR; return code from pthread_create() is %d\n", rc);
    exit(-1);
  }

  while (last_idx < n - 1) { // loop until all values are updated by the child
    pthread_mutex_lock(&mutex);
    int idx = last_idx;
    pthread_mutex_unlock(&mutex);

    if (idx >= 0) { // print new values if there are any
      for (int i = 0; i <= idx; i++) {
        printf("%d ", fib_sequence[i]);
      }
      printf("\n");
    }
  }

  pthread_join(threads[0], NULL);

  pthread_mutex_destroy(&mutex);
  pthread_exit(NULL);
}
