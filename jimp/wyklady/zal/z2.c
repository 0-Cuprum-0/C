#ifdef SAMOROBKA

void ssort( char *s ) {
	char *p = s;
	while( *p++ )
		;
	int n= p - s - 1;
	for( int i= 1; i < n; i++ ) {
		char tmp = s[i];
		int j;
		for( j = i; j > 0 && s[j-1] > tmp; j-- )
			s[j] = s[j-1];
		s[j] = tmp;
	}
}

#else

#include <string.h>
#include <stdlib.h>

int cmp( const void *a, const void *b ) {
	return *(char *)a - *(char *)b;
}

void ssort( char *s ) {
	qsort( s, strlen(s), 1, cmp );
}

#endif

#include <stdio.h>

int main( int argc, char **argv ) {
	for( int i= 1; i < argc; i++ ) {
		printf( "%s -> ", argv[i] );
		ssort( argv[i] );
		printf( "%s\n", argv[i] );
	}
	return 0;
}
