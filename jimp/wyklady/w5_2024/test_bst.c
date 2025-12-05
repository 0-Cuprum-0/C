#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv ) {
	bst_t t = NULL;

	for( int it= 1; it < argc; it++ ) {
		t = insert( t, atof(argv[it]) );
	}

	print_bst( t, 0, stdout );

	printf( "---\n" );

	print_incr( t, stdout );

	printf( "---\n" );

	print_decr( t, stdout );

	free_bst( t );

	return 0;
}
