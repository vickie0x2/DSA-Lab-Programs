#include <stdio.h>
#define N 100
int main(void) {
    int q[N], f = 0, r = 0, count = 0, ch, x;
    do {
        printf("1 Enqueue 2 Dequeue 3 Display 0 Exit: ");
        scanf("%d", &ch);
        if (ch == 1) {
            scanf("%d", &x);
            if (count == N) puts("Full");
            else {
                q[r] = x;
                r = (r + 1) % N;
                count++;
            }
        }
        else if (ch == 2) {
            if (!count) puts("Empty");
            else {
                printf("%d\n", q[f]);
                f = (f + 1) % N;
                count--;
            }
        }
        else if (ch == 3) {
            for (int i = 0; i < count; i++) printf("%d ", q[(f + i) % N]);
            puts("");
        }
    }
    while (ch);
    return 0;
}
