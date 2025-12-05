double *bad( double s, double e, int n ) {
	double v[n];
	double d = ( e - s ) / ( n - 1 );
	for( int i= 0; i < n; i++ )
		v[i] = s + i * d;
	return v;
}

#include <stdlib.h>

double *good( double s, double e, int n ) {
	double *v = malloc( n * sizeof *v );
	if( v == NULL )
		return NULL;
	double d = ( e - s ) / ( n - 1 );
	for( int i= 0; i < n; i++ )
		v[i] = s + i * d;
	return v;
}

#include <stdio.h>

int main( int argc, char **argv ) {
	int n = argc > 1 ? atoi(argv[1]) : 5;
	double s = argc > 2 ? atof(argv[2]) : 0.0;
	double e = argc > 3 ? atof(argv[3]) : 1.0;

	double *result = bad( s, e, n );

	printf( "bad:\n" );
	for( int i = 0; i < n; i++ )
		printf( "%g\n", result[i] );

	result = good( s, e, n );

	printf( "good:\n" );
	for( int i = 0; i < n; i++ )
		printf( "%g\n", result[i] );

	free( result );

	return 0;

}
