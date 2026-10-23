/* Visual Studio practical: array traversal, insertion and deletion */
#include <stdio.h>
#define MAX 100
int main(void) {
    int a[MAX], n, choice, pos, value;
    printf("Number of elements: ");
    scanf("%d", &n);
    if (n < 0 || n > MAX) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("1 Display  2 Insert  3 Delete: ");
    scanf("%d", &choice);
    if (choice == 2) {
        if (n == MAX) {
            puts("Array full");
            return 0;
        }
        printf("Position (1-based), value: ");
        scanf("%d%d", &pos, &value);
        if (pos < 1 || pos > n + 1) {
            puts("Invalid position");
            return 0;
        }
        for (int i = n; i >= pos; i--) a[i] = a[i - 1];
        a[pos - 1] = value;
        n++;
    } else if (choice == 3) {
        printf("Position to delete (1-based): ");
        scanf("%d", &pos);
        if (pos < 1 || pos > n) {
            puts("Invalid position");
            return 0;
        }
        for (int i = pos - 1; i < n - 1; i++) a[i] = a[i + 1];
        n--;
    }
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
    return 0;
}
