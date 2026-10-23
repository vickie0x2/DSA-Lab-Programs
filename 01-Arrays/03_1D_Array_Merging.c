/* Concatenate two arrays */
#include <stdio.h>
int main(void) {
    int a[100], b[100], c[200], n, m;
    if (scanf("%d", &n) != 1 || n < 0 || n > 100) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    if (scanf("%d", &m) != 1 || m < 0 || m > 100) return 1;
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    for (int i = 0; i < n; i++) c[i] = a[i];
    for (int i = 0; i < m; i++) c[n + i] = b[i];
    for (int i = 0; i < n + m; i++) printf("%d ", c[i]);
    puts("");
    return 0;
}
