#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpin( double da, double db ) {
	return da < db ? -1 : (da == db ? 0 : 1);
}

int cmpde( double da, double db ) {
	return da < db ? 1 : (da == db ? 0 : -1);
}

int sorted( double *t, int n, int (*f)(double, double) ) {
	for( int i= 1; i < n; i++ )
		if( f( t[i-1], t[i]) > 0 )
			return 0;
	return 1;
}

int podziel( double t[], int p, int k, int (*f)(double, double) ) {
	int i= p+1;
	int j= k;
	while( i < j ) {
		while( i < j && f( t[i], t[p] ) <= 0 )
			i++;
		while( i < j && f( t[j], t[p]) > 0 )
			j--;
		if( i != j ) {
			double tmp = t[i]; t[i] = t[j]; t[j] = tmp;
		}
	}
	if( f( t[i], t[p]) > 0 )
		i--;
	double tmp= t[i];
	t[i] = t[p];
	t[p] = tmp;
	return i;
}

void qsrect( double t[], int p, int k, int (*f)(double, double) ) {
	if( k > p ) {
		int s = podziel( t, p, k, f );
		qsrect( t, p, s-1, f );
		qsrect( t, s+1, k, f );
	}
}

void kusort( double t[], int n, int (*f)(double, double) ) {
	qsrect( t, 0, n-1, f );
}

int main(int argc, char **argv) {
	int n = argc > 1 ? atoi(argv[1]) : 100;
	int (*f)( double, double ) = cmpin;
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
	kusort( t, n, f );
	printf( sorted( t, n, f ) ? "posortowana\n" : "nieposortowana\n" );
	if( n <= 20 ) {
		for( int i= 0; i < n; i++ )
			printf( "%g\n", t[i] );
	}
	return 0;
}
