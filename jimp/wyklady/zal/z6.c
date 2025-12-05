#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv ) {
	if( argc < 2 )
		return 1;

	double sum = 0;
	for( int i= 1; i < argc; i++ )
		sum += atof(argv[i]);

	printf( "sum=%g\n", sum );
	
	return 0;
}
