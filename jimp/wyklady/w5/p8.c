#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpin( const void *a, const void *b ) {
	double da = *(double*) a;
	double db = *(double*) b;
	return da < db ? -1 : (da == db ? 0 : 1);
}

int cmpde( const void *a, const void *b ) {
	double da = *(double*) a;
	double db = *(double*) b;
	return da < db ? 1 : (da == db ? 0 : -1);
}

int sorted( double *t, int n, int (*f)(const void *, const void * ) ) {
	for( int i= 1; i < n; i++ )
		if( f( t+i-1, t+i) > 0 )
			return 0;
	return 1;
}

int podziel( char *t, int p, int k, size_t s, int (*f)(const void *, const void *) ) {
	char *tmp = malloc( s );
	int i= p+1;
	int j= k;
	while( i < j ) {
		while( i < j && f( t+i*s, t+p*s ) <= 0 )
			i++;
		while( i < j && f( t+j*s, t+p*s) > 0 )
			j--;
		if( i != j ) {
			memcpy( tmp, t+i*s, s );
			memcpy( t+i*s, t+j*s, s );
		       	memcpy( t+j*s, tmp, s );
		}
	}
	if( f( t+i*s, t+p*s) > 0 )
		i--;
	memcpy( tmp, t+i*s, s );
	memcpy( t+i*s, t+p*s, s );
	memcpy( t+p*s, tmp, s );
	free(tmp);
	return i;
}

void qsrect( char *t, int p, int k, size_t s, int (*f)(const void *, const void *) ) {
	if( k > p ) {
		int m = podziel( t, p, k, s, f );
		qsrect( t, p, m-1, s, f );
		qsrect( t, m+1, k, s, f );
	}
}

void kusort( char *t, int n, size_t s, int (*f)(const void *, const void *) ) {
	qsrect( t, 0, n-1, s, f );
}

int main(int argc, char **argv) {
	int n = argc > 1 ? atoi(argv[1]) : 100;
	int (*f)( const void*, const void * ) = cmpin;
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
	kusort( (char*)t, n, sizeof t[0], f );
	printf( sorted( t, n, f ) ? "posortowana\n" : "nieposortowana\n" );
	if( n <= 20 ) {
		for( int i= 0; i < n; i++ )
			printf( "%g\n", t[i] );
	}
	return 0;
}
