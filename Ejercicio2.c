#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int size) 
{
	int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int size) 
{
	int i,j;
    for (i = 1; i < size; i++) {
        int key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int low, int high) 
{
	int j;
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bubbleSort(int arr[], int size) 
{
	int i,j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int arraySize = 10000;
    const int numExecutions = 100;
    clock_t start, end;
    double cpu_time_used;
    
    int i,j;

    int originalArray[arraySize];
    int workingArray[arraySize];

    srand(time(NULL));

    for (i = 0; i < arraySize; i++) {
        originalArray[i] = rand() % 10000;
    }

    double insertionSortTimes[numExecutions];

    for (i = 0; i < numExecutions; i++) {
        for (j = 0; j < arraySize; j++) {
            workingArray[j] = originalArray[j];
        }

        start = clock();
        insertionSort(workingArray, arraySize);
        end = clock();

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000.0;
        insertionSortTimes[i] = cpu_time_used;
    }

    double insertionSortSum = 0;
    double insertionSortMin = insertionSortTimes[0];
    double insertionSortMax = insertionSortTimes[0];

    for (i = 0; i < numExecutions; i++) {
        insertionSortSum += insertionSortTimes[i];

        if (insertionSortTimes[i] < insertionSortMin) {
            insertionSortMin = insertionSortTimes[i];
        }

        if (insertionSortTimes[i] > insertionSortMax) {
            insertionSortMax = insertionSortTimes[i];
        }
    }
    
   
    printf("Insertion Sort:\n");
    printf("Tiempo promedio: %f milisegundos\n", insertionSortSum / numExecutions);
    printf("Tiempo minimo: %f milisegundos\n", insertionSortMin);
    printf("Tiempo maximo: %f milisegundos\n", insertionSortMax);
    
    double quickSortTimes[numExecutions];

    for (i = 0; i < numExecutions; i++) {
        for (j = 0; j < arraySize; j++) {
            workingArray[j] = originalArray[j];
        }

        start = clock();
        quickSort(workingArray, 0, arraySize - 1);
        end = clock();

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000.0;
        quickSortTimes[i] = cpu_time_used;
    }

    double quickSortSum = 0;
    double quickSortMin = quickSortTimes[0];
    double quickSortMax = quickSortTimes[0];

    for (i = 0; i < numExecutions; i++) {
        quickSortSum += quickSortTimes[i];

        if (quickSortTimes[i] < quickSortMin) {
            quickSortMin = quickSortTimes[i];
        }

        if (quickSortTimes[i] > quickSortMax) {
            quickSortMax = quickSortTimes[i];
        }
    }
printf("-------");
    printf("\nQuick Sort :\n");
    printf("Tiempo promedio: %f milisegundos\n", quickSortSum / numExecutions);
    printf("Tiempo minimo: %f milisegundos\n", quickSortMin);
    printf("Tiempo maximo: %f milisegundos\n", quickSortMax);
    
    double bubbleSortTimes[numExecutions];

    for (i = 0; i < numExecutions; i++) {
        for (j = 0; j < arraySize; j++) {
            workingArray[j] = originalArray[j];
        }

        start = clock();
        bubbleSort(workingArray, arraySize);
        end = clock();

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000.0;
        bubbleSortTimes[i] = cpu_time_used;
    }

    double bubbleSortSum = 0;
    double bubbleSortMin = bubbleSortTimes[0];
    double bubbleSortMax = bubbleSortTimes[0];

    for (i = 0; i < numExecutions; i++) {
        bubbleSortSum += bubbleSortTimes[i];

        if (bubbleSortTimes[i] < bubbleSortMin) {
            bubbleSortMin = bubbleSortTimes[i];
        }

        if (bubbleSortTimes[i] > bubbleSortMax) {
            bubbleSortMax = bubbleSortTimes[i];
        }
    }
printf("-------");
    printf("\nBubble sort:\n");
    printf("Tiempo promedio: %f milisegundos\n", bubbleSortSum / numExecutions);
    printf("Tiempo minimo: %f milisegundos\n", bubbleSortMin);
    printf("tiempo maximo: %f milisegundos\n\n", bubbleSortMax);
    


    return 0;
}
