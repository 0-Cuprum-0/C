#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int comp (const void *a, const void *b){
const char *pa=*(const char **)a;
const void *pb=*(const char **)b;
return(strcmp(pa , pb));
}

int main(int argc, char** argv){
	qsort(argv+1, argc-1, sizeof(*argv), comp);
	for (int i = 1; i < argc; i++)
	{
	printf(argv[i]);
	printf(" ");
	}
	return 0;



}
