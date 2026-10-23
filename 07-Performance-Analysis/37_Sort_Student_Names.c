/* qsort gives O(n log n) average sorting; compare with insertion/bubble sort for small lists. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compareNames(const void * a, const void * b) {
    return strcmp((const char * ) a, (const char * ) b);
}
int main(void) {
    char names[100][80];
    int n;
    scanf("%d", &n);
    if (n < 0 || n > 100) return 1;
    for (int i = 0; i < n; i++) scanf("%79s", names[i]);
    qsort(names, n, sizeof names[0], compareNames);
    for (int i = 0; i < n; i++) puts(names[i]);
    return 0;
}
