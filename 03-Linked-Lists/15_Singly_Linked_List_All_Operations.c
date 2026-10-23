#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node * next;
}
Node;
Node * insert(Node * h, int x, int pos) {
    Node * n = malloc(sizeof ( * n));
    if (!n) return h;
    n->data = x;
    n->next = NULL;
    if (pos <= 1 || !h) {
        n->next = h;
        return n;
    }
    Node * p = h;
    for (int i = 1; i < pos - 1 &&p->next; i++) p = p->next;
    n->next = p->next;
    p->next = n;
    return h;
}
Node * del(Node * h, int pos) {
    if (!h) return NULL;
    if (pos <= 1) {
        Node * t = h->next;
        free(h);
        return t;
    }
    Node * p = h;
    for (int i = 1; i < pos - 1 &&p->next; i++) p = p->next;
    if (p->next) {
        Node * t = p->next;
        p->next = t->next;
        free(t);
    }
    return h;
}
void display(Node * h) {
    while (h) {
        printf("%d -> ", h->data);
        h = h->next;
    }
    puts("NULL");
}
int main(void) {
    Node * h = NULL;
    int ch, x, p;
    do {
        printf("1 Insert 2 Delete 3 Search 4 Count 5 Reverse 6 Display 0 Exit: ");
        if (scanf("%d", &ch) != 1) break;
        switch (ch) {
            case 1: scanf("%d%d", &x, &p);
            h = insert(h, x, p);
            break;
            case 2: scanf("%d", &p);
            h = del(h, p);
            break;
            case 3: {
                scanf("%d", &x);
                int i = 0, found = 0;
                for (Node * t = h; t; t = t->next, i++) if (t->data == x) {
                    printf("Found at index %d\n", i);
                    found = 1;
                    break;
                }
                if (!found) puts("Not found");
                break;
            }
            case 4: {
                int n = 0;
                for (Node * t = h; t; t = t->next) n++;
                printf("Nodes: %d\n", n);
                break;
            }
            case 5: {
                Node * prev = NULL, * cur = h;
                while (cur) {
                    Node * n = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = n;
                }
                h = prev;
                break;
            }
            case 6: display(h);
            break;
        }
    }
    while (ch);
    while (h) {
        Node * t = h;
        h = h->next;
        free(t);
    }
    return 0;
}
