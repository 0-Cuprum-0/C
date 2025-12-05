#include <stdio.h>
int main(int argc, char *argv[]){
	
	FILE *in = argc > 1 ? fopen(argv[1], "r") : stdin;
	if (in == NULL){
       		printf("cant read the file!!!");
		return 1;
	}
	double sum= 0.0;
        int c;	
        while ((c=fgetc(in)) != EOF){
//		printf("%c",c);
		if (c >='0' && c<='9'){
       		sum+= c - '0';
		}
        }
	printf("%f", sum);
       

}


