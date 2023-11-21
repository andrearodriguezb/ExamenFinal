#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sequentialSearch(int arr[], int element, int num) {
  int i;
  for (i = 0; i < num; i++) {
    if (arr[i] == element) {
      return (i + 1);
    }
  }
  return -1;
}

int binarySearch(int arr[], int element, int first, int last) {
  if (first <= last) {
    int middle = (first + last) / 2;

    if (element == arr[middle]) {
      return (middle + 1);
    } else if (element < arr[middle]) {
      return binarySearch(arr, element, first, middle - 1);
    } else {
      return binarySearch(arr, element, middle + 1, last);
    }
  }
  return -1;
}

float calculateAverage(float times[], int n) {
  float sum = 0;
  int i;
  for (i = 0; i < n; i++) {
    sum += times[i];
  }
  return sum / n;
}

int indexOfMax(float times[], int n) {
  int i, index = 0;
  float maximum = -10000;
  for (i = 0; i < n; i++) {
    if (times[i] > maximum) {
      index = i;
      maximum = times[i];
    }
  }
  return index;
}

int indexOfMin(float times[], int n) {
  int i, index = 0;
  float minimum = 10000;
  for (i = 0; i < n; i++) {
    if (times[i] < minimum) {
      index = i;
      minimum = times[i];
    }
  }
  return index;
}

int main() {
  int array[500000];
  float timesBinary[100], timesSequential[100], cumulativeBinary = 0, cumulativeSequential = 0;
  int i, element;

  for (i = 0; i < 500000; i++) {
    array[i] = i;
  }

  for (i = 0; i < 100; i++) {
    element = rand() % 500000;

    clock_t startSequential = clock();
    sequentialSearch(array, element, 500000);
    clock_t endSequential = clock();
    timesSequential[i] = ((double)(endSequential - startSequential) / CLOCKS_PER_SEC);
    cumulativeSequential += timesSequential[i];

    clock_t startBinary = clock();
    binarySearch(array, element, 0, 500000);
    clock_t endBinary = clock();
    timesBinary[i] = ((double)(endBinary - startBinary) / CLOCKS_PER_SEC);
    cumulativeBinary += timesBinary[i];
  }

  printf("\nSequential Search\n");
  printf("Average time: %f\n", calculateAverage(timesSequential, 100));
  printf("Max time of Sequential Search: %f\n", timesSequential[indexOfMax(timesSequential, 100)]);
  printf("Min time of Sequential Search: %f\n", timesSequential[indexOfMin(timesSequential, 100)]);

  printf("\nBinary Search");
  printf("\nAverage time: %f\n", calculateAverage(timesBinary, 100));
  printf("Max time of Binary Search: %f\n", timesBinary[indexOfMax(timesBinary, 100)]);
  printf("Min time of Binary Search: %f\n", timesBinary[indexOfMin(timesBinary, 100)]);

  return 0;
}

