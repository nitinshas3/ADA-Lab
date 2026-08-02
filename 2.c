#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

//---------------- Linear Search ----------------//

int linearSearch(int a[], int n, int key)
{
    count = 0;

    for(int i=0;i<n;i++)
    {
        count++;

        if(a[i]==key)
            return i;
    }

    return -1;
}

//---------------- Binary Search ----------------//

int binarySearch(int a[], int low, int high, int key)
{
    count++;

    if(low>high)
        return -1;

    int mid=(low+high)/2;

    if(a[mid]==key)
        return mid;

    if(key<a[mid])
        return binarySearch(a,low,mid-1,key);

    return binarySearch(a,mid+1,high,key);
}

//---------------- Tester ----------------//

void tester()
{
    int n,key,ch;
    int a[100];

    printf("\n1.Linear Search\n2.Binary Search\n");
    scanf("%d",&ch);

    printf("Enter array size: ");
    scanf("%d",&n);

    printf("Enter array elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter key: ");
    scanf("%d",&key);

    int ans;

    if(ch==1)
        ans=linearSearch(a,n,key);
    else
    {
        count=0;
        ans=binarySearch(a,0,n-1,key);
    }

    if(ans==-1)
        printf("Key Not Found\n");
    else
        printf("Key Found at Index %d\n",ans);

    printf("Operation Count = %d\n",count);
}

//---------------- Plotter ----------------//

void plotter()
{
    FILE *fl=fopen("linear.txt","w");
    FILE *fb=fopen("binary.txt","w");

    for(int n=2;n<=1024;n*=2)
    {
        int a[1100];

        // Sorted array
        for(int i=0;i<n;i++)
            a[i]=i+1;

        // Linear Worst Case
        linearSearch(a,n,n+1);
        fprintf(fl,"%d %d\n",n,count);

        // Binary Worst Case
        count=0;
        binarySearch(a,0,n-1,n+1);
        fprintf(fb,"%d %d\n",n,count);
    }

    fclose(fl);
    fclose(fb);

    printf("linear.txt and binary.txt created.\n");
}

//---------------- Main ----------------//

int main()
{
    int ch;

    do
    {
        printf("\n1.Tester\n2.Plotter\n3.Exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                tester();
                break;

            case 2:
                plotter();
                break;

            case 3:
                break;

            default:
                printf("Invalid Choice\n");
        }

    }while(ch!=3);

    return 0;
}