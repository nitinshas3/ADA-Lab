// knapsack tabulation 
// bottom up 
#include <stdio.h>

int dp[100][100], weight[100], profit[100], opcount = 0;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void knapsack(int n, int W)
{
    opcount = 0;

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;

            else if(weight[i-1] <= j)
            {
                opcount++;
                dp[i][j]=max(dp[i-1][j],
                             profit[i-1]+dp[i-1][j-weight[i-1]]);
            }

            else
            {
                opcount++;
                dp[i][j]=dp[i-1][j];
            }
        }
    }
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

    knapsack(n,W);

    printf("\nMaximum Profit = %d\n",dp[n][W]);

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
    FILE *fp=fopen("knapsackBottomUp.txt","w");

    for(int n=5;n<=10;n++)
    {
        int W=n*2;

        for(int i=0;i<n;i++)
        {
            weight[i]=i+1;
            profit[i]=(i+1)*10;
        }

        knapsack(n,W);

        fprintf(fp,"%d %d\n",n,opcount);
    }

    fclose(fp);

    printf("Data stored in knapsackBottomUp.txt\n");
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