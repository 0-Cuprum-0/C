#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int onp( char *exp, double *rslt, char **err ) {
	printf( "WyraÅenie: \"%s\"\n", exp );
	char *token;
	double stos[1000];
	int ws = 0;
        while ((token = strsep(&exp, " ")) != NULL) {
		if( strlen(token) > 0 ) {
			double x;
			char *ptr = NULL;
			x = strtod( token, &ptr );
			if( ptr == NULL ) {
				stos[ws++] = x;
			} else {
				if( ws < 2 ) {
					fprintf( stderr, "ws=%d, %s\n", ws, token );
					*err = "Syntax error";
					return 1;
				}
				if( token[0] == '+' ) {
					stos[ws-2] = stos[ws-2] + stos[ws-1];
					ws--;
				} else if( token[0] == '-' ) {
					stos[ws-2] = stos[ws-2] - stos[ws-1];
					ws--;
				} else if( token[0] == '*' ) {
					stos[ws-2] = stos[ws-2] * stos[ws-1];
					ws--;
				} else if( token[0] == '/' ) {
					stos[ws-2] = stos[ws-2] / stos[ws-1];
					ws--;
				}
			}
		}
	}
	if( ws != 1 ) {
		*err = "Not empty";
	}
	*rslt = stos[0];
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


int main( int argc, char **argv ) {
	// posklejac argumenty
	char buf[1024];
	buf[0] = '\0';
	for( int i= 1; i < argc; i++ ) {
		catcat( buf, argv[i] );
		//printf( "<%s>\n", buf );
	}
	char *err = NULL;
	double wynik = 0;
	if( onp( buf, &wynik, &err ) ) {
		fprintf( stderr, "%s: error: %s\n", argv[0], err );
		return EXIT_FAILURE;
	} else {
		printf( "=%g\n", wynik );
		return EXIT_SUCCESS;
	}
}
