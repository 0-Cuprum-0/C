#include <stdio.h>
#include <stdlib.h>

int main() {
    int n ;
    printf("Print a number:\n");
    fflush(stdout);
    scanf("%d", &n);
    //printf("%d", n);
    if (n == 0) {
        printf("Write a number of desired outputs!");
        return 1;
    }
    else {  
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++) {
                printf("1");
            }
           printf("0");
            printf("\n");
        }
        return 0;
    }
}

