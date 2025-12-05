#include <stdio.h>

int onp( char *exp, double *rslt, char **err ) {
	printf( "Wyra≈enie: \"%s\"\n", exp );
	return 0;
}

char *catcat( char *s1, char *s2 ) {
	char *p = s1;
	while( *p )
		p++;
	*p++ = ' ';
	while( *s2 )
		*p++ = *s2++;
	*p = '\0';
	return s1;
}

#include <stdlib.h>
#include <string.h>

int main( int argc, char **argv ) {
	// posklejac argumenty
	for( int i= 2; i < argc; i++ ) {
		catcat( argv[1], argv[i] );
		printf( "<%s>\n", argv[1] );
	}
	char *err = NULL;
	double wynik = 0;
	if( onp( argv[1], &wynik, &err ) ) {
		fprintf( stderr, "%s: error: %s\n", argv[0], err );
		return EXIT_FAILURE;
	} else {
		printf( "=%g\n", wynik );
		return EXIT_SUCCESS;
	}
}
