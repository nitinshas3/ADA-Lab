#include <stdio.h>
#include <stdlib.h>

#define INF 9999

int graph[20][20];
int visited[20];
int n;
int count;

// Prim's Algorithm
void prim() {
    int edges = 0;
    int min, x = 0, y = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        min = INF;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    count++;  // basic operation

                    if (!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("%d -> %d : %d\n", x, y, graph[x][y]);

        visited[y] = 1;
        edges++;
    }
}

// Correctness check
void correctness() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter Cost Matrix (9999 for INF):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    count = 0;
    prim();
    printf("\nCount = %d\n", count);
}

// Analysis with only dense graph
void analysis() {
    FILE *fp = fopen("PrimsDense.txt", "w");

    for (n = 4; n <= 10; n++) {
        // Dense Graph
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    graph[i][j] = 0;
                else
                    graph[i][j] = i + j + 1;
            }
        }

        count = 0;
        prim();
        fprintf(fp, "%d\t%d\n", n, count);
    }

    fclose(fp);

    printf("\nAnalysis stored in PrimsDense.txt\n");
    system("gnuplot > load 'command.txt'");
}

int main() {
    int choice;
    printf("1. Correctness Check\n");
    printf("2. Analysis\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: correctness(); break;
        case 2: analysis(); break;
        default: printf("Invalid Choice\n");
    }
    return 0;
}
