#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;  // single counter for comparisons

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n) {
        count++;
        if (arr[left] > arr[largest]) largest = left;
    }

    if (right < n) {
        count++;
        if (arr[right] > arr[largest]) largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void tester() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    count = 0;
    heapSort(arr, n);

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nComparisons: %d\n", count);
}

void plotter() {
    srand(time(NULL));
    FILE *f1 = fopen("heapBest.txt", "w");
    FILE *f2 = fopen("heapWorst.txt", "w");
    FILE *f3 = fopen("heapAvg.txt", "w");

    int n = 100;
    while (n <= 1000) {
        int arr[n];

        // Best Case (descending order)
        for (int i = 0; i < n; i++) arr[i] = n - i;
        count = 0;
        heapSort(arr, n);
        fprintf(f1, "%d\t%d\n", n, count);

        // Worst Case (ascending order)
        for (int i = 0; i < n; i++) arr[i] = i + 1;
        count = 0;
        heapSort(arr, n);
        fprintf(f2, "%d\t%d\n", n, count);

        // Average Case (random)
        for (int i = 0; i < n; i++) arr[i] = rand() % n;
        count = 0;
        heapSort(arr, n);
        fprintf(f3, "%d\t%d\n", n, count);

        n += 100;
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main() {
    int ch;
    printf("Enter\n1.Tester\n2.Plotter\n");
    scanf("%d", &ch);

    switch (ch) {
        case 1: tester(); break;
        case 2: plotter(); break;
        default: printf("Invalid Choice\n");
    }
    return 0;
}
