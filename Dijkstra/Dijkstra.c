#include <stdio.h>
#define V 9

int G[V][V] = {
    {0, 4, 0, 0, 0, 0, 0, 8, 0},
    {4, 0, 8, 0, 0, 0, 0, 11, 0},
    {0, 8, 0, 7, 0, 4, 0, 0, 2},
    {0, 0, 7, 0, 9, 14, 0, 0, 0},
    {0, 0, 0, 9, 0, 10, 0, 0, 0},
    {0, 0, 4, 14, 10, 0, 2, 0, 0},
    {0, 0, 0, 0, 0, 2, 0, 1, 6},
    {8, 11, 0, 0, 0, 0, 1, 0, 7},
    {0, 0, 2, 0, 0, 0, 6, 7, 0}};

int main()
{
    // Initializing variables
    int S = 0, i, j;
    int distance[V], vis[V];

    // Initializing distance and visited arrays
    for (i = 0; i < V; i++)
    {
        if (G[S][i] > 0)
            distance[i] = G[S][i];
        else
            distance[i] = 999;
        vis[i] = 0;
    }

    // Setting the source vertex distance to zero and marking it as visited
    distance[S] = 0;
    vis[S] = 1;

    int count = 0;
    while (count < V - 1)
    {
        int a, min = 999;

        // Finding the vertex with the minimum distance from the source vertex
        for (i = 0; i < V; i++)
        {
            if (distance[i] < min && vis[i] == 0)
            {
                min = distance[i];
                a = i;
            }
        }

        vis[a] = 1;

        // Updating the distances of adjacent vertices
        for (j = 0; j < V; j++)
        {
            if (G[a][j] > 0 && j != S && distance[j] > distance[a] + G[a][j])
            {
                    distance[j] = distance[a] + G[a][j];
            }
        }

        count++;
    }

    // Printing the shortest path from the source vertex to all other vertices
    for (i = 0; i < V; i++)
    {
        printf("%d  %d\n", i, distance[i]);
    }

    return 0;
}
