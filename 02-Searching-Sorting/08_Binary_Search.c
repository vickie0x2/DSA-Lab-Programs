/* Enter sorted values in ascending order. */
#include <stdio.h>
int main(void) {
    int a[100], n, x, l = 0, r, m;
    scanf("%d", &n);
    if (n < 0 || n > 100) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &x);
    r = n - 1;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (a[m] == x) {
            printf("Found at index %d\n", m);
            return 0;
        }
        if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    puts("Not found");
    return 0;
}
