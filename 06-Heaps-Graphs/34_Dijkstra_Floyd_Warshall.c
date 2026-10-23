/* Input n, adjacency matrix (use -1 for no edge), then source vertex. */
#include <stdio.h>
#define N 100
#define INF 1000000000
int main(void) {
    int n, a[N][N], d[N], used[N] = {
        0
    }, s;
    scanf("%d", &n);
    if (n < 1 || n > N) return 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        scanf("%d", &a[i][j]);
        if (a[i][j] == - 1) a[i][j] = INF;
    }
    scanf("%d", &s);
    for (int i = 0; i < n; i++) d[i] = a[s][i];
    d[s] = 0;
    for (int z = 0; z < n; z++) {
        int u = - 1;
        for (int i = 0; i < n; i++) if (!used[i] &&(u == - 1 || d[i] < d[u])) u = i;
        if (u == - 1 || d[u] >= INF) break;
        used[u] = 1;
        for (int v = 0; v < n; v++) if (a[u][v] < INF &&d[v] > d[u] + a[u][v]) d[v] = d[u] + a[u][v];
    }
    puts("Dijkstra distances:");
    for (int i = 0; i < n; i++) if (d[i] >= INF) printf("%d: INF\n", i);
    else printf("%d: %d\n", i, d[i]);
    for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (a[i][k] < INF &&a[k][j] < INF &&a[i][j] > a[i][k] + a[k][j]) a[i][j] = a[i][k] + a[k][j];
    puts("Floyd-Warshall:");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (a[i][j] >= INF) printf("INF ");
        else printf("%d ", a[i][j]);
        puts("");
    }
    return 0;
}
