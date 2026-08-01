// memoizatoin or memory function 
#include <stdio.h>

int dp[100][100];
int weight[100], profit[100];
int opcount = 0;

int max(int a,int b)
{
    return (a>b)?a:b;
}

void init(int n,int W)
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else
                dp[i][j]=-1;
        }
}

int knapsackMemo(int n,int W)
{
    if(dp[n][W]!=-1)
        return dp[n][W];

    opcount++;

    if(weight[n-1] <= W)
        dp[n][W]=max(knapsackMemo(n-1,W),
                     profit[n-1]+knapsackMemo(n-1,W-weight[n-1]));
    else
        dp[n][W]=knapsackMemo(n-1,W);

    return dp[n][W];
}

void tester()
{
    int n,W;

    printf("Enter number of items: ");
    scanf("%d",&n);

    printf("Enter capacity: ");
    scanf("%d",&W);

    for(int i=0;i<n;i++)
    {
        printf("Weight Profit of item %d: ",i+1);
        scanf("%d%d",&weight[i],&profit[i]);
    }

    init(n,W);

    printf("\nMaximum Profit = %d\n",knapsackMemo(n,W));

    printf("\nDP Table:\n");

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
            printf("%d ",dp[i][j]);
        printf("\n");
    }

    printf("\nSelected Items:\n");

    int i=n,j=W;

    while(i>0 && j>0)
    {
        if(dp[i][j]!=dp[i-1][j])
        {
            printf("%d ",i);
            j-=weight[i-1];
        }
        i--;
    }

    printf("\nOpcount = %d\n",opcount);
}

void plotter()
{
    FILE *fp=fopen("knapsackMemo.txt","w");

    for(int n=5;n<=10;n++)
    {
        int W=n*2;

        for(int i=0;i<n;i++)
        {
            weight[i]=i+1;
            profit[i]=(i+1)*10;
        }

        init(n,W);

        opcount=0;

        knapsackMemo(n,W);

        fprintf(fp,"%d %d\n",n,opcount);
    }

    fclose(fp);

    printf("Data stored in knapsackMemo.txt\n");
}

int main()
{
    int ch;

    printf("1.Tester\n2.Plotter\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: tester(); break;
        case 2: plotter(); break;
        default: printf("Invalid Choice");
    }

    return 0;
}