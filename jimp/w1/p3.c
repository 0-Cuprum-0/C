#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] ) {
	printf( "%s:\n", argv[0] );
	int a = argc > 1 ? atoi( argv[1] ) : 1;
  int b = argc > 2 ? atoi( argv[2] ) : 10;
	for( int i = a; i <= b; i++ )
		printf( "%d\n", i );
	return 0;
}
