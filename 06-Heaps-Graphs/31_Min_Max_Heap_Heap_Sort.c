#include <stdio.h>
void down(int a[], int n, int i) {
    while (1) {
        int m = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < n &&a[l] > a[m]) m = l;
        if (r < n &&a[r] > a[m]) m = r;
        if (m == i) return;
        int t = a[i];
        a[i] = a[m];
        a[m] = t;
        i = m;
    }
}
int main(void) {
    int a[100], n;
    scanf("%d", &n);
    if (n < 0 || n > 100) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = n / 2 - 1; i >= 0; i--) down(a, n, i);
    puts("Max heap:");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
    for (int i = n - 1; i > 0; i--) {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        down(a, i, 0);
    }
    puts("Heap sort ascending:");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
    return 0;
}
