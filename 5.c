#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count;

void merge(int arr[], int beg, int mid, int end)
{
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    int left[n1], right[n2];

    for(int i=0;i<n1;i++)
        left[i] = arr[beg+i];

    for(int j=0;j<n2;j++)
        right[j] = arr[mid+j+1];

    int i=0,j=0,k=beg;

    while(i<n1 && j<n2)
    {
        count++;

        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while(i<n1)
        arr[k++] = left[i++];

    while(j<n2)
        arr[k++] = right[j++];
}

void mergeSort(int arr[], int beg, int end)
{
    if(beg < end)
    {
        int mid = (beg+end)/2;

        mergeSort(arr,beg,mid);
        mergeSort(arr,mid+1,end);

        merge(arr,beg,mid,end);
    }
}

void worst(int arr[], int beg, int end)
{
    if(beg < end)
    {
        int mid = (beg+end)/2;

        int n1 = mid-beg+1;
        int n2 = end-mid;

        int a[n1], b[n2];

        for(int i=0;i<n1;i++)
            a[i] = arr[2*i];

        for(int j=0;j<n2;j++)
            b[j] = arr[(2*j)+1];

        worst(a,beg,mid);
        worst(b,mid+1,end);

        int i,j;

        for(i=0;i<n1;i++)
            arr[i] = a[i];

        for(j=0;j<n2;j++)
            arr[i+j] = b[j];
    }
}

void tester()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter array elements:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("Array before sorting:\n");

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("\n");

    mergeSort(arr,0,n-1);

    printf("Array after sorting:\n");

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("\n");
}

void plotter()
{
    srand(time(NULL));

    FILE *f1,*f2,*f3,*f4;

    f1 = fopen("Mergebest.txt","w");
    f2 = fopen("Mergeworst.txt","w");
    f3 = fopen("Mergeavg.txt","w");
    f4 = fopen("Worstdata.txt","w");

    for(int n=2;n<=1024;n=n*2)
    {
        int arr[n];

        /* Best Case */
        for(int i=0;i<n;i++)
            arr[i]=i+1;

        count=0;
        mergeSort(arr,0,n-1);

        fprintf(f1,"%d\t%d\n",n,count);

        /* Worst Case */
        count=0;

        worst(arr,0,n-1);

        for(int i=0;i<n;i++)
            fprintf(f4,"%d",arr[i]);

        fprintf(f4,"\n");

        mergeSort(arr,0,n-1);

        fprintf(f2,"%d\t%d\n",n,count);

        /* Average Case */
        for(int i=0;i<n;i++)
            arr[i]=rand()%n;

        count=0;

        mergeSort(arr,0,n-1);

        fprintf(f3,"%d\t%d\n",n,count);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);

    printf("Data entered into files\n");
}

int main()
{
    int ch;

    printf("Enter your choice:\n\n1.Tester\n2.Plotter\n");
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
            printf("Invalid Choice!!!\n");
    }

    return 0;
}