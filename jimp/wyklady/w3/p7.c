#include <stdio.h>

int jest( char c, char *s ) {
	int i= 0;
	while( s[i] ) {
		if( s[i] == c )
			return i;
		i++;
	}
	return -1;
}

char *szyfr( char *s ) {
	char *doszyfru = "abcdeo";
	char *szyfr = "prmnkl";
	for( int i= 0; s[i] != '\0'; i++ ) {
		int p = jest( s[i], doszyfru );
		if( p >= 0 )
			s[i] = szyfr[p];
	}
	return s;
}

int main( int argc, char *argv[] ) {
	for( int i= 1; i < argc; i++ ) {
		printf( "%s -> ", argv[i] );
		printf( "%s\n", szyfr(argv[i]) );
		printf( "%s\n", argv[i] );
	}
	return 0;
}
