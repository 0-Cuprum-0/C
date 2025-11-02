#include <stdio.h>

int main( int argc, char *argv[] ) {
	int c;
	int n= 0;
	while( (c=getchar()) != EOF ) {
		printf( "%c - %d - %X\n", c, c, c );
		n++;
	}

	printf( "%d znakuf\n", n );
	return 0;
}
