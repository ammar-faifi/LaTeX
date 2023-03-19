#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100
#define RANGE 10

int A[N], B[N], C[N];

void *sum(void *arg) {
  int i = *(int *)arg;
  C[i] = A[i] + B[i];
  return NULL;
}

int main() {
  srandom(time(NULL)); // randomize seed

  // initialize A and B
  for (int i = 0; i < N; i++) {
    A[i] = random() % RANGE;
    B[i] = random() % RANGE;
  }

  // create N threads to compute C[i] = A[i] + B[i]
  pthread_t threads[N];
  for (int i = 0; i < N; i++) {
    pthread_create(&threads[i], NULL, sum, &i);
  }

  // wait for all threads to finish
  for (int i = 0; i < N; i++) {
    pthread_join(threads[i], NULL);
  }

  // print A, B, and C
  printf("A = [");
  for (int i = 0; i < N; i++) {
    printf("%d ", A[i]);
  }
  printf("]\n");

  printf("B = [");
  for (int i = 0; i < N; i++) {
    printf("%d ", B[i]);
  }
  printf("]\n");

  printf("C = [");
  for (int i = 0; i < N; i++) {
    printf("%d ", C[i]);
  }
  printf("]\n");

  return 0;
}
