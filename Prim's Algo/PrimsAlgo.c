// Prim's Algorithm in C

#include <stdio.h>
#define V 5

int G[V][V] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}};

int main()
{
    for (int i = 0; i <V; i++){
        for (int j = 0; j <V ; j++){
            if(G[i][j] == 0){
                G[i][j] = 999;
            }
        }
    }

    printf("node1 -> node2 (weight)\n");
    int visited[V], edgNo=0;
    visited[0]=1;

    while(edgNo<V){
        printf("\nedge no:%d, V:%d\n", edgNo, V);
        int min =999;
        int a=0, b=0;
        for(int i = 0; i <V; i++){
            for(int j = 0; j <V; j++){
                if(visited[i]!=0 && G[i][j]<min){
                    min = G[i][j];
                    a=i;
                    b=j;
                }
            }
        }
        printf("%d   ->   %d     (%d)\n",a,b,G[a][b]);
        visited[b]=1;
        G[a][b] = G[b][a] = 999;
        edgNo++;
    }

    return 0;
}
