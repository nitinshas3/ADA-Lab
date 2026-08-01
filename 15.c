//dijkstras
#include <stdio.h>
#include <limits.h>

int n, opcount = 0;

void dijkstra(int adjMat[100][100], int source)
{
    int dist[100], visited[100];

    // Initialization
    for(int i=0;i<n;i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Dijkstra Algorithm
    for(int count=0; count<n-1; count++)
    {
        int min = INT_MAX, u = -1;

        // Find minimum distance vertex
        for(int i=0;i<n;i++)
        {
            opcount++;
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // Update distances
        for(int v=0;v<n;v++)
        {
            opcount++;

            if(!visited[v] &&
               adjMat[u][v] != INT_MAX &&
               dist[u] != INT_MAX &&
               dist[u] + adjMat[u][v] < dist[v])
            {
                dist[v] = dist[u] + adjMat[u][v];
            }
        }
    }

    printf("\nShortest Distances from Source %d:\n", source);

    for(int i=0;i<n;i++)
        printf("%d -> %d = %d\n", source, i, dist[i]);
}

void tester()
{
    int adjMat[100][100], source;

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

    printf("Enter source vertex: ");
    scanf("%d",&source);

    opcount = 0;

    dijkstra(adjMat, source);

    printf("\nOperation Count = %d\n", opcount);
}

void plotter()
{
    FILE *fp = fopen("dijkstra.txt","w");

    for(n=5;n<=25;n+=5)
    {
        int adjMat[100][100];

        // Sample graph
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    adjMat[i][j]=0;
                else
                    adjMat[i][j]=i+j+1;
            }

        opcount = 0;

        dijkstra(adjMat,0);

        fprintf(fp,"%d %d\n",n,opcount);
    }

    fclose(fp);

    printf("Data stored in dijkstra.txt\n");
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