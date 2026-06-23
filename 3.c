#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count;

/* Bubble Sort */
void bubbleSort(int arr[], int n)
{
    count = 0;

    for(int i=0;i<n-1;i++)
    {
        int flag=0;

        for(int j=0;j<n-i-1;j++)
        {
            count++;

            if(arr[j] > arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

                flag=1;
            }
        }

        if(flag==0)
            break;
    }
}

/* Insertion Sort */
void insertionSort(int arr[], int n)
{
    count = 0;

    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;

        while(++count && j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=key;
    }
}

/* Selection Sort */
void selectionSort(int arr[], int n)
{
    count = 0;

    for(int i=0;i<n-1;i++)
    {
        int min=i;

        for(int j=i+1;j<n;j++)
        {
            count++;

            if(arr[j] < arr[min])
                min=j;
        }

        if(min!=i)
        {
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}

/* Bubble Sort Plotter */
void plotterBubble()
{
    FILE *f1,*f2,*f3;

    f1=fopen("Bubblebest.txt","w");
    f2=fopen("Bubbleworst.txt","w");
    f3=fopen("Bubbleavg.txt","w");

    int n=10;

    while(n<=30000)
    {
        int arr[n];

        for(int i=0;i<n;i++)
            arr[i]=n-i;

        bubbleSort(arr,n);
        fprintf(f2,"%d\t%d\n",n,count);

        for(int i=0;i<n;i++)
            arr[i]=i+1;

        bubbleSort(arr,n);
        fprintf(f1,"%d\t%d\n",n,count);

        for(int i=0;i<n;i++)
            arr[i]=rand()%n;

        bubbleSort(arr,n);
        fprintf(f3,"%d\t%d\n",n,count);

        if(n<10000)
            n*=10;
        else
            n+=10000;
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
}

/* Insertion Sort Plotter */
void plotterInsertion()
{
    FILE *f1,*f2,*f3;

    f1=fopen("Insertionbest.txt","w");
    f2=fopen("Insertionworst.txt","w");
    f3=fopen("Insertionavg.txt","w");

    int n=10;

    while(n<=30000)
    {
        int arr[n];

        for(int i=0;i<n;i++)
            arr[i]=n-i;

        insertionSort(arr,n);
        fprintf(f2,"%d\t%d\n",n,count);

        for(int i=0;i<n;i++)
            arr[i]=i+1;

        insertionSort(arr,n);
        fprintf(f1,"%d\t%d\n",n,count);

        for(int i=0;i<n;i++)
            arr[i]=rand()%n;

        insertionSort(arr,n);
        fprintf(f3,"%d\t%d\n",n,count);

        if(n<10000)
            n*=10;
        else
            n+=10000;
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
}

/* Selection Sort Plotter */
void plotterSelection()
{
    FILE *f1;

    f1=fopen("Selectionsort.txt","w");

    int n=10;

    while(n<=30000)
    {
        int arr[n];

        for(int i=0;i<n;i++)
            arr[i]=i;

        selectionSort(arr,n);

        fprintf(f1,"%d\t%d\n",n,count);

        if(n<10000)
            n*=10;
        else
            n+=10000;
    }

    fclose(f1);
}

/* Tester */
void tester()
{
    int n,ch;

    printf("Enter array size: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter array elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("\n1.Bubble Sort");
    printf("\n2.Insertion Sort");
    printf("\n3.Selection Sort");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
            bubbleSort(arr,n);
            printf("\nArray after Bubble Sort:\n");
            break;

        case 2:
            insertionSort(arr,n);
            printf("\nArray after Insertion Sort:\n");
            break;

        case 3:
            selectionSort(arr,n);
            printf("\nArray after Selection Sort:\n");
            break;

        default:
            printf("Invalid Choice\n");
            return;
    }

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("\n");
}

/* Main */
int main()
{
    int ch;

    srand(time(NULL));

    printf("Enter\n1.Tester\n2.Plotter\n");
    scanf("%d",&ch);

    if(ch==1)
    {
        tester();
    }
    else if(ch==2)
    {
        printf("\n1.Bubble Sort");
        printf("\n2.Insertion Sort");
        printf("\n3.Selection Sort");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                plotterBubble();
                break;

            case 2:
                plotterInsertion();
                break;

            case 3:
                plotterSelection();
                break;

            default:
                printf("Invalid Choice\n");
        }
    }
    else
    {
        printf("Invalid Choice\n");
    }

    return 0;
}