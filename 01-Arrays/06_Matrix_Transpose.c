#include <stdio.h>
int main(void) {
    int a[20][20], r, c;
    scanf("%d%d", &r, &c);
    if (r < 1 || r > 20 || c < 1 || c > 20) return 1;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) scanf("%d", &a[i][j]);
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) printf("%d ", a[i][j]);
        puts("");
    }
    return 0;
}
