#include <stdio.h>

void int_copy (char *pA, char *pB, int nbr){
		char *q = pA;
		for (nbr;nbr>0; nbr--){
		*pB++ = *q++;

		}
}
int main(){
char arrA[20]= {'1', '2','3'};
char arrB[20]={'1','2', '3', '5', '7'};
int nbra = 4;
int_copy(arrA, arrB, nbra);
puts(arrA);
puts(arrB);
}
