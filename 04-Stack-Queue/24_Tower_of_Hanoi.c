#include <stdio.h>
void hanoi(int n, char from, char aux, char to) {
    if (n == 0) return;
    hanoi(n - 1, from, to, aux);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi(n - 1, aux, from, to);
}
int main(void) {
    int n;
    scanf("%d", &n);
    if (n < 0 || n > 20) return 1;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
