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
    //Editing 999 in the place of 0's in above matrix
    for (int i = 0; i <V; i++){
        for (int j = 0; j <V ; j++){
            if(G[i][j] == 0){
                G[i][j] = 999;
            }
        }
    }

    printf("node1 -> node2 (weight)\n");
    //Visited is array of those vertices which are visited
    //edgNo is a variable which denotes the number of edges that are visited
    int visited[V], edgNo=0;
    //Assigning visited of 0th index to 1, cuz we are starting from 0th index
    visited[0]=1;

    //While loop is execute till all the vertices are not visited
    //As for 6 vertices(say), we need atleast 5 edges to connect all of them
    while(edgNo<V){
        printf("\nedge no:%d, V:%d\n", edgNo, V);
        int min =999;
        int a=0, b=0;
        for(int i = 0; i <V; i++){
            for(int j = 0; j <V; j++){
                // visited[i]!=0  -> This will check next node must not be visited node
                // G[i][j]<min -> Find the minimum one that
                if(visited[i]!=0 && G[i][j]<min){
                    // When both are true update the minimum value
                    min = G[i][j];
                    // Store the row and column value of minimum weight in a and b respectively
                    a=i;
                    b=j;
                }
            }
        }
        //Print the minimum value whose vertex has not been visited
        printf("%d   ->   %d     (%d)\n",a,b,G[a][b]);
        //Now update the vertex which we are recently visited
        visited[b]=1;
        //Change the value of recently visited to 999
        G[a][b] = G[b][a] = 999;
        //Increase the value of edgeNo, as we had created new edge here
        edgNo++;
    }

    return 0;
}
