#include <stdio.h>

char main(){
	char word[20];
	scanf("%s", word);
//*	printf("%s", word);
	int l;
	char *ptr;
	ptr = word;
	while (*ptr !='\0'){
		l++;
		*ptr++;
	}

	if (l>20){
		printf("Nie mozna wiecej 20 !!!");
		return 1;
	}
	*ptr = word[0];
	printf("%s", *ptr++);

}
