#include <stdio.h>
int main(void) {
    int a[20][20], b[20][20], r, c;
    scanf("%d%d", &r, &c);
    if (r < 1 || r > 20 || c < 1 || c > 20) return 1;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) scanf("%d", &a[i][j]);
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) scanf("%d", &b[i][j]);
    puts("Addition:");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) printf("%d ", a[i][j] + b[i][j]);
        puts("");
    }
    puts("Subtraction:");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) printf("%d ", a[i][j] - b[i][j]);
        puts("");
    }
    return 0;
}
