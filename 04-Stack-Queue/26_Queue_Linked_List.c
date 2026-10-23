#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node * next;
}
Node;
int main(void) {
    Node * f = NULL, * r = NULL;
    int ch, x;
    do {
        printf("1 Enqueue 2 Dequeue 3 Display 0 Exit: ");
        scanf("%d", &ch);
        if (ch == 1) {
            scanf("%d", &x);
            Node * n = malloc(sizeof ( * n));
            if (!n) continue;
            n->data = x;
            n->next = NULL;
            if (r) r->next = n;
            else f = n;
            r = n;
        }
        else if (ch == 2) {
            if (!f) puts("Empty");
            else {
                Node * t = f;
                printf("%d\n", t->data);
                f = f->next;
                if (!f) r = NULL;
                free(t);
            }
        }
        else if (ch == 3) {
            for (Node * t = f; t; t = t->next) printf("%d ", t->data);
            puts("");
        }
    }
    while (ch);
    return 0;
}
