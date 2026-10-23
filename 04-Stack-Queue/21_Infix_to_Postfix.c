#include <stdio.h>
#include <ctype.h>
#define MAX 256
int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}
int main(void) {
    char in[MAX], st[MAX], out[MAX];
    int top = - 1, k = 0;
    if (!fgets(in, sizeof in, stdin)) return 0;
    for (int i = 0; in[i] &&in[i] != '\n'; i++) {
        char c = in[i];
        if (isalnum((unsigned char) c)) out[k++] = c;
        else if (c == '(') st[++top] = c;
        else if (c == ')') {
            while (top >= 0 &&st[top] != '(') out[k++] = st[top--];
            if (top >= 0) top--;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (top >= 0 &&st[top] != '(' &&(prec(st[top]) > prec(c) || (prec(st[top]) == prec(c) &&c != '^'))) out[k++] = st[top--];
            st[++top] = c;
        }
    }
    while (top >= 0) out[k++] = st[top--];
    out[k] = '\0';
    puts(out);
    return 0;
}
