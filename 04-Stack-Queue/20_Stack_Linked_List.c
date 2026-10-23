#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node * next;
}
Node;
int main(void) {
    Node * top = NULL;
    int ch, x;
    do {
        printf("1 Push 2 Pop 3 Display 0 Exit: ");
        scanf("%d", &ch);
        if (ch == 1) {
            scanf("%d", &x);
            Node * n = malloc(sizeof ( * n));
            if (!n) {
                puts("Allocation failed");
                continue;
            }
            n->data = x;
            n->next = top;
            top = n;
        }
        else if (ch == 2) {
            if (!top) puts("Underflow");
            else {
                Node * t = top;
                printf("%d\n", t->data);
                top = top->next;
                free(t);
            }
        }
        else if (ch == 3) {
            for (Node * t = top; t; t = t->next) printf("%d ", t->data);
            puts("");
        }
    }
    while (ch);
    while (top) {
        Node * t = top;
        top = top->next;
        free(t);
    }
    return 0;
}
