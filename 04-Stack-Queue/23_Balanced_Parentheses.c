#include <stdio.h>
int main(void) {
    char s[1000], st[1000];
    int top = - 1;
    if (!fgets(s, sizeof s, stdin)) return 0;
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') st[++top] = c;
        else if (c == ')' || c == ']' || c == '}') {
            if (top < 0) {
                puts("Not balanced");
                return 0;
            }
            char o = st[top--];
            if (!((o == '(' &&c == ')') || (o == '[' &&c == ']') || (o == '{' &&c == '}'))) {
                puts("Not balanced");
                return 0;
            }
        }
    }
    puts(top == - 1?"Balanced": "Not balanced");
    return 0;
}
