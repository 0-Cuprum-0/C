#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toBinary(int x, char *buf) {
    int i = 0;
    char temp[32];
    while (x > 0) {
        temp[i++] = (x % 2) + '0';
        x /= 2;
    }
    if (i == 0) temp[i++] = '0';

    // reverse
    for (int j = 0; j < i; j++)
        buf[j] = temp[i - j - 1];
    buf[i] = '\0';
}

int main() {
    int n;
    printf("Print a number:\n");
    scanf("%d", &n);

    printf("Grammar:\n");
    printf("S -> A S | 0\n");
    printf("A -> A S | 1\n\n");

    int count = 0;
    int x = 0;
    char buffer[64];

    while (count < n) {
        toBinary(x, buffer);
        if (buffer[strlen(buffer) - 1] == '0') {
            printf("%s\n", buffer);
            count++;
        }
        x++;
    }

    return 0;
}

