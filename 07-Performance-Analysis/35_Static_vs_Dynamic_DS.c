#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int fixed[100] = {
        0
    }, n;
    printf("Enter n (1-100): ");
    scanf("%d", &n);
    if (n < 1 || n > 100) return 1;
    int * p = calloc((size_t) n, sizeof (int));
    if (!p) return 1;
    for (int i = 0; i < n; i++) {
        fixed[i] = i + 1;
        p[i] = i + 1;
    }
    printf("Static array storage: %zu bytes\n", sizeof fixed);
    printf("Dynamic array payload: %zu bytes\n", (size_t) n * sizeof (int));
    free(p);
    return 0;
}
