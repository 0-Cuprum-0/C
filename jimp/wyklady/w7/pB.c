#include <stdlib.h>

typedef struct nd {
	double x;
	struct nd *nxt;
}  *list_t, node_t;

list_t insert( list_t l, double d ) {
	list_t nowy = malloc( sizeof *nowy );
	nowy->x = d;
	nowy->nxt = l;
	return nowy;
}

list_t append( list_t l, double d ) {
	if( l == NULL ) {
		list_t nowy = malloc( sizeof *nowy );
		nowy->x = d;
		nowy->nxt = l;
		return nowy;
	} else {
		l->nxt = append( l->nxt, d );
		return l;
	}
}

list_t insort( list_t l, double d ) {
	if( l == NULL || l->x > d ) {
		list_t nowy = malloc( sizeof *nowy );
		nowy->x = d;
		nowy->nxt = l;
		return nowy;
	} else {
		l->nxt = insort( l->nxt, d );
		return l;
	}
}

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

	list_t lista = NULL;
	list_t atsil = NULL;
	list_t ailst = NULL;

	for( int i= 0; i < n; i++ ) {
		double d = (double)(rand() % 1000 );
		lista = insert( lista, d );
		atsil = append( atsil, d );
		ailst = insort( ailst, d );
	}

#ifdef PRINT
	wypisz( lista );
	wypisz( atsil );
	wypisz( ailst );
#endif

	return 0;
}
