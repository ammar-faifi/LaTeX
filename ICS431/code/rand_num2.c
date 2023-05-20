#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int arr[SIZE];
sem_t empty;
sem_t full;
int idx = 0;
int produced = 0;

void *produce(void *arg) {
  srand(time(0));
  while (idx < SIZE) {
    if (produced == 0) {
      int num = rand() % 100;
      sem_wait(&empty);
      arr[idx++] = num;
      printf("Produced: %d\n", num);
      produced = 1;
      sem_post(&full);
    }
  }
  return NULL;
}

void *consume(void *arg) {
  int curr_index = 0;
  while (curr_index < SIZE) {
    if (produced == 1) {
      sem_wait(&full);
      printf("Consumed: %d\n", arr[curr_index++]);
      produced = 0;
      sem_post(&empty);
    }
  }
  return NULL;
}

int main() {
  pthread_t producer, consumer;

  sem_init(&empty, 0, SIZE);
  sem_init(&full, 0, 0);

  pthread_create(&producer, NULL, &produce, NULL);
  pthread_create(&consumer, NULL, &consume, NULL);

  pthread_join(producer, NULL);
  pthread_join(consumer, NULL);

  sem_destroy(&empty);
  sem_destroy(&full);

  return 0;
}
