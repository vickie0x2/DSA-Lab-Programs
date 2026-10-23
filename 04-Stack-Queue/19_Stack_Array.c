#include <stdio.h>
#define MAX 100
int main(void) {
    int s[MAX], top = - 1, ch, x;
    do {
        printf("1 Push 2 Pop 3 Peek 4 Display 0 Exit: ");
        scanf("%d", &ch);
        if (ch == 1) {
            scanf("%d", &x);
            if (top == MAX - 1) puts("Overflow");
            else s[++top] = x;
        }
        else if (ch == 2) {
            if (top < 0) puts("Underflow");
            else printf("%d\n", s[top--]);
        }
        else if (ch == 3) {
            if (top < 0) puts("Empty");
            else printf("%d\n", s[top]);
        }
        else if (ch == 4) {
            for (int i = top; i >= 0; i--) printf("%d ", s[i]);
            puts("");
        }
    }
    while (ch);
    return 0;
}
