#include <stdio.h>

int dlug(char *s){
	for (char *i =s; *i != '\0';i++);
	return i-s; 
}
int dlugosc (char *s){
	int n = 0;
	while *(s+n) != '\0')
		n++;
	return n;
}

int main (int argc, char *argv[]){
	for (int i =1; i<argc;i++)
		printf("%s(%d=%d)\n", argv[i], dlug(argv[i]), dlugosc(argv[i]));
	return 0;
}
