/* Input hashtag and frequency pairs; print top 10 by frequency. */
#include <stdio.h>
typedef struct {
    char tag[40];
    int count;
}
Item;
int main(void) {
    Item a[100];
    int n;
    scanf("%d", &n);
    if (n < 0 || n > 100) return 1;
    for (int i = 0; i < n; i++) scanf("%39s%d", a[i].tag, &a[i].count);
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (a[j].count > a[i].count) {
        Item t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    for (int i = 0; i < n &&i < 10; i++) printf("%s %d\n", a[i].tag, a[i].count);
    return 0;
}
