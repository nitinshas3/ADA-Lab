#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int beg, int end) {
    int pivot = arr[beg];
    int i = beg;
    int j = end + 1;

    do {
        do { count++; i++; } while (arr[i] < pivot);
        do { count++; j--; } while (arr[j] > pivot);
        swap(&arr[i], &arr[j]);
    } while (i < j);

    swap(&arr[i], &arr[j]);      // redundant but matches your code
    swap(&arr[beg], &arr[j]);    // put pivot in correct place
    return j;
}

void quicksort(int arr[], int beg, int end) {
    if (beg < end) {
        int split = partition(arr, beg, end);
        quicksort(arr, beg, split - 1);
        quicksort(arr, split + 1, end);
    }
}


void tester()
{
    int n;

    printf("Enter number of elements:\n");
    scanf("%d",&n);

    int arr[n+1];

    printf("Enter array elements:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    arr[n]=999999;     // sentinel

    printf("Array before sorting:\n");

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("\n");

    quicksort(arr,0,n-1);

    printf("Array after sorting:\n");

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("\n");
}

void plotter()
{
    srand(time(NULL));

    FILE *f1,*f2,*f3;

    f1=fopen("Quickbest.txt","w");
    f2=fopen("Quickworst.txt","w");
    f3=fopen("Quickavg.txt","w");

    int n=4;

    while(n<=1024)
    {
        int arr[n+1];

        /* Best Case */

        for(int i=0;i<n;i++)
            arr[i]=5;

        arr[n]=999999;

        count=0;

        quicksort(arr,0,n-1);

        fprintf(f1,"%d\t%d\n",n,count);

        /* Worst Case */

        for(int i=0;i<n;i++)
            arr[i]=i+1;

        arr[n]=999999;

        count=0;

        quicksort(arr,0,n-1);

        fprintf(f2,"%d\t%d\n",n,count);

        /* Average Case */

        for(int i=0;i<n;i++)
            arr[i]=rand()%n;

        arr[n]=999999;

        count=0;

        quicksort(arr,0,n-1);

        fprintf(f3,"%d\t%d\n",n,count);

        n=n*2;
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main()
{
    int ch;

    printf("Enter your choice:\n\n1.Tester\n2.Plotter\n\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
            tester();
            break;

        case 2:
            plotter();
            break;

        default:
            printf("Invalid choice!!!\n");
    }

    return 0;
}       