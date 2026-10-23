#include <stdio.h>
int main(void) {
    int a[100], n;
    scanf("%d", &n);
    if (n < 0 || n > 100) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) if (a[j] > a[j + 1]) {
            int t = a[j];
            a[j] = a[j + 1];
            a[j + 1] = t;
            swapped = 1;
        }
        if (!swapped) break;
    }
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
    return 0;
}
