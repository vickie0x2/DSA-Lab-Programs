#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node * l, * r;
}
Node;
Node * newNode(int x) {
    Node * n = malloc(sizeof ( * n));
    if (!n) return NULL;
    n->data = x;
    n->l = n->r = NULL;
    return n;
}
void pre(Node * t) {
    if (t) {
        printf("%d ", t->data);
        pre(t->l);
        pre(t->r);
    }
}
void in(Node * t) {
    if (t) {
        in(t->l);
        printf("%d ", t->data);
        in(t->r);
    }
}
void post(Node * t) {
    if (t) {
        post(t->l);
        post(t->r);
        printf("%d ", t->data);
    }
}
/* Build a sample tree: input values are read in fixed order. */ int main(void) {
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    Node * r = newNode(a);
    r->l = newNode(b);
    r->r = newNode(c);
    r->l->l = newNode(d);
    r->l->r = newNode(e);
    printf("Preorder: ");
    pre(r);
    printf("\nInorder: ");
    in(r);
    printf("\nPostorder: ");
    post(r);
    puts("");
    return 0;
}
