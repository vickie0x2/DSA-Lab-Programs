#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int x;
    struct Node * l, * r;
}
Node;
Node * ins(Node * t, int x) {
    if (!t) {
        t = malloc(sizeof ( * t));
        t->x = x;
        t->l = t->r = NULL;
    } else if (x < t->x) t->l = ins(t->l, x); else if (x > t->x) t->r = ins(t->r, x);
    return t;
}
Node * find(Node * t, int x) {
    while (t &&t->x != x) t = x < t->x?t->l: t->r;
    return t;
}
Node * minNode(Node * t) {
    while (t &&t->l) t = t->l;
    return t;
}
Node * del(Node * t, int x) {
    if (!t) return NULL;
    if (x < t->x) t->l = del(t->l, x); else if (x > t->x) t->r = del(t->r, x); else {
        if (!t->l) {
            Node * n = t->r;
            free(t);
            return n;
        }
        if (!t->r) {
            Node * n = t->l;
            free(t);
            return n;
        }
        Node * n = minNode(t->r);
        t->x = n->x;
        t->r = del(t->r, n->x);
    }
    return t;
}
void inorder(Node * t) {
    if (t) {
        inorder(t->l);
        printf("%d ", t->x);
        inorder(t->r);
    }
}
int main(void) {
    Node * t = NULL;
    int ch, x;
    do {
        printf("1 Insert 2 Search 3 Delete 4 Display 0 Exit: ");
        scanf("%d", &ch);
        if (ch == 1) {
            scanf("%d", &x);
            t = ins(t, x);
        }
        else if (ch == 2) {
            scanf("%d", &x);
            puts(find(t, x)?"Found": "Not found");
        }
        else if (ch == 3) {
            scanf("%d", &x);
            t = del(t, x);
        }
        else if (ch == 4) {
            inorder(t);
            puts("");
        }
    }
    while (ch);
    return 0;
}
