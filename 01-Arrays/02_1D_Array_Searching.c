/* Linear search in an unsorted array */
#include <stdio.h>
int main(void) {
    int a[100], n, x;
    scanf("%d", &n);
    if (n < 0 || n > 100) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &x);
    for (int i = 0; i < n; i++) if (a[i] == x) {
        printf("Found at index %d\n", i);
        return 0;
    }
    puts("Not found");
    return 0;
}
