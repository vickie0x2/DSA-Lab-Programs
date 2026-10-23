#include <stdio.h>
#include <ctype.h>
int main(void) {
    char s[256];
    int st[256], top = - 1;
    if (!fgets(s, sizeof s, stdin)) return 0;
    for (int i = 0; s[i] &&s[i] != '\n'; i++) {
        char c = s[i];
        if (c == ' ') continue;
        if (isdigit((unsigned char) c)) st[++top] = c - '0';
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (top < 1) {
                puts("Invalid expression");
                return 1;
            }
            int b = st[top--], a = st[top--];
            if (c == '+') st[++top] = a + b;
            else if (c == '-') st[++top] = a - b;
            else if (c == '*') st[++top] = a * b;
            else {
                if (!b) {
                    puts("Division by zero");
                    return 1;
                }
                st[++top] = a / b;
            }
        }
        else {
            puts("Use single-digit operands");
            return 1;
        }
    }
    if (top == 0) printf("%d\n", st[top]);
    else puts("Invalid postfix");
    return 0;
}
