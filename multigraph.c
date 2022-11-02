#include<stdio.h>
#include<limits.h>

#define N 8
#define INF INT_MAX

int min(int a, int b){
    return (a > b) ? b : a;
}

int shortestDist(int graph[N][N])
{
    int dist[N];
    dist[N - 1] = 0;
    for (int i = N - 2; i >= 0; i--)
    {
        dist[i] = INF;
        for (int j = i; j < N; j++)
        {
            if (graph[i][j] == INF)
            {
                continue;
            }
            dist[i] = min(dist[i], graph[i][j]
                    + dist[j]);
        }
    }
    return dist[0];
}
 
int main(){
    int graph[N][N] = {{INF, 1, 2, 5, INF, INF, INF, INF},
        {INF, INF, INF, INF, 4, 11, INF, INF},
        {INF, INF, INF, INF, 9, 5, 16, INF},
        {INF, INF, INF, INF, INF, INF, 2, INF},
        {INF, INF, INF, INF, INF, INF, INF, 18},
        {INF, INF, INF, INF, INF, INF, INF, 13},
        {INF, INF, INF, INF, INF, INF, INF, 2}};

    printf("%d minimum distance between from source node to target node", shortestDist(graph));
    return 0;
}
