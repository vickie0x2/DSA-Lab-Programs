#include <stdio.h>
#include <stdlib.h>
typedef struct Term {
    int coef, pow;
    struct Term * next;
}
Term;
void append(Term * * h, int c, int p) {
    Term * n = malloc(sizeof ( * n));
    n->coef = c;
    n->pow = p;
    n->next = NULL;
    if (! * h) * h = n; else {
        Term * t = * h;
        while (t->next) t = t->next;
        t->next = n;
    }
}
Term * add(Term * a, Term * b) {
    Term * r = NULL;
    while (a &&b) {
        if (a->pow == b->pow) {
            if (a->coef + b->coef) append( &r, a->coef + b->coef, a->pow);
            a = a->next;
            b = b->next;
        }
        else if (a->pow > b->pow) {
            append( &r, a->coef, a->pow);
            a = a->next;
        }
        else {
            append( &r, b->coef, b->pow);
            b = b->next;
        }
    }
    while (a) {
        append( &r, a->coef, a->pow);
        a = a->next;
    }
    while (b) {
        append( &r, b->coef, b->pow);
        b = b->next;
    }
    return r;
}
void print(Term * t) {
    if (!t) {
        puts("0");
        return;
    }
    while (t) {
        printf("%+dx^%d ", t->coef, t->pow);
        t = t->next;
    }
    puts("");
}
int main(void) {
    Term * a = NULL, * b = NULL;
    int n, c, p;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &c, &p);
        append( &a, c, p);
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &c, &p);
        append( &b, c, p);
    }
    puts("A:");
    print(a);
    puts("B:");
    print(b);
    puts("Sum:");
    print(add(a, b));
    return 0;
}
