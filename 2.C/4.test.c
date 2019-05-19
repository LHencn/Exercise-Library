#include <stdio.h>
#include <stdlib.h>

#define max 10
int main() {
    char s[max];
    int size = 5;
    while (feof(stdin) == 0) {
        fgets(s, size + 1, stdin);
    }
    for (int i = 0; s[i]; i++) {
        printf("%c ", s[i]);
    }
    printf("\n");



    return 0;
}
