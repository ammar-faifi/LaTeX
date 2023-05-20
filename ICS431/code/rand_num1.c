#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int arr[SIZE];
pthread_mutex_t lock;
int idx = 0;
int produced = 0;

void *produce(void *arg) {
  srand(time(0));
  while (idx < SIZE) {
    if (produced == 0) {
      pthread_mutex_lock(&lock);
      int num = rand() % 100;
      arr[idx++] = num;
      printf("Produced: %d\n", num);
      produced = 1;
      pthread_mutex_unlock(&lock);
    }
  }
  return NULL;
}

void *consume(void *arg) {
  int curr_index = 0;
  while (curr_index < SIZE) {
    pthread_mutex_lock(&lock);
    if (curr_index < idx && produced == 1) {
      printf("Consumed: %d\n", arr[curr_index++]);
      produced = 0;
    }
    pthread_mutex_unlock(&lock);
  }
  return NULL;
}

int main() {
  pthread_t producer, consumer;
  pthread_mutex_init(&lock, NULL);

  pthread_create(&producer, NULL, &produce, NULL);
  pthread_create(&consumer, NULL, &consume, NULL);

  pthread_join(producer, NULL);
  pthread_join(consumer, NULL);

  pthread_mutex_destroy(&lock);

  return 0;
}
