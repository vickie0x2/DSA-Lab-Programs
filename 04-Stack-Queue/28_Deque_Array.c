#include <stdio.h>
#define N 100
int main(void) {
    int a[N], f = 0, r = - 1, c = 0, ch, x;
    do {
        printf("1 InsertFront 2 InsertRear 3 DeleteFront 4 DeleteRear 5 Display 0 Exit: ");
        scanf("%d", &ch);
        if (ch == 1 || ch == 2) {
            scanf("%d", &x);
            if (c == N) puts("Full");
            else if (ch == 1) {
                f = (f - 1 + N) % N;
                a[f] = x;
                if (c == 0) r = f;
                c++;
            }
            else {
                r = (r + 1) % N;
                a[r] = x;
                if (c == 0) f = r;
                c++;
            }
        }
        else if (ch == 3 || ch == 4) {
            if (!c) puts("Empty");
            else {
                if (ch == 3) f = (f + 1) % N;
                else r = (r - 1 + N) % N;
                c--;
            }
        }
        else if (ch == 5) {
            for (int i = 0; i < c; i++) printf("%d ", a[(f + i) % N]);
            puts("");
        }
    }
    while (ch);
    return 0;
}
