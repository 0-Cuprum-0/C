#include <stdio.h>

char *my_strcpy(char *destination, char *source)
{
	char *p = destination;
	while (*source != '\0')
	{
	*p++ = *source++;

	}
	*p = '\0';
	return destination;
}
char main(void){
	char strA[80] = "string";
	char strB[80];
	my_strcpy(strB, strA);
	puts(strB);
}
//* *p++ does one step in memory, while (*p)++ will work only with the value(the letter) stored in memory[so it will add one in unicode]
