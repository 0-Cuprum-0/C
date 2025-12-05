#include "bst.h"
#include <stdlib.h>

bst_t insert( bst_t t, double nx ) {
	if( t == NULL ) {
		node_t *nn = malloc( sizeof *nn );
		nn->x = nx;
		nn->l = nn->r = NULL;
		return nn;
	} 
	if( t->x > nx ) {
		t->l = insert( t->l, nx );
	} else if( t->x < nx ) {
		t->r = insert( t->r, nx );
	}	
	return t;
}

void print_bst( bst_t t, int lev, FILE *out ) {
	if( t == NULL )
		return;
	if( t->r != NULL )
		print_bst( t->r, lev+1, out );
	for( int i= 0; i < lev; i++ )
		fprintf( out, "   " );
	fprintf( out, "%g\n", t->x );
	if( t->l != NULL )
		print_bst( t->l, lev+1, out );
}

void print_incr( bst_t t, FILE *out ) {
	if( t == NULL ) 
		return;
	print_incr( t->l, out );
	fprintf( out, "%g\n", t->x );
	print_incr( t->r, out );
}

void print_decr( bst_t t, FILE *out ) {
	if( t == NULL ) 
		return;
	print_decr( t->r, out );
	fprintf( out, "%g\n", t->x );
	print_decr( t->l, out );
}

void free_bst( bst_t t ) {
	if( t == NULL )
		return;
	if( t->l != NULL )
		free_bst( t->l );
	if( t->r != NULL )
		free_bst( t->r );
	free( t );
}
