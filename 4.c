#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int count=0;

int stringmatching(char text[], char pattern[], int n, int m)
{
    count=0;

    for(int i=0;i<=n-m;i++)
    {
        int j=0;

        while(j<m)
        {
            count++;

            if(pattern[j]!=text[i+j])
                break;

            j++;
        }

        if(j==m)
            return 1;
    }

    return 0;
}

void tester()
{
    int n,m;

    printf("Enter text length: ");
    scanf("%d",&n);

    char text[n+1];

    printf("Enter text: ");
    scanf(" %[^\n]",text);

    printf("Enter pattern length: ");
    scanf("%d",&m);

    char pattern[m+1];

    printf("Enter pattern: ");
    scanf(" %[^\n]",pattern);

    if(stringmatching(text,pattern,n,m))
        printf("\nPattern Found\n");
    else
        printf("\nPattern Not Found\n");
}

void plotter()
{
    srand(time(NULL));

    FILE *f1,*f2,*f3;

    f1=fopen("strbest.txt","w");
    f2=fopen("strworst.txt","w");
    f3=fopen("stravg.txt","w");

    char text[1000];

    for(int i=0;i<1000;i++)
        text[i]='a';

    int n=1000;
    int m=10;

    while(m<=1000)
    {
        char pattern[m];

        /* Best Case */

        for(int i=0;i<m;i++)
            pattern[i]='a';

        stringmatching(text,pattern,n,m);

        fprintf(f1,"%d\t%d\n",m,count);

        /* Worst Case */

        for(int i=0;i<m;i++)
            pattern[i]='a';

        pattern[m-1]='b';

        stringmatching(text,pattern,n,m);

        fprintf(f2,"%d\t%d\n",m,count);

        /* Average Case */

        for(int i=0;i<m;i++)
            pattern[i]='a'+rand()%3;

        stringmatching(text,pattern,n,m);

        fprintf(f3,"%d\t%d\n",m,count);

        if(m<100)
            m+=10;
        else
            m+=100;
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main()
{
    int ch;

    printf("Enter\n1.Tester\n2.Plotter\n");
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
            printf("Invalid Choice\n");
    }

    return 0;
}