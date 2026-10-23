#include <stdio.h>
#define N 100
int g[N][N], seen[N], n;
void dfs(int u) {
    seen[u] = 1;
    printf("%d ", u);
    for (int v = 0; v < n; v++) if (g[u][v] &&!seen[v]) dfs(v);
}
void bfs(int s) {
    int q[N], f = 0, r = 0;
    for (int i = 0; i < n; i++) seen[i] = 0;
    q[r++] = s;
    seen[s] = 1;
    while (f < r) {
        int u = q[f++];
        printf("%d ", u);
        for (int v = 0; v < n; v++) if (g[u][v] &&!seen[v]) {
            seen[v] = 1;
            q[r++] = v;
        }
    }
}
int main(void) {
    int m, u, v, s;
    scanf("%d%d", &n, &m);
    if (n < 1 || n > N || m < 0) return 1;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        if (u < 0 || u >= n || v < 0 || v >= n) return 1;
        g[u][v] = g[v][u] = 1;
    }
    scanf("%d", &s);
    if (s < 0 || s >= n) return 1;
    printf("BFS: ");
    bfs(s);
    for (int i = 0; i < n; i++) seen[i] = 0;
    printf("\nDFS: ");
    dfs(s);
    puts("");
    return 0;
}
