#include<stdio.h>
#include<stdlib.h>

int isCycle=0;
int components=0;
int n;
int opcount=0;
int isTester;

void bfs(int n, int mat[n][n], int vis[], int source)
{
    int queue[n];
    int parent[n];

    int front=-1;
    int rear=-1;

    vis[source]=1;

    queue[++rear]=source;
    parent[rear]=-1;

    while(rear!=front)
    {
        int curr=queue[++front];
        int par=parent[front];

        if(isTester)
            printf("%d ",curr);

        for(int i=0;i<n;i++)
        {
            opcount++;

            if(i!=par && mat[curr][i] && vis[i])
                isCycle=1;

            if(mat[curr][i] && !vis[i])
            {
                queue[++rear]=i;
                parent[rear]=curr;
                vis[i]=1;
            }
        }
    }
}

void checkConnectivity(int n, int mat[n][n])
{
    int vis[n];

    for(int i=0;i<n;i++)
        vis[i]=0;

    int k=1;

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            components++;

            if(isTester)
                printf("\nConnected Component %d: ",k++);

            bfs(n,mat,vis,i);
        }
    }
}

void tester()
{
    isTester=1;

    printf("Enter number of vertices:\n");
    scanf("%d",&n);

    int adjMat[n][n];

    printf("Enter adjacency matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adjMat[i][j]);
        }
    }

    components=0;
    isCycle=0;

    checkConnectivity(n,adjMat);

    printf("\nNumber of Connected Components: %d\n",components);

    if(isCycle)
        printf("Cycle Exists\n");
    else
        printf("Cycle Does Not Exist\n");
}

void plotter()
{
    isTester=0;

    FILE *f1;

    f1=fopen("bfsadjMat.txt","w");

    for(int k=1;k<=10;k++)
    {
        n=k;

        int adjMat[n][n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                    adjMat[i][j]=1;
                else
                    adjMat[i][j]=0;
            }
        }

        opcount=0;
        components=0;
        isCycle=0;

        checkConnectivity(n,adjMat);

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