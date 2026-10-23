#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node * next;
}
Node;
Node * insertEnd(Node * h, int x) {
    Node * n = malloc(sizeof ( * n));
    n->data = x;
    if (!h) {
        n->next = n;
        return n;
    }
    Node * t = h;
    while (t->next != h) t = t->next;
    t->next = n;
    n->next = h;
    return h;
}
Node * deleteValue(Node * h, int x) {
    if (!h) return NULL;
    Node * cur = h, * prev = NULL;
    do {
        if (cur->data == x) {
            if (cur->next == cur) {
                free(cur);
                return NULL;
            }
            if (!prev) {
                Node * t = h;
                while (t->next != h) t = t->next;
                h = h->next;
                t->next = h;
            }
            else prev->next = cur->next;
            free(cur);
            return h;
        }
        prev = cur;
        cur = cur->next;
    }
    while (cur != h);
    return h;
}
void display(Node * h) {
    if (!h) {
        puts("Empty");
        return;
    }
    Node * t = h;
    do {
        printf("%d ", t->data);
        t = t->next;
    }
    while (t != h);
    puts("");
}
int main(void) {
    Node * h = NULL;
    int ch, x;
    do {
        printf("1 insert 2 delete value 3 display 0 exit: ");
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
