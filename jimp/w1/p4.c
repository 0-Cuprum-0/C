#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char* argv[] ) {
	printf( "%s:\n", argv[0] );
	int a = argc > 1 ? atoi( argv[1] ) : 1;
  int b = argc > 2 ? atoi( argv[2] ) : 10;
	int d = 1;
	if( a > b ) {
		int tmp = a;
		a = b;
		b = tmp;
	}	
	if( strcmp( "./odwrotnie", argv[0] ) == 0 ) {
		int tmp = a;
		a = b;
		b = tmp;
		d = -1;
	}
	for( int i = a; i != b+d; i+= d )
		printf( "%d\n", i );
	return 0;
}
