#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define ROWS 40
#define COLS 40

int matrixA[ROWS][COLS];
int matrixB[ROWS][COLS];
int sumMatrix[ROWS][COLS];
int diffMatrix[ROWS][COLS];

void *computeSum(void *arg) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
    }
  }
  pthread_exit(NULL);
}

void *computeDiff(void *arg) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      diffMatrix[i][j] = matrixA[i][j] - matrixB[i][j];
    }
  }
  pthread_exit(NULL);
}

void printMatrix(int matrix[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  pthread_t threadSum, threadDiff;

  // Initialize matrices with binary inputs
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      matrixA[i][j] = rand() % 2;
      matrixB[i][j] = rand() % 2;
    }
  }

  // Create threads for computing sum and difference
  pthread_create(&threadSum, NULL, computeSum, NULL);
  pthread_create(&threadDiff, NULL, computeDiff, NULL);

  // Wait for threads to complete
  pthread_join(threadSum, NULL);
  pthread_join(threadDiff, NULL);

  printf("\nSum Matrix:\n");
  printMatrix(sumMatrix);

  printf("\nDifference Matrix:\n");
  printMatrix(diffMatrix);

  return 0;
}
