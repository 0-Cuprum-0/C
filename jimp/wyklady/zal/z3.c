#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv ) {
	int count['z'-'a'+1] = {0}; // liter jest 26, ale nie trzeba tego pamiętać
	FILE *in = argc > 1 ? fopen( argv[1], "r" ) : stdin;
	if( in == NULL )
		return EXIT_FAILURE;
	int c;
	while( (c = fgetc(in)) != EOF ) {
		if( c >= 'a' && c <= 'z' )
			count[c-'a']++;
	}

	fclose(in);
	for( int i= 0; i < sizeof count / sizeof count[0]; i++ )
		printf( "%c -> %d\n", 'a'+i, count[i] );

	return EXIT_SUCCESS;
}
