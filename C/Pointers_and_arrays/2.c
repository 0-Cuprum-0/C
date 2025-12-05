#include <stdio.h>

int main(void){
int k;
k=3;
int j;
int *ptr;
ptr = &k;
printf ("k=%d\n", k);
printf ("ptr=%d\n", ptr);
*ptr=5;
printf ("k2.0=%d\n", k);
printf ("ptr=%d\n", ptr);
}
