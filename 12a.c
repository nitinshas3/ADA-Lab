//warshals algorithm 


#include <stdio.h>

int n, opcount, paths[100][100];

void warshall(int adjMat[100][100], int n)
{
    opcount = 0;

    // Copy adjacency matrix
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            paths[i][j] = adjMat[i][j];

    // Warshall Algorithm
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                opcount++;
                paths[i][j] = paths[i][j] || (paths[i][k] && paths[k][j]);
            }
}

void tester()
{
    int adjMat[100][100];

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&adjMat[i][j]);

    warshall(adjMat,n);

    printf("\nTransitive Closure Matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",paths[i][j]);
        printf("\n");
    }
}

void plotter()
{
    FILE *fp = fopen("warshall.txt","w");

    for(n=2;n<=10;n++)
    {
        int adjMat[100][100];

        // Worst case graph
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i==j)
                    adjMat[i][j]=0;
                else
                    adjMat[i][j]=1;

        warshall(adjMat,n);

        fprintf(fp,"%d %d\n",n,opcount);
    }

    fclose(fp);

    printf("Data stored in warshall.txt\n");
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



/*a) Implement Warshall‟s Algorithm to find the transitive closure of a directed graph and perform its analysis for different inputs. 





#include <stdio.h>
#include <stdlib.h>

int n, opcount, paths[100][100];

int warshall(int adjMat[n][n], int n)
{
    opcount = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            paths[i][j] = adjMat[i][j];
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            if (paths[i][k])
            {
                for (int j = 0; j < n; j++)
                {
                    opcount++;
                    paths[i][j] = paths[i][j] || (paths[i][k] && paths[k][j]);
                }
            }
}

void tester()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int adjMat[n][n];
    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adjMat[i][j]);
    warshall(adjMat, n);
    printf("Transitive closure matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", paths[i][j]);
        printf("\n");
    }
}

void plotter()
{
    FILE *f1 = fopen("warshallbest.txt", "w");
    FILE *f2 = fopen("warshallworst.txt", "w");
    for (int k = 1; k <= 10; k++)
    {
        n = k;
        int adjMat[n][n];
        for (int j = 0; j < n; j++)
            for (int i = 0; i < n; i++)
                if (i != j)
                    adjMat[i][j] = 1;
                else
                    adjMat[i][j] = 0;
        warshall(adjMat, n);
        fprintf(f2, "%d\t%d\n", n, opcount);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adjMat[i][j] = 0;
        for (int i = 0; i < n - 1; i++)
            adjMat[i][i + 1] = 1;
        adjMat[n - 1][0] = 1;
        warshall(adjMat, n);
        fprintf(f1, "%d\t%d\n", n, opcount);
    }
    fclose(f1);
    fclose(f2);
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