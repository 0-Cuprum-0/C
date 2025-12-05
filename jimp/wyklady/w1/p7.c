#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int *nrand( int n, int t[] ) {
	// Wypełnia t n liczbami losowymi
  for( int i= 0; i < n; i++ )
		t[i] = rand() % 1000;
	return t;
}

int main( int argc, char* argv[] ) {
	printf( "%s:\n", argv[0] );
	int n = argc > 1 ? atoi( argv[1] ) : 10;
	int s = argc > 2 ? atoi( argv[2] ) : time(NULL);
	srand( s );
	int* w = malloc( n * sizeof *w );
	nrand( n, w );
	if( strcmp( "./odwrotnie", argv[0] ) != 0 ) {
		for( int i = 0; i < n; i++ )
			printf( "%d\n", w[i]  );
	} else {
		for( int i = n-1; i >= 0; i-- )
			printf( "%d\n", w[i] );
	}
	free( w );
	return 0;
}
