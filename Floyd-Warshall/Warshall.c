#include <stdio.h>
#define nV 5
#define INF 999

void printMatrix(int matrix[][nV]);

void floydWarshall(int graph[][nV])
{
    int matrix[nV][nV], i, j, k;

    for (i = 0; i < nV; i++)
        for (j = 0; j < nV; j++)
            matrix[i][j] = graph[i][j];

    for (k = 0; k < nV; k++)
    {
        for (i = 0; i < nV; i++)
        {
            for (j = 0; j < nV; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j]){
                    matrix[i][j] = 1;
                }
            }
        }
        printMatrix(matrix);
        printf("\n\n");
    }
    printf("\n\nPrinting final matrix\n\n");
    printMatrix(matrix);
}

void printMatrix(int matrix[][nV])
{
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            if (matrix[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[nV][nV] = {{0, 1, INF, 1, 1},
                         {1, 0, INF, INF, INF, INF},
                         {INF, 1, 0, INF, INF},
                         {INF, INF, 1, 0, 1},
                         {INF, INF, INF, INF, 0}};
    floydWarshall(graph);
}
