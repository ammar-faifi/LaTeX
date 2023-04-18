#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *fibonacci(void *arg) {
  int n = *((int *)arg);
  int *seq = (int *)malloc(sizeof(int) * n);
  seq[0] = 0;
  seq[1] = 1;

  for (int i = 2; i < n; i++) {
    seq[i] = seq[i - 1] + seq[i - 2];
  }

  pthread_exit((void *)seq);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <n>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  pthread_t thread;
  void *seq;

  pthread_create(&thread, NULL, fibonacci, (void *)&n);
  pthread_join(thread, &seq);

  int *fib_seq = (int *)seq;
  for (int i = 0; i < n; i++) {
    printf("%d ", fib_seq[i]);
  }
  printf("\n");

  free(fib_seq);
  return 0;
}
