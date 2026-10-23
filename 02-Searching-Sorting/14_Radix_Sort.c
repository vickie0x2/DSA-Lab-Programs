/* Radix sort for non-negative integers. */
#include <stdio.h>
int getMax(int a[], int n) {
    int m = a[0];
    for (int i = 1; i < n; i++) if (a[i] > m) m = a[i];
    return m;
}
void countSort(int a[], int n, int exp) {
    int out[100], count[10] = {
        0
    };
    for (int i = 0; i < n; i++) count[(a[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) out[--count[(a[i] / exp) % 10]] = a[i];
    for (int i = 0; i < n; i++) a[i] = out[i];
}
int main(void) {
    int a[100], n;
    scanf("%d", &n);
    if (n < 1 || n > 100) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0) {
            puts("Only non-negative values are supported");
            return 1;
        }
    }
    int m = getMax(a, n);
    for (int e = 1; m / e > 0; e *= 10) countSort(a, n, e);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
    return 0;
}
