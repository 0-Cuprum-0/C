#include <stdlib.h>
#include <stdio.h>

typedef struct {
	double *v;
	int n;
	int size;
} dt_t;

int init_dt( dt_t * dt, int size ) {
	dt->v = malloc( size * sizeof * dt->v );
	if( dt->v == NULL )
		return 1;
	dt->size = size;
	dt->n = 0;
	return 0;
}

int double_size_dt( dt_t * dt ) {
	double *nv = realloc( dt->v, 2 * dt->size * sizeof *(dt->v) );
	if( nv != NULL ) {
		dt->v = nv;
		dt->size *= 2;
		return 0;
	} else {
		return 1;
	}
}

int append_dt( dt_t *dt, double x ) {
	if( dt->n == dt->size )
		if( double_size_dt( dt ) )
			return 1;  // double_size failed
	dt->v[dt->n++] = x;
	return 0;
}

int dcmp( const void *a, const void *b ) {
	double da = *(double*)a;
	double db = *(double*)b;
	return da < db ? -1 : (da == db ? 0 : 1 );
}

int main( int argc, char **argv ) {
	int n = argc > 1 ? atoi(argv[1]) : 10;

	dt_t dt;
	if( init_dt( &dt, 100 ) ) {
		fprintf( stderr, "%s: brak pamieci na poczontku!\n", argv[0] );
		return EXIT_FAILURE;
	}

	for( int i= 0; i < n; i++ ) 
		if( append_dt( &dt, rand() % 1000 ) ) {
			fprintf( stderr, "%s: nie mozna dodac elementu nr %d\n", argv[0], i );
			return EXIT_FAILURE;
		}

	qsort( dt.v, dt.n, sizeof dt.v[0], dcmp );
#ifdef PRINT
	for( int i= 0; i < dt.n; i++ )
		printf( "%g ", dt.v[i] );
	printf( "\n" );
#endif
	return 0;
}
