#include <stdio.h>

int dlug( char *s ) {
	char *i = s;
	while( *i )
		i++;
	return i-s;
}

int dlugkons( char *s ) {
	int n= 0;
	while( *(s+n) != '\0' )
		n++;
	return n;
}

int main( int argc, char *argv[] ) {
	for( int i= 1; i < argc; i++ )
		printf( "%s(%d=%d)\n", argv[i], dlug(argv[i]), dlugkons(argv[i]) );
	return 0;
}
