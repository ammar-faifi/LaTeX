#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *print_primes(void *arg) {
  int num = *(int *)arg;
  int i, j, flag;
  for (i = 2; i <= num; i++) {
    flag = 1;
    for (j = 2; j <= i / 2; j++) {
      if (i % j == 0) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) {
      printf("%d ", i);
    }
  }
  printf("\n");
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  int num = atoi(argv[1]);

  pthread_t tid;
  pthread_attr_t attr;
  pthread_attr_init(&attr);

  pthread_create(&tid, &attr, print_primes, &num);
  pthread_join(tid, NULL);

  return 0;
}
