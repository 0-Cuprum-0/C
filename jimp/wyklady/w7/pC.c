#include "listy.h"
#include <stdio.h>

void wypisz( list_t l ) {
	while( l != NULL ) {
		printf( "%g -> ", l->x );
		l = l->nxt;
	}
	printf( "NULL\n" );
}

int main( int argc, char **argv ) {
	int n = argc > 1 ? atoi(argv[1]) : 10;

	list_t ailst = NULL;

	for( int i= 0; i < n; i++ ) {
		double d = (double)(rand() % 1000 );
#ifdef RECURSIVE
		ailst = insort( ailst, d );
#else
		ailst = iinsort( ailst, d );
#endif
	}

#ifdef PRINT
	wypisz( ailst );
#endif

	return 0;
}
