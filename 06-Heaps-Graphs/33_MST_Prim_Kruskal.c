/* Prim's algorithm on an undirected weighted graph; enter 0 for no edge, vertices 0..n-1. */
#include <stdio.h>
#define N 100
#define INF 1000000000
int main(void) {
    int n, w[N][N], key[N], parent[N], used[N] = {
        0
    };
    scanf("%d", &n);
    if (n < 1 || n > N) return 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        scanf("%d", &w[i][j]);
        if (i != j &&w[i][j] == 0) w[i][j] = INF;
    }
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        parent[i] = - 1;
    }
    key[0] = 0;
    int total = 0;
    for (int step = 0; step < n; step++) {
        int u = - 1;
        for (int i = 0; i < n; i++) if (!used[i] &&(u == - 1 || key[i] < key[u])) u = i;
        if (u == - 1 || key[u] == INF) {
            puts("Graph disconnected");
            return 0;
        }
        used[u] = 1;
        total += key[u];
        for (int v = 0; v < n; v++) if (!used[v] &&w[u][v] < key[v]) {
            key[v] = w[u][v];
            parent[v] = u;
        }
    }
    for (int v = 1; v < n; v++) printf("%d - %d : %d\n", parent[v], v, key[v]);
    printf("MST cost = %d\n", total);
    return 0;
}
