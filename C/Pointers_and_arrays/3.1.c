#include <stdio.h>

char strA[80] = "A string";
char strB[80]= "012344567891011121314151617181920";

int main(void){
	char *pA;
	char *pB;
	puts(strA);
	pA = strA;
	puts(pA);
	pB = strB;
	puts(pB);
	putchar('\n');
	while(*pA != '\0')
	{
		*pB++ = *pA++;
		printf("strA:");
		puts(strA);
		printf("strB");
		puts(strB);
	}
//*	*pB = '\0';
	puts(strB);
	return 0;
}
