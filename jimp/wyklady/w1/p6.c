#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *tint2( int a, int n, int t[] ) {
	// Wypełnia t liczbami a,a+1,s+2 a+n-1
  for( int i= 0; i < n; i++ )
		t[i] = a + i;
	return t;
}

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
	int n = b - a +1;
	int* w = malloc( n * sizeof *w );
	tint2( a, n, w );
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
