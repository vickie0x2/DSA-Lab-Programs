/* Higher priority = smaller priority number. */
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data, priority;
    struct Node * next;
}
Node;
int main(void) {
    Node * h = NULL;
    int ch, x, p;
    do {
        printf("1 Insert(value priority) 2 Delete highest priority 3 Display 0 Exit: ");
        scanf("%d", &ch);
        if (ch == 1) {
            scanf("%d%d", &x, &p);
            Node * n = malloc(sizeof ( * n));
            if (!n) continue;
            n->data = x;
            n->priority = p;
            if (!h || p < h->priority) {
                n->next = h;
                h = n;
            }
            else {
                Node * t = h;
                while (t->next &&t->next->priority <= p) t = t->next;
                n->next = t->next;
                t->next = n;
            }
        }
        else if (ch == 2) {
            if (!h) puts("Empty");
            else {
                Node * t = h;
                printf("%d\n", t->data);
                h = h->next;
                free(t);
            }
        }
        else if (ch == 3) {
            for (Node * t = h; t; t = t->next) printf("(%d,p=%d) ", t->data, t->priority);
            puts("");
        }
    }
    while (ch);
    return 0;
}
