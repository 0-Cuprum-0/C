#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpin( const void *a, const void *b ) {
	double da = *(double*)a;
	double db = *(double*)b;
	return da < db ? -1 : (da == db ? 0 : 1);
}

int cmpde( const void *a, const void *b ) {
	double da = *(double*)a;
	double db = *(double*)b;
	return da < db ? 1 : (da == db ? 0 : -1);
}

int sorted( double *t, int n, int (*f)(const void *, const void *) ) {
	for( int i= 1; i < n; i++ )
		if( f( t+i-1, t+i) > 0 )
			return 0;
	return 1;
}

int main(int argc, char **argv) {
	int n = argc > 1 ? atoi(argv[1]) : 100;
	int (*f)( const void *, const void *) = cmpin;
	if( argc > 2 ) {
		if( strcmp( argv[2], "-m" ) == 0 )
			f = cmpde;
		else
			fprintf( stderr, "Uwaga: %s zignorowane!\n", argv[2] );
	}
	double* t = malloc( n * sizeof *t );
	for( int i= 0; i < n; i++ ) {
		t[i] = rand() % 99;
	}
	qsort( t, n, sizeof t[0], f );
	printf( sorted( t, n, f ) ? "posortowana\n" : "nieposortowana\n" );
	if( n <= 20 ) {
		for( int i= 0; i < n; i++ )
			printf( "%g\n", t[i] );
	}
	return 0;
}
