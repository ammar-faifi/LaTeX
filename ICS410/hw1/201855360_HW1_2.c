#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function to perform a simple bubble sort
void bubbleSort(int arr[], int n) {
  int swapped;

  do {
    for (int i = 0; i < n - 1; i++) {
      swapped = 0;
      for (int j = 0; j < n - i - 1; j++) {
        // If the current element is larger than the next element, swap them
        if (arr[j] > arr[j + 1]) {
          swap(&arr[j], &arr[j + 1]);
          swapped = 1;
        }
      }
    }
  } while (swapped);
}

int main() {
  int size;

  printf("Enter array size: ");
  scanf("%d", &size);

  int array[2 * size];

  printf("Enter %d elements in the 1st array:\n", size);
  for (int i = 0; i < 2 * size; i++) {
    if (i > 0 && i % size == 0) {
      printf("\nEnter %d elements in the 2nd array:\n", size);
    }
    printf("element [%d] : ", i % size);
    scanf("%d", &array[i]);
  }

  // Sort both arrays
  bubbleSort(array, 2 * size);

  // Combine the arrays in zigcending order
  printf("The combined array in zigcending order is:\n\n");
  for (int i = 0; i < size; i++) {
    printf("%d,%d, ", array[2 * size - i - 1], array[i]);
  }
  printf("\n");

  return 0;
}
