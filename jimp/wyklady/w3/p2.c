#include <stdio.h>

int main( int argc, char *argv[] ) {
	int c;
	int n= 0;
	while( (c=getchar()) != EOF )
		if( c >= '0' && c <= '9' )
			n++;

	printf( "%d cyfr dziesientnych\n", n );
	return 0;
}
