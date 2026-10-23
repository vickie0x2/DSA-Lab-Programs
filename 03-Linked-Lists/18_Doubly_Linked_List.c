#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node * prev, * next;
}
Node;
Node * insertEnd(Node * h, int x) {
    Node * n = malloc(sizeof ( * n));
    n->data = x;
    n->next = NULL;
    n->prev = NULL;
    if (!h) return n;
    Node * t = h;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
    return h;
}
Node * deleteValue(Node * h, int x) {
    Node * t = h;
    while (t &&t->data != x) t = t->next;
    if (!t) return h;
    if (t->prev) t->prev->next = t->next;
    else h = t->next;
    if (t->next) t->next->prev = t->prev;
    free(t);
    return h;
}
void display(Node * h) {
    for (; h; h = h->next) printf("%d <-> ", h->data);
    puts("NULL");
}
int main(void) {
    Node * h = NULL;
    int ch, x;
    do {
        printf("1 insert end 2 delete value 3 display 0 exit: ");
        scanf("%d", &ch);
        if (ch == 1) {
            scanf("%d", &x);
            h = insertEnd(h, x);
        }
        else if (ch == 2) {
            scanf("%d", &x);
            h = deleteValue(h, x);
        }
        else if (ch == 3) display(h);
    }
    while (ch);
    return 0;
}
