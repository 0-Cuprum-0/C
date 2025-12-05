#include "lista.h"
#include <stdlib.h>

list_t insert( list_t l, double nx ) {
	elem_t *nowy = malloc( sizeof *nowy );
	// powinniśmy zbadać, czy nie NULL
	nowy->x = nx;
	nowy->nast = l;
	return nowy;
}

list_t append( list_t l, double nx ) {
	if( l == NULL ) {
		elem_t *nowy = malloc( sizeof * nowy ); // powinniśmy .. czy nie NULL
		nowy->x = nx;
		nowy->nast = NULL;
		return nowy;
	}	else {
		l->nast = append( l->nast, nx );
		return l;
	}
}

list_t append_no_rec( list_t l, double nx ) {
  if( l == NULL ) {
    elem_t *nowy = malloc( sizeof * nowy ); // powinniśmy .. czy nie NULL
    nowy->x = nx;
    nowy->nast = NULL;
    return nowy;
  } else {
    list_t iterator = l;
		while( iterator->nast != NULL )
			iterator = iterator->nast;
		elem_t *nowy = malloc( sizeof * nowy ); // powinniśmy .. czy nie NULL
    nowy->x = nx;
    nowy->nast = NULL; 
		iterator->nast = nowy;
		return l;
	}
}

list_t insert_sort( list_t l, double nx ) {
	if( l == NULL || l->x > nx ) {
    elem_t *nowy = malloc( sizeof * nowy ); // powinniśmy .. czy nie NULL
    nowy->x = nx;
    nowy->nast = l;
		return nowy;
	} else {
		l->nast = insert_sort( l->nast, nx );
		return l;
	}
}

list_t insert_sort_no_rec( list_t l, double nx ) {
  if( l == NULL || l->x > nx ) {
    elem_t *nowy = malloc( sizeof * nowy ); // powinniśmy .. czy nie NULL
    nowy->x = nx;
    nowy->nast = l;
    return nowy;
  } else {
    list_t iterator = l;
    while( iterator->nast != NULL && iterator->nast->x <= nx )
      iterator = iterator->nast;
    elem_t *nowy = malloc( sizeof * nowy ); // powinniśmy .. czy nie NULL
    nowy->x = nx;
    nowy->nast = iterator->nast;
    iterator->nast = nowy;
    return l;
  }
}

void free_list( list_t l ) {
	while( l != NULL ) {
		list_t tmp = l->nast;
		free( l );
		l = tmp;
	}
}
