
#include <stdio.h>
#define V 6

int G[V][V] = {
    {0, 4, 4, 0, 0, 0},
    {4, 0, 2, 0, 0, 0},
    {4, 2, 0, 3, 4, 2},
    {0, 0, 3, 0, 3, 0},
    {0, 0, 4, 3, 0, 3},
    {0, 0, 2, 0, 3, 0}};

int main()
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (G[i][j] == 0)
            {
                G[i][j] = 999;
            }
        }
    }
    int a = 0, b = 0, mincost=0;
    printf("node1 -> node2 (weight)\n");
    int visited[V], edgNo = 1;
    visited[0] = 1;

    while (edgNo < V)
    {
        int min = 999;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if( !(visited[i]==1 && visited[j]==1) && G[i][j] < min)
                {
                    min = G[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        printf("%d   ->   %d     (%d)\n", a, b, G[a][b]);
        visited[b] = 1;
        mincost+=min;
        G[a][b] = G[b][a] = 999;
        edgNo++;
    }
    printf("Minimum cost: %d\n", mincost);
    return 0;
}
