#include <stdio.h>
int main(void) {
    int a[100], n;
    scanf("%d", &n);
    if (n < 0 || n > 100) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) if (a[j] < a[m]) m = j;
        int t = a[i];
        a[i] = a[m];
        a[m] = t;
    }
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
    return 0;
}
