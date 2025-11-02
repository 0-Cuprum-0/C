#include <stdio.h>

int main( int argc, char *argv[] ) {
	int c;
	int n= 0;
	while( (c=getchar()) != EOF )
		n++;

	printf( "%d znakuf\n", n );
	return 0;
}
