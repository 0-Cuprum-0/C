#include <stdio.h>
int my_array[] = {1, 2, 3, 4, 5, 6};
int *ptr;
int main(void)
{
	int i;
	ptr = my_array;
	for (i = 0; i<6; i++)
	{
		printf("%d\n", my_array[i]);
		printf ("ptr + %d =%d\n ",i,*(ptr++));
	}
	return 0;

}
