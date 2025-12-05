typedef struct e {
	double value;
	struct e * next;
} * list_t;

#include <stdio.h>  // dla NULL 

double mean_val( list_t list ) {
	if( list == NULL )
		return 0;

	double sum = 0.0;
	int n = 0;

	while( list != NULL ) {
		sum += list->value;
		n++;
		list = list->next;
	}

	return sum / n;
}

#include <stdlib.h>

list_t add( list_t list, double value ) {
	list_t n = malloc( sizeof *n );
	n->value = value;
	n->next = list;
	return n;
}

int main( int argc, char **argv ) {
	list_t l = NULL;
	for( int i= 1; i < argc; i++ )
		l = add( l, atof(argv[i]) );

	printf( "mean = %g\n", mean_val( l ) );
	return 0;
}
