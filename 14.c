// prims
#include <stdio.h>
#include <limits.h>

int n, opcount = 0;

int prims(int adjMat[100][100])
{
    int parent[100], key[100], visited[100];
    int cost = 0;

    // Initialization
    for(int i=0;i<n;i++)
    {
        key[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    key[0] = 0;

    // Prim's Algorithm
    for(int count=0; count<n-1; count++)
    {
        int min = INT_MAX, u = -1;

        // Find minimum key vertex
        for(int i=0;i<n;i++)
        {
            opcount++;
            if(!visited[i] && key[i] < min)
            {
                min = key[i];
                u = i;
            }
        }

        visited[u] = 1;

        // Update adjacent vertices
        for(int v=0;v<n;v++)
        {
            opcount++;

            if(adjMat[u][v] != INT_MAX &&
               !visited[v] &&
               adjMat[u][v] < key[v])
            {
                key[v] = adjMat[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nEdges in MST:\n");

    for(int i=1;i<n;i++)
    {
        printf("%d - %d\n", parent[i], i);
        cost += key[i];
    }

    return cost;
}

void tester()
{
    int adjMat[100][100];

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix (-1 for no edge):\n");

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adjMat[i][j]);

            if(adjMat[i][j]==-1)
                adjMat[i][j]=INT_MAX;
        }

    opcount = 0;

    printf("\nMinimum Cost = %d\n",prims(adjMat));

    printf("Operation Count = %d\n",opcount);
}

void plotter()
{
    FILE *fp=fopen("prims.txt","w");

    for(n=5;n<=25;n+=5)
    {
        int adjMat[100][100];

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    adjMat[i][j]=0;
                else
                    adjMat[i][j]=i+j+1;
            }

        opcount=0;

        prims(adjMat);

        fprintf(fp,"%d %d\n",n,opcount);
    }

    fclose(fp);

    printf("Data stored in prims.txt\n");
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