//floyds algorithm

#include <stdio.h>
#include <limits.h>

int n, opcount, dist[100][100];

void floyds(int adjMat[100][100], int n)
{
    opcount = 0;

    // Copy matrix
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(adjMat[i][j]==-1)
                dist[i][j]=INT_MAX;
            else
                dist[i][j]=adjMat[i][j];
        }

    // Floyd Algorithm
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                opcount++;

                if(dist[i][k]!=INT_MAX &&
                   dist[k][j]!=INT_MAX &&
                   dist[i][j] > dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
}

void tester()
{
    int adjMat[100][100];

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix (-1 for INF):\n");

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&adjMat[i][j]);

    floyds(adjMat,n);

    printf("\nShortest Distance Matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[i][j]==INT_MAX)
                printf("INF ");
            else
                printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
}

void plotter()
{
    FILE *fp = fopen("floyd.txt","w");

    for(n=2;n<=10;n++)
    {
        int adjMat[100][100];

        // Sample weighted graph
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    adjMat[i][j]=0;
                else
                    adjMat[i][j]=i+j+1;
            }

        floyds(adjMat,n);

        fprintf(fp,"%d %d\n",n,opcount);
    }

    fclose(fp);

    printf("Data stored in floyd.txt\n");
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



/*
b)  Implement  Floyd's  Algorithm  to  find  All-pair  shortest  paths  for  a graph and perform its analysis for different inputs


// b) Floyd's Algorithm:

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int n, opcount, dist[100][100];

int floyds(int adjMat[n][n], int n)
{
    opcount = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (adjMat[i][j] == -1)
                dist[i][j] = INT_MAX;
            else
                dist[i][j] = adjMat[i][j];
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
        {
            int tempDist = dist[i][k];
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] > tempDist)
                {
                    opcount++;
                    if (dist[k][j] != INT_MAX && dist[i][j] > tempDist + dist[k][j])
                    {
                        dist[i][j] = tempDist + dist[k][j];
                    }
                }
            }
        }
}

void tester()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int adjMat[n][n];
    printf("Enter adjacency matrix: \n");
    printf("[Note: Enter -1 to indicate infinity]\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adjMat[i][j]);
    floyds(adjMat, n);
    printf("Shortest distance between all pair of nodes:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", dist[i][j]);
        printf("\n");
    }
}

void plotter()
{
    srand(time(NULL));
    FILE *fp = fopen("floydes.txt", "w");
    for (int k = 2; k < 12; k++)
    {
        n = k;
        int adjMat[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j)
                    adjMat[i][j] = rand();
                else
                    adjMat[i][j] = 0;
        floyds(adjMat, n);
        fprintf(fp, "%d\t%d\n", n, opcount);
    }
    fclose(fp);
}

void main()
{
    int ch;
    printf("Enter\n1.Tester\n2.Plotter\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        tester();
        break;
    case 2:
        plotter();
        break;
    default:
        printf("Invalid choice!! ");
    }
}*/