#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void print_list( list_t l, char *name ) {
	printf( "Lista %s: ", name );
  while( l != NULL ) {
    printf( "%g -> ", l->x );
    l = l->nast;
  } 
  printf( "NULL\n" );
}

int main( int argc, char **argv ) {
	list_t l = NULL;
	list_t k = NULL;
	list_t j = NULL;
	list_t i = NULL;
	list_t h = NULL;

	for( int it= 1; it < argc; it++ ) {
		l = insert( l, atof(argv[it]) );
		k = append( k, atof(argv[it]) );
		j = append_no_rec( j, atof(argv[it]) );
		i = insert_sort( i, atof(argv[it]) );
		h = insert_sort_no_rec( h, atof(argv[it]) );
	}

	print_list( l, "l" );
	print_list( k, "k" );
	print_list( j, "j" );
	print_list( i, "i" );
	print_list( h, "h" );

	free_list( h );
	free_list( i );
	free_list( j );
	free_list( k );
	free_list( l );

	return 0;
}
