#include "listy.h"

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

list_t iinsort( list_t l, double d ) {
	if( l == NULL || l->x > d ) {
		list_t nowy = malloc ( sizeof *nowy );
		nowy->x = d;
		nowy->nxt = l;
		return nowy;
	} else {
		list_t it = l;
		while( it->nxt != NULL && it->x <= d )
			it = it->nxt;
		list_t nowy = malloc( sizeof *nowy );
		nowy->x = d;
		nowy->nxt = it->nxt;
		it->nxt = nowy;
		return l;
	}
}
