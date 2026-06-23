#include<stdio.h>
#include<stdlib.h>

int n;
int opcount=0;
int top=-1;
int isCycle=0;

void dfs(int n, int mat[n][n], int vis[], int track[], int source, int stack[])
{
    vis[source]=1;
    track[source]=1;

    for(int i=0;i<n;i++)
    {
        opcount++;

        if(mat[source][i] && vis[i] && track[i])
        {
            isCycle=1;
            return;
        }

        if(mat[source][i] && !vis[i])
            dfs(n,mat,vis,track,i,stack);
    }

    stack[++top]=source;
    track[source]=0;
}

void topologicalSort(int n, int mat[n][n], int stack[])
{
    int vis[n];
    int track[n];

    for(int i=0;i<n;i++)
    {
        vis[i]=0;
        track[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            dfs(n,mat,vis,track,i,stack);
    }
}

void tester()
{
    printf("Enter number of vertices:\n");
    scanf("%d",&n);

    int adjMat[n][n];
    int stack[n];

    printf("Enter adjacency matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adjMat[i][j]);
        }
    }

    top=-1;
    isCycle=0;

    topologicalSort(n,adjMat,stack);

    if(isCycle)
    {
        printf("Cycle Exists. Cannot perform Topological Sort\n");
        return;
    }

    printf("Topological Order:\n");

    while(top!=-1)
    {
        printf("%d ",stack[top--]);
    }

    printf("\n");
}

void plotter()
{
    FILE *f1;

    f1=fopen("bfsMatTopSort.txt","w");

    for(int k=1;k<=10;k++)
    {
        n=k;

        int adjMat[n][n];
        int stack[n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                adjMat[i][j]=0;
            }
        }

        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                adjMat[i][j]=1;
            }
        }

        opcount=0;
        top=-1;
        isCycle=0;

        topologicalSort(n,adjMat,stack);

        fprintf(f1,"%d\t%d\n",n,opcount);
    }

    fclose(f1);
}

int main()
{
    int choice;

    printf("Enter\n1.Tester\n2.Plotter\n");
    scanf("%d",&choice);

    switch(choice)
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