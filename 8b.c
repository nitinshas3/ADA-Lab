#include<stdio.h>
#include<stdlib.h>

int n;
int indeg[20];
int opcount=0;

int queue[20];
int front=-1;
int rear=-1;

int bfs(int n, int mat[n][n])
{
    int count=0;

    front=-1;
    rear=-1;

    for(int i=0;i<n;i++)
    {
        if(indeg[i]==0)
            queue[++rear]=i;
    }

    while(front!=rear)
    {
        int curr=queue[++front];

        count++;

        for(int i=0;i<n;i++)
        {
            opcount++;

            if(mat[curr][i])
            {
                indeg[i]--;

                if(indeg[i]==0)
                    queue[++rear]=i;
            }
        }
    }

    return count!=n;
}

void tester()
{
    printf("Enter number of vertices:\n");
    scanf("%d",&n);

    int adjMat[n][n];

    for(int i=0;i<n;i++)
        indeg[i]=0;

    printf("Enter adjacency matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adjMat[i][j]);

            if(adjMat[i][j])
                indeg[j]++;
        }
    }

    if(bfs(n,adjMat))
    {
        printf("Cycle Exists. Cannot perform Topological Sort\n");
        return;
    }

    printf("Topological Order:\n");

    for(int i=0;i<=rear;i++)
        printf("%d ",queue[i]);

    printf("\n");
}

void plotter()
{
    FILE *f1;

    f1=fopen("srcrmMatTopSort.txt","w");

    for(int k=1;k<=10;k++)
    {
        n=k;

        int adjMat[n][n];

        for(int i=0;i<n;i++)
            indeg[i]=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                adjMat[i][j]=0;
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                adjMat[i][j]=1;
                indeg[j]++;
            }
        }

        opcount=0;

        bfs(n,adjMat);

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