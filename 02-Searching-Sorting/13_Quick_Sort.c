#include <stdio.h>
int partition(int a[], int l, int h) {
    int pivot = a[h], i = l - 1;
    for (int j = l; j < h; j++) if (a[j] <= pivot) {
        i++;
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    int t = a[i + 1];
    a[i + 1] = a[h];
    a[h] = t;
    return i + 1;
}
void quickSort(int a[], int l, int h) {
    if (l < h) {
        int p = partition(a, l, h);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, h);
    }
}
int main(void) {
    int a[100], n;
    scanf("%d", &n);
    if (n < 0 || n > 100) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
    return 0;
}
